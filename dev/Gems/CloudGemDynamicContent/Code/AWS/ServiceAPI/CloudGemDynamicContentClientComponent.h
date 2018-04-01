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
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
// THIS CODE IS AUTOGENERATED, DO NOT MODIFY
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
#pragma once
#include <AzCore/Component/Component.h>
#include <AzCore/Component/Entity.h>
#include <AzCore/Component/ComponentBus.h>
#include <AzCore/EBus/EBus.h>
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/RTTI/BehaviorContext.h>
#include <AzCore/Serialization/EditContext.h>
#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/std/smart_ptr/make_shared.h>
#include <AzCore/std/smart_ptr/shared_ptr.h>
#include <AzCore/std/string/conversions.h>

#if defined (PLATFORM_SUPPORTS_AWS_NATIVE_SDK)
#include <aws/core/http/HttpRequest.h>
#include <aws/core/http/HttpResponse.h>
#endif // (PLATFORM_SUPPORTS_AWS_NATIVE_SDK)

#include <CloudGemFramework/ServiceRequestJob.h>

#include "CloudGemDynamicContent_precompiled.h"

namespace CloudGemDynamicContent {
namespace ServiceAPI {
    
    extern const char* LmbrAWS_CodeGen_Component_UUID;
    
    extern const char* LmbrAWS_CodeGen_PortalFileRequest_UUID;
    
    extern const char* LmbrAWS_CodeGen_PortalFileListResults_UUID;
    
    extern const char* LmbrAWS_CodeGen_ResponseHandler_UUID;
    
    extern const char* LmbrAWS_CodeGen_NotificationBus1_UUID;
    
    extern const char* LmbrAWS_CodeGen_RequestBus1_UUID;
    
    extern const char* LmbrAWS_CodeGen_RequestData_UUID;
    
    extern const char* LmbrAWS_CodeGen_FileRequestResults_UUID;
    
    extern const char* LmbrAWS_CodeGen_FileRequestResult_UUID;
    
    extern const char* LmbrAWS_CodeGen_ServiceStatus_UUID;
    
    extern const char* LmbrAWS_CodeGen_PortalFileRequestList_UUID;
    
    extern const char* LmbrAWS_CodeGen_PortalFileInfo_UUID;
    

    // redefs
    

    bool WriteJson(CloudGemFramework::JsonWriter& writer, const int& item);

    bool WriteJson(CloudGemFramework::JsonWriter& writer, const AZStd::string& item);

    bool WriteJson(CloudGemFramework::JsonWriter& writer, const double& item);

    
    
    using RequestDataPropertyFileList = AZStd::vector<AZStd::string>;

    bool WriteJson(CloudGemFramework::JsonWriter& writer, const RequestDataPropertyFileList& list);
    
    
    
    struct RequestData
    {

        AZ_TYPE_INFO(RequestData, LmbrAWS_CodeGen_RequestData_UUID)
        AZ_CLASS_ALLOCATOR(RequestData, AZ::SystemAllocator, 0)

        
        RequestDataPropertyFileList FileList;
        

        bool OnJsonKey(const char* key, CloudGemFramework::JsonReader& reader);

        static void Reflect(AZ::ReflectContext* reflection);
    };

    bool WriteJson(CloudGemFramework::JsonWriter& writer, const RequestData& item);
    
    
    
    struct FileRequestResult
    {

        AZ_TYPE_INFO(FileRequestResult, LmbrAWS_CodeGen_FileRequestResult_UUID)
        AZ_CLASS_ALLOCATOR(FileRequestResult, AZ::SystemAllocator, 0)

        
        AZStd::string FileStatus;
        
        AZStd::string Signature;
        
        AZStd::string PresignedURL;
        
        AZStd::string FileName;
        

        bool OnJsonKey(const char* key, CloudGemFramework::JsonReader& reader);

        static void Reflect(AZ::ReflectContext* reflection);
    };

    bool WriteJson(CloudGemFramework::JsonWriter& writer, const FileRequestResult& item);
    
    
    
    using FileRequestResultArray = AZStd::vector<FileRequestResult>;

    bool WriteJson(CloudGemFramework::JsonWriter& writer, const FileRequestResultArray& list);
    
    
    
    struct FileRequestResults
    {

        AZ_TYPE_INFO(FileRequestResults, LmbrAWS_CodeGen_FileRequestResults_UUID)
        AZ_CLASS_ALLOCATOR(FileRequestResults, AZ::SystemAllocator, 0)

        
        FileRequestResultArray ResultList;
        

        bool OnJsonKey(const char* key, CloudGemFramework::JsonReader& reader);

        static void Reflect(AZ::ReflectContext* reflection);
    };

    bool WriteJson(CloudGemFramework::JsonWriter& writer, const FileRequestResults& item);
    
    
    
    struct PortalFileRequest
    {

        AZ_TYPE_INFO(PortalFileRequest, LmbrAWS_CodeGen_PortalFileRequest_UUID)
        AZ_CLASS_ALLOCATOR(PortalFileRequest, AZ::SystemAllocator, 0)

        
        AZStd::string StagingEnd;
        
        AZStd::string StagingStatus;
        
        AZStd::string StagingStart;
        
        AZStd::string FileName;
        

        bool OnJsonKey(const char* key, CloudGemFramework::JsonReader& reader);

        static void Reflect(AZ::ReflectContext* reflection);
    };

    bool WriteJson(CloudGemFramework::JsonWriter& writer, const PortalFileRequest& item);
    
    
    
    using PortalFileRequestListPropertyFileList = AZStd::vector<PortalFileRequest>;

    bool WriteJson(CloudGemFramework::JsonWriter& writer, const PortalFileRequestListPropertyFileList& list);
    
    
    
    struct PortalFileRequestList
    {

        AZ_TYPE_INFO(PortalFileRequestList, LmbrAWS_CodeGen_PortalFileRequestList_UUID)
        AZ_CLASS_ALLOCATOR(PortalFileRequestList, AZ::SystemAllocator, 0)

        
        PortalFileRequestListPropertyFileList FileList;
        

        bool OnJsonKey(const char* key, CloudGemFramework::JsonReader& reader);

        static void Reflect(AZ::ReflectContext* reflection);
    };

    bool WriteJson(CloudGemFramework::JsonWriter& writer, const PortalFileRequestList& item);
    
    
    
    struct PortalFileInfo
    {

        AZ_TYPE_INFO(PortalFileInfo, LmbrAWS_CodeGen_PortalFileInfo_UUID)
        AZ_CLASS_ALLOCATOR(PortalFileInfo, AZ::SystemAllocator, 0)

        
        AZStd::string StagingEnd;
        
        AZStd::string StagingStatus;
        
        AZStd::string StagingStart;
        
        AZStd::string Parent;
        
        AZStd::string FileName;
        

        bool OnJsonKey(const char* key, CloudGemFramework::JsonReader& reader);

        static void Reflect(AZ::ReflectContext* reflection);
    };

    bool WriteJson(CloudGemFramework::JsonWriter& writer, const PortalFileInfo& item);
    
    
    
    using PortalFileListResultsPropertyResults = AZStd::vector<PortalFileInfo>;

    bool WriteJson(CloudGemFramework::JsonWriter& writer, const PortalFileListResultsPropertyResults& list);
    
    
    
    struct PortalFileListResults
    {

        AZ_TYPE_INFO(PortalFileListResults, LmbrAWS_CodeGen_PortalFileListResults_UUID)
        AZ_CLASS_ALLOCATOR(PortalFileListResults, AZ::SystemAllocator, 0)

        
        PortalFileListResultsPropertyResults results;
        

        bool OnJsonKey(const char* key, CloudGemFramework::JsonReader& reader);

        static void Reflect(AZ::ReflectContext* reflection);
    };

    bool WriteJson(CloudGemFramework::JsonWriter& writer, const PortalFileListResults& item);
    
    
    
    struct ServiceStatus
    {

        AZ_TYPE_INFO(ServiceStatus, LmbrAWS_CodeGen_ServiceStatus_UUID)
        AZ_CLASS_ALLOCATOR(ServiceStatus, AZ::SystemAllocator, 0)

        
        AZStd::string status;
        

        bool OnJsonKey(const char* key, CloudGemFramework::JsonReader& reader);

        static void Reflect(AZ::ReflectContext* reflection);
    };

    bool WriteJson(CloudGemFramework::JsonWriter& writer, const ServiceStatus& item);
    
    


    // Service RequestJobs
    CLOUD_GEM_SERVICE(CloudGemDynamicContent);


    
    class PostClientContentRequest
        : public CloudGemFramework::ServiceRequest
    {
    public:
        SERVICE_REQUEST(CloudGemDynamicContent, HttpMethod::HTTP_POST, "/client/content");

        struct Parameters
        {
            
            RequestData request_content;
            

            bool BuildRequest(CloudGemFramework::RequestBuilder& request);

            bool WriteJson(CloudGemFramework::JsonWriter& writer) const;
        };

        
        FileRequestResults result;
        

        Parameters parameters;
    };


    using PostClientContentRequestJob = CloudGemFramework::ServiceRequestJob<PostClientContentRequest>;
    
    class PostPortalContentRequest
        : public CloudGemFramework::ServiceRequest
    {
    public:
        SERVICE_REQUEST(CloudGemDynamicContent, HttpMethod::HTTP_POST, "/portal/content");

        struct Parameters
        {
            
            PortalFileRequestList request_content;
            

            bool BuildRequest(CloudGemFramework::RequestBuilder& request);

            bool WriteJson(CloudGemFramework::JsonWriter& writer) const;
        };

        
        PortalFileListResults result;
        

        Parameters parameters;
    };


    using PostPortalContentRequestJob = CloudGemFramework::ServiceRequestJob<PostPortalContentRequest>;
    
    class DeletePortalContentRequest
        : public CloudGemFramework::ServiceRequest
    {
    public:
        SERVICE_REQUEST(CloudGemDynamicContent, HttpMethod::HTTP_DELETE, "/portal/content");

        struct Parameters
        {
            

            bool BuildRequest(CloudGemFramework::RequestBuilder& request);

            bool WriteJson(CloudGemFramework::JsonWriter& writer) const;
        };

        
        PortalFileRequestList result;
        

        Parameters parameters;
    };


    using DeletePortalContentRequestJob = CloudGemFramework::ServiceRequestJob<DeletePortalContentRequest>;
    
    class GetPortalContentRequest
        : public CloudGemFramework::ServiceRequest
    {
    public:
        SERVICE_REQUEST(CloudGemDynamicContent, HttpMethod::HTTP_GET, "/portal/content");

        struct Parameters
        {
            

            bool BuildRequest(CloudGemFramework::RequestBuilder& request);

            bool WriteJson(CloudGemFramework::JsonWriter& writer) const;
        };

        
        PortalFileListResults result;
        

        Parameters parameters;
    };


    using GetPortalContentRequestJob = CloudGemFramework::ServiceRequestJob<GetPortalContentRequest>;
    
    class GetServiceStatusRequest
        : public CloudGemFramework::ServiceRequest
    {
    public:
        SERVICE_REQUEST(CloudGemDynamicContent, HttpMethod::HTTP_GET, "/service/status");

        struct Parameters
        {
            

            bool BuildRequest(CloudGemFramework::RequestBuilder& request);

            bool WriteJson(CloudGemFramework::JsonWriter& writer) const;
        };

        
        ServiceStatus result;
        

        Parameters parameters;
    };


    using GetServiceStatusRequestJob = CloudGemFramework::ServiceRequestJob<GetServiceStatusRequest>;
    
    class DeletePortalInfoRequest
        : public CloudGemFramework::ServiceRequest
    {
    public:
        SERVICE_REQUEST(CloudGemDynamicContent, HttpMethod::HTTP_DELETE, "/portal/info/{file_name}");

        struct Parameters
        {
            
            AZStd::string file_name;
            

            bool BuildRequest(CloudGemFramework::RequestBuilder& request);

            bool WriteJson(CloudGemFramework::JsonWriter& writer) const;
        };

        
        PortalFileRequestList result;
        

        Parameters parameters;
    };


    using DeletePortalInfoRequestJob = CloudGemFramework::ServiceRequestJob<DeletePortalInfoRequest>;
    
    class GetPortalInfoRequest
        : public CloudGemFramework::ServiceRequest
    {
    public:
        SERVICE_REQUEST(CloudGemDynamicContent, HttpMethod::HTTP_GET, "/portal/info/{file_name}");

        struct Parameters
        {
            
            AZStd::string file_name;
            

            bool BuildRequest(CloudGemFramework::RequestBuilder& request);

            bool WriteJson(CloudGemFramework::JsonWriter& writer) const;
        };

        
        PortalFileInfo result;
        

        Parameters parameters;
    };


    using GetPortalInfoRequestJob = CloudGemFramework::ServiceRequestJob<GetPortalInfoRequest>;
    


    // Notification bus for this component
    class CloudGemDynamicContentNotifications
        : public AZ::ComponentBus
    {
    public:
        
        /**
         * Sent when the request is a success
         *
         * Params:
         *    jsonOutput:       The output receieved from the lambda call
         *    request:          The AWS Lambda request object
         */
        
        virtual void OnPostClientContentRequestSuccess(const FileRequestResults response);
        

        /**
         * Sent when the request fails
         *
         * Params:
         *    error:           The output receieved from the lambda call,
         *                     could be function error or an issue with the request
         *    request:         The AWS Lambda request object
         */
        virtual void OnPostClientContentRequestError(const CloudGemFramework::Error error);
        
        /**
         * Sent when the request is a success
         *
         * Params:
         *    jsonOutput:       The output receieved from the lambda call
         *    request:          The AWS Lambda request object
         */
        
        virtual void OnPostPortalContentRequestSuccess(const PortalFileListResults response);
        

        /**
         * Sent when the request fails
         *
         * Params:
         *    error:           The output receieved from the lambda call,
         *                     could be function error or an issue with the request
         *    request:         The AWS Lambda request object
         */
        virtual void OnPostPortalContentRequestError(const CloudGemFramework::Error error);
        
        /**
         * Sent when the request is a success
         *
         * Params:
         *    jsonOutput:       The output receieved from the lambda call
         *    request:          The AWS Lambda request object
         */
        
        virtual void OnDeletePortalContentRequestSuccess(const PortalFileRequestList response);
        

        /**
         * Sent when the request fails
         *
         * Params:
         *    error:           The output receieved from the lambda call,
         *                     could be function error or an issue with the request
         *    request:         The AWS Lambda request object
         */
        virtual void OnDeletePortalContentRequestError(const CloudGemFramework::Error error);
        
        /**
         * Sent when the request is a success
         *
         * Params:
         *    jsonOutput:       The output receieved from the lambda call
         *    request:          The AWS Lambda request object
         */
        
        virtual void OnGetPortalContentRequestSuccess(const PortalFileListResults response);
        

        /**
         * Sent when the request fails
         *
         * Params:
         *    error:           The output receieved from the lambda call,
         *                     could be function error or an issue with the request
         *    request:         The AWS Lambda request object
         */
        virtual void OnGetPortalContentRequestError(const CloudGemFramework::Error error);
        
        /**
         * Sent when the request is a success
         *
         * Params:
         *    jsonOutput:       The output receieved from the lambda call
         *    request:          The AWS Lambda request object
         */
        
        virtual void OnGetServiceStatusRequestSuccess(const ServiceStatus response);
        

        /**
         * Sent when the request fails
         *
         * Params:
         *    error:           The output receieved from the lambda call,
         *                     could be function error or an issue with the request
         *    request:         The AWS Lambda request object
         */
        virtual void OnGetServiceStatusRequestError(const CloudGemFramework::Error error);
        
        /**
         * Sent when the request is a success
         *
         * Params:
         *    jsonOutput:       The output receieved from the lambda call
         *    request:          The AWS Lambda request object
         */
        
        virtual void OnDeletePortalInfoRequestSuccess(const PortalFileRequestList response);
        

        /**
         * Sent when the request fails
         *
         * Params:
         *    error:           The output receieved from the lambda call,
         *                     could be function error or an issue with the request
         *    request:         The AWS Lambda request object
         */
        virtual void OnDeletePortalInfoRequestError(const CloudGemFramework::Error error);
        
        /**
         * Sent when the request is a success
         *
         * Params:
         *    jsonOutput:       The output receieved from the lambda call
         *    request:          The AWS Lambda request object
         */
        
        virtual void OnGetPortalInfoRequestSuccess(const PortalFileInfo response);
        

        /**
         * Sent when the request fails
         *
         * Params:
         *    error:           The output receieved from the lambda call,
         *                     could be function error or an issue with the request
         *    request:         The AWS Lambda request object
         */
        virtual void OnGetPortalInfoRequestError(const CloudGemFramework::Error error);
        
    };

    using CloudGemDynamicContentNotificationBus = AZ::EBus<CloudGemDynamicContentNotifications>;

    class BehaviorCloudGemDynamicContentNotificationBusHandler
        : public CloudGemDynamicContentNotificationBus::Handler, public AZ::BehaviorEBusHandler
    {
    public:
        AZ_EBUS_BEHAVIOR_BINDER(BehaviorCloudGemDynamicContentNotificationBusHandler, LmbrAWS_CodeGen_NotificationBus1_UUID, AZ::SystemAllocator
        
        , OnPostClientContentRequestSuccess
        , OnPostClientContentRequestError
        
        , OnPostPortalContentRequestSuccess
        , OnPostPortalContentRequestError
        
        , OnDeletePortalContentRequestSuccess
        , OnDeletePortalContentRequestError
        
        , OnGetPortalContentRequestSuccess
        , OnGetPortalContentRequestError
        
        , OnGetServiceStatusRequestSuccess
        , OnGetServiceStatusRequestError
        
        , OnDeletePortalInfoRequestSuccess
        , OnDeletePortalInfoRequestError
        
        , OnGetPortalInfoRequestSuccess
        , OnGetPortalInfoRequestError
        
        );
        
        
        void OnPostClientContentRequestSuccess(const FileRequestResults response) override;
        
        void OnPostClientContentRequestError(const CloudGemFramework::Error error) override;
        
        
        void OnPostPortalContentRequestSuccess(const PortalFileListResults response) override;
        
        void OnPostPortalContentRequestError(const CloudGemFramework::Error error) override;
        
        
        void OnDeletePortalContentRequestSuccess(const PortalFileRequestList response) override;
        
        void OnDeletePortalContentRequestError(const CloudGemFramework::Error error) override;
        
        
        void OnGetPortalContentRequestSuccess(const PortalFileListResults response) override;
        
        void OnGetPortalContentRequestError(const CloudGemFramework::Error error) override;
        
        
        void OnGetServiceStatusRequestSuccess(const ServiceStatus response) override;
        
        void OnGetServiceStatusRequestError(const CloudGemFramework::Error error) override;
        
        
        void OnDeletePortalInfoRequestSuccess(const PortalFileRequestList response) override;
        
        void OnDeletePortalInfoRequestError(const CloudGemFramework::Error error) override;
        
        
        void OnGetPortalInfoRequestSuccess(const PortalFileInfo response) override;
        
        void OnGetPortalInfoRequestError(const CloudGemFramework::Error error) override;
        
    };
    class CloudGemDynamicContentResponseHandler;

    // Request bus for this component
    class CloudGemDynamicContentRequests
        : public AZ::ComponentBus
    {
    public:
        virtual ~CloudGemDynamicContentRequests() {}
        
        
        virtual void PostClientContent(const RequestData& request_content, CloudGemDynamicContentResponseHandler* responseHandler);
        
        
        
        virtual void PostPortalContent(const PortalFileRequestList& request_content, CloudGemDynamicContentResponseHandler* responseHandler);
        
        
        
        virtual void DeletePortalContent(CloudGemDynamicContentResponseHandler* responseHandler);
        
        
        
        virtual void GetPortalContent(CloudGemDynamicContentResponseHandler* responseHandler);
        
        
        
        virtual void GetServiceStatus(CloudGemDynamicContentResponseHandler* responseHandler);
        
        
        
        virtual void DeletePortalInfo(const AZStd::string& file_name, CloudGemDynamicContentResponseHandler* responseHandler);
        
        
        
        virtual void GetPortalInfo(const AZStd::string& file_name, CloudGemDynamicContentResponseHandler* responseHandler);
        
        
    };

    using CloudGemDynamicContentRequestBus = AZ::EBus<CloudGemDynamicContentRequests>;

    // This class is used as a parameter for all requests and throws the response on the CloudGemDynamicContentNotificationBus
    // Inherit from this to define custom behavior.
    class CloudGemDynamicContentResponseHandler
    {
    public:
        AZ_TYPE_INFO(CloudGemDynamicContentResponseHandler, LmbrAWS_CodeGen_ResponseHandler_UUID)
        AZ_CLASS_ALLOCATOR(CloudGemDynamicContentResponseHandler, AZ::SystemAllocator, 0)

        virtual ~CloudGemDynamicContentResponseHandler() {}
        
        virtual void HandlePostClientContentSuccess(PostClientContentRequestJob* job, AZ::EntityId entityId);
        virtual void HandlePostClientContentError(PostClientContentRequestJob* job, AZ::EntityId entityId);
        
        virtual void HandlePostPortalContentSuccess(PostPortalContentRequestJob* job, AZ::EntityId entityId);
        virtual void HandlePostPortalContentError(PostPortalContentRequestJob* job, AZ::EntityId entityId);
        
        virtual void HandleDeletePortalContentSuccess(DeletePortalContentRequestJob* job, AZ::EntityId entityId);
        virtual void HandleDeletePortalContentError(DeletePortalContentRequestJob* job, AZ::EntityId entityId);
        
        virtual void HandleGetPortalContentSuccess(GetPortalContentRequestJob* job, AZ::EntityId entityId);
        virtual void HandleGetPortalContentError(GetPortalContentRequestJob* job, AZ::EntityId entityId);
        
        virtual void HandleGetServiceStatusSuccess(GetServiceStatusRequestJob* job, AZ::EntityId entityId);
        virtual void HandleGetServiceStatusError(GetServiceStatusRequestJob* job, AZ::EntityId entityId);
        
        virtual void HandleDeletePortalInfoSuccess(DeletePortalInfoRequestJob* job, AZ::EntityId entityId);
        virtual void HandleDeletePortalInfoError(DeletePortalInfoRequestJob* job, AZ::EntityId entityId);
        
        virtual void HandleGetPortalInfoSuccess(GetPortalInfoRequestJob* job, AZ::EntityId entityId);
        virtual void HandleGetPortalInfoError(GetPortalInfoRequestJob* job, AZ::EntityId entityId);
        
    };

    class CloudGemDynamicContentClientComponent
        : public AZ::Component
        , public CloudGemDynamicContentRequestBus::Handler
    {
    public:
        AZ_COMPONENT(CloudGemDynamicContentClientComponent, LmbrAWS_CodeGen_Component_UUID);
        virtual ~CloudGemDynamicContentClientComponent() = default;

        AZStd::shared_ptr<CloudGemDynamicContentResponseHandler> m_defaultResponseHandler;

        void Init() override;

        void Activate() override;

        void Deactivate() override;

        static void Reflect(AZ::ReflectContext* reflection)
        {
            
            
            
            
            RequestData::Reflect(reflection);
            
            
            
            FileRequestResult::Reflect(reflection);
            
            
            
            
            
            FileRequestResults::Reflect(reflection);
            
            
            
            PortalFileRequest::Reflect(reflection);
            
            
            
            
            
            PortalFileRequestList::Reflect(reflection);
            
            
            
            PortalFileInfo::Reflect(reflection);
            
            
            
            
            
            PortalFileListResults::Reflect(reflection);
            
            
            
            ServiceStatus::Reflect(reflection);
            
            

            AZ::SerializeContext* serializeContext = azrtti_cast<AZ::SerializeContext*>(reflection);
            if (serializeContext)
            {
                // we must include any fields we want to expose to the editor or lua in the serialize context
                serializeContext->Class<CloudGemDynamicContentClientComponent>()
                    ->Version(1);

                AZ::EditContext* editContext = serializeContext->GetEditContext();
                if (editContext)
                {
                    editContext->Class<CloudGemDynamicContentClientComponent>("CloudGemDynamicContentClientComponent", "CloudGemDynamicContent Component")
                        ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                            ->Attribute(AZ::Edit::Attributes::Category, "Cloud Canvas Gems")
                            ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("Game"));
                }
            }

            AZ::BehaviorContext* behaviorContext = azrtti_cast<AZ::BehaviorContext*>(reflection);
            if (behaviorContext)
            {
                behaviorContext->EBus<CloudGemDynamicContentRequestBus>("CloudGemDynamicContentRequestBus")
                    // one of these for each function
                    
                    ->Event("PostClientContent", &CloudGemDynamicContentRequestBus::Events::PostClientContent)
                    
                    ->Event("PostPortalContent", &CloudGemDynamicContentRequestBus::Events::PostPortalContent)
                    
                    ->Event("DeletePortalContent", &CloudGemDynamicContentRequestBus::Events::DeletePortalContent)
                    
                    ->Event("GetPortalContent", &CloudGemDynamicContentRequestBus::Events::GetPortalContent)
                    
                    ->Event("GetServiceStatus", &CloudGemDynamicContentRequestBus::Events::GetServiceStatus)
                    
                    ->Event("DeletePortalInfo", &CloudGemDynamicContentRequestBus::Events::DeletePortalInfo)
                    
                    ->Event("GetPortalInfo", &CloudGemDynamicContentRequestBus::Events::GetPortalInfo)
                    
                    ;
                behaviorContext->EBus<CloudGemDynamicContentNotificationBus>("CloudGemDynamicContentNotificationBus")
                    ->Handler<BehaviorCloudGemDynamicContentNotificationBusHandler>()
                ;
            }
        }

        // Functions from the swagger definitions
        
        
        void PostClientContent(const RequestData& request_content, CloudGemDynamicContentResponseHandler* responseHandler) override;
        
        
        
        void PostPortalContent(const PortalFileRequestList& request_content, CloudGemDynamicContentResponseHandler* responseHandler) override;
        
        
        
        void DeletePortalContent(CloudGemDynamicContentResponseHandler* responseHandler) override;
        
        
        
        void GetPortalContent(CloudGemDynamicContentResponseHandler* responseHandler) override;
        
        
        
        void GetServiceStatus(CloudGemDynamicContentResponseHandler* responseHandler) override;
        
        
        
        void DeletePortalInfo(const AZStd::string& file_name, CloudGemDynamicContentResponseHandler* responseHandler) override;
        
        
        
        void GetPortalInfo(const AZStd::string& file_name, CloudGemDynamicContentResponseHandler* responseHandler) override;
        
        
    };
} // ServiceAPI
} // CloudGemDynamicContent