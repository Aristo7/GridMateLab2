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

#include "StdAfx.h"
#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Component/ComponentApplication.h>

#include "EditorFrameworkAPI.h"

namespace LegacyFramework
{
    const char* appName()
    {
        const char* result = NULL;
        EBUS_EVENT_RESULT(result, FrameworkApplicationMessages::Bus, GetApplicationName);
        return result;
    }

    const char* appModule()
    {
        const char* result = NULL;
        EBUS_EVENT_RESULT(result, FrameworkApplicationMessages::Bus, GetApplicationModule);
        return result;
    }

    const char* appDir()
    {
        const char* result = NULL;
        EBUS_EVENT_RESULT(result, FrameworkApplicationMessages::Bus, GetApplicationDirectory);
        return result;
    }

    bool RequiresGameProject()
    {
        bool result = false;
        EBUS_EVENT_RESULT(result, FrameworkApplicationMessages::Bus, RequiresGameProject);
        return result;
    }

    bool IsGUIMode()
    {
        bool result = false;
        EBUS_EVENT_RESULT(result, FrameworkApplicationMessages::Bus, IsRunningInGUIMode);
        return result;
    }

    bool appAbortRequested()
    {
        bool result = false;
        EBUS_EVENT_RESULT(result, FrameworkApplicationMessages::Bus, GetAbortRequested);
        return result;
    }

    bool isMaster()
    {
        bool result = false;
        EBUS_EVENT_RESULT(result, FrameworkApplicationMessages::Bus, IsMaster);
        return result;
    }

    bool IsAppConfigWritable()
    {
        bool result = false;
        EBUS_EVENT_RESULT(result, FrameworkApplicationMessages::Bus, IsAppConfigWritable);
        return result;
    }

    // helper function which retrieves the serialize context and asserts if its not found.
    AZ::SerializeContext* GetSerializeContext()
    {
        AZ::SerializeContext* serializeContext = NULL;
        EBUS_EVENT_RESULT(serializeContext, AZ::ComponentApplicationBus, GetSerializeContext);
        AZ_Assert(serializeContext, "No serialize context");
        return serializeContext;
    }

    void AddToPATH(const char* folder)
    {
        QString currentPath = QString::fromUtf8(qgetenv("PATH"));
        currentPath.append(";");
        currentPath.append(folder);
        qputenv("PATH", currentPath.toUtf8());
    }

    bool ShouldRunAssetProcessor()
    {
        bool result = false;
        EBUS_EVENT_RESULT(result, FrameworkApplicationMessages::Bus, ShouldRunAssetProcessor);
        return result;
    }
}
