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
 * @file AMM_StandardCdrAux.hpp
 * This source file contains some definitions of CDR related functions.
 *
 * This file was generated by the tool fastddsgen.
 */

#ifndef _FAST_DDS_GENERATED_AMM_AMM_STANDARDCDRAUX_HPP_
#define _FAST_DDS_GENERATED_AMM_AMM_STANDARDCDRAUX_HPP_

#include "AMM_Standard.h"

constexpr uint32_t AMM_EventRecord_max_cdr_typesize {5441UL};
constexpr uint32_t AMM_EventRecord_max_key_cdr_typesize {0UL};

constexpr uint32_t AMM_FragmentAmendmentRequest_max_cdr_typesize {1072UL};
constexpr uint32_t AMM_FragmentAmendmentRequest_max_key_cdr_typesize {0UL};

constexpr uint32_t AMM_RenderModification_max_cdr_typesize {4893UL};
constexpr uint32_t AMM_RenderModification_max_key_cdr_typesize {0UL};

constexpr uint32_t AMM_Semantic_Version_max_cdr_typesize {10UL};
constexpr uint32_t AMM_Semantic_Version_max_key_cdr_typesize {0UL};



constexpr uint32_t AMM_Assessment_max_cdr_typesize {796UL};
constexpr uint32_t AMM_Assessment_max_key_cdr_typesize {0UL};

constexpr uint32_t AMM_ModuleConfiguration_max_cdr_typesize {12805UL};
constexpr uint32_t AMM_ModuleConfiguration_max_key_cdr_typesize {0UL};

constexpr uint32_t AMM_Status_max_cdr_typesize {1328UL};
constexpr uint32_t AMM_Status_max_key_cdr_typesize {0UL};



constexpr uint32_t AMM_UUID_max_cdr_typesize {264UL};
constexpr uint32_t AMM_UUID_max_key_cdr_typesize {0UL};

constexpr uint32_t AMM_PhysiologyValue_max_cdr_typesize {816UL};
constexpr uint32_t AMM_PhysiologyValue_max_key_cdr_typesize {0UL};


constexpr uint32_t AMM_PhysiologyModification_max_cdr_typesize {4893UL};
constexpr uint32_t AMM_PhysiologyModification_max_key_cdr_typesize {0UL};

constexpr uint32_t AMM_PhysiologyWaveform_max_cdr_typesize {816UL};
constexpr uint32_t AMM_PhysiologyWaveform_max_key_cdr_typesize {0UL};

constexpr uint32_t AMM_OperationalDescription_max_cdr_typesize {14357UL};
constexpr uint32_t AMM_OperationalDescription_max_key_cdr_typesize {0UL};

constexpr uint32_t AMM_OmittedEvent_max_cdr_typesize {5441UL};
constexpr uint32_t AMM_OmittedEvent_max_key_cdr_typesize {0UL};

constexpr uint32_t AMM_FMA_Location_max_cdr_typesize {268UL};
constexpr uint32_t AMM_FMA_Location_max_key_cdr_typesize {0UL};

constexpr uint32_t AMM_EventFragment_max_cdr_typesize {5441UL};
constexpr uint32_t AMM_EventFragment_max_key_cdr_typesize {0UL};

constexpr uint32_t AMM_SimulationControl_max_cdr_typesize {284UL};
constexpr uint32_t AMM_SimulationControl_max_key_cdr_typesize {0UL};


constexpr uint32_t AMM_Log_max_cdr_typesize {544UL};
constexpr uint32_t AMM_Log_max_key_cdr_typesize {0UL};


namespace eprosima {
namespace fastcdr {

class Cdr;
class CdrSizeCalculator;



eProsima_user_DllExport void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const AMM::FMA_Location& data);



eProsima_user_DllExport void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const AMM::UUID& data);




eProsima_user_DllExport void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const AMM::Assessment& data);




eProsima_user_DllExport void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const AMM::EventFragment& data);



eProsima_user_DllExport void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const AMM::EventRecord& data);




eProsima_user_DllExport void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const AMM::FragmentAmendmentRequest& data);




eProsima_user_DllExport void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const AMM::Log& data);



eProsima_user_DllExport void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const AMM::ModuleConfiguration& data);



eProsima_user_DllExport void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const AMM::OmittedEvent& data);



eProsima_user_DllExport void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const AMM::Semantic_Version& data);



eProsima_user_DllExport void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const AMM::OperationalDescription& data);



eProsima_user_DllExport void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const AMM::PhysiologyModification& data);



eProsima_user_DllExport void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const AMM::PhysiologyValue& data);



eProsima_user_DllExport void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const AMM::PhysiologyWaveform& data);



eProsima_user_DllExport void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const AMM::RenderModification& data);




eProsima_user_DllExport void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const AMM::SimulationControl& data);




eProsima_user_DllExport void serialize_key(
        eprosima::fastcdr::Cdr& scdr,
        const AMM::Status& data);



} // namespace fastcdr
} // namespace eprosima

#endif // _FAST_DDS_GENERATED_AMM_AMM_STANDARDCDRAUX_HPP_
