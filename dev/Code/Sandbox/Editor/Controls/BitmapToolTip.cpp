/*
* All or portions of this file Copyright (c) Amazon.com, Inc. or its affiliates or
* its licensors.
*
* For complete copyright and license terms please see the LICENSE at the root of this
* distribution (the "License"). All use of this software is governed by the License,
* or, if provided, by the license below or the license accompanying this file. Do not
* remove or modify any license notices. This file is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*
*/
// Original file Copyright Crytek GMBH or its affiliates, used under license.

// Description : Tooltip that displays bitmap.


#include "StdAfx.h"
#include "BitmapToolTip.h"
#include "Util/PathUtil.h"

#include <QApplication>
#include <QDesktopWidget>
#include <QKeyEvent>
#include <QVBoxLayout>

static const int STATIC_TEXT_C_HEIGHT = 42;
static const int HISTOGRAM_C_HEIGHT = 130;

/////////////////////////////////////////////////////////////////////////////
// CBitmapToolTip
CBitmapToolTip::CBitmapToolTip(QWidget* parent)
    : QWidget(parent, Qt::ToolTip)
    , m_staticBitmap(new QLabel(this))
    , m_staticText(new QLabel(this))
    , m_rgbaHistogram(new CImageHistogramCtrl(this))
    , m_alphaChannelHistogram(new CImageHistogramCtrl(this))
{
    m_nTimer = 0;
    m_hToolWnd = nullptr;
    m_bShowHistogram = true;
    m_bShowFullsize = false;

    connect(&m_timer, &QTimer::timeout, this, &CBitmapToolTip::OnTimer);

    auto* layout = new QVBoxLayout(this);
    layout->setSizeConstraint(QLayout::SetFixedSize);

    layout->addWidget(m_staticBitmap);
    layout->addWidget(m_staticText);

    auto* histogramLayout = new QHBoxLayout(this);
    histogramLayout->addWidget(m_rgbaHistogram);
    histogramLayout->addWidget(m_alphaChannelHistogram);
    m_alphaChannelHistogram->setVisible(false);

    layout->addLayout(histogramLayout);

    setLayout(layout);
}

CBitmapToolTip::~CBitmapToolTip()
{
}

//////////////////////////////////////////////////////////////////////////
void CBitmapToolTip::GetShowMode(EShowMode& eShowMode, bool& bShowInOriginalSize) const
{
    bShowInOriginalSize = CheckVirtualKey(Qt::Key_Space);
    eShowMode = ESHOW_RGB;

    if (m_bHasAlpha)
    {
        if (CheckVirtualKey(Qt::Key_Control))
        {
            eShowMode = ESHOW_RGB_ALPHA;
        }
        else if (CheckVirtualKey(Qt::Key_Alt))
        {
            eShowMode = ESHOW_ALPHA;
        }
        else if (CheckVirtualKey(Qt::Key_Shift))
        {
            eShowMode = ESHOW_RGBA;
        }
    }
    else if (m_bIsLimitedHDR)
    {
        if (CheckVirtualKey(Qt::Key_Shift))
        {
            eShowMode = ESHOW_RGBE;
        }
    }
}

const char* CBitmapToolTip::GetShowModeDescription(EShowMode eShowMode, bool bShowInOriginalSize) const
{
    switch (eShowMode)
    {
    case ESHOW_RGB:
        return "RGB";
    case ESHOW_RGB_ALPHA:
        return "RGB+A";
    case ESHOW_ALPHA:
        return "Alpha";
    case ESHOW_RGBA:
        return "RGBA";
    case ESHOW_RGBE:
        return "RGBExp";
    }

    return "";
}

void CBitmapToolTip::RefreshViewmode()
{
    LoadImage(m_filename);

    if (m_eShowMode == ESHOW_RGB_ALPHA || m_eShowMode == ESHOW_RGBA)
    {
        m_rgbaHistogram->setVisible(true);
        m_alphaChannelHistogram->setVisible(true);
    }
    else if (m_eShowMode == ESHOW_ALPHA)
    {
        m_rgbaHistogram->setVisible(false);
        m_alphaChannelHistogram->setVisible(true);
    }
    else
    {
        m_rgbaHistogram->setVisible(true);
        m_alphaChannelHistogram->setVisible(false);
    }
}

bool CBitmapToolTip::LoadImage(const QString& imageFilename)
{
    EShowMode eShowMode = ESHOW_RGB;
    const char* pShowModeDescription = "RGB";
    bool bShowInOriginalSize = false;

    GetShowMode(eShowMode, bShowInOriginalSize);
    pShowModeDescription = GetShowModeDescription(eShowMode, bShowInOriginalSize);

    if ((m_eShowMode == eShowMode) && (m_bShowFullsize == bShowInOriginalSize))
    {
        return true;
    }

    // For max quality, let's try loading the source image if available:
    QString convertedFileName = Path::GamePathToFullPath(Path::ReplaceExtension(imageFilename, ".dds"));

    CCryFile fileCheck;
    if (!fileCheck.Open(convertedFileName.toUtf8().data(), "rb"))
    {
        // if we didn't find it, then default back to just using what we can find (if any)
        convertedFileName = imageFilename;
    }
    else
    {
        fileCheck.Close();
    }

    if ((m_filename == convertedFileName))
    {
        return true;
    }

    m_eShowMode = eShowMode;
    m_bShowFullsize = bShowInOriginalSize;

    CImageEx image;
    image.SetHistogramEqualization(CheckVirtualKey(Qt::Key_Shift));
    bool loadedRequestedAsset = true;
    if (!CImageUtil::LoadImage(imageFilename, image))
    {
        //Failed to load the requested asset,  let's try loading the source asset if available.
        loadedRequestedAsset = false;
        if (!CImageUtil::LoadImage(convertedFileName, image))
        {
            m_staticBitmap->clear();
            return false;
        }
    }

    QString imginfo;

    m_filename = loadedRequestedAsset ? imageFilename : convertedFileName;
    m_bHasAlpha = image.HasAlphaChannel();
    m_bIsLimitedHDR = image.IsLimitedHDR();

    GetShowMode(eShowMode, bShowInOriginalSize);
    pShowModeDescription = GetShowModeDescription(eShowMode, bShowInOriginalSize);

    if (m_bHasAlpha)
    {
        imginfo = tr("%1x%2 %3\nShowing %4 (ALT=Alpha, SHIFT=RGBA, CTRL=RGB+A, SPACE=see in original size)");
    }
    else if (m_bIsLimitedHDR)
    {
        imginfo = tr("%1x%2 %3\nShowing %4 (SHIFT=see hist.-equalized, SPACE=see in original size)");
    }
    else
    {
        imginfo = tr("%1x%2 %3\nShowing %4 (SPACE=see in original size)");
    }

    imginfo = imginfo.arg(image.GetWidth()).arg(image.GetHeight()).arg(image.GetFormatDescription()).arg(pShowModeDescription);

    m_staticText->setText(imginfo);

    int w = image.GetWidth();
    int h = image.GetHeight();
    int multiplier = (m_eShowMode == ESHOW_RGB_ALPHA ? 2 : 1);
    int originalW = w * multiplier;
    int originalH = h;

    if (!bShowInOriginalSize || (w == 0))
    {
        w = 256;
    }
    if (!bShowInOriginalSize || (h == 0))
    {
        h = 256;
    }

    w *= multiplier;

    resize(w + 4, h + 4 + STATIC_TEXT_C_HEIGHT + HISTOGRAM_C_HEIGHT);
    setVisible(true);

    CImageEx scaledImage;

    if (bShowInOriginalSize && (originalW < w))
    {
        w = originalW;
    }
    if (bShowInOriginalSize && (originalH < h))
    {
        h = originalH;
    }

    scaledImage.Allocate(w, h);

    if (m_eShowMode == ESHOW_RGB_ALPHA)
    {
        CImageUtil::ScaleToDoubleFit(image, scaledImage);
    }
    else
    {
        CImageUtil::ScaleToFit(image, scaledImage);
    }

    if (m_eShowMode == ESHOW_RGB || m_eShowMode == ESHOW_RGBE)
    {
        scaledImage.SwapRedAndBlue();
        scaledImage.FillAlpha();
    }
    else if (m_eShowMode == ESHOW_ALPHA)
    {
        for (int h = 0; h < scaledImage.GetHeight(); h++)
        {
            for (int w = 0; w < scaledImage.GetWidth(); w++)
            {
                int a = scaledImage.ValueAt(w, h) >> 24;
                scaledImage.ValueAt(w, h) = RGB(a, a, a);
            }
        }
    }
    else if (m_eShowMode == ESHOW_RGB_ALPHA)
    {
        int halfWidth = scaledImage.GetWidth() / 2;
        for (int h = 0; h < scaledImage.GetHeight(); h++)
        {
            for (int w = 0; w < halfWidth; w++)
            {
                int r = GetRValue(scaledImage.ValueAt(w, h));
                int g = GetGValue(scaledImage.ValueAt(w, h));
                int b = GetBValue(scaledImage.ValueAt(w, h));
                int a = scaledImage.ValueAt(w, h) >> 24;
                scaledImage.ValueAt(w, h) = RGB(b, g, r);
                scaledImage.ValueAt(w + halfWidth, h) = RGB(a, a, a);
            }
        }
    }
    else //if (m_showMode == ESHOW_RGBA)
    {
        scaledImage.SwapRedAndBlue();
    }

    QImage qImage(scaledImage.GetWidth(), scaledImage.GetHeight(), QImage::Format_RGB32);
    memcpy(qImage.bits(), scaledImage.GetData(), qImage.byteCount());
    m_staticBitmap->setPixmap(QPixmap::fromImage(qImage));

    if (m_bShowHistogram && scaledImage.GetData())
    {
        m_rgbaHistogram->ComputeHistogram(image, CImageHistogram::eImageFormat_32BPP_BGRA);
        m_rgbaHistogram->setDrawMode(EHistogramDrawMode::OverlappedRGB);

        m_alphaChannelHistogram->histogramDisplay()->CopyComputedDataFrom(m_rgbaHistogram->histogramDisplay());
        m_alphaChannelHistogram->setDrawMode(EHistogramDrawMode::AlphaChannel);
    }

    return true;
}

void CBitmapToolTip::OnTimer()
{
    /*
    if (IsWindowVisible())
    {
        if (m_bHaveAnythingToRender)
            Invalidate();
    }
    */
    if (m_hToolWnd)
    {
        QRect toolRc(m_toolRect);
        QRect rc = geometry();
        QPoint cursorPos = QCursor::pos();
        toolRc.moveTopLeft(m_hToolWnd->mapToGlobal(toolRc.topLeft()));
        if (!toolRc.contains(cursorPos) && !rc.contains(cursorPos))
        {
            setVisible(false);
        }
        else
        {
            RefreshViewmode();
        }
    }
}

//////////////////////////////////////////////////////////////////////////
void CBitmapToolTip::showEvent(QShowEvent* event)
{
    QPoint cursorPos = QCursor::pos();
    move(cursorPos);
    m_timer.start(500);
}

//////////////////////////////////////////////////////////////////////////
void CBitmapToolTip::hideEvent(QHideEvent* event)
{
    m_timer.stop();
}

//////////////////////////////////////////////////////////////////////////

void CBitmapToolTip::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Control || event->key() == Qt::Key_Alt || event->key() == Qt::Key_Shift)
    {
        RefreshViewmode();
    }
}

void CBitmapToolTip::keyReleaseEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Control || event->key() == Qt::Key_Alt || event->key() == Qt::Key_Shift)
    {
        RefreshViewmode();
    }
}

//////////////////////////////////////////////////////////////////////////
void CBitmapToolTip::SetTool(QWidget* pWnd, const QRect& rect)
{
    assert(pWnd);
    m_hToolWnd = pWnd;
    m_toolRect = rect;
}

#include <Controls/BitmapToolTip.moc>
