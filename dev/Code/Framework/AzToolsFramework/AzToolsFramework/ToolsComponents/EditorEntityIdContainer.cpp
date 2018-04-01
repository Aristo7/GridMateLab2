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
#include "EditorEntityIdContainer.h"
#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Component/Component.h>
#include <AzCore/Component/ComponentApplicationBus.h>
#include <AzCore/Serialization/ObjectStream.h>
#include <AzCore/Serialization/Utils.h>
#include <AzCore/IO/GenericStreams.h>
#include <AzCore/IO/ByteContainerStream.h>


namespace AzToolsFramework
{
    void EditorEntityIdContainer::Reflect(AZ::ReflectContext* context)
    {
        AZ::SerializeContext* serializeContext = azrtti_cast<AZ::SerializeContext*>(context);
        if (serializeContext)
        {
            serializeContext->Class<EditorEntityIdContainer>()
                ->Field("m_entityIds", &EditorEntityIdContainer::m_entityIds)
                ->Version(1);
        }
    }

    bool EditorEntityIdContainer::ToBuffer(AZStd::vector<char>& buffer)
    {
        buffer.clear();
        AZ::IO::ByteContainerStream<AZStd::vector<char> > ms(&buffer);
        return AZ::Utils::SaveObjectToStream(ms, AZ::DataStream::ST_BINARY, this);
    }

    bool EditorEntityIdContainer::FromBuffer(const char* data, AZStd::size_t size)
    {
        AZ::IO::MemoryStream ms(data, size);

        EditorEntityIdContainer* pContainer = AZ::Utils::LoadObjectFromStream<EditorEntityIdContainer>(ms, nullptr);
        if (pContainer)
        {
            m_entityIds = AZStd::move(pContainer->m_entityIds);
            delete pContainer;
            return true;
        }

        return false;
    }

    bool EditorEntityIdContainer::FromBuffer(const AZStd::vector<char>& buffer)
    {
        return FromBuffer(buffer.data(), buffer.size());
    }
}
