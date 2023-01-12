// @author   Gregory Veksler

// Modified for L9 by Yoni Sarusi

#include "adj/apr_j2esdiameter/J2esMiniProtocolHandler.h"
#include "adj/apr_j2esdiameter/Utils.h"
#include "adj/apr_j2esdiameter/J2esDiameterCodes.h"

#include "cpf/fwc/ConGlobalServices.h"
#include "cpf/AtomicObject.h"
#include "afc/LoggerMacros.h"

#include "adj/String.h"
#include "adj/CustomerID.h"
#include "adj/SubscriberID.h"
#include "adj/DiameterConstants.h"
#include "adj/DiameterHeaderParser.h"
#include "adj/DiameterInspector.h"
#include "adj/DiameterGlobalInfo.h"
#include "adj/GenericDiameterMsgFormatter.h"

#include "adj/apr_intpr/InternalProtocolCodes.h"
#include "adj/apr_netpr/CRProtocolHandlerBase.h"
#include "adj/apr_netpr/BufferWrapper.h"
#include "adj/apr_netpr/Constants.h"

#include "adj/apr_common/APRGlobalProcessData.h"
#include "adj/apr_common/Constants.h"
#include "adj/apr_gdd/LogMessages.h"

namespace adj
{
    namespace apr_j2esdiameter
    {

        // 2 types of request can come in - reserve or charge SOA event requests
        static const char *requestMessageTypeReserve = "XL SOA Diameter reserve";
        static const char *requestMessageTypeCharge = "XL SOA Diameter charge";
        static const char *messageKeySOAReserveJ2es = "SOA_RESERV_J2ES";
        static const char *messageKeySOAChargeJ2es = "SOA_CHARGE_J2ES";
        static const char *requestMessageTypeReplenish = "Replenish";
        static const char *messageKeyReplenishJ2es = "SOA_REPLENISHMENT_J2ES";
        static const char *requestMessageTypePurchase = "Purchase scheduler";
        static const char *messageKeyPurchaseJ2es = "PURCH_SCHED_J2ES";
        static const char *requestMessageTypeGetLock = "GetLockUnlock";
        static const char *requestMessageTypePutLock = "PutLockUnlock";
        static const char *requestMessageTypePretoPost = "PretoPost"; // ST changes
        static const char *requestMessageTypePosttoPre = "PosttoPre"; // ST changes

        bool PurchaseEvent = false;
        // ==============================================================
        J2esMiniProtocolHandler::J2esMiniProtocolHandler()
        {
        }

        // =================================================================
        bool J2esMiniProtocolHandler::doInit()
        {
            if (adj::apr_netpr::DiameterCRProtocolHandler::doInit())
            {
                cpf::fwc::ConGlobalServices &cgs = cpf::fwc::ConGlobalServices::instance();
                this->m_pTimeManager = cgs.service<cpf::TimeManager>(adj::apr_common::Constants::TIME_MANAGER);
                // this->m_pNetworkProtocolsMgr = cgs.service<adj::olc_channels::NetworkProtocolsMgr>();
                return true;
            }

            return false;
        }

        // =================================================================
        bool
        J2esMiniProtocolHandler::generateESIncomingEventKey(const char *i_pBuffer,
                                                            cpf::UInt32 i_bufferSize,
                                                            cpf::UInt32 i_messageCode,
                                                            string &o_strMessageKey)
        {
            CPF_METHOD_TRACE("J2esMiniProtocolHandler::generateESIncomingEventKey", this->m_pLogger);

            switch (i_messageCode)
            {
            case CDiameterGlobalInfo::ncJ2ES_REQUEST:
            {
                const char *pAVP = 0;
                cpf::UInt32 avpSize = 0;

                if (adj::GenericDiameterMsgParser::getElement(J2esDiameterCodes::avpA_API_SERVICE_TYPE,
                                                              adj::Diameter::default_VENDOR_ID,
                                                              i_pBuffer, i_bufferSize,
                                                              pAVP, avpSize))
                {
                    if (!ACE_OS::strcmp(pAVP, requestMessageTypeReserve))
                    {
                        o_strMessageKey = messageKeySOAReserveJ2es;
                        CPF_LOG_MSG(this->m_pLogger, afc::LogLevel::ms_TRACE, "J2 srv <1>", pAVP);
                        return true;
                    }
                    else if (!ACE_OS::strcmp(pAVP, requestMessageTypeCharge))
                    {
                        o_strMessageKey = messageKeySOAChargeJ2es;
                        CPF_LOG_MSG(this->m_pLogger, afc::LogLevel::ms_TRACE, "J2 srv <1>", pAVP);
                        return true;
                    }
                    else if (!ACE_OS::strcmp(pAVP, requestMessageTypePurchase))
                    {
                        o_strMessageKey = messageKeyPurchaseJ2es;
                        CPF_LOG_MSG(this->m_pLogger, afc::LogLevel::ms_TRACE, "J2 srv <1>", pAVP);
                        return true;
                    }
                    else if (!ACE_OS::strcmp(pAVP, requestMessageTypeReplenish))
                    {
                        o_strMessageKey = messageKeyReplenishJ2es;
                        CPF_LOG_MSG(this->m_pLogger, afc::LogLevel::ms_TRACE, "J2 srv <1>", pAVP);
                        return true;
                    }
                    else if (!ACE_OS::strcmp(pAVP, requestMessageTypeGetLock))
                    {
                        // GetLockUnlock we will use replenish messageKey
                        o_strMessageKey = messageKeyReplenishJ2es;
                        CPF_LOG_MSG(this->m_pLogger, afc::LogLevel::ms_TRACE, "J2 srv <1>", pAVP);
                        return true;
                    }
                    else if (!ACE_OS::strcmp(pAVP, requestMessageTypePutLock))
                    {
                        // PutLockUnlock we will use replenish messageKey
                        o_strMessageKey = messageKeyReplenishJ2es;
                        CPF_LOG_MSG(this->m_pLogger, afc::LogLevel::ms_TRACE, "J2 srv <1>", pAVP);
                        return true;
                    }
                    // ST changes start
                    else if (!ACE_OS::strcmp(pAVP, requestMessageTypePretoPost))
                    {
                        // PretoPost we will use Purchase scheduler messageKey
                        o_strMessageKey = messageKeyPurchaseJ2es;
                        CPF_LOG_MSG(this->m_pLogger, afc::LogLevel::ms_TRACE, "J2 srv <1>", pAVP);
                        return true;
                    }
                    else if (!ACE_OS::strcmp(pAVP, requestMessageTypePosttoPre))
                    {
                        // PosttoPre we will use Purchase scheduler messageKey
                        o_strMessageKey = messageKeyPurchaseJ2es;
                        CPF_LOG_MSG(this->m_pLogger, afc::LogLevel::ms_TRACE, "J2 srv <1>", pAVP);
                        return true;
                    }
                    // ST changes end
                    CPF_LOG_MSG(this->m_pLogger, afc::LogLevel::ms_ERROR, "J2 Unsupported srv <1>", pAVP);
                }
                else
                {
                    CPF_LOG_MSG_BY_ID(this->m_pLogger, adj::apr_gdd::LogMessages::APP_ID,
                                      adj::apr_gdd::LogMessages::ATTRIBUTE_NOT_FOUND,
                                      "J2"
                                          << "API-SERVICE-TYPE");
                }
            }
            break;

            default:
            {
                CPF_LOG_MSG(this->m_pLogger, afc::LogLevel::ms_ERROR,
                            "J2 Unable to determine Incoming Event Key. Msg code <1> is unsupported", i_messageCode);
            }
            break;
            }

            return false;
        }

        // ==============================================================
        adj::apr_netpr::DiameterCRProtocolHandler::ParseResult
        J2esMiniProtocolHandler::doParse(const char *i_pBuffer,
                                         cpf::UInt32 i_bufferSize,
                                         adj::apr_netpr::CRProtocolHandlerBase::ParsingOutput &o_parsingOutput)
        {
            CPF_METHOD_TRACE("J2esMiniProtocolHandler::doParse", this->m_pLogger);

            // skip over extra internal header
            const char *pBuffer = i_pBuffer + adj::apr_netpr::Constants::DIAMETER_EXTRA_INTERNAL_HEADER_SIZE;
            cpf::UInt32 bufferSize = i_bufferSize - adj::apr_netpr::Constants::DIAMETER_EXTRA_INTERNAL_HEADER_SIZE;
            ParentClass::ParseResultOptions pro;

            ADJ_DIAMETER_TRACE_BY_PARSING_MODE(this->m_pLogger, "J2 Request\n<1>", pBuffer, this->isNewParsingMode());

            o_parsingOutput.m_requestNumber = 0;

            // Event Start Time
            if (!Utils::getEventStarTime(pBuffer, bufferSize,
                                         this->m_pTimeManager.get(), this->m_pLogger, o_parsingOutput.m_eventTime))
            {
                return internalCreateErrorResponse(adj::Diameter::err_DIAMETER_INVALID_AVP_VALUE,
                                                   i_pBuffer, i_bufferSize, *(o_parsingOutput.m_pResponseBuffer));
            }

            // Add GMT time difference to timestamp (timezone is adjusted to -ve value if local time>GMT time)
            o_parsingOutput.m_eventTime -= timezone;

            // Get Session ID from payload and set on the event
            const char *pApiSvcPayload;
            cpf::UInt32 apiSvcPayloadeSize;

            if (!adj::GenericDiameterMsgParser::getElement(adj::Diameter::avpA_TRANSACTION_PAYLOAD, adj::Diameter::default_VENDOR_ID,
                                                           pBuffer, bufferSize, pApiSvcPayload, apiSvcPayloadeSize))
            {
                CPF_LOG_MSG_NO_PARAMS(this->m_pLogger, afc::LogLevel::ms_ERROR,
                                      "J2 Payload AVP is missing");
                return internalCreateErrorResponse(adj::CDiameterGlobalInfo::rDIAMETER_UNABLE_TO_COMPLY,
                                                   i_pBuffer, i_bufferSize, *(o_parsingOutput.m_pResponseBuffer));
            }
            else
            {
                CPF_LOG_MSG(this->m_pLogger, afc::LogLevel::ms_TRACE,
                            "J2 Payload:<1>", pApiSvcPayload);

                CPF_LOG_MSG(this->m_pLogger, afc::LogLevel::ms_TRACE,
                            "J2 Payload sz:<1>", apiSvcPayloadeSize);

                string payLoad = pApiSvcPayload;
                vector<string> tokens;
                stringstream tmpPayLoad(payLoad);
                string interimToken;
                // Input payload has pipe separated attribues-value pairs
                // Each attribute-value pair has = between them. <attribute name>=<attribute value> format
                // Session id=62147|Charge amount=123.50|Currency code=IDR|CC Request Type=1
                bool foundSessionIdInRequest = false;
                while (getline(tmpPayLoad, interimToken, '|'))
                {
                    CPF_LOG_MSG(this->m_pLogger, afc::LogLevel::ms_TRACE,
                                "J2 interimToken:<1>", interimToken.c_str());
                    tokens.push_back(interimToken);

                    // Look for Session id and set on the buffer
                    stringstream tmpAttrValue(interimToken);
                    string interimAttr, interimValue;
                    if (getline(tmpAttrValue, interimAttr, '='))
                    {
                        if (interimAttr.compare("Session id") == 0)
                        {
                            if (getline(tmpAttrValue, interimValue, '='))
                            {
                                char usersessionID[64];
                                ACE_OS::memset(usersessionID, 0, sizeof(usersessionID));
                                ACE_OS::snprintf(usersessionID, sizeof(usersessionID) - 1, "%s", interimValue.c_str());
                                size_t sessionSize = strlen(usersessionID) + 1;
                                o_parsingOutput.m_pSession = o_parsingOutput.m_pSessionBuffer->getBuffer(sessionSize);
                                ACE_OS::memcpy((void *)(o_parsingOutput.m_pSession), usersessionID, sessionSize);
                                o_parsingOutput.m_sessionSize = sessionSize;

                                foundSessionIdInRequest = true;
                                CPF_LOG_MSG(this->m_pLogger, afc::LogLevel::ms_TRACE, "J2 SessionID [<1>] set", usersessionID);
                            }
                            else
                            {
                                CPF_LOG_MSG_NO_PARAMS(this->m_pLogger, afc::LogLevel::ms_ERROR, "J2 Session id value NOT FOUND");
                            }
                        }
                    }
                } // end while
                // If session id not found in request, then set autogenerated value so that response can be sent
                if (foundSessionIdInRequest == false)
                {
                    CPF_LOG_MSG_NO_PARAMS(this->m_pLogger, afc::LogLevel::ms_ERROR, "J2 Session id NOT FOUND");
                    if (!adj::GenericDiameterMsgParser::getElement(adj::Diameter::avp_SESSION_ID, 0, pBuffer, bufferSize,
                                                                   o_parsingOutput.m_pSession, o_parsingOutput.m_sessionSize))
                    {
                        CPF_LOG_MSG_BY_ID(this->m_pLogger, adj::apr_gdd::LogMessages::APP_ID,
                                          adj::apr_gdd::LogMessages::ATTRIBUTE_NOT_FOUND,
                                          "J2"
                                              << "Session ID");

                        return internalCreateErrorResponse(adj::CDiameterGlobalInfo::rDIAMETER_UNABLE_TO_COMPLY,
                                                           i_pBuffer, i_bufferSize, *(o_parsingOutput.m_pResponseBuffer));
                    }
                }
            }

            const char *resourceType;
            cpf::UInt32 resourceTypeSize = 0;

            // Start - Hiren - 17-Nov-2021 Set customer id info if resource not found
            // In this version the resource type is assumed to be a number that matches one value in the resource map
            if (!adj::GenericDiameterMsgParser::getElement(adj::Diameter::avp_RESOURCE_TYPE, adj::Diameter::default_VENDOR_ID, pBuffer, bufferSize, resourceType, resourceTypeSize))
            {

                CPF_LOG_MSG_BY_ID(
                    this->m_pLogger,
                    adj::apr_gdd::LogMessages::APP_ID,
                    adj::apr_gdd::LogMessages::ATTRIBUTE_NOT_FOUND,
                    "J2"
                        << "Res type");
                // return ParentClass::proERROR;

                // Customer ID, Subscriber ID and Cycle code are mandatory if no resource data was sent
                cpf::UInt64 tmpVal;
                if (!adj::GenericDiameterMsgParser::getElement<cpf::UInt64>(
                        adj::Diameter::avp_CUSTOMER_ID, adj::Diameter::default_VENDOR_ID, pBuffer, bufferSize, tmpVal))
                {
                    CPF_LOG_MSG_BY_ID(this->m_pLogger, adj::apr_gdd::LogMessages::APP_ID,
                                      adj::apr_gdd::LogMessages::ATTRIBUTE_NOT_FOUND,
                                      "J2ES"
                                          << "Customer Id");

                    return internalCreateErrorResponse(adj::CDiameterGlobalInfo::rDIAMETER_UNABLE_TO_COMPLY,
                                                       i_pBuffer, i_bufferSize, *(o_parsingOutput.m_pResponseBuffer));
                }
                o_parsingOutput.m_customerID = static_cast<adj::CustomerID::StorageType>(tmpVal);

                if (!adj::GenericDiameterMsgParser::getElement<cpf::UInt64>(
                        adj::Diameter::avp_SUBSCRIBER_ID, adj::Diameter::default_VENDOR_ID, pBuffer, bufferSize, tmpVal))
                {
                    CPF_LOG_MSG_BY_ID(this->m_pLogger, adj::apr_gdd::LogMessages::APP_ID,
                                      adj::apr_gdd::LogMessages::ATTRIBUTE_NOT_FOUND,
                                      "J2ES"
                                          << "Subscriber Id");

                    return internalCreateErrorResponse(adj::CDiameterGlobalInfo::rDIAMETER_UNABLE_TO_COMPLY,
                                                       i_pBuffer, i_bufferSize, *(o_parsingOutput.m_pResponseBuffer));
                }
                o_parsingOutput.m_subscriberID = static_cast<adj::SubscriberID::StorageType>(tmpVal);

                cpf::UInt32 cycleCode = 0;
                if (!adj::GenericDiameterMsgParser::getElement(adj::Diameter::avp_CYCLE_CODE, adj::Diameter::default_VENDOR_ID, pBuffer, bufferSize, cycleCode))
                {
                    CPF_LOG_MSG_BY_ID(this->m_pLogger, adj::apr_gdd::LogMessages::APP_ID,
                                      adj::apr_gdd::LogMessages::ATTRIBUTE_NOT_FOUND,
                                      "J2ES"
                                          << "Cycle code");

                    return internalCreateErrorResponse(adj::CDiameterGlobalInfo::rDIAMETER_UNABLE_TO_COMPLY,
                                                       i_pBuffer, i_bufferSize, *(o_parsingOutput.m_pResponseBuffer));
                }
                o_parsingOutput.m_cycleCode = cycleCode;

                pro = ParentClass::proOnlyGuidingInfo;
            }
            else
            {
                // Resource based guiding
                CPF_LOG_MSG(this->m_pLogger, afc::LogLevel::ms_TRACE, "J2 Res type [<1>]", resourceType);
                o_parsingOutput.m_resourceType = static_cast<cpf::UInt32>(ACE_OS::atoi(resourceType));

                cpf::ConstResult<cpf::UInt32> convertResourceTypeRes = this->m_resourceConvertor.externalResourceTypeToInernalByProtocolId(this->getProtocolId(),
                                                                                                                                           o_parsingOutput.m_resourceType);
                if (convertResourceTypeRes.m_ok)
                {
                    o_parsingOutput.m_resourceType = convertResourceTypeRes.m_result;
                }

                if (!adj::GenericDiameterMsgParser::getElement(adj::Diameter::avp_RESOURCE_VALUE, adj::Diameter::default_VENDOR_ID, pBuffer, bufferSize, o_parsingOutput.m_pResourceValue, o_parsingOutput.m_resourceValueSize))
                {
                    CPF_LOG_MSG_BY_ID(
                        this->m_pLogger,
                        adj::apr_gdd::LogMessages::APP_ID,
                        adj::apr_gdd::LogMessages::ATTRIBUTE_NOT_FOUND,
                        "J2"
                            << "Res val");

                    return internalCreateErrorResponse(adj::CDiameterGlobalInfo::rDIAMETER_UNABLE_TO_COMPLY,
                                                       i_pBuffer, i_bufferSize, *(o_parsingOutput.m_pResponseBuffer));
                }

                CPF_LOG_MSG(this->m_pLogger, afc::LogLevel::ms_TRACE, "J2 Res val [<1>]", o_parsingOutput.m_pResourceValue);
                pro = ParentClass::proOnlyResourceInfo;
            }
            // End - Hiren - 17-Nov-2021 Set customer id info if resource not found

            // ELA Token, not mandatory
            adj::GenericDiameterMsgParser::getElement(adj::Diameter::avpA_ELA_TOKEN, adj::Diameter::default_VENDOR_ID,
                                                      pBuffer, bufferSize, o_parsingOutput.m_elaToken);

            // Get message code
            cpf::UInt32 msgCode = 0;
            if (!this->getMessageCode(pBuffer, msgCode))
            {
                CPF_LOG_MSG_NO_PARAMS(this->m_pLogger, afc::LogLevel::ms_ERROR,
                                      "J2 Msg code not found");

                return internalCreateErrorResponse(adj::Diameter::err_DIAMETER_COMMAND_UNSUPPORTED,
                                                   i_pBuffer, i_bufferSize, *(o_parsingOutput.m_pResponseBuffer));
            }

            if (!generateESIncomingEventKey(pBuffer, bufferSize, msgCode, o_parsingOutput.m_eventIDDescriptor))
            {
                return internalCreateErrorResponse(adj::Diameter::err_DIAMETER_INVALID_AVP_VALUE,
                                                   i_pBuffer, i_bufferSize, *(o_parsingOutput.m_pResponseBuffer));
            }

            // Set request number 0 or 1 depending on Reserve or Charge.
            // This is must to avoid dup responses between Reserve and Charge
            if (!ACE_OS::strcmp(o_parsingOutput.m_eventIDDescriptor.c_str(), messageKeySOAReserveJ2es))
            {
                o_parsingOutput.m_requestNumber = 0;
            }
            else
            {
                o_parsingOutput.m_requestNumber = 1;
            }

            return pro;
        }

        // ==============================================================
        void
        J2esMiniProtocolHandler::doCreateErrorResponse(cpf::Int32 i_externalResultCode,
                                                       const std::pair<const char *, cpf::UInt32> &i_networkBuffer,
                                                       adj::apr_netpr::BufferWrapper &o_responseBuffer,
                                                       const CreateErrorResponseInfo &i_additionalInfo)
        {
            CPF_METHOD_TRACE("J2esMiniProtocolHandler::doCreateErrorResponse", this->m_pLogger);

            // Get the hostname once at constructor
            static const char *pHostName = adj::apr_common::getHostName().c_str();
            static const cpf::UInt32 hostNameSize = static_cast<cpf::UInt32>(ACE_OS::strlen(pHostName));

            char *pResponse = o_responseBuffer.getBuffer(adj::Diameter::size_BUFFER_SMALL);
            adj::GenericDiameterMsgFormatter responseFormatter(pResponse);

            const char *pRequest = i_networkBuffer.first + adj::apr_netpr::Constants::DIAMETER_EXTRA_INTERNAL_HEADER_SIZE;
            cpf::UInt32 requestSize = i_networkBuffer.second - adj::apr_netpr::Constants::DIAMETER_EXTRA_INTERNAL_HEADER_SIZE;

            // start from scratch
            responseFormatter.reset(pResponse);
            // reset header
            char commandFlags = 0x00; // response
            ACE_OS::memcpy(pResponse, pRequest, adj::DiameterGlobalInfo::hoHEADER_SIZE);
            ACE_OS::memcpy(pResponse + adj::DiameterGlobalInfo::hoCOMMAND_FLAG_OFFSET, &commandFlags, sizeof(char));

            // session id is the only mandatory field +
            // it has to be the first according to Diameter protocol
            const char *pDiamVal = 0;
            cpf::UInt32 dimValSize = 0;

            CPF_LOG_MSG_NO_PARAMS(this->m_pLogger, afc::LogLevel::ms_TRACE, "J2 doCreateErrorResponse get SID");
            if (adj::GenericDiameterMsgParser::getElement(adj::Diameter::avp_SESSION_ID, 0, pRequest, requestSize, pDiamVal, dimValSize))
            {
                responseFormatter.addElement(adj::Diameter::avp_SESSION_ID, pDiamVal, dimValSize);
                CPF_LOG_MSG(this->m_pLogger, afc::LogLevel::ms_TRACE, "J2 SID [<1>]", pDiamVal);
            }

            // origin host
            responseFormatter.addElement(adj::Diameter::avp_ORIGIN_HOST, pHostName, hostNameSize);

            // origin realm
            responseFormatter.addElement(adj::Diameter::avp_ORIGIN_REALM,
                                         adj::Diameter::DiameterConstants::ORIGIN_REALM, J2esDiameterCodes::ORIGIN_REALM_SIZE);
            // result code
            responseFormatter.addElement<cpf::UInt32>(adj::Diameter::avp_RESULT_CODE, i_externalResultCode);
            CPF_LOG_MSG(this->m_pLogger, afc::LogLevel::ms_TRACE, "J2 RES CD [<1>]", i_externalResultCode);

            // auth application id
            responseFormatter.addElement<cpf::UInt32>(adj::Diameter::avp_AUTH_APPLICATION_ID, adj::Diameter::DiameterConstants::AUTH_APPLICATION_ID);

            // set actual size both in Diameter buffer and in BufferWrapper
            cpf::UInt32 responseSize = responseFormatter.getMessageSize();
            responseFormatter.updateMessageLength();
            o_responseBuffer.setSerializedSize(responseSize);

            ADJ_DIAMETER_TRACE(this->m_pLogger, "J2esMiniProtocolHandler::doCreateErrorResponse Response:\n\n<1>", pResponse);
        }

        // ==============================================================
        adj::apr_netpr::DiameterCRProtocolHandler::ParseResult
        J2esMiniProtocolHandler::internalCreateErrorResponse(cpf::Int32 i_externalResultCode,
                                                             const char *i_pBuffer,
                                                             cpf::UInt32 i_bufferSize,
                                                             adj::apr_netpr::BufferWrapper &o_responseBuffer)
        {
            CreateErrorResponseInfo errInfo;
            std::pair<const char *, cpf::UInt32> networkBuffer(i_pBuffer, i_bufferSize);
            doCreateErrorResponse(i_externalResultCode, networkBuffer, o_responseBuffer, errInfo);
            return ParentClass::proERROR;
        }

    } // namespace apr_j2esdiameter
} // namespace adj
