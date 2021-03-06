// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*! 
 * @file AMM_ExtendedPubSubTypes.h
 * This header file contains the declaration of the serialization functions.
 *
 * This file was generated by the tool fastcdrgen.
 */


#ifndef _AMM_AMM_EXTENDED_PUBSUBTYPES_H_
#define _AMM_AMM_EXTENDED_PUBSUBTYPES_H_

#include <fastrtps/config.h>
#include <fastrtps/TopicDataType.h>

#include "AMM_Extended.h"

#if !defined(GEN_API_VER) || (GEN_API_VER != 1)
#error Generated AMM_Extended is not compatible with current installed Fast-RTPS. Please, regenerate it with fastrtpsgen.
#endif

namespace AMM
{
    /*!
     * @brief This class represents the TopicDataType of the type Tick defined by the user in the IDL file.
     * @ingroup AMM_EXTENDED
     */
    class TickPubSubType : public eprosima::fastrtps::TopicDataType {
    public:
            typedef Tick type;

    	TickPubSubType();
    	virtual ~TickPubSubType();
    	virtual bool serialize(void *data, eprosima::fastrtps::rtps::SerializedPayload_t *payload) override;
    	virtual bool deserialize(eprosima::fastrtps::rtps::SerializedPayload_t *payload, void *data) override;
        virtual std::function<uint32_t()> getSerializedSizeProvider(void* data) override;
    	virtual bool getKey(void *data, eprosima::fastrtps::rtps::InstanceHandle_t *ihandle,
    		bool force_md5 = false) override;
    	virtual void* createData() override;
    	virtual void deleteData(void * data) override;
    	MD5 m_md5;
    	unsigned char* m_keyBuffer;
    };
    /*!
     * @brief This class represents the TopicDataType of the type InstrumentData defined by the user in the IDL file.
     * @ingroup AMM_EXTENDED
     */
    class InstrumentDataPubSubType : public eprosima::fastrtps::TopicDataType {
    public:
            typedef InstrumentData type;

    	InstrumentDataPubSubType();
    	virtual ~InstrumentDataPubSubType();
    	virtual bool serialize(void *data, eprosima::fastrtps::rtps::SerializedPayload_t *payload) override;
    	virtual bool deserialize(eprosima::fastrtps::rtps::SerializedPayload_t *payload, void *data) override;
        virtual std::function<uint32_t()> getSerializedSizeProvider(void* data) override;
    	virtual bool getKey(void *data, eprosima::fastrtps::rtps::InstanceHandle_t *ihandle,
    		bool force_md5 = false) override;
    	virtual void* createData() override;
    	virtual void deleteData(void * data) override;
    	MD5 m_md5;
    	unsigned char* m_keyBuffer;
    };
    /*!
     * @brief This class represents the TopicDataType of the type Command defined by the user in the IDL file.
     * @ingroup AMM_EXTENDED
     */
    class CommandPubSubType : public eprosima::fastrtps::TopicDataType {
    public:
            typedef Command type;

    	CommandPubSubType();
    	virtual ~CommandPubSubType();
    	virtual bool serialize(void *data, eprosima::fastrtps::rtps::SerializedPayload_t *payload) override;
    	virtual bool deserialize(eprosima::fastrtps::rtps::SerializedPayload_t *payload, void *data) override;
        virtual std::function<uint32_t()> getSerializedSizeProvider(void* data) override;
    	virtual bool getKey(void *data, eprosima::fastrtps::rtps::InstanceHandle_t *ihandle,
    		bool force_md5 = false) override;
    	virtual void* createData() override;
    	virtual void deleteData(void * data) override;
    	MD5 m_md5;
    	unsigned char* m_keyBuffer;
    };
}

#endif // _AMM_AMM_EXTENDED_PUBSUBTYPES_H_