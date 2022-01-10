#pragma once

#include <string>

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

#include "AMM/BaseLogger.h"

#include "AmmDataType.h"
#include "DDS_Listeners.h"
#include "AMM_StandardPubSubTypes.h"
#include "AMM_Standard.h"


// Naming Key:
// -----------------------------------
//  LTNR = Listener
//  ASMT = Assessment
//  EVFR = Event Fragment
//  EVRC = Event Record
//  FARQ = Fragment Amendment Request
//  ALOG = "AMM" Log
//  MOCF = Module Configuration
//  OMEV = Omitted Event
//  OPDS = Operational Description
//  PHMO = Physiology Modification
//  PHVA = Physiology Value
//  PHWV = Physiology Wave
//  RDMO = Render Modification
//  SMCN = Simulation Control
//  STAT = Status
//  TICK = Tick
//  IDAT = Instrument Data
//  CMND = Command

#define ASMT_TYPE AMM::AssessmentPubSubType
#define ASMT_LTNR AMM::DDS_Listeners::AssessmentListener
#define ASMT      AMM::Assessment
#define ASMT_STR  "Assessment"

#define EVFR_TYPE AMM::EventFragmentPubSubType
#define EVFR_LTNR AMM::DDS_Listeners::EventFragmentListener
#define EVFR      AMM::EventFragment
#define EVFR_STR  "Event Fragment"

#define EVRC_TYPE AMM::EventRecordPubSubType
#define EVRC_LTNR AMM::DDS_Listeners::EventRecordListener
#define EVRC      AMM::EventRecord
#define EVRC_STR  "Event Record"

#define FARQ_TYPE AMM::FragmentAmendmentRequestPubSubType
#define FARQ_LTNR AMM::DDS_Listeners::FragmentAmendmentRequestListener
#define FARQ      AMM::FragmentAmendmentRequest
#define FARQ_STR  "Fragment Amendment Request"

#define ALOG_TYPE AMM::LogPubSubType
#define ALOG_LTNR AMM::DDS_Listeners::LogListener
#define ALOG      AMM::Log
#define ALOG_STR  "Log"

#define MOCF_TYPE AMM::ModuleConfigurationPubSubType
#define MOCF_LTNR AMM::DDS_Listeners::ModuleConfigurationListener
#define MOCF      AMM::ModuleConfiguration
#define MOCF_STR  "Module Configuration"

#define OMEV_TYPE AMM::OmittedEventPubSubType
#define OMEV_LTNR AMM::DDS_Listeners::OmittedEventListener
#define OMEV      AMM::OmittedEvent
#define OMEV_STR  "Omitted Event"

#define OPDS_TYPE AMM::OperationalDescriptionPubSubType
#define OPDS_LTNR AMM::DDS_Listeners::OperationalDescriptionListener
#define OPDS      AMM::OperationalDescription
#define OPDS_STR  "Operational Description"

#define PHMO_TYPE AMM::PhysiologyModificationPubSubType
#define PHMO_LTNR AMM::DDS_Listeners::PhysiologyModificationListener
#define PHMO      AMM::PhysiologyModification
#define PHMO_STR  "Physiology Modification"

#define PHVA_TYPE AMM::PhysiologyValuePubSubType
#define PHVA_LTNR AMM::DDS_Listeners::PhysiologyValueListener
#define PHVA      AMM::PhysiologyValue
#define PHVA_STR  "Physiology Value"

#define PHWV_TYPE AMM::PhysiologyWaveformPubSubType
#define PHWV_LTNR AMM::DDS_Listeners::PhysiologyWaveformListener
#define PHWV      AMM::PhysiologyWaveform
#define PHWV_STR  "Physiology Waveform"

#define RDMO_TYPE AMM::RenderModificationPubSubType
#define RDMO_LTNR AMM::DDS_Listeners::RenderModificationListener
#define RDMO      AMM::RenderModification
#define RDMO_STR  "Render Modification"

#define SMCN_TYPE AMM::SimulationControlPubSubType
#define SMCN_LTNR AMM::DDS_Listeners::SimulationControlListener
#define SMCN      AMM::SimulationControl
#define SMCN_STR  "Simulation Control"

#define STAT_TYPE AMM::StatusPubSubType
#define STAT_LTNR AMM::DDS_Listeners::StatusListener
#define STAT      AMM::Status
#define STAT_STR  "Status"

#define TICK_TYPE AMM::TickPubSubType
#define TICK_LTNR AMM::DDS_Listeners::TickListener
#define TICK      AMM::Tick
#define TICK_STR  "Tick"

#define IDAT_TYPE AMM::InstrumentDataPubSubType
#define IDAT_LTNR AMM::DDS_Listeners::InstrumentDataListener
#define IDAT      AMM::InstrumentData
#define IDAT_STR  "Instrument Data"

#define CMND_TYPE AMM::CommandPubSubType
#define CMND_LTNR AMM::DDS_Listeners::CommandListener
#define CMND      AMM::Command
#define CMND_STR  "Command"


namespace AMM {


/// Wrapper interface for managing AMM Data Types.
///
/// Specialization A<br>
/// This is the specialization template for handling the function pointer type
/// of a class instance for subscribed events.
    template<class U>
    class DDSManager : public ListenerInterface {

    private:

        /// Assessment type handler.
        /// Handler for registering, publishering, and subscribing data for Assessment.
        AmmDataType<ASMT_TYPE, ASMT_LTNR, ASMT, U> *m_assessment;

        /// Event Fragment type handler.
        /// Handler for registering, publishering, and subscribing data for Event Fragment.
        AmmDataType<EVFR_TYPE, EVFR_LTNR, EVFR, U> *m_eventFragment;

        /// Event Record type handler.
        /// Handler for registering, publishering, and subscribing data for Event Record.
        AmmDataType<EVRC_TYPE, EVRC_LTNR, EVRC, U> *m_eventRecord;

        /// Fragment Amendment Request type handler.
        /// Handler for registering, publishering, and subscribing data for Fragment Amendment Request.
        AmmDataType<FARQ_TYPE, FARQ_LTNR, FARQ, U> *m_fragmentAmendmentRequest;

        /// Log type handler.
        /// Handler for registering, publishering, and subscribing data for Log.
        AmmDataType<ALOG_TYPE, ALOG_LTNR, ALOG, U> *m_log;

        /// Module Configuration type handler.
        /// Handler for registering, publishering, and subscribing data for Module Configuration.
        AmmDataType<MOCF_TYPE, MOCF_LTNR, MOCF, U> *m_moduleConfiguration;

        /// Omitted Description type handler.
        /// Handler for registering, publishering, and subscribing data for Omitted Description.
        AmmDataType<OMEV_TYPE, OMEV_LTNR, OMEV, U> *m_omittedEvent;

        /// Operational Description type handler.
        /// Handler for registering, publishering, and subscribing data for Operational Description.
        AmmDataType<OPDS_TYPE, OPDS_LTNR, OPDS, U> *m_operationalDescription;

        /// Physiology Modification type handler.
        /// Handler for registering, publishering, and subscribing data for Physiology Modification.
        AmmDataType<PHMO_TYPE, PHMO_LTNR, PHMO, U> *m_physiologyModification;

        /// Physiology Value type handler.
        /// Handler for registering, publishering, and subscribing data for Physiology Value.
        AmmDataType<PHVA_TYPE, PHVA_LTNR, PHVA, U> *m_physiologyValue;

        /// Physiology Waveform type handler.
        /// Handler for registering, publishering, and subscribing data for Physiology Waveform.
        AmmDataType<PHWV_TYPE, PHWV_LTNR, PHWV, U> *m_physiologyWaveform;

        /// Render Modification type handler.
        /// Handler for registering, publishering, and subscribing data for Render Modification.
        AmmDataType<RDMO_TYPE, RDMO_LTNR, RDMO, U> *m_renderModification;

        /// Simulation Control type handler.
        /// Handler for registering, publishering, and subscribing data for Simulation Control.
        AmmDataType<SMCN_TYPE, SMCN_LTNR, SMCN, U> *m_simulationControl;

        /// Status type handler.
        /// Handler for registering, publishering, and subscribing data for Status.
        AmmDataType<STAT_TYPE, STAT_LTNR, STAT, U> *m_status;

        /// Tick type handler.
        /// Handler for registering, publishering, and subscribing data for Tick.
        AmmDataType<TICK_TYPE, TICK_LTNR, TICK, U> *m_tick;

        /// Instrument Data type handler.
        /// Handler for registering, publishering, and subscribing data for Instrument Data.
        AmmDataType<IDAT_TYPE, IDAT_LTNR, IDAT, U> *m_instrumentData;

        /// Command type handler.
        /// Handler for registering, publishering, and subscribing data for Command.
        AmmDataType<CMND_TYPE, CMND_LTNR, CMND, U> *m_command;

        /// Initializer flag for Assessment.
        /// State of whether the AMMDataType pointer for Assessment is valid.
        bool m_isAssessmentInit = false;

        /// Initializer flag for Event Fragment.
        /// State of whether the AMMDataType pointer for Event Fragment is valid.
        bool m_isEventFragInit = false;

        /// Initializer flag for Event Record.
        /// State of whether the AMMDataType pointer for Event Record is valid.
        bool m_isEventRecInit = false;

        /// Initializer flag for Fragment Amendment Request.
        /// State of whether the AMMDataType pointer for Fragment Amendment Request is valid.
        bool m_isFragAmendReqInit = false;

        /// Initializer flag for Log.
        /// State of whether the AMMDataType pointer for Log is valid.
        bool m_isLogInit = false;

        /// Initializer flag for Module Configuration.
        /// State of whether the AMMDataType pointer for Module Configuration is valid.
        bool m_isModConfigInit = false;

        /// Initializer flag for Omitted Event.
        /// State of whether the AMMDataType pointer for Omitted Event is valid.
        bool m_isOmitEventInit = false;

        /// Initializer flag for Operational Description.
        /// State of whether the AMMDataType pointer for Operational Description is valid.
        bool m_isOpDescriptInit = false;

        /// Initializer flag for Physiology Modification.
        /// State of whether the AMMDataType pointer for Physiology Modification is valid.
        bool m_isPhysModInit = false;

        /// Initializer flag for Physiology Value.
        /// State of whether the AMMDataType pointer for Physiology Value is valid.
        bool m_isPhysValInit = false;

        /// Initializer flag for Physiology Waveform.
        /// State of whether the AMMDataType pointer for Physiology Waveform is valid.
        bool m_isPhysWaveInit = false;

        /// Initializer flag for Render Modification.
        /// State of whether the AMMDataType pointer for Render Modification is valid.
        bool m_isRendModInit = false;

        /// Initializer flag for Simulation Control.
        /// State of whether the AMMDataType pointer for Simulation Control is valid.
        bool m_isSimControlInit = false;

        /// Initializer flag for Status.
        /// State of whether the AMMDataType pointer for Status is valid.
        bool m_isStatusInit = false;

        /// Initializer flag for Tick.
        /// State of whether the AMMDataType pointer for Tick is valid.
        bool m_isTickInit = false;

        /// Initializer flag for Instrument Data.
        /// State of whether the AMMDataType pointer for Instrument Data is valid.
        bool m_isInstDataInit = false;

        /// Initializer flag for Command.
        /// State of whether the AMMDataType pointer for Command is valid.
        bool m_isCommandInit = false;


    private:

        /// UUID of this module.
        std::string m_moduleId;

        /// Name of this module.
        std::string m_moduleName;

        /// Default domain ID for AMM Modules.
        const int DOMAIN_ID = 15;

        /// DDS Participant of this module.
        /// Each AMM Module has one Participant used to register their activity on the DDS network.
        /// A Participant is created at the time of the module's inception, and removed once a module
        /// shuts down.
        eprosima::fastrtps::Participant *m_participant;

        /// DDS Listener object for publishers.
        /// All publishers for each AMMDataType use the same publisher listener
        /// referenced from here.
        /// @note Is created at the time of the module's inception.
        DDS_Listeners::PubListener *m_pubListener;

    public:
        /// Default constructor taking in a module name defined by the user.
        /// @param moduleName String name of this module.
        DDSManager(std::string configFile);

        /// Default deconstructor.
        ~DDSManager() {};

        /// Default shutdown command for the module.
        /// Should always be used before exiting the executable, because this ensures all Participant activity
        /// is properly terminated and cleaned up for memory management sake on the DDS network.
        /// @note Shutdown routine will not stop if an error flag is raised. Will ignore and continue on.
        void Shutdown();

        /// Override shutdown outputting an error message if any error flags are raised suring shutdown.
        /// @param errmsg Error message output.
        /// @note Shutdown routine will not stop if an error flag is raised. Will ignore and continue on.
        void Shutdown(std::string &errmsg);

        /// Generates a random UUID.
        /// @returns A string form of a UUID.
        static std::string GenerateUuidString();

        /// Initializer routine for Assessment.
        /// Initializes m_assessment with a new AmmDataType pointer.
        /// @returns 0 if successful.
        int InitializeAssessment();

        /// Overload initializer routine for Assessment.
        /// Initializes m_assessment with a new AmmDataType pointer.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int InitializeAssessment(std::string &errmsg);

        /// State of whether Assessment is currently valid.
        /// @returns True if m_assessment is valid pointer.
        bool IsAssessmentInitialized();

        /// Create the data publisher for Assessment on this module.
        /// Allows Assessment data to be published to the DDS network.
        /// @returns 0 if successful.
        int CreateAssessmentPublisher();

        /// Create the data publisher for Assessment on this module.
        /// Allows Assessment data to be published to the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int CreateAssessmentPublisher(std::string &errmsg);

        /// Remove the publisher for Assessment on this module from the DDS network.
        /// @returns 0 if successful.
        int RemoveAssessmentPublisher();

        /// Remove the publisher for Assessment on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemoveAssessmentPublisher(std::string &errmsg);

        /// Create the data subscriber for Assessment published events on this module.
        /// Allows the module to receive Assessment data when it is published on the DDS network.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreateAssessmentSubscriber(
           U *parentClass, void (U::*onEvent)(AMM::Assessment &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Create the data subscriber for Assessment published events on this module.
        /// Allows the module to receive Assessment data when it is published on the DDS network.
        /// @param errmsg Error message output.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreateAssessmentSubscriber(
           std::string &errmsg, U *parentClass,
           void (U::*onEvent)(AMM::Assessment &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Remove the subscriber for Assessment on this module from the DDS network.
        /// @returns 0 if successful.
        int RemoveAssessmentSubscriber();

        /// Remove the subscriber for Assessment on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemoveAssessmentSubscriber(std::string &errmsg);

        /// Call upon the active publisher for Assessment to write data to the DDS network.
        /// @param a Reference to Assessment data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WriteAssessment(AMM::Assessment &a);

        /// Call upon the active publisher for Assessment to write data to the DDS network.
        /// @param errmsg Error message output.
        /// @param a Reference to Assessment data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WriteAssessment(std::string &errmsg, AMM::Assessment &a);

        /// Listener Interface override for handling Assessment subscribed events.
        /// Calls OnEvent on m_assessment passing along data to the handler defined by
        /// the user in CreateAssessmentSubscriber.
        /// @see AmmDataType::OnEvent
        /// @see ListenerInterface::onNewAssessment
        /// @param assessment incoming Assessment data from the DDS network.
        /// @param info FastRTPS sample info.
        void onNewAssessment(AMM::Assessment assessment, eprosima::fastrtps::SampleInfo_t *info) override;

        /// Clean up Assessment and set it to an inactive state.
        /// Calls Delete on m_assessment.
        /// @returns 0 if successful.
        int DecommissionAssessment();

        /// Clean up assessment and set it to an inactive state.
        /// Calls Delete on m_assessment.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int DecommissionAssessment(std::string &errmsg);

        // - - - Event Fragment - - -

        /// Initializer routine for Event Fragment.
        /// Initializes m_eventFragment with a new AmmDataType pointer.
        /// @returns 0 if successful.
        int InitializeEventFragment();

        /// Overload initializer routine for Event Fragment.
        /// Initializes m_eventFragment with a new AmmDataType pointer.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int InitializeEventFragment(std::string &errmsg);

        /// State of whether Event Fragment is currently valid.
        /// @returns True if m_eventFragment is valid pointer.
        bool IsEventFragmentInitialzied();

        /// Create the data publisher for Event Fragment on this module.
        /// Allows Event Fragment data to be published to the DDS network.
        /// @returns 0 if successful.
        int CreateEventFragmentPublisher();

        /// Create the data publisher for Event Fragment on this module.
        /// Allows Event Fragment data to be published to the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int CreateEventFragmentPublisher(std::string &errmsg);

        /// Remove the publisher for Event Fragment on this module from the DDS network.
        /// @returns 0 if successful.
        int RemoveEventFragmentPublisher();

        /// Remove the publisher for Event Fragment on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemoveEventFragmentPublisher(std::string &errmsg);

        /// Create the data subscriber for Event Fragment published events on this module.
        /// Allows the module to receive Event Fragment data when it is published on the DDS network.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreateEventFragmentSubscriber(
           U *parentClass, void (U::*onEvent)(AMM::EventFragment &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Create the data subscriber for Event Fragment published events on this module.
        /// Allows the module to receive Event Fragment data when it is published on the DDS network.
        /// @param errmsg Error message output.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreateEventFragmentSubscriber(
           std::string &errmsg, U *parentClass,
           void (U::*onEvent)(AMM::EventFragment &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Remove the subscriber for Event Fragment on this module from the DDS network.
        /// @returns 0 if successful.
        int RemoveEventFragmentSubscriber();

        /// Remove the subscriber for Event Fragment on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemoveEventFragmentSubscriber(std::string &errmsg);

        /// Call upon the active publisher for Event Fragment to write data to the DDS network.
        /// @param a Reference to Event Fragment data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WriteEventFragment(AMM::EventFragment &a);

        /// Call upon the active publisher for Event Fragment to write data to the DDS network.
        /// @param errmsg Error message output.
        /// @param a Reference to Event Fragment data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WriteEventFragment(std::string &errmsg, AMM::EventFragment &a);

        /// Listener Interface override for handling Assessment subscribed events.
        /// Calls OnEvent on m_eventFragment passing along data to the handler defined by
        /// the user in CreateEventFragmentSubscriber.
        /// @see AmmDataType::OnEvent
        /// @see DDSManager::m_aseessment
        /// @see ListenerInterface::onNewEventFragment
        /// @param eventFrag incoming Event Fragment data from the DDS network.
        /// @param info FastRTPS sample info.
        void onNewEventFragment(AMM::EventFragment eventFrag, eprosima::fastrtps::SampleInfo_t *info) override;

        /// Clean up Event Fragment and set it to an inactive state.
        /// Calls Delete on m_eventFragment.
        /// @returns 0 if successful.
        int DecommissionEventFragment();

        /// Clean up Event Fragment and set it to an inactive state.
        /// Calls Delete on m_eventFragment.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int DecommissionEventFragment(std::string &errmsg);

        // - - - Event Record - - -

        /// Initializer routine for Event Record.
        /// Initializes m_eventRecord with a new AmmDataType pointer.
        /// @returns 0 if successful.
        int InitializeEventRecord();

        /// Overload initializer routine for Event Record.
        /// Initializes m_eventRecord with a new AmmDataType pointer.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int InitializeEventRecord(std::string &errmsg);

        /// State of whether Event Record is currently valid.
        /// @returns True if m_eventRecord is valid pointer.
        bool IsEventRecordInitialized();

        /// Create the data publisher for Event Record on this module.
        /// Allows Event Record data to be published to the DDS network.
        /// @returns 0 if successful.
        int CreateEventRecordPublisher();

        /// Create the data publisher for Event Record on this module.
        /// Allows Event Fragment data to be published to the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int CreateEventRecordPublisher(std::string &errmsg);

        /// Remove the publisher for Event Record on this module from the DDS network.
        /// @returns 0 if successful.
        int RemoveEventRecordPublisher();

        /// Remove the publisher for Event Record on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemoveEventRecordPublisher(std::string &errmsg);

        /// Create the data subscriber for Event Record published events on this module.
        /// Allows the module to receive Event Record data when it is published on the DDS network.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreateEventRecordSubscriber(
           U *parentClass, void (U::*onEvent)(AMM::EventRecord &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Create the data subscriber for Event Record published events on this module.
        /// Allows the module to receive Event Record data when it is published on the DDS network.
        /// @param errmsg Error message output.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreateEventRecordSubscriber(
           std::string &errmsg, U *parentClass,
           void (U::*onEvent)(AMM::EventRecord &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Remove the subscriber for Event Record on this module from the DDS network.
        /// @returns 0 if successful.
        int RemoveEventRecordSubscriber();

        /// Remove the subscriber for Event Record on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemoveEventRecordSubscriber(std::string &errmsg);

        /// Call upon the active publisher for Event Record to write data to the DDS network.
        /// @param a Reference to Event Record data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WriteEventRecord(AMM::EventRecord &a);

        /// Call upon the active publisher for Event Record to write data to the DDS network.
        /// @param errmsg Error message output.
        /// @param a Reference to Event Record data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WriteEventRecord(std::string &errmsg, AMM::EventRecord &a);

        /// Listener Interface override for handling Event Record subscribed events.
        /// Calls OnEvent on m_eventRecord passing along data to the handler defined by
        /// the user in CreateEventRecordSubscriber.
        /// @see AmmDataType::OnEvent
        /// @see ListenerInterface::onNewEventRecord
        /// @param eventFrag incoming Event Record data from the DDS network.
        /// @param info FastRTPS sample info.
        void onNewEventRecord(AMM::EventRecord eventRec, eprosima::fastrtps::SampleInfo_t *info) override;

        /// Clean up Event Record and set it to an inactive state.
        /// Calls Delete on m_eventRecord.
        /// @returns 0 if successful.
        int DecommissionEventRecord();

        /// Clean up Event Record and set it to an inactive state.
        /// Calls Delete on m_eventRecord.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int DecommissionEventRecord(std::string &errmsg);

        // - - - Fragment Amendment Request - - -

        /// Initializer routine for Fragment Amendment Request.
        /// Initializes m_fragmentAmendmentRequest with a new AmmDataType pointer.
        /// @returns 0 if successful.
        int InitializeFragmentAmendmentRequest();

        /// Overload initializer routine for Fragment Amendment Request.
        /// Initializes m_fragmentAmendmentRequest with a new AmmDataType pointer.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int InitializeFragmentAmendmentRequest(std::string &errmsg);

        /// State of whether Fragment Amendment Request is currently valid.
        /// @returns True if m_fragmentAmendmentRequest is valid pointer.
        bool IsFragmentAmendmentRequestInitialized();

        /// Create the data publisher for Fragment Amendment Request on this module.
        /// Allows Fragment Amendment Request data to be published to the DDS network.
        /// @returns 0 if successful.
        int CreateFragmentAmendmentRequestPublisher();

        /// Create the data publisher for Fragment Amendment Request on this module.
        /// Allows Fragment Amendment Request data to be published to the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int CreateFragmentAmendmentRequestPublisher(std::string &errmsg);

        /// Remove the publisher for Fragment Amendment Request on this module from the DDS network.
        /// @returns 0 if successful.
        int RemoveFragmentAmendmentRequestPublisher();

        /// Remove the publisher for Fragment Amendment Request on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemoveFragmentAmendmentRequestPublisher(std::string &errmsg);

        /// Create the data subscriber for Fragment Amendment Request published events on this module.
        /// Allows the module to receive Fragment Amendment Request data when it is published on the DDS network.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreateFragmentAmendmentRequestSubscriber(
           U *parentClass, void (U::*onEvent)(AMM::FragmentAmendmentRequest &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Create the data subscriber for Fragment Amendment Request published events on this module.
        /// Allows the module to receive Fragment Amendment Request data when it is published on the DDS network.
        /// @param errmsg Error message output.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreateFragmentAmendmentRequestSubscriber(
           std::string &errmsg, U *parentClass,
           void (U::*onEvent)(AMM::FragmentAmendmentRequest &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Remove the subscriber for Fragment Amendment Request on this module from the DDS network.
        /// @returns 0 if successful.
        int RemoveFragmentAmendmentRequestSubscriber();

        /// Remove the subscriber for Fragment Amendment Request on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemoveFragmentAmendmentRequestSubscriber(std::string &errmsg);

        /// Call upon the active publisher for Fragment Amendment Request to write data to the DDS network.
        /// @param a Reference to Fragment Amendment Request data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WriteFragmentAmendmentRequest(AMM::FragmentAmendmentRequest &a);

        /// Call upon the active publisher for Fragment Amendmnet Request to write data to the DDS network.
        /// @param errmsg Error message output.
        /// @param a Reference to Fragment Amendment Request data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WriteFragmentAmendmentRequest(std::string &errmsg, AMM::FragmentAmendmentRequest &a);

        /// Listener Interface override for handling Fragment Amendment Request subscribed events.
        /// Calls OnEvent on m_fragmentAmendmentRequest passing along data to the handler defined by
        /// the user in CreateFragmentAmendmentRequestSubscriber.
        /// @see AmmDataType::OnEvent
        /// @see ListenerInterface::onNewFragmentAmendmentRequest
        /// @param ffar incoming Fragment Amendment Request data from the DDS network.
        /// @param info FastRTPS sample info.
        void onNewFragmentAmendmentRequest(AMM::FragmentAmendmentRequest ffar,
                                           eprosima::fastrtps::SampleInfo_t *info) override;

        /// Clean up Fragment Amendment Request and set it to an inactive state.
        /// Calls Delete on m_fragmentAmendmentRequest.
        /// @returns 0 if successful.
        int DecommissionFragmentAmendmentRequest();

        /// Clean up Fragment Amendment Request and set it to an inactive state.
        /// Calls Delete on m_fragmentAmendmentRequest.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int DecommissionFragmentAmendmentRequest(std::string &errmsg);

        // - - - Log - - -

        /// Initializer routine for Log.
        /// Initializes m_log with a new AmmDataType pointer.
        /// @returns 0 if successful.
        int InitializeLog();

        /// Overload initializer routine for Log.
        /// Initializes m_log with a new AmmDataType pointer.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int InitializeLog(std::string &errmsg);

        /// State of whether Log is currently valid.
        /// @returns True if m_log is valid pointer.
        bool IsLogInitialized();

        /// Create the data publisher for Log on this module.
        /// Allows Log data to be published to the DDS network.
        /// @returns 0 if successful.
        int CreateLogPublisher();

        /// Create the data publisher for Log on this module.
        /// Allows Log data to be published to the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int CreateLogPublisher(std::string &errmsg);

        /// Remove the publisher for Log on this module from the DDS network.
        /// @returns 0 if successful.
        int RemoveLogPublisher();

        /// Remove the publisher for Log on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemoveLogPublisher(std::string &errmsg);

        /// Create the data subscriber for Log published events on this module.
        /// Allows the module to receive Log data when it is published on the DDS network.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreateLogSubscriber(
           U *parentClass, void (U::*onEvent)(AMM::Log &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Create the data subscriber for Log published events on this module.
        /// Allows the module to receive Log data when it is published on the DDS network.
        /// @param errmsg Error message output.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreateLogSubscriber(
           std::string &errmsg, U *parentClass, void (U::*onEvent)(AMM::Log &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Remove the subscriber for Log on this module from the DDS network.
        /// @returns 0 if successful.
        int RemoveLogSubscriber();

        /// Remove the subscriber for Log on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemoveLogSubscriber(std::string &errmsg);

        /// Call upon the active publisher for Log to write data to the DDS network.
        /// @param a Reference to Log data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WriteLog(AMM::Log &a);

        /// Call upon the active publisher for Log to write data to the DDS network.
        /// @param errmsg Error message output.
        /// @param a Reference to Log data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WriteLog(std::string &errmsg, AMM::Log &a);

        /// Listener Interface override for handling Log subscribed events.
        /// Calls OnEvent on m_log passing along data to the handler defined by
        /// the user in CreateLogSubscriber.
        /// @see AmmDataType::OnEvent
        /// @see ListenerInterface::onNewLog
        /// @param log incoming Log data from the DDS network.
        /// @param info FastRTPS sample info.
        void onNewLog(AMM::Log eventRec, eprosima::fastrtps::SampleInfo_t *info) override;

        /// Clean up Log and set it to an inactive state.
        /// Calls Delete on m_log.
        /// @returns 0 if successful.
        int DecommissionLog();

        /// Clean up Log and set it to an inactive state.
        /// Calls Delete on m_log.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int DecommissionLog(std::string &errmsg);

        // - - - Module Configuration - - -

        /// Initializer routine for Module Configuration.
        /// Initializes m_moduleConfiguration with a new AmmDataType pointer.
        /// @returns 0 if successful.
        int InitializeModuleConfiguration();

        /// Overload initializer routine for Module Configuration.
        /// Initializes m_moduleConfiguration with a new AmmDataType pointer.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int InitializeModuleConfiguration(std::string &errmsg);

        /// State of whether Module Configuration is currently valid.
        /// @returns True if m_moduleConfiguration is valid pointer.
        bool IsModuleConfigurationInitialized();

        /// Create the data publisher for Module Configuration on this module.
        /// Allows Module Configuration data to be published to the DDS network.
        /// @returns 0 if successful.
        int CreateModuleConfigurationPublisher();

        /// Create the data publisher for Module Configuration on this module.
        /// Allows Module Configuration data to be published to the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int CreateModuleConfigurationPublisher(std::string &errmsg);

        /// Remove the publisher for Module Configuration on this module from the DDS network.
        /// @returns 0 if successful.
        int RemoveModuleConfigurationPublisher();

        /// Remove the publisher for Module Configuration on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemoveModuleConfigurationPublisher(std::string &errmsg);

        /// Create the data subscriber for Module Configuration published events on this module.
        /// Allows the module to receive Module Configuration data when it is published on the DDS network.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreateModuleConfigurationSubscriber(
           U *parentClass, void (U::*onEvent)(AMM::ModuleConfiguration &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Create the data subscriber for Module Configuration published events on this module.
        /// Allows the module to receive Module Configuration data when it is published on the DDS network.
        /// @param errmsg Error message output.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreateModuleConfigurationSubscriber(
           std::string &errmsg, U *parentClass,
           void (U::*onEvent)(AMM::ModuleConfiguration &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Remove the subscriber for Module Configuration on this module from the DDS network.
        /// @returns 0 if successful.
        int RemoveModuleConfigurationSubscriber();

        /// Remove the subscriber for Module Configuration on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemoveModuleConfigurationSubscriber(std::string &errmsg);

        /// Call upon the active publisher for Module Configuration to write data to the DDS network.
        /// @param a Reference to Module Configuration data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WriteModuleConfiguration(AMM::ModuleConfiguration &a);

        /// Call upon the active publisher for Module Configuration to write data to the DDS network.
        /// @param errmsg Error message output.
        /// @param a Reference to Module Configuration data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WriteModuleConfiguration(std::string &errmsg, AMM::ModuleConfiguration &a);

        /// Listener Interface override for handling Module Configuration subscribed events.
        /// Calls OnEvent on m_moduleConfiguration passing along data to the handler defined by
        /// the user in CreateModuleConfigurationSubscriber.
        /// @see AmmDataType::OnEvent
        /// @see ListenerInterface::onNewModuleConfiguration
        /// @param modConfig incoming Module Configuration data from the DDS network.
        /// @param info FastRTPS sample info.
        void
        onNewModuleConfiguration(AMM::ModuleConfiguration modConfig, eprosima::fastrtps::SampleInfo_t *info) override;

        /// Clean up Module Configuration and set it to an inactive state.
        /// Calls Delete on m_moduleConfiguration.
        /// @returns 0 if successful.
        int DecommissionModuleConfiguration();

        /// Clean up Module Configuration and set it to an inactive state.
        /// Calls Delete on m_moduleConfiguration.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int DecommissionModuleConfiguration(std::string &errmsg);

        // - - - Omitted Event - - -

        /// Initializer routine for Omitted Event.
        /// Initializes m_omittedEvent with a new AmmDataType pointer.
        /// @returns 0 if successful.
        int InitializeOmittedEvent();

        /// Overload initializer routine for Omitted Event.
        /// Initializes m_omittedEvent with a new AmmDataType pointer.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int InitializeOmittedEvent(std::string &errmsg);

        /// State of whether Omitted Event is currently valid.
        /// @returns True if m_omittedEvent is valid pointer.
        bool IsOmittedEventInitialized();

        /// Create the data publisher for Omitted Event on this module.
        /// Allows Omitted Event data to be published to the DDS network.
        /// @returns 0 if successful.
        int CreateOmittedEventPublisher();

        /// Create the data publisher for Omitted Event on this module.
        /// Allows Omitted Event data to be published to the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int CreateOmittedEventPublisher(std::string &errmsg);

        /// Remove the publisher for Omitted Event on this module from the DDS network.
        /// @returns 0 if successful.
        int RemoveOmittedEventPublisher();

        /// Remove the publisher for Omitted Event on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemoveOmittedEventPublisher(std::string &errmsg);

        /// Create the data subscriber for Omitted Event published events on this module.
        /// Allows the module to receive Omitted Event data when it is published on the DDS network.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreateOmittedEventSubscriber(
           U *parentClass, void (U::*onEvent)(AMM::OmittedEvent &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Create the data subscriber for Omitted Event published events on this module.
        /// Allows the module to receive Omitted Event data when it is published on the DDS network.
        /// @param errmsg Error message output.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreateOmittedEventSubscriber(
           std::string &errmsg, U *parentClass,
           void (U::*onEvent)(AMM::OmittedEvent &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Remove the subscriber for Omitted Event on this module from the DDS network.
        /// @returns 0 if successful.
        int RemoveOmittedEventSubscriber();

        /// Remove the subscriber for Omitted Event on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemoveOmittedEventSubscriber(std::string &errmsg);

        /// Call upon the active publisher for Omitted Event to write data to the DDS network.
        /// @param a Reference to Omitted Event data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WriteOmittedEvent(AMM::OmittedEvent &a);

        /// Call upon the active publisher for Omitted Event to write data to the DDS network.
        /// @param errmsg Error message output.
        /// @param a Reference to Omitted Event data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WriteOmittedEvent(std::string &errmsg, AMM::OmittedEvent &a);

        /// Listener Interface override for handling Omitted Event subscribed events.
        /// Calls OnEvent on m_omittedEvent passing along data to the handler defined by
        /// the user in CreateOmittedEventSubscriber.
        /// @see AmmDataType::OnEvent
        /// @see ListenerInterface::onNewOmittedEvent
        /// @param omittedEvent incoming Omitted Event data from the DDS network.
        /// @param info FastRTPS sample info..
        void onNewOmittedEvent(AMM::OmittedEvent omittedEvent, eprosima::fastrtps::SampleInfo_t *info) override;

        /// Clean up Omitted Event and set it to an inactive state.
        /// Calls Delete on m_omittedEvent.
        /// @returns 0 if successful.
        int DecommissionOmittedEvent();

        /// Clean up Omitted Event and set it to an inactive state.
        /// Calls Delete on m_omittedEvent.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int DecommissionOmittedEvent(std::string &errmsg);

        // - - - Operational Description - - -

        /// Initializer routine for Operational Description.
        /// Initializes m_operationalDescription with a new AmmDataType pointer.
        /// @returns 0 if successful.
        int InitializeOperationalDescription();

        /// Overload initializer routine for Operational Description.
        /// Initializes m_operationalDescription with a new AmmDataType pointer.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int InitializeOperationalDescription(std::string &errmsg);

        /// State of whether Operational Description is currently valid.
        /// @returns True if m_operationalDescription is valid pointer.
        bool IsOperationalDescriptionInitialized();

        /// Create the data publisher for Operational Description on this module.
        /// Allows Operational Description data to be published to the DDS network.
        /// @returns 0 if successful.
        int CreateOperationalDescriptionPublisher();

        /// Create the data publisher for Operational Desription on this module.
        /// Allows Operational Description data to be published to the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int CreateOperationalDescriptionPublisher(std::string &errmsg);

        /// Remove the publisher for Operational Description on this module from the DDS network.
        /// @returns 0 if successful.
        int RemoveOperationalDescriptionPublisher();

        /// Remove the publisher for Operational Description on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemoveOperationalDescriptionPublisher(std::string &errmsg);

        /// Create the data subscriber for Operational Description published events on this module.
        /// Allows the module to receive Operational Description data when it is published on the DDS network.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreateOperationalDescriptionSubscriber(
           U *parentClass, void (U::*onEvent)(AMM::OperationalDescription &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Create the data subscriber for Operational Description published events on this module.
        /// Allows the module to receive Operational Description data when it is published on the DDS network.
        /// @param errmsg Error message output.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreateOperationalDescriptionSubscriber(
           std::string &errmsg, U *parentClass,
           void (U::*onEvent)(AMM::OperationalDescription &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Remove the subscriber for Operation Description on this module from the DDS network.
        /// @returns 0 if successful.
        int RemoveOperationalDescriptionSubscriber();

        /// Remove the subscriber for Operational Description on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemoveOperationalDescriptionSubscriber(std::string &errmsg);

        /// Call upon the active publisher for Operational Description to write data to the DDS network.
        /// @param a Reference to Operational Description data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WriteOperationalDescription(AMM::OperationalDescription &a);

        /// Call upon the active publisher for Operational Description to write data to the DDS network.
        /// @param errmsg Error message output.
        /// @param a Reference to Operational Description data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WriteOperationalDescription(std::string &errmsg, AMM::OperationalDescription &a);

        /// Listener Interface override for handling Operational Description subscribed events.
        /// Calls OnEvent on m_operationalDescription passing along data to the handler defined by
        /// the user in CreateOperationalDescriptionSubscriber.
        /// @see AmmDataType::OnEvent
        /// @see ListenerInterface::onNewOperationalDescription
        /// @param opDescript incoming Operational Description data from the DDS network.
        /// @param info FastRTPS sample info.
        void onNewOperationalDescription(AMM::OperationalDescription opDescript,
                                         eprosima::fastrtps::SampleInfo_t *info) override;

        /// Clean up Operational Description and set it to an inactive state.
        /// Calls Delete on m_operationalDescription.
        /// @returns 0 if successful.
        int DecommissionOperationalDescription();

        /// Clean up Operational Description and set it to an inactive state.
        /// Calls Delete on m_operationalDescription.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int DecommissionOperationalDescription(std::string &errmsg);

        // - - - Physiology Modification - - -

        /// Initializer routine for Physiology Modification.
        /// Initializes m_physiologyModification with a new AmmDataType pointer.
        /// @returns 0 if successful.
        int InitializePhysiologyModification();

        /// Overload initializer routine for Physiology Modification.
        /// Initializes m_physiologyModification with a new AmmDataType pointer.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int InitializePhysiologyModification(std::string &errmsg);

        /// State of whether Physiology Modfication is currently valid.
        /// @returns True if m_physiologyModification is valid pointer.
        bool IsPhysiologyModificationInitialized();

        /// Create the data publisher for Physiology Modification on this module.
        /// Allows Physiology Modification data to be published to the DDS network.
        /// @returns 0 if successful.
        int CreatePhysiologyModificationPublisher();

        /// Create the data publisher for Physiology Modification on this module.
        /// Allows Physiology Modification data to be published to the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int CreatePhysiologyModificationPublisher(std::string &errmsg);

        /// Remove the publisher for Physiology Modification on this module from the DDS network.
        /// @returns 0 if successful.
        int RemovePhysiologyModificationPublisher();

        /// Remove the publisher for Physiology Modification on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemovePhysiologyModificationPublisher(std::string &errmsg);

        /// Create the data subscriber for Physiology Modification published events on this module.
        /// Allows the module to receive Physiology Modification data when it is published on the DDS network.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreatePhysiologyModificationSubscriber(
           U *parentClass, void (U::*onEvent)(AMM::PhysiologyModification &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Create the data subscriber for Physiology Modification published events on this module.
        /// Allows the module to receive Physiology Modification data when it is published on the DDS network.
        /// @param errmsg Error message output.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreatePhysiologyModificationSubscriber(
           std::string &errmsg, U *parentClass,
           void (U::*onEvent)(AMM::PhysiologyModification &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Remove the subscriber for Physiology Modification on this module from the DDS network.
        /// @returns 0 if successful.
        int RemovePhysiologyModificationSubscriber();

        /// Remove the subscriber for Physiology Modification on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemovePhysiologyModificationSubscriber(std::string &errmsg);

        /// Call upon the active publisher for Physiology Modification to write data to the DDS network.
        /// @param a Reference to Physiology Modification data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WritePhysiologyModification(AMM::PhysiologyModification &a);

        /// Call upon the active publisher for Physiology Modification to write data to the DDS network.
        /// @param errmsg Error message output.
        /// @param a Reference to Physiology Modification data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WritePhysiologyModification(std::string &errmsg, AMM::PhysiologyModification &a);

        /// Listener Interface override for handling Physiology Modification subscribed events.
        /// Calls OnEvent on m_physiologyModification passing along data to the handler defined by
        /// the user in CreatePhysiologyModificationSubscriber.
        /// @see AmmDataType::OnEvent
        /// @see ListenerInterface::onNewPhysiologyModification
        /// @param physMod incoming Physiology Modification data from the DDS network.
        /// @param info FastRTPS sample info.
        void onNewPhysiologyModification(AMM::PhysiologyModification physMod,
                                         eprosima::fastrtps::SampleInfo_t *info) override;

        /// Clean up Physiology Modification and set it to an inactive state.
        /// Calls Delete on m_physiologyModification.
        /// @returns 0 if successful.
        int DecommissionPhysiologyModification();

        /// Clean up Physiology Modification and set it to an inactive state.
        /// Calls Delete on m_physiologyModification.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int DecommissionPhysiologyModification(std::string &errmsg);

        // - - - Physioogy Value - - -

        /// Initializer routine for Physiology Value.
        /// Initializes m_physiologyValue with a new AmmDataType pointer.
        /// @returns 0 if successful.
        int InitializePhysiologyValue();

        /// Overload initializer routine for Physiology Value.
        /// Initializes m_physiologyValue with a new AmmDataType pointer.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int InitializePhysiologyValue(std::string &errmsg);

        /// State of whether Physiology Value is currently valid.
        /// @returns True if m_physiologyValue is valid pointer.
        bool IsPhysiologyValueInitialized();

        /// Create the data publisher for Physiology Value on this module.
        /// Allows Physiology Value data to be published to the DDS network.
        /// @returns 0 if successful.
        int CreatePhysiologyValuePublisher();

        /// Create the data publisher for Physiology Value on this module.
        /// Allows Physiology Value data to be published to the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int CreatePhysiologyValuePublisher(std::string &errmsg);

        /// Remove the publisher for Physiology Value on this module from the DDS network.
        /// @returns 0 if successful.
        int RemovePhysiologyValuePublisher();

        /// Remove the publisher for Physiology Value on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemovePhysiologyValuePublisher(std::string &errmsg);

        /// Create the data subscriber for Physiology Value published events on this module.
        /// Allows the module to receive Physiology Value data when it is published on the DDS network.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreatePhysiologyValueSubscriber(
           U *parentClass, void (U::*onEvent)(AMM::PhysiologyValue &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Create the data subscriber for Physiology Value published events on this module.
        /// Allows the module to receive Physiology Value data when it is published on the DDS network.
        /// @param errmsg Error message output.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreatePhysiologyValueSubscriber(
           std::string &errmsg, U *parentClass,
           void (U::*onEvent)(AMM::PhysiologyValue &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Remove the subscriber for Physiology Value on this module from the DDS network.
        /// @returns 0 if successful.
        int RemovePhysiologyValueSubscriber();

        /// Remove the subscriber for Physiology Value on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemovePhysiologyValueSubscriber(std::string &errmsg);

        /// Call upon the active publisher for Physiology Value to write data to the DDS network.
        /// @param a Reference to Physiology Value data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WritePhysiologyValue(AMM::PhysiologyValue &a);

        /// Call upon the active publisher for Physiology Value to write data to the DDS network.
        /// @param errmsg Error message output.
        /// @param a Reference to Physiology Value data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WritePhysiologyValue(std::string &errmsg, AMM::PhysiologyValue &a);

        /// Listener Interface override for handling Physiology Value subscribed events.
        /// Calls OnEvent on m_physiologyValue passing along data to the handler defined by
        /// the user in CreatePhysiologyValueSubscriber.
        /// @see AmmDataType::OnEvent
        /// @see ListenerInterface::onNewPhysiologyValue
        /// @param physVal incoming Physiology Value data from the DDS network.
        /// @param info FastRTPS sample info.
        void onNewPhysiologyValue(AMM::PhysiologyValue physVal, eprosima::fastrtps::SampleInfo_t *info) override;

        /// Clean up Physiology Value and set it to an inactive state.
        /// Calls Delete on m_physiologyValue.
        /// @returns 0 if successful.
        int DecommissionPhysiologyValue();

        /// Clean up Physiology Value and set it to an inactive state.
        /// Calls Delete on m_physiologyValue.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int DecommissionPhysiologyValue(std::string &errmsg);

        // - - - Physiology Waveform - - -

        /// Initializer routine for Physiology Waveform.
        /// Initializes m_physiologyWaveform with a new AmmDataType pointer.
        /// @returns 0 if successful.
        int InitializePhysiologyWaveform();

        /// Overload initializer routine for Physiology Waveform.
        /// Initializes m_physiolgyWaveform with a new AmmDataType pointer.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int InitializePhysiologyWaveform(std::string &errmsg);

        /// State of whether Physiology Waveform is currently valid.
        /// @returns True if m_physiologyWaveform is valid pointer.
        bool IsPhysiologyWaveformInitialized();

        /// Create the data publisher for Physiology Waveform on this module.
        /// Allows Physiology Waveform data to be published to the DDS network.
        /// @returns 0 if successful.
        int CreatePhysiologyWaveformPublisher();

        /// Create the data publisher for Physiology Waveform on this module.
        /// Allows Physiology Waveform data to be published to the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int CreatePhysiologyWaveformPublisher(std::string &errmsg);

        /// Remove the publisher for Physiology Waveform on this module from the DDS network.
        /// @returns 0 if successful.
        int RemovePhysiologyWaveformPublisher();

        /// Remove the publisher for Physiology Waveform on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemovePhysiologyWaveformPublisher(std::string &errmsg);

        /// Create the data subscriber for Physiology Waveform published events on this module.
        /// Allows the module to receive Physiology Waeform data when it is published on the DDS network.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreatePhysiologyWaveformSubscriber(
           U *parentClass, void (U::*onEvent)(AMM::PhysiologyWaveform &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Create the data subscriber for Physiology Waveform published events on this module.
        /// Allows the module to receive Physiology Waveform data when it is published on the DDS network.
        /// @param errmsg Error message output.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreatePhysiologyWaveformSubscriber(
           std::string &errmsg, U *parentClass,
           void (U::*onEvent)(AMM::PhysiologyWaveform &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Remove the subscriber for Physiology Waveform on this module from the DDS network.
        /// @returns 0 if successful.
        int RemovePhysiologyWaveformSubscriber();

        /// Remove the subscriber for Physiology Waveform on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemovePhysiologyWaveformSubscriber(std::string &errmsg);

        /// Call upon the active publisher for Physiology Waveform to write data to the DDS network.
        /// @param a Reference to Physiology Waveform data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WritePhysiologyWaveform(AMM::PhysiologyWaveform &a);

        /// Call upon the active publisher for Physiology Waveform to write data to the DDS network.
        /// @param errmsg Error message output.
        /// @param a Reference to Physiology Waveform data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WritePhysiologyWaveform(std::string &errmsg, AMM::PhysiologyWaveform &a);

        /// Listener Interface override for handling Physiology Waveform subscribed events.
        /// Calls OnEvent on m_physiologyWaveform passing along data to the handler defined by
        /// the user in CreatePhysiologyWaveformSubscriber.
        /// @see AmmDataType::OnEvent
        /// @see ListenerInterface::onNewPhysiologyWaveform
        /// @param eventFrag incoming Physiology Waveform data from the DDS network.
        /// @param info FastRTPS sample info.
        void onNewPhysiologyWaveform(AMM::PhysiologyWaveform physWave, eprosima::fastrtps::SampleInfo_t *info) override;

        /// Clean up Physiology Waveform and set it to an inactive state.
        /// Calls Delete on m_physiologyWaveform.
        /// @returns 0 if successful.
        int DecommissionPhysiologyWaveform();

        /// Clean up Physiology Waveform and set it to an inactive state.
        /// Calls Delete on m_physiologyWaveform.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int DecommissionPhysiologyWaveform(std::string &errmsg);

        // - - - Render Modification - - -

        /// Initializer routine for Render Modification.
        /// Initializes m_renderModification with a new AmmDataType pointer.
        /// @returns 0 if successful.
        int InitializeRenderModification();

        /// Overload initializer routine for Render Modification.
        /// Initializes m_renderModification with a new AmmDataType pointer.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int InitializeRenderModification(std::string &errmsg);

        /// State of whether Render Modification is currently valid.
        /// @returns True if m_renderModification is valid pointer.
        bool IsRenderModificationInitialized();

        /// Create the data publisher for Render Modification on this module.
        /// Allows Render Modification data to be published to the DDS network.
        /// @returns 0 if successful.
        int CreateRenderModificationPublisher();

        /// Create the data publisher for Render Modification on this module.
        /// Allows Render Modification data to be published to the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int CreateRenderModificationPublisher(std::string &errmsg);

        /// Remove the publisher for Render Modification on this module from the DDS network.
        /// @returns 0 if successful.
        int RemoveRenderModificationPublisher();

        /// Remove the publisher for Render Modification on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemoveRenderModificationPublisher(std::string &errmsg);

        /// Create the data subscriber for Render Modification published events on this module.
        /// Allows the module to receive Render Modification data when it is published on the DDS network.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreateRenderModificationSubscriber(
           U *parentClass, void (U::*onEvent)(AMM::RenderModification &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Create the data subscriber for Render Modification published events on this module.
        /// Allows the module to receive Render Modification data when it is published on the DDS network.
        /// @param errmsg Error message output.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreateRenderModificationSubscriber(
           std::string &errmsg, U *parentClass,
           void (U::*onEvent)(AMM::RenderModification &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Remove the subscriber for Render Modification on this module from the DDS network.
        /// @returns 0 if successful.
        int RemoveRenderModificationSubscriber();

        /// Remove the subscriber for Render Modification on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemoveRenderModificationSubscriber(std::string &errmsg);

        /// Call upon the active publisher for Render Modification to write data to the DDS network.
        /// @param a Reference to Render Modification data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WriteRenderModification(AMM::RenderModification &a);

        /// Call upon the active publisher for Render Modification to write data to the DDS network.
        /// @param errmsg Error message output.
        /// @param a Reference to Render Modification data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WriteRenderModification(std::string &errmsg, AMM::RenderModification &a);

        /// Listener Interface override for handling Render Modification subscribed events.
        /// Calls OnEvent on m_renderModification passing along data to the handler defined by
        /// the user in CreateRenderModificationSubscriber.
        /// @see AmmDataType::OnEvent
        /// @see ListenerInterface::onNewRenderModification
        /// @param eventFrag incoming Render Modification data from the DDS network.
        /// @param info FastRTPS sample info.
        void onNewRenderModification(AMM::RenderModification rendMod, eprosima::fastrtps::SampleInfo_t *info) override;

        /// Clean up Render Modification and set it to an inactive state.
        /// Calls Delete on m_renderModification.
        /// @returns 0 if successful.
        int DecommissionRenderModification();

        /// Clean up Render Modification and set it to an inactive state.
        /// Calls Delete on m_renderModification.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int DecommissionRenderModification(std::string &errmsg);

        // - - - Simulation Control - - -

        /// Initializer routine for Simulation Control.
        /// Initializes m_simulationControl with a new AmmDataType pointer.
        /// @returns 0 if successful.
        int InitializeSimulationControl();

        /// Overload initializer routine for Simulation Control.
        /// Initializes m_simulationControl with a new AmmDataType pointer.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int InitializeSimulationControl(std::string &errmsg);

        /// State of whether Simulation Control is currently valid.
        /// @returns True if m_simulationControl is valid pointer.
        bool IsSimulationControlInitialized();

        /// Create the data publisher for Simulation Control on this module.
        /// Allows Simulation Control data to be published to the DDS network.
        /// @returns 0 if successful.
        int CreateSimulationControlPublisher();

        /// Create the data publisher for Eve on this module.
        /// Allows Simulation Control data to be published to the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int CreateSimulationControlPublisher(std::string &errmsg);

        /// Remove the publisher for Simulation Control on this module from the DDS network.
        /// @returns 0 if successful.
        int RemoveSimulationControlPublisher();

        /// Remove the publisher for Simulation Control on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemoveSimulationControlPublisher(std::string &errmsg);

        /// Create the data subscriber for Simulation Control published events on this module.
        /// Allows the module to receive Simulation Control data when it is published on the DDS network.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreateSimulationControlSubscriber(
           U *parentClass, void (U::*onEvent)(AMM::SimulationControl &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Create the data subscriber for Simulation Control published events on this module.
        /// Allows the module to receive Simulation Control data when it is published on the DDS network.
        /// @param errmsg Error message output.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreateSimulationControlSubscriber(
           std::string &errmsg, U *parentClass,
           void (U::*onEvent)(AMM::SimulationControl &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Remove the subscriber for Simulation Control on this module from the DDS network.
        /// @returns 0 if successful.
        int RemoveSimulationControlSubscriber();

        /// Remove the subscriber for Simulation Control on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemoveSimulationControlSubscriber(std::string &errmsg);

        /// Call upon the active publisher for Simulation Control to write data to the DDS network.
        /// @param a Reference to Simulation Control data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WriteSimulationControl(AMM::SimulationControl &a);

        /// Call upon the active publisher for Simulation Control to write data to the DDS network.
        /// @param errmsg Error message output.
        /// @param a Reference to Simulation Control data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WriteSimulationControl(std::string &errmsg, AMM::SimulationControl &a);

        /// Listener Interface override for handling Simulation Control subscribed events.
        /// Calls OnEvent on m_simulationControl passing along data to the handler defined by
        /// the user in CreateSimulationControlSubscriber.
        /// @see AmmDataType::OnEvent
        /// @see ListenerInterface::onNewSimulationControl
        /// @param eventFrag incoming Simulation Control data from the DDS network.
        /// @param info FastRTPS sample info.
        void onNewSimulationControl(AMM::SimulationControl simControl, eprosima::fastrtps::SampleInfo_t *info) override;

        /// Clean up Simulation Control and set it to an inactive state.
        /// Calls Delete on m_simulationControl.
        /// @returns 0 if successful.
        int DecommissionSimulationControl();

        /// Clean up Simulation Control and set it to an inactive state.
        /// Calls Delete on m_simulationControl.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int DecommissionSimulationControl(std::string &errmsg);

        // - - - Status - - -

        /// Initializer routine for Status.
        /// Initializes m_stuatus with a new AmmDataType pointer.
        /// @returns 0 if successful.
        int InitializeStatus();

        /// Overload initializer routine for Status.
        /// Initializes m_status with a new AmmDataType pointer.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int InitializeStatus(std::string &errmsg);

        /// State of whether Status is currently valid.
        /// @returns True if m_status is valid pointer.
        bool IsStatusInitialized();

        /// Create the data publisher for Status on this module.
        /// Allows Status data to be published to the DDS network.
        /// @returns 0 if successful.
        int CreateStatusPublisher();

        /// Create the data publisher for Status on this module.
        /// Allows Status data to be published to the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int CreateStatusPublisher(std::string &errmsg);

        /// Remove the publisher for Status on this module from the DDS network.
        /// @returns 0 if successful.
        int RemoveStatusPublisher();

        /// Remove the publisher for Status on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemoveStatusPublisher(std::string &errmsg);

        /// Create the data subscriber for Status published events on this module.
        /// Allows the module to receive Status data when it is published on the DDS network.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreateStatusSubscriber(
           U *parentClass, void (U::*onEvent)(AMM::Status &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Create the data subscriber for Status published events on this module.
        /// Allows the module to receive Status data when it is published on the DDS network.
        /// @param errmsg Error message output.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreateStatusSubscriber(
           std::string &errmsg, U *parentClass, void (U::*onEvent)(AMM::Status &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Remove the subscriber for Status on this module from the DDS network.
        /// @returns 0 if successful.
        int RemoveStatusSubscriber();

        /// Remove the subscriber for Status on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemoveStatusSubscriber(std::string &errmsg);

        /// Call upon the active publisher for Status to write data to the DDS network.
        /// @param a Reference to Status data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WriteStatus(AMM::Status &a);

        /// Call upon the active publisher for Status to write data to the DDS network.
        /// @param errmsg Error message output.
        /// @param a Reference to Status data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WriteStatus(std::string &errmsg, AMM::Status &a);

        /// Listener Interface override for handling Status subscribed events.
        /// Calls OnEvent on m_status passing along data to the handler defined by
        /// the user in CreateStatusSubscriber.
        /// @see AmmDataType::OnEvent
        /// @see ListenerInterface::onNewStatus
        /// @param status incoming Status data from the DDS network.
        /// @param info FastRTPS sample info.
        void onNewStatus(AMM::Status status, eprosima::fastrtps::SampleInfo_t *info) override;

        /// Clean up Status and set it to an inactive state.
        /// Calls Delete on m_status.
        /// @returns 0 if successful.
        int DecommissionStatus();

        /// Clean up Status and set it to an inactive state.
        /// Calls Delete on m_status.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int DecommissionStatus(std::string &errmsg);

        // - - - Tick - - -

        /// Initializer routine for Tick.
        /// Initializes m_tick with a new AmmDataType pointer.
        /// @returns 0 if successful.
        int InitializeTick();

        /// Overload initializer routine for Tick.
        /// Initializes m_tick with a new AmmDataType pointer.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int InitializeTick(std::string &errmsg);

        /// State of whether Tick is currently valid.
        /// @returns True if m_tick is valid pointer.
        bool IsTickInitialized();

        /// Create the data publisher for Tick on this module.
        /// Allows Tick data to be published to the DDS network.
        /// @returns 0 if successful.
        int CreateTickPublisher();

        /// Create the data publisher for Tick on this module.
        /// Allows Tick data to be published to the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int CreateTickPublisher(std::string &errmsg);

        /// Remove the publisher for Tick on this module from the DDS network.
        /// @returns 0 if successful.
        int RemoveTickPublisher();

        /// Remove the publisher for Tick on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemoveTickPublisher(std::string &errmsg);

        /// Create the data subscriber for Tick published events on this module.
        /// Allows the module to receive Tick data when it is published on the DDS network.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreateTickSubscriber(
           U *parentClass, void (U::*onEvent)(AMM::Tick &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Create the data subscriber for Tick published events on this module.
        /// Allows the module to receive Tick data when it is published on the DDS network.
        /// @param errmsg Error message output.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreateTickSubscriber(
           std::string &errmsg, U *parentClass, void (U::*onEvent)(AMM::Tick &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Remove the subscriber for Tick on this module from the DDS network.
        /// @returns 0 if successful.
        int RemoveTickSubscriber();

        /// Remove the subscriber for Tick on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemoveTickSubscriber(std::string &errmsg);

        /// Call upon the active publisher for Tick to write data to the DDS network.
        /// @param a Reference to Tick data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WriteTick(AMM::Tick &a);

        /// Call upon the active publisher for Tick to write data to the DDS network.
        /// @param errmsg Error message output.
        /// @param a Reference to Tick data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WriteTick(std::string &errmsg, AMM::Tick &a);

        /// Listener Interface override for handling Tick subscribed events.
        /// Calls OnEvent on m_tick passing along data to the handler defined by
        /// the user in CreateTickSubscriber.
        /// @see AmmDataType::OnEvent
        /// @see ListenerInterface::onNewTick
        /// @param tick incoming Tick data from the DDS network.
        /// @param info FastRTPS sample info.
        void onNewTick(AMM::Tick tick, eprosima::fastrtps::SampleInfo_t *info) override;

        /// Clean up Tick and set it to an inactive state.
        /// Calls Delete on m_tick.
        /// @returns 0 if successful.
        int DecommissionTick();

        /// Clean up Tick and set it to an inactive state.
        /// Calls Delete on m_tick.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int DecommissionTick(std::string &errmsg);

        // - - - Instrument Data - - -

        /// Initializer routine for Instrument Data.
        /// Initializes m_instrumentData with a new AmmDataType pointer.
        /// @returns 0 if successful.
        int InitializeInstrumentData();

        /// Overload initializer routine for Instrument Data.
        /// Initializes m_instrumentData with a new AmmDataType pointer.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int InitializeInstrumentData(std::string &errmsg);

        /// State of whether Instrument Data is currently valid.
        /// @returns True if m_instrumentData is valid pointer.
        bool IsInstrumentDataInitialized();

        /// Create the data publisher for Instrument Data on this module.
        /// Allows Instrument Data data to be published to the DDS network.
        /// @returns 0 if successful.
        int CreateInstrumentDataPublisher();

        /// Create the data publisher for Instrument Data on this module.
        /// Allows Instrument Data data to be published to the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int CreateInstrumentDataPublisher(std::string &errmsg);

        /// Remove the publisher for Instrument Data on this module from the DDS network.
        /// @returns 0 if successful.
        int RemoveInstrumentDataPublisher();

        /// Remove the publisher for Instrument Data on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemoveInstrumentDataPublisher(std::string &errmsg);

        /// Create the data subscriber for Instrument Data published events on this module.
        /// Allows the module to receive Instrument Data data when it is published on the DDS network.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreateInstrumentDataSubscriber(
           U *parentClass, void (U::*onEvent)(AMM::InstrumentData &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Create the data subscriber for Instrument Data published events on this module.
        /// Allows the module to receive Instrument Data data when it is published on the DDS network.
        /// @param errmsg Error message output.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreateInstrumentDataSubscriber(
           std::string &errmsg, U *parentClass,
           void (U::*onEvent)(AMM::InstrumentData &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Remove the subscriber for Instrument Data on this module from the DDS network.
        /// @returns 0 if successful.
        int RemoveInstrumentDataSubscriber();

        /// Remove the subscriber for Instrument Data on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemoveInstrumentDataSubscriber(std::string &errmsg);

        /// Call upon the active publisher for Instrument Data to write data to the DDS network.
        /// @param a Reference to Instrument Data data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WriteInstrumentData(AMM::InstrumentData &a);

        /// Call upon the active publisher for Instrument Data to write data to the DDS network.
        /// @param errmsg Error message output.
        /// @param a Reference to Instrument Data data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WriteInstrumentData(std::string &errmsg, AMM::InstrumentData &a);

        /// Listener Interface override for handling Instrument Data subscribed events.
        /// Calls OnEvent on m_instrumentData passing along data to the handler defined by
        /// the user in CreateInstrumentDataSubscriber.
        /// @see AmmDataType::OnEvent
        /// @see ListenerInterface::onNewInstrumentData
        /// @param instData incoming Instrument Data data from the DDS network.
        /// @param info FastRTPS sample info.
        void onNewInstrumentData(AMM::InstrumentData instData, eprosima::fastrtps::SampleInfo_t *info) override;

        /// Clean up Instrument Data and set it to an inactive state.
        /// Calls Delete on m_instrumentData.
        /// @returns 0 if successful.
        int DecommissionInstrumentData();

        /// Clean up Instrument Data and set it to an inactive state.
        /// Calls Delete on m_instrumentData.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int DecommissionInstrumentData(std::string &errmsg);

        // - - - Command - - -

        /// Initializer routine for Command.
        /// Initializes m_command with a new AmmDataType pointer.
        /// @returns 0 if successful.
        int InitializeCommand();

        /// Overload initializer routine for Command.
        /// Initializes m_command with a new AmmDataType pointer.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int InitializeCommand(std::string &errmsg);

        /// State of whether Command is currently valid.
        /// @returns True if m_command is valid pointer.
        bool IsCommandInitialized();

        /// Create the data publisher for Command on this module.
        /// Allows Command data to be published to the DDS network.
        /// @returns 0 if successful.
        int CreateCommandPublisher();

        /// Create the data publisher for Command on this module.
        /// Allows Command data to be published to the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int CreateCommandPublisher(std::string &errmsg);

        /// Remove the publisher for Command on this module from the DDS network.
        /// @returns 0 if successful.
        int RemoveCommandPublisher();

        /// Remove the publisher for Command on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemoveCommandPublisher(std::string &errmsg);

        /// Create the data subscriber for Command published events on this module.
        /// Allows the module to receive Command data when it is published on the DDS network.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreateCommandSubscriber(
           U *parentClass, void (U::*onEvent)(AMM::Command &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Create the data subscriber for Command published events on this module.
        /// Allows the module to receive Command data when it is published on the DDS network.
        /// @param errmsg Error message output.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreateCommandSubscriber(
           std::string &errmsg, U *parentClass, void (U::*onEvent)(AMM::Command &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Remove the subscriber for Command on this module from the DDS network.
        /// @returns 0 if successful.
        int RemoveCommandSubscriber();

        /// Remove the subscriber for Command on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemoveCommandSubscriber(std::string &errmsg);

        /// Call upon the active publisher for Command to write data to the DDS network.
        /// @param a Reference to Command data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WriteCommand(AMM::Command &a);

        /// Call upon the active publisher for Command to write data to the DDS network.
        /// @param errmsg Error message output.
        /// @param a Reference to Command data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WriteCommand(std::string &errmsg, AMM::Command &a);

        /// Listener Interface override for handling Command subscribed events.
        /// Calls OnEvent on m_command passing along data to the handler defined by
        /// the user in CreateCommandSubscriber.
        /// @see AmmDataType::OnEvent
        /// @see ListenerInterface::onNewCommand
        /// @param command incoming Command data from the DDS network.
        /// @param info FastRTPS sample info.
        void onNewCommand(AMM::Command command, eprosima::fastrtps::SampleInfo_t *info) override;

        /// Clean up Command and set it to an inactive state.
        /// Calls Delete on m_command.
        /// @returns 0 if successful.
        int DecommissionCommand();

        /// Clean up Command and set it to an inactive state.
        /// Calls Delete on m_command.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int DecommissionCommand(std::string &errmsg);


    }; // class DDSManager <U>

    template<class U>
    inline DDSManager<U>::DDSManager(std::string configFile) {

       /*eprosima::fastrtps::ParticipantAttributes pa;
   pa.rtps.builtin.domainId = (uint32_t) DOMAIN_ID;
   pa.rtps.setName(moduleName.c_str());*/
       try {
          if (!eprosima::fastrtps::Domain::loadXMLProfilesFile(configFile)) {
             std::cout << "Unable to load XML file to create FastRTPS domain participant." << std::endl;
          }
          m_participant = eprosima::fastrtps::Domain::createParticipant("amm_participant");
       } catch (std::exception &e) {
          std::cerr << e.what() << std::endl;
       }
       if (m_participant == nullptr) {
          std::cout << "Unable to create FastRTPS domain participant." << std::endl;
          return;
       }

       m_pubListener = new DDS_Listeners::PubListener();

       m_moduleId = DDSManager::GenerateUuidString();
       m_moduleName = m_participant->getAttributes().rtps.getName();

    }

    template<class U>
    inline void DDSManager<U>::Shutdown(std::string &errmsg) {
       int err = 0;

       // Output from each decommission.
       std::string localerrmsg;

       if (DecommissionAssessment(localerrmsg) != 0) errmsg + localerrmsg + "\n";
       if (DecommissionEventFragment(localerrmsg) != 0) errmsg + localerrmsg + "\n";
       if (DecommissionEventRecord(localerrmsg) != 0) errmsg + localerrmsg + "\n";
       if (DecommissionFragmentAmendmentRequest(localerrmsg) != 0) errmsg + localerrmsg + "\n";
       if (DecommissionLog(localerrmsg) != 0) errmsg + localerrmsg + "\n";
       if (DecommissionModuleConfiguration(localerrmsg) != 0) errmsg + localerrmsg + "\n";
       if (DecommissionOmittedEvent(localerrmsg) != 0) errmsg + localerrmsg + "\n";
       if (DecommissionOperationalDescription(localerrmsg) != 0) errmsg + localerrmsg + "\n";
       if (DecommissionPhysiologyModification(localerrmsg) != 0) errmsg + localerrmsg + "\n";
       if (DecommissionPhysiologyValue(localerrmsg) != 0) errmsg + localerrmsg + "\n";
       if (DecommissionPhysiologyWaveform(localerrmsg) != 0) errmsg + localerrmsg + "\n";
       if (DecommissionRenderModification(localerrmsg) != 0) errmsg + localerrmsg + "\n";
       if (DecommissionSimulationControl(localerrmsg) != 0) errmsg + localerrmsg + "\n";
       if (DecommissionStatus(localerrmsg) != 0) errmsg + localerrmsg + "\n";
       if (DecommissionTick(localerrmsg) != 0) errmsg + localerrmsg + "\n";
       if (DecommissionInstrumentData(localerrmsg) != 0) errmsg + localerrmsg + "\n";
       if (DecommissionCommand(localerrmsg) != 0) errmsg + localerrmsg + "\n";

       eprosima::fastrtps::Domain::stopAll();
    }

    template<class U>
    inline void DDSManager<U>::Shutdown() {
       DecommissionAssessment();
       DecommissionEventFragment();
       DecommissionEventRecord();
       DecommissionFragmentAmendmentRequest();
       DecommissionLog();
       DecommissionModuleConfiguration();
       DecommissionOmittedEvent();
       DecommissionOperationalDescription();
       DecommissionPhysiologyModification();
       DecommissionPhysiologyValue();
       DecommissionPhysiologyWaveform();
       DecommissionRenderModification();
       DecommissionSimulationControl();
       DecommissionStatus();
       DecommissionTick();
       DecommissionInstrumentData();
       DecommissionCommand();

       eprosima::fastrtps::Domain::stopAll();
    }

    template<class U>
    inline std::string DDSManager<U>::GenerateUuidString() {
       boost::uuids::uuid uuid = boost::uuids::random_generator()();
       return boost::uuids::to_string(uuid);
    }


// - - - Assesment - - -

    template<class U>
    inline int DDSManager<U>::InitializeAssessment() {

       if (m_isAssessmentInit) return 0;

       int err = 0;
       m_assessment = new AmmDataType<ASMT_TYPE, ASMT_LTNR, ASMT, U>(
          err, ASMT_STR, m_participant, m_pubListener
       );

       if (err != 0) return 1;

       m_isAssessmentInit = true;

       return 0;
    }

    template<class U>
    inline int DDSManager<U>::InitializeAssessment(std::string &errmsg) {

       if (m_isAssessmentInit) {
          errmsg = "Assessment is already initialized.";
          return 0;
       }

       int err = 0;
       m_assessment = new AmmDataType<ASMT_TYPE, ASMT_LTNR, ASMT, U>(
          err, errmsg, ASMT_STR, m_participant, m_pubListener
       );

       if (err != 0) return 1;

       m_isAssessmentInit = true;

       return 0;
    }

    template<class U>
    inline bool DDSManager<U>::IsAssessmentInitialized() {
       if (m_isAssessmentInit) return m_assessment->IsTypeRegistered();
       return false;
    }

    template<class U>
    inline int DDSManager<U>::CreateAssessmentPublisher() {
       if (!m_isAssessmentInit) return 0;
       return m_assessment->CreatePublisher();
    }

    template<class U>
    inline int DDSManager<U>::CreateAssessmentPublisher(std::string &errmsg) {
       if (!m_isAssessmentInit) {
          errmsg = "Assessment is not properly initialized";
          return 0;
       }
       return m_assessment->CreatePublisher(errmsg);
    }

    template<class U>
    inline int DDSManager<U>::RemoveAssessmentPublisher() {
       if (!m_isAssessmentInit) return 1;
       return m_assessment->RemovePublisher();
    }

    template<class U>
    inline int DDSManager<U>::RemoveAssessmentPublisher(std::string &errmsg) {
       if (!m_isAssessmentInit) {
          errmsg = "Assessment is not properly initialized";
          return 1;
       }
       return m_assessment->RemovePublisher(errmsg);
    }

    template<class U>
    inline int DDSManager<U>::CreateAssessmentSubscriber(
       U *parentClass, void (U::*onEvent)(AMM::Assessment &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isAssessmentInit) return 1;
       return m_assessment->CreateSubscriber((ListenerInterface *) this, parentClass, onEvent);
    }

    template<class U>
    inline int DDSManager<U>::CreateAssessmentSubscriber(
       std::string &errmsg, U *parentClass, void (U::*onEvent)(AMM::Assessment &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isAssessmentInit) {
          errmsg = "Assessment is not properly initialized";
          return 1;
       }
       return m_assessment->CreateSubscriber(errmsg, (ListenerInterface *) this, parentClass, onEvent);
    }

    template<class U>
    inline int DDSManager<U>::RemoveAssessmentSubscriber() {
       if (!m_isAssessmentInit) return 1;
       return m_assessment->RemoveSubscriber();
    }

    template<class U>
    inline int DDSManager<U>::RemoveAssessmentSubscriber(std::string &errmsg) {
       if (!m_isAssessmentInit) {
          errmsg = "Assessment is not properly initialized";
          return 1;
       }
       return m_assessment->RemoveSubscriber(errmsg);
    }

    template<class U>
    inline int DDSManager<U>::WriteAssessment(AMM::Assessment &a) {
       if (!m_isAssessmentInit) return 1;
       return m_assessment->Write(a);
    }

    template<class U>
    inline int DDSManager<U>::WriteAssessment(std::string &errmsg, AMM::Assessment &a) {
       if (!m_isAssessmentInit) {
          errmsg = "Assessment is not properly initialized.";
          return 1;
       }
       return m_assessment->Write(errmsg, a);
    }

    template<class U>
    inline void DDSManager<U>::onNewAssessment(
       AMM::Assessment assessment, eprosima::fastrtps::SampleInfo_t *info
    ) {
       m_assessment->OnEvent(assessment, info);
    }

    template<class U>
    inline int DDSManager<U>::DecommissionAssessment() {
       if (!m_isAssessmentInit) return 0;

       if (m_assessment->Delete() != 0) return 1;

       m_isAssessmentInit = false;
       return 0;
    }

    template<class U>
    inline int DDSManager<U>::DecommissionAssessment(std::string &errmsg) {
       if (!m_isAssessmentInit) {
          errmsg = "Assessment is already decommissioned.";
          return 0;
       }

       if (m_assessment->Delete(errmsg) != 0) return 1;
       m_isAssessmentInit = false;

       return 0;
    }


// - - - Event Fragment - - -

    template<class U>
    inline int DDSManager<U>::InitializeEventFragment() {

       if (m_isEventFragInit) return 0;

       int err = 0;

       m_eventFragment = new AmmDataType<EVFR_TYPE, EVFR_LTNR, EVFR, U>(
          err, EVFR_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isEventFragInit = true;

       return err;
    }

    template<class U>
    inline int DDSManager<U>::InitializeEventFragment(std::string &errmsg) {

       if (m_isEventFragInit) {
          errmsg = "Event Fragment is already initialized.";
          return 0;
       }

       int err = 0;

       m_eventFragment = new AmmDataType<EVFR_TYPE, EVFR_LTNR, EVFR, U>(
          err, errmsg, EVFR_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isEventFragInit = true;

       return err;
    }

    template<class U>
    inline bool DDSManager<U>::IsEventFragmentInitialzied() {
       if (m_isEventFragInit) return m_eventFragment->IsTypeRegistered();
       return false;
    }

    template<class U>
    inline int DDSManager<U>::CreateEventFragmentPublisher() {
       if (!m_isEventFragInit) return 1;
       return m_eventFragment->CreatePublisher();
    }

    template<class U>
    inline int DDSManager<U>::CreateEventFragmentPublisher(std::string &errmsg) {
       if (!m_isEventFragInit) {
          errmsg = "Event Fragment is not properly initialized.";
          return 1;
       }
       return m_eventFragment->CreatePublisher(errmsg);
    }

    template<class U>
    inline int DDSManager<U>::RemoveEventFragmentPublisher() {
       if (!m_isEventFragInit) return 1;
       return m_eventFragment->RemovePublisher();
    }

    template<class U>
    inline int DDSManager<U>::RemoveEventFragmentPublisher(std::string &errmsg) {
       if (!m_isEventFragInit) {
          errmsg = "Event Fragment is not properly initialized.";
          return 1;
       }
       return m_eventFragment->RemovePublisher(errmsg);
    }

    template<class U>
    inline int DDSManager<U>::CreateEventFragmentSubscriber(
       U *parentClass, void (U::*onEvent)(AMM::EventFragment &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isEventFragInit) return 1;
       return m_eventFragment->CreateSubscriber((ListenerInterface *) this, parentClass, onEvent);
    }

    template<class U>
    inline int DDSManager<U>::CreateEventFragmentSubscriber(
       std::string &errmsg, U *parentClass, void (U::*onEvent)(AMM::EventFragment &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isEventFragInit) {
          errmsg = "Event Fragment is not properly initialized.";
          return 1;
       }
       return m_eventFragment->CreateSubscriber(errmsg, (ListenerInterface *) this, parentClass, onEvent);
    }

    template<class U>
    inline int DDSManager<U>::RemoveEventFragmentSubscriber() {
       if (!m_isEventFragInit) return 1;
       return m_eventFragment->RemoveSubscriber();
    }

    template<class U>
    inline int DDSManager<U>::RemoveEventFragmentSubscriber(std::string &errmsg) {
       if (!m_isEventFragInit) {
          errmsg = "Event Fragment is not properly initialized.";
          return 1;
       }
       return m_eventFragment->RemoveSubscriber(errmsg);
    }

    template<class U>
    inline int DDSManager<U>::WriteEventFragment(AMM::EventFragment &a) {
       if (!m_isEventFragInit) return 1;
       return m_eventFragment->Write(a);
    }

    template<class U>
    inline int DDSManager<U>::WriteEventFragment(std::string &errmsg, AMM::EventFragment &a) {
       if (!m_isEventFragInit) {
          errmsg = "Event Fragment is not properly initialized.";
          return 1;
       }
       return m_eventFragment->Write(errmsg, a);
    }

    template<class U>
    inline void DDSManager<U>::onNewEventFragment(
       AMM::EventFragment eventFragment, eprosima::fastrtps::SampleInfo_t *info
    ) {
       m_eventFragment->OnEvent(eventFragment, info);
    }

    template<class U>
    inline int DDSManager<U>::DecommissionEventFragment() {
       if (!m_isEventFragInit) return 0;

       int err = m_eventFragment->Delete();
       if (err == 0) m_isEventFragInit = false;

       return err;
    }

    template<class U>
    inline int DDSManager<U>::DecommissionEventFragment(std::string &errmsg) {
       if (!m_isEventFragInit) {
          errmsg = "Event Fragment is already decommissioned.";
          return 0;
       }

       int err = m_eventFragment->Delete(errmsg);
       if (err == 0) m_isEventFragInit = false;

       return err;
    }


// - - - Event Record - - -

    template<class U>
    inline int DDSManager<U>::InitializeEventRecord() {

       if (m_isEventFragInit) return 0;

       int err = 0;

       m_eventRecord = new AmmDataType<EVRC_TYPE, EVRC_LTNR, EVRC, U>(
          err, EVRC_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isEventRecInit = true;

       return err;
    }

    template<class U>
    inline int DDSManager<U>::InitializeEventRecord(std::string &errmsg) {

       if (m_isEventRecInit) {
          errmsg = "Event Record is already initialized.";
          return 0;
       }

       int err = 0;

       m_eventRecord = new AmmDataType<EVRC_TYPE, EVRC_LTNR, EVRC, U>(
          err, errmsg, EVRC_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isEventRecInit = true;

       return err;
    }

    template<class U>
    inline bool DDSManager<U>::IsEventRecordInitialized() {
       if (m_isEventRecInit) return m_eventRecord->IsTypeRegistered();
       return false;
    }

    template<class U>
    inline int DDSManager<U>::CreateEventRecordPublisher() {
       if (!m_isEventRecInit) return 1;
       return m_eventRecord->CreatePublisher();
    }

    template<class U>
    inline int DDSManager<U>::CreateEventRecordPublisher(std::string &errmsg) {
       if (!m_isEventRecInit) {
          errmsg = "Event Record is not properly initialized.";
          return 1;
       }
       return m_eventRecord->CreatePublisher(errmsg);
    }

    template<class U>
    inline int DDSManager<U>::RemoveEventRecordPublisher() {
       if (!m_isEventRecInit) return 1;
       return m_eventRecord->RemovePublisher();
    }

    template<class U>
    inline int DDSManager<U>::RemoveEventRecordPublisher(std::string &errmsg) {
       if (!m_isEventRecInit) {
          errmsg = "Event Record is not properly initialized.";
          return 1;
       }
       return m_eventRecord->RemovePublisher(errmsg);
    }

    template<class U>
    inline int DDSManager<U>::CreateEventRecordSubscriber(
       U *parentClass, void (U::*onEvent)(AMM::EventRecord &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isEventRecInit) return 1;
       return m_eventRecord->CreateSubscriber((ListenerInterface *) this, parentClass, onEvent);
    }

    template<class U>
    inline int DDSManager<U>::CreateEventRecordSubscriber(
       std::string &errmsg, U *parentClass, void (U::*onEvent)(AMM::EventRecord &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isEventRecInit) {
          errmsg = "Event Record is not properly initialized.";
          return 1;
       }
       return m_eventRecord->CreateSubscriber(errmsg, (ListenerInterface *) this, parentClass, onEvent);
    }

    template<class U>
    inline int DDSManager<U>::RemoveEventRecordSubscriber(std::string &errmsg) {
       if (!m_isEventRecInit) {
          errmsg = "Event Record is not properly initialized.";
          return 1;
       }
       return m_eventRecord->RemoveSubscriber(errmsg);
    }

    template<class U>
    inline int DDSManager<U>::RemoveEventRecordSubscriber() {
       if (!m_isEventRecInit) return 1;
       return m_eventRecord->RemoveSubscriber();
    }

    template<class U>
    inline int DDSManager<U>::WriteEventRecord(AMM::EventRecord &a) {
       if (!m_isEventRecInit) return 1;
       return m_eventRecord->Write(a);
    }

    template<class U>
    inline int DDSManager<U>::WriteEventRecord(std::string &errmsg, AMM::EventRecord &a) {
       if (!m_isEventRecInit) {
          errmsg = "Event Record is not properly initialized.";
          return 1;
       }
       return m_eventRecord->Write(errmsg, a);
    }

    template<class U>
    inline void DDSManager<U>::onNewEventRecord(
       AMM::EventRecord eventRecord, eprosima::fastrtps::SampleInfo_t *info
    ) {
       m_eventRecord->OnEvent(eventRecord, info);
    }

    template<class U>
    inline int DDSManager<U>::DecommissionEventRecord() {
       if (!m_isEventRecInit) return 0;

       int err = m_eventRecord->Delete();
       if (err == 0) { m_isEventRecInit = false; }

       return err;
    }

    template<class U>
    inline int DDSManager<U>::DecommissionEventRecord(std::string &errmsg) {
       if (!m_isEventRecInit) {
          errmsg = "Event Record is already decommissioned.";
          return 0;
       }

       int err = m_eventRecord->Delete(errmsg);
       if (err == 0) m_isEventRecInit = false;

       return err;
    }


// - - - Fragment Amendment Request - - -

    template<class U>
    inline int DDSManager<U>::InitializeFragmentAmendmentRequest() {

       if (m_isFragAmendReqInit) return 0;

       int err = 0;

       m_fragmentAmendmentRequest = new AmmDataType<FARQ_TYPE, FARQ_LTNR, FARQ, U>(
          err, FARQ_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isFragAmendReqInit = true;

       return err;
    }

    template<class U>
    inline int DDSManager<U>::InitializeFragmentAmendmentRequest(std::string &errmsg) {

       if (m_isFragAmendReqInit) {
          errmsg = "Fragment Amendment Request is already initialized.";
          return 0;
       }

       int err = 0;

       m_fragmentAmendmentRequest = new AmmDataType<FARQ_TYPE, FARQ_LTNR, FARQ, U>(
          err, errmsg, FARQ_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isFragAmendReqInit = true;

       return err;
    }

    template<class U>
    inline bool DDSManager<U>::IsFragmentAmendmentRequestInitialized() {
       if (m_isFragAmendReqInit) return m_fragmentAmendmentRequest->IsTypeRegistered();
       return false;
    }

    template<class U>
    inline int DDSManager<U>::CreateFragmentAmendmentRequestPublisher() {
       if (!m_isFragAmendReqInit) return 1;
       return m_fragmentAmendmentRequest->CreatePublisher();
    }

    template<class U>
    inline int DDSManager<U>::CreateFragmentAmendmentRequestPublisher(std::string &errmsg) {
       if (!m_isFragAmendReqInit) {
          errmsg = "Fragment Amendment Request is not properly initialized.";
          return 1;
       }
       return m_fragmentAmendmentRequest->CreatePublisher(errmsg);
    }

    template<class U>
    inline int DDSManager<U>::RemoveFragmentAmendmentRequestPublisher() {
       if (!m_isFragAmendReqInit) return 1;
       return m_fragmentAmendmentRequest->RemovePublisher();
    }

    template<class U>
    inline int DDSManager<U>::RemoveFragmentAmendmentRequestPublisher(std::string &errmsg) {
       if (!m_isFragAmendReqInit) {
          errmsg = "Fragment Amendment Request is not properly initialized.";
          return 1;
       }
       return m_fragmentAmendmentRequest->RemovePublisher(errmsg);
    }

    template<class U>
    inline int DDSManager<U>::CreateFragmentAmendmentRequestSubscriber(
       U *parentClass, void (U::*onEvent)(AMM::FragmentAmendmentRequest &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isFragAmendReqInit) return 1;
       return m_fragmentAmendmentRequest->CreateSubscriber((ListenerInterface *) this, parentClass, onEvent);
    }

    template<class U>
    inline int DDSManager<U>::CreateFragmentAmendmentRequestSubscriber(
       std::string &errmsg, U *parentClass,
       void (U::*onEvent)(AMM::FragmentAmendmentRequest &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isFragAmendReqInit) {
          errmsg = "Fragment Amendment Request is not properly initialized.";
          return 1;
       }
       return m_fragmentAmendmentRequest->CreateSubscriber(errmsg, (ListenerInterface *) this, parentClass, onEvent);
    }

    template<class U>
    inline int DDSManager<U>::RemoveFragmentAmendmentRequestSubscriber() {
       return m_fragmentAmendmentRequest->RemoveSubscriber();
    }

    template<class U>
    inline int DDSManager<U>::RemoveFragmentAmendmentRequestSubscriber(std::string &errmsg) {
       if (!m_isFragAmendReqInit) {
          errmsg = "Fragment Amendment Request is not properly initialized.";
          return 1;
       }
       return m_fragmentAmendmentRequest->RemoveSubscriber(errmsg);
    }

    template<class U>
    inline int DDSManager<U>::WriteFragmentAmendmentRequest(AMM::FragmentAmendmentRequest &a) {
       if (!m_isFragAmendReqInit) return 1;
       return m_fragmentAmendmentRequest->Write(a);
    }

    template<class U>
    inline int DDSManager<U>::WriteFragmentAmendmentRequest(std::string &errmsg, AMM::FragmentAmendmentRequest &a) {
       if (!m_isFragAmendReqInit) {
          errmsg = "Fragment Amendment Request is not properly initialized.";
          return 1;
       }
       return m_fragmentAmendmentRequest->Write(errmsg, a);
    }

    template<class U>
    inline void DDSManager<U>::onNewFragmentAmendmentRequest(
       AMM::FragmentAmendmentRequest ffar, eprosima::fastrtps::SampleInfo_t *info
    ) {
       m_fragmentAmendmentRequest->OnEvent(ffar, info);
    }

    template<class U>
    inline int DDSManager<U>::DecommissionFragmentAmendmentRequest() {
       if (!m_isFragAmendReqInit) return 0;

       int err = m_fragmentAmendmentRequest->Delete();
       if (err == 0) m_isFragAmendReqInit = false;

       return err;
    }

    template<class U>
    inline int DDSManager<U>::DecommissionFragmentAmendmentRequest(std::string &errmsg) {
       if (!m_isFragAmendReqInit) {
          errmsg = "Fragment Amendment Request is already decommissioned.";
          return 0;
       }

       int err = m_fragmentAmendmentRequest->Delete(errmsg);
       if (err == 0) m_isFragAmendReqInit = false;

       return err;
    }


// - - - Log - - -

    template<class U>
    inline int DDSManager<U>::InitializeLog() {

       if (m_isLogInit) return 0;

       int err = 0;

       m_log = new AmmDataType<ALOG_TYPE, ALOG_LTNR, ALOG, U>(
          err, ALOG_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isLogInit = true;

       return err;
    }

    template<class U>
    inline int DDSManager<U>::InitializeLog(std::string &errmsg) {

       if (m_isLogInit) {
          errmsg = "Log is already initialized.";
          return 0;
       }

       int err = 0;

       m_log = new AmmDataType<ALOG_TYPE, ALOG_LTNR, ALOG, U>(
          err, errmsg, ALOG_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isLogInit = true;

       return err;
    }

    template<class U>
    inline bool DDSManager<U>::IsLogInitialized() {
       if (m_isLogInit) return m_log->IsTypeRegistered();
       return false;
    }

    template<class U>
    inline int DDSManager<U>::CreateLogPublisher() {
       if (!m_isLogInit) return 1;
       return m_log->CreatePublisher();
    }

    template<class U>
    inline int DDSManager<U>::CreateLogPublisher(std::string &errmsg) {
       if (!m_isLogInit) {
          errmsg = "Log is not properly initialized.";
          return 1;
       }
       return m_log->CreatePublisher(errmsg);
    }

    template<class U>
    inline int DDSManager<U>::RemoveLogPublisher() {
       if (!m_isLogInit) return 1;
       return m_log->RemovePublisher();
    }

    template<class U>
    inline int DDSManager<U>::RemoveLogPublisher(std::string &errmsg) {
       if (!m_isLogInit) {
          errmsg = "Log is not properly initialized.";
          return 1;
       }
       return m_log->RemovePublisher(errmsg);
    }

    template<class U>
    inline int DDSManager<U>::CreateLogSubscriber(
       U *parentClass, void (U::*onEvent)(AMM::Log &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isLogInit) return 1;
       return m_log->CreateSubscriber((ListenerInterface *) this, parentClass, onEvent);
    }

    template<class U>
    inline int DDSManager<U>::CreateLogSubscriber(
       std::string &errmsg, U *parentClass, void (U::*onEvent)(AMM::Log &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isLogInit) {
          errmsg = "Log is not properly initialized.";
          return 1;
       }
       return m_log->CreateSubscriber(errmsg, (ListenerInterface *) this, parentClass, onEvent);
    }

    template<class U>
    inline int DDSManager<U>::RemoveLogSubscriber() {
       if (!m_isLogInit) return 1;
       return m_log->RemoveSubscriber();
    }

    template<class U>
    inline int DDSManager<U>::RemoveLogSubscriber(std::string &errmsg) {
       if (!m_isLogInit) {
          errmsg = "Log is not properly initialized.";
          return 1;
       }
       return m_log->RemoveSubscriber(errmsg);
    }

    template<class U>
    inline int DDSManager<U>::WriteLog(AMM::Log &a) {
       if (!m_isLogInit) return 1;
       return m_log->Write(a);
    }

    template<class U>
    inline int DDSManager<U>::WriteLog(std::string &errmsg, AMM::Log &a) {
       if (!m_isLogInit) {
          errmsg = "Log is not properly initialized.";
          return 1;
       }
       return m_log->Write(errmsg, a);
    }

    template<class U>
    inline void DDSManager<U>::onNewLog(
       AMM::Log log, eprosima::fastrtps::SampleInfo_t *info
    ) {
       m_log->OnEvent(log, info);
    }

    template<class U>
    inline int DDSManager<U>::DecommissionLog() {
       if (!m_isLogInit) return 0;

       int err = m_log->Delete();
       if (err == 0) m_isLogInit = false;

       return err;
    }

    template<class U>
    inline int DDSManager<U>::DecommissionLog(std::string &errmsg) {
       if (!m_isLogInit) {
          errmsg = "Log is already decommissioned.";
          return 0;
       }

       int err = m_log->Delete(errmsg);
       if (err == 0) m_isLogInit = false;

       return err;
    }


// - - - Module Configuration - - -

    template<class U>
    inline int DDSManager<U>::InitializeModuleConfiguration() {

       if (m_isModConfigInit) return 0;

       int err = 0;

       m_moduleConfiguration = new AmmDataType<MOCF_TYPE, MOCF_LTNR, MOCF, U>(
          err, MOCF_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isModConfigInit = true;

       return err;
    }

    template<class U>
    inline int DDSManager<U>::InitializeModuleConfiguration(std::string &errmsg) {

       if (m_isModConfigInit) {
          errmsg = "Module Configuration is already initialized.";
          return 0;
       }

       int err = 0;

       m_moduleConfiguration = new AmmDataType<MOCF_TYPE, MOCF_LTNR, MOCF, U>(
          err, errmsg, MOCF_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isModConfigInit = true;

       return err;
    }

    template<class U>
    inline bool DDSManager<U>::IsModuleConfigurationInitialized() {
       if (m_isModConfigInit) return m_moduleConfiguration->IsTypeRegistered();
       return false;
    }

    template<class U>
    inline int DDSManager<U>::CreateModuleConfigurationPublisher() {
       if (!m_isModConfigInit) return 1;
       return m_moduleConfiguration->CreatePublisher();
    }

    template<class U>
    inline int DDSManager<U>::CreateModuleConfigurationPublisher(std::string &errmsg) {
       if (!m_isModConfigInit) {
          errmsg = "Module Configuration is not properly initialized.";
          return 1;
       }
       return m_moduleConfiguration->CreatePublisher(errmsg);
    }

    template<class U>
    inline int DDSManager<U>::RemoveModuleConfigurationPublisher() {
       if (!m_isModConfigInit) return 1;
       return m_moduleConfiguration->RemovePublisher();
    }

    template<class U>
    inline int DDSManager<U>::RemoveModuleConfigurationPublisher(std::string &errmsg) {
       if (!m_isModConfigInit) {
          errmsg = "Module Configuration is not properly initialized.";
          return 1;
       }
       return m_moduleConfiguration->RemovePublisher(errmsg);
    }

    template<class U>
    inline int DDSManager<U>::CreateModuleConfigurationSubscriber(
       U *parentClass, void (U::*onEvent)(AMM::ModuleConfiguration &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isModConfigInit) return 1;
       return m_moduleConfiguration->CreateSubscriber((ListenerInterface *) this, parentClass, onEvent);
    }

    template<class U>
    inline int DDSManager<U>::CreateModuleConfigurationSubscriber(
       std::string &errmsg, U *parentClass,
       void (U::*onEvent)(AMM::ModuleConfiguration &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isModConfigInit) {
          errmsg = "Module Configuration is not properly initialized.";
          return 1;
       }
       return m_moduleConfiguration->CreateSubscriber(errmsg, (ListenerInterface *) this, parentClass, onEvent);
    }

    template<class U>
    inline int DDSManager<U>::RemoveModuleConfigurationSubscriber() {
       if (!m_isModConfigInit) return 1;
       return m_moduleConfiguration->RemoveSubscriber();
    }

    template<class U>
    inline int DDSManager<U>::RemoveModuleConfigurationSubscriber(std::string &errmsg) {
       if (!m_isModConfigInit) {
          errmsg = "Module Configuration is not properly initialized.";
          return 1;
       }
       return m_moduleConfiguration->RemoveSubscriber(errmsg);
    }

    template<class U>
    inline int DDSManager<U>::WriteModuleConfiguration(AMM::ModuleConfiguration &a) {
       if (!m_isModConfigInit) return 1;
       return m_moduleConfiguration->Write(a);
    }

    template<class U>
    inline int DDSManager<U>::WriteModuleConfiguration(std::string &errmsg, AMM::ModuleConfiguration &a) {
       if (!m_isModConfigInit) {
          errmsg = "Module Configuration is not properly initialized.";
          return 1;
       }
       return m_moduleConfiguration->Write(errmsg, a);
    }

    template<class U>
    inline void DDSManager<U>::onNewModuleConfiguration(
       AMM::ModuleConfiguration modConfig, eprosima::fastrtps::SampleInfo_t *info
    ) {
       m_moduleConfiguration->OnEvent(modConfig, info);
    }

    template<class U>
    inline int DDSManager<U>::DecommissionModuleConfiguration() {
       if (!m_isModConfigInit) return 0;

       int err = m_moduleConfiguration->Delete();
       if (err == 0) m_isModConfigInit = false;

       return err;
    }

    template<class U>
    inline int DDSManager<U>::DecommissionModuleConfiguration(std::string &errmsg) {
       if (!m_isModConfigInit) {
          errmsg = "Module Configuration is already decommissioned.";
          return 0;
       }

       int err = m_moduleConfiguration->Delete(errmsg);
       if (err == 0) m_isModConfigInit = false;

       return err;
    }


// - - - Omitted Event - - -

    template<class U>
    inline int DDSManager<U>::InitializeOmittedEvent() {

       if (m_isOmitEventInit) return 0;

       int err = 0;

       m_omittedEvent = new AmmDataType<OMEV_TYPE, OMEV_LTNR, OMEV, U>(
          err, OMEV_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isOmitEventInit = true;

       return err;
    }

    template<class U>
    inline int DDSManager<U>::InitializeOmittedEvent(std::string &errmsg) {

       if (m_isOmitEventInit) {
          errmsg = "Omitted Event is already initialized.";
          return 0;
       }

       int err = 0;

       m_omittedEvent = new AmmDataType<OMEV_TYPE, OMEV_LTNR, OMEV, U>(
          err, errmsg, OMEV_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isOmitEventInit = true;

       return err;
    }

    template<class U>
    inline bool DDSManager<U>::IsOmittedEventInitialized() {
       if (m_isOmitEventInit) m_omittedEvent->IsTypeRegistered();
       return false;
    }

    template<class U>
    inline int DDSManager<U>::CreateOmittedEventPublisher() {
       if (!m_isOmitEventInit) return 1;
       return m_omittedEvent->CreatePublisher();
    }

    template<class U>
    inline int DDSManager<U>::CreateOmittedEventPublisher(std::string &errmsg) {
       if (!m_isOmitEventInit) {
          errmsg = "Omitted Event is not properly initialized.";
          return 1;
       }
       return m_omittedEvent->CreatePublisher(errmsg);
    }

    template<class U>
    inline int DDSManager<U>::RemoveOmittedEventPublisher() {
       if (!m_isOmitEventInit) return 1;
       return m_omittedEvent->RemovePublisher();
    }

    template<class U>
    inline int DDSManager<U>::RemoveOmittedEventPublisher(std::string &errmsg) {
       if (!m_isOmitEventInit) {
          errmsg = "Omitted Event is not properly initialized.";
          return 1;
       }
       return m_omittedEvent->RemovePublisher(errmsg);
    }

    template<class U>
    inline int DDSManager<U>::CreateOmittedEventSubscriber(
       U *parentClass, void (U::*onEvent)(AMM::OmittedEvent &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isOmitEventInit) return 1;
       return m_omittedEvent->CreateSubscriber((ListenerInterface *) this, parentClass, onEvent);
    }

    template<class U>
    inline int DDSManager<U>::CreateOmittedEventSubscriber(
       std::string &errmsg, U *parentClass, void (U::*onEvent)(AMM::OmittedEvent &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isOmitEventInit) {
          errmsg = "Omitted Event is not properly initialized.";
          return 1;
       }
       return m_omittedEvent->CreateSubscriber(errmsg, (ListenerInterface *) this, parentClass, onEvent);
    }

    template<class U>
    inline int DDSManager<U>::RemoveOmittedEventSubscriber() {
       if (!m_isOmitEventInit) return 1;
       return m_omittedEvent->RemoveSubscriber();
    }

    template<class U>
    inline int DDSManager<U>::RemoveOmittedEventSubscriber(std::string &errmsg) {
       if (!m_isOmitEventInit) {
          errmsg = "Omitted Event is not properly initialized.";
          return 1;
       }
       return m_omittedEvent->RemoveSubscriber(errmsg);
    }

    template<class U>
    inline int DDSManager<U>::WriteOmittedEvent(AMM::OmittedEvent &a) {
       if (!m_isOmitEventInit) return 1;
       return m_omittedEvent->Write(a);
    }

    template<class U>
    inline int DDSManager<U>::WriteOmittedEvent(std::string &errmsg, AMM::OmittedEvent &a) {
       if (!m_isOmitEventInit) {
          errmsg = "Omitted Event is not properly initialized.";
          return 1;
       }
       return m_omittedEvent->Write(errmsg, a);
    }

    template<class U>
    inline void DDSManager<U>::onNewOmittedEvent(
       AMM::OmittedEvent omittedEvent, eprosima::fastrtps::SampleInfo_t *info
    ) {
       m_omittedEvent->OnEvent(omittedEvent, info);
    }

    template<class U>
    inline int DDSManager<U>::DecommissionOmittedEvent() {
       if (!m_isOmitEventInit) return 0;

       int err = m_omittedEvent->Delete();
       if (err == 0) m_isOmitEventInit = false;

       return err;
    }

    template<class U>
    inline int DDSManager<U>::DecommissionOmittedEvent(std::string &errmsg) {
       if (!m_isOmitEventInit) {
          errmsg = "Omitted Event is already decommissioned.";
          return 0;
       }

       int err = m_omittedEvent->Delete(errmsg);
       if (err == 0) m_isOmitEventInit = false;

       return err;
    }


// - - - Operational Description - - -

    template<class U>
    inline int DDSManager<U>::InitializeOperationalDescription() {

       if (m_isOpDescriptInit) return 0;

       int err = 0;

       m_operationalDescription = new AmmDataType<OPDS_TYPE, OPDS_LTNR, OPDS, U>(
          err, OPDS_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isOpDescriptInit = true;

       return err;
    }

    template<class U>
    inline int DDSManager<U>::InitializeOperationalDescription(std::string &errmsg) {

       if (m_isOpDescriptInit) {
          errmsg = "Operational Description is already initialized.";
          return 0;
       }

       int err = 0;

       m_operationalDescription = new AmmDataType<OPDS_TYPE, OPDS_LTNR, OPDS, U>(
          err, errmsg, OPDS_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isOpDescriptInit = true;

       return err;
    }

    template<class U>
    inline bool DDSManager<U>::IsOperationalDescriptionInitialized() {
       if (m_isOpDescriptInit) return m_operationalDescription->IsTypeRegistered();
       return false;
    }

    template<class U>
    inline int DDSManager<U>::CreateOperationalDescriptionPublisher() {
       if (!m_isOpDescriptInit) return 1;
       return m_operationalDescription->CreatePublisher();
    }

    template<class U>
    inline int DDSManager<U>::CreateOperationalDescriptionPublisher(std::string &errmsg) {
       if (!m_isOpDescriptInit) {
          errmsg = "Operational Description is not properly initialized.";
          return 1;
       }
       return m_operationalDescription->CreatePublisher(errmsg);
    }

    template<class U>
    inline int DDSManager<U>::RemoveOperationalDescriptionPublisher() {
       if (!m_isOpDescriptInit) return 1;
       return m_operationalDescription->RemovePublisher();
    }

    template<class U>
    inline int DDSManager<U>::RemoveOperationalDescriptionPublisher(std::string &errmsg) {
       if (!m_isOpDescriptInit) {
          errmsg = "Operational Description is not properly initialized.";
          return 1;
       }
       return m_operationalDescription->RemovePublisher(errmsg);
    }

    template<class U>
    inline int DDSManager<U>::CreateOperationalDescriptionSubscriber(
       U *parentClass, void (U::*onEvent)(AMM::OperationalDescription &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isOpDescriptInit) return 1;
       return m_operationalDescription->CreateSubscriber((ListenerInterface *) this, parentClass, onEvent);
    }

    template<class U>
    inline int DDSManager<U>::CreateOperationalDescriptionSubscriber(
       std::string &errmsg, U *parentClass,
       void (U::*onEvent)(AMM::OperationalDescription &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isOpDescriptInit) {
          errmsg = "Operational Description is not properly initialized.";
          return 1;
       }
       return m_operationalDescription->CreateSubscriber(errmsg, (ListenerInterface *) this, parentClass, onEvent);
    }

    template<class U>
    inline int DDSManager<U>::RemoveOperationalDescriptionSubscriber() {
       if (!m_isOpDescriptInit) return 1;
       return m_operationalDescription->RemoveSubscriber();
    }

    template<class U>
    inline int DDSManager<U>::RemoveOperationalDescriptionSubscriber(std::string &errmsg) {
       if (!m_isOpDescriptInit) {
          errmsg = "Operational Description is not properly initialized.";
          return 1;
       }
       return m_operationalDescription->RemoveSubscriber(errmsg);
    }

    template<class U>
    inline int DDSManager<U>::WriteOperationalDescription(AMM::OperationalDescription &a) {
       if (!m_isOpDescriptInit) return 1;
       return m_operationalDescription->Write(a);
    }

    template<class U>
    inline int DDSManager<U>::WriteOperationalDescription(std::string &errmsg, AMM::OperationalDescription &a) {
       if (!m_isOpDescriptInit) {
          errmsg = "Operational Description is not properly initialized.";
          return 1;
       }
       return m_operationalDescription->Write(errmsg, a);
    }

    template<class U>
    inline void DDSManager<U>::onNewOperationalDescription(
       AMM::OperationalDescription opDescript, eprosima::fastrtps::SampleInfo_t *info
    ) {
       m_operationalDescription->OnEvent(opDescript, info);
    }

    template<class U>
    inline int DDSManager<U>::DecommissionOperationalDescription() {
       if (!m_isOpDescriptInit) return 0;

       int err = m_operationalDescription->Delete();
       if (err == 0) m_isOpDescriptInit = false;

       return err;
    }

    template<class U>
    inline int DDSManager<U>::DecommissionOperationalDescription(std::string &errmsg) {
       if (!m_isOpDescriptInit) {
          errmsg = "Operational Description is already decommissed.";
          return 0;
       }

       int err = m_operationalDescription->Delete(errmsg);
       if (err == 0) m_isOpDescriptInit = false;

       return err;
    }


// - - - Physiology Modification - - -

    template<class U>
    inline int DDSManager<U>::InitializePhysiologyModification() {

       if (m_isPhysModInit) return 0;

       int err = 0;

       m_physiologyModification = new AmmDataType<PHMO_TYPE, PHMO_LTNR, PHMO, U>(
          err, PHMO_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isPhysModInit = true;

       return err;
    }

    template<class U>
    inline int DDSManager<U>::InitializePhysiologyModification(std::string &errmsg) {

       if (m_isPhysModInit) {
          errmsg = "Physiology Modification is already initialized.";
          return 0;
       }

       int err = 0;

       m_physiologyModification = new AmmDataType<PHMO_TYPE, PHMO_LTNR, PHMO, U>(
          err, errmsg, PHMO_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isPhysModInit = true;

       return err;
    }

    template<class U>
    inline bool DDSManager<U>::IsPhysiologyModificationInitialized() {
       if (m_isPhysModInit) return m_physiologyModification->IsTypeRegistered();
       return false;
    }

    template<class U>
    inline int DDSManager<U>::CreatePhysiologyModificationPublisher() {
       if (!m_isPhysModInit) return 1;
       return m_physiologyModification->CreatePublisher();
    }

    template<class U>
    inline int DDSManager<U>::CreatePhysiologyModificationPublisher(std::string &errmsg) {
       if (!m_isPhysModInit) {
          errmsg = "Physiology Modification is not properly initialized.";
          return 1;
       }
       return m_physiologyModification->CreatePublisher(errmsg);
    }

    template<class U>
    inline int DDSManager<U>::RemovePhysiologyModificationPublisher() {
       if (!m_isPhysModInit) return 1;
       return m_physiologyModification->RemovePublisher();
    }

    template<class U>
    inline int DDSManager<U>::RemovePhysiologyModificationPublisher(std::string &errmsg) {
       if (!m_isPhysModInit) {
          errmsg = "Physiology Modification is not properly initialized.";
          return 1;
       }
       return m_physiologyModification->RemovePublisher(errmsg);
    }

    template<class U>
    inline int DDSManager<U>::CreatePhysiologyModificationSubscriber(
       U *parentClass, void (U::*onEvent)(AMM::PhysiologyModification &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isPhysModInit) return 1;
       return m_physiologyModification->CreateSubscriber((ListenerInterface *) this, parentClass, onEvent);
    }

    template<class U>
    inline int DDSManager<U>::CreatePhysiologyModificationSubscriber(
       std::string &errmsg, U *parentClass,
       void (U::*onEvent)(AMM::PhysiologyModification &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isPhysModInit) {
          errmsg = "Physiology Modification is not properly initialized.";
          return 1;
       }
       return m_physiologyModification->CreateSubscriber(errmsg, (ListenerInterface *) this, parentClass, onEvent);
    }

    template<class U>
    inline int DDSManager<U>::RemovePhysiologyModificationSubscriber() {
       if (!m_isPhysModInit) return 1;
       return m_physiologyModification->RemoveSubscriber();
    }

    template<class U>
    inline int DDSManager<U>::RemovePhysiologyModificationSubscriber(std::string &errmsg) {
       if (!m_isPhysModInit) {
          errmsg = "Physiology Modification is not properly initialized.";
          return 1;
       }
       return m_physiologyModification->RemoveSubscriber(errmsg);
    }

    template<class U>
    inline int DDSManager<U>::WritePhysiologyModification(AMM::PhysiologyModification &a) {
       if (!m_isPhysModInit) return 1;
       return m_physiologyModification->Write(a);
    }

    template<class U>
    inline int DDSManager<U>::WritePhysiologyModification(std::string &errmsg, AMM::PhysiologyModification &a) {
       if (!m_isPhysModInit) {
          errmsg = "Physiology Modification is not properly initialized.";
          return 1;
       }
       return m_physiologyModification->Write(errmsg, a);
    }

    template<class U>
    inline void DDSManager<U>::onNewPhysiologyModification(
       AMM::PhysiologyModification physMod, eprosima::fastrtps::SampleInfo_t *info
    ) {
       m_physiologyModification->OnEvent(physMod, info);
    }

    template<class U>
    inline int DDSManager<U>::DecommissionPhysiologyModification() {
       if (!m_isPhysModInit) return 0;
       int err = m_physiologyModification->Delete();
       if (err == 0) { m_isPhysModInit = false; }

       return err;
    }

    template<class U>
    inline int DDSManager<U>::DecommissionPhysiologyModification(std::string &errmsg) {
       if (!m_isPhysModInit) {
          errmsg = "Physiology Modification is already decommissioned.";
          return 0;
       }

       int err = m_physiologyModification->Delete(errmsg);
       if (err == 0) m_isPhysModInit = false;

       return err;
    }


// - - - Physiology Value - - -

    template<class U>
    inline int DDSManager<U>::InitializePhysiologyValue() {

       if (m_isPhysValInit) return 0;

       int err = 0;

       m_physiologyValue = new AmmDataType<PHVA_TYPE, PHVA_LTNR, PHVA, U>(
          err, PHVA_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isPhysValInit = true;

       return err;
    }

    template<class U>
    inline int DDSManager<U>::InitializePhysiologyValue(std::string &errmsg) {

       if (m_isPhysValInit) {
          errmsg = "Physiology Value is already initialized.";
          return 0;
       }

       int err = 0;

       m_physiologyValue = new AmmDataType<PHVA_TYPE, PHVA_LTNR, PHVA, U>(
          err, errmsg, PHVA_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isPhysValInit = true;

       return err;
    }

    template<class U>
    inline bool DDSManager<U>::IsPhysiologyValueInitialized() {
       if (m_isPhysValInit) return m_physiologyValue->IsTypeRegistered();
       return false;
    }

    template<class U>
    inline int DDSManager<U>::CreatePhysiologyValuePublisher() {
       if (!m_isPhysValInit) return 1;
       return m_physiologyValue->CreatePublisher();
    }

    template<class U>
    inline int DDSManager<U>::CreatePhysiologyValuePublisher(std::string &errmsg) {
       if (!m_isPhysValInit) {
          errmsg = "Physiology Value is not properly initialized.";
          return 1;
       }
       return m_physiologyValue->CreatePublisher(errmsg);
    }

    template<class U>
    inline int DDSManager<U>::RemovePhysiologyValuePublisher() {
       if (!m_isPhysValInit) return 1;
       return m_physiologyValue->RemovePublisher();
    }

    template<class U>
    inline int DDSManager<U>::RemovePhysiologyValuePublisher(std::string &errmsg) {
       if (!m_isPhysValInit) {
          errmsg = "Physiology Value is not properly initialized.";
          return 1;
       }
       return m_physiologyValue->RemovePublisher(errmsg);
    }

    template<class U>
    inline int DDSManager<U>::CreatePhysiologyValueSubscriber(
       U *parentClass, void (U::*onEvent)(AMM::PhysiologyValue &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isPhysValInit) return 1;
       return m_physiologyValue->CreateSubscriber((ListenerInterface *) this, parentClass, onEvent);
    }

    template<class U>
    inline int DDSManager<U>::CreatePhysiologyValueSubscriber(
       std::string &errmsg, U *parentClass,
       void (U::*onEvent)(AMM::PhysiologyValue &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isPhysValInit) {
          errmsg = "Physiology Value is not properly initialized.";
          return 1;
       }
       return m_physiologyValue->CreateSubscriber(errmsg, (ListenerInterface *) this, parentClass, onEvent);
    }

    template<class U>
    inline int DDSManager<U>::RemovePhysiologyValueSubscriber() {
       if (!m_isPhysValInit) return 1;
       return m_physiologyValue->RemoveSubscriber();
    }

    template<class U>
    inline int DDSManager<U>::RemovePhysiologyValueSubscriber(std::string &errmsg) {
       if (!m_isPhysValInit) {
          errmsg = "Physiology Value is not properly initialized.";
          return 1;
       }
       return m_physiologyValue->RemoveSubscriber(errmsg);
    }

    template<class U>
    inline int DDSManager<U>::WritePhysiologyValue(AMM::PhysiologyValue &a) {
       if (!m_isPhysValInit) return 1;
       return m_physiologyValue->Write(a);
    }

    template<class U>
    inline int DDSManager<U>::WritePhysiologyValue(std::string &errmsg, AMM::PhysiologyValue &a) {
       if (!m_isPhysValInit) {
          errmsg = "Physiology Value is not properly initialized.";
          return 1;
       }
       return m_physiologyValue->Write(errmsg, a);
    }

    template<class U>
    inline void DDSManager<U>::onNewPhysiologyValue(
       AMM::PhysiologyValue physValue, eprosima::fastrtps::SampleInfo_t *info
    ) {
       m_physiologyValue->OnEvent(physValue, info);
    }

    template<class U>
    inline int DDSManager<U>::DecommissionPhysiologyValue() {
       if (!m_isPhysValInit) return 0;

       int err = m_physiologyValue->Delete();
       if (err == 0) m_isPhysValInit = false;

       return err;
    }

    template<class U>
    inline int DDSManager<U>::DecommissionPhysiologyValue(std::string &errmsg) {
       if (!m_isPhysValInit) {
          errmsg = "Physiology Value is already decommissioned.";
          return 0;
       }

       int err = m_physiologyValue->Delete(errmsg);
       if (err == 0) m_isPhysValInit = false;

       return err;
    }


// - - - Physiology Waveform - - -

    template<class U>
    inline int DDSManager<U>::InitializePhysiologyWaveform() {

       if (m_isPhysWaveInit) return 0;

       int err = 0;

       m_physiologyWaveform = new AmmDataType<PHWV_TYPE, PHWV_LTNR, PHWV, U>(
          err, PHWV_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isPhysWaveInit = true;

       return err;
    }

    template<class U>
    inline int DDSManager<U>::InitializePhysiologyWaveform(std::string &errmsg) {

       if (m_isPhysWaveInit) {
          errmsg = "Physiology Waveform is already initialized.";
          return 0;
       }

       int err = 0;

       m_physiologyWaveform = new AmmDataType<PHWV_TYPE, PHWV_LTNR, PHWV, U>(
          err, errmsg, PHWV_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isPhysWaveInit = true;

       return err;
    }

    template<class U>
    inline bool DDSManager<U>::IsPhysiologyWaveformInitialized() {
       if (m_isPhysWaveInit) return m_physiologyWaveform->IsTypeRegistered();
       return false;
    }

    template<class U>
    inline int DDSManager<U>::CreatePhysiologyWaveformPublisher() {
       if (!m_isPhysWaveInit) return 1;
       return m_physiologyWaveform->CreatePublisher();
    }

    template<class U>
    inline int DDSManager<U>::CreatePhysiologyWaveformPublisher(std::string &errmsg) {
       if (!m_isPhysWaveInit) {
          errmsg = "Physiology Waveform is not properly initialized.";
          return 1;
       }
       return m_physiologyWaveform->CreatePublisher(errmsg);
    }

    template<class U>
    inline int DDSManager<U>::RemovePhysiologyWaveformPublisher() {
       if (!m_isPhysWaveInit) return 1;
       return m_physiologyWaveform->RemovePublisher();
    }

    template<class U>
    inline int DDSManager<U>::RemovePhysiologyWaveformPublisher(std::string &errmsg) {
       if (!m_isPhysWaveInit) {
          errmsg = "Physiology Waveform is not properly initialized.";
          return 1;
       }
       return m_physiologyWaveform->RemovePublisher(errmsg);
    }

    template<class U>
    inline int DDSManager<U>::CreatePhysiologyWaveformSubscriber(
       U *parentClass, void (U::*onEvent)(AMM::PhysiologyWaveform &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isPhysWaveInit) return 1;
       return m_physiologyWaveform->CreateSubscriber((ListenerInterface *) this, parentClass, onEvent);
    }

    template<class U>
    inline int DDSManager<U>::CreatePhysiologyWaveformSubscriber(
       std::string &errmsg, U *parentClass,
       void (U::*onEvent)(AMM::PhysiologyWaveform &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isPhysWaveInit) {
          errmsg = "Physiology Waveform is not properly initialized.";
          return 1;
       }
       return m_physiologyWaveform->CreateSubscriber(errmsg, (ListenerInterface *) this, parentClass, onEvent);
    }

    template<class U>
    inline int DDSManager<U>::RemovePhysiologyWaveformSubscriber() {
       if (!m_isPhysWaveInit) return 1;
       return m_physiologyWaveform->RemoveSubscriber();
    }

    template<class U>
    inline int DDSManager<U>::RemovePhysiologyWaveformSubscriber(std::string &errmsg) {
       if (!m_isPhysWaveInit) {
          errmsg = "Physiology Waveform is not properly initialized.";
          return 1;
       }
       return m_physiologyWaveform->RemoveSubscriber(errmsg);
    }

    template<class U>
    inline int DDSManager<U>::WritePhysiologyWaveform(AMM::PhysiologyWaveform &a) {
       if (!m_isPhysWaveInit) return 1;
       return m_physiologyWaveform->Write(a);
    }

    template<class U>
    inline int DDSManager<U>::WritePhysiologyWaveform(std::string &errmsg, AMM::PhysiologyWaveform &a) {
       if (!m_isPhysWaveInit) {
          errmsg = "Physiology Waveform is not properly initialized.";
          return 1;
       }
       return m_physiologyWaveform->Write(errmsg, a);
    }

    template<class U>
    inline void DDSManager<U>::onNewPhysiologyWaveform(
       AMM::PhysiologyWaveform physWave, eprosima::fastrtps::SampleInfo_t *info
    ) {
       m_physiologyWaveform->OnEvent(physWave, info);
    }

    template<class U>
    inline int DDSManager<U>::DecommissionPhysiologyWaveform() {
       if (!m_isPhysWaveInit) return 0;

       int err = m_physiologyWaveform->Delete();
       if (err == 0) m_isPhysWaveInit = false;

       return err;
    }

    template<class U>
    inline int DDSManager<U>::DecommissionPhysiologyWaveform(std::string &errmsg) {
       if (!m_isPhysWaveInit) {
          errmsg = "Physiology Waveform is already decommissioned.";
          return 0;
       }

       int err = m_physiologyWaveform->Delete(errmsg);
       if (err == 0) m_isPhysWaveInit = false;

       return err;
    }


// - - - Render Modification - - -

    template<class U>
    inline int DDSManager<U>::InitializeRenderModification() {

       if (m_isRendModInit) return 0;

       int err = 0;

       m_renderModification = new AmmDataType<RDMO_TYPE, RDMO_LTNR, RDMO, U>(
          err, RDMO_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isRendModInit = true;

       return err;
    }

    template<class U>
    inline int DDSManager<U>::InitializeRenderModification(std::string &errmsg) {

       if (m_isRendModInit) {
          errmsg = "Render Modification is already initialized";
          return 0;
       }

       int err = 0;

       m_renderModification = new AmmDataType<RDMO_TYPE, RDMO_LTNR, RDMO, U>(
          err, errmsg, RDMO_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isRendModInit = true;

       return err;
    }

    template<class U>
    inline bool DDSManager<U>::IsRenderModificationInitialized() {
       if (m_isRendModInit) return m_renderModification->IsTypeRegistered();
       return false;
    }

    template<class U>
    inline int DDSManager<U>::CreateRenderModificationPublisher() {
       if (!m_isRendModInit) return 1;
       return m_renderModification->CreatePublisher();
    }

    template<class U>
    inline int DDSManager<U>::CreateRenderModificationPublisher(std::string &errmsg) {
       if (!m_isRendModInit) {
          errmsg = "Render Modification is not properly initialized.";
          return 1;
       }
       return m_renderModification->CreatePublisher(errmsg);
    }

    template<class U>
    inline int DDSManager<U>::RemoveRenderModificationPublisher() {
       if (!m_isRendModInit) return 1;
       return m_renderModification->RemovePublisher();
    }

    template<class U>
    inline int DDSManager<U>::RemoveRenderModificationPublisher(std::string &errmsg) {
       if (!m_isRendModInit) {
          errmsg = "Render Modification is not properly initialized.";
          return 1;
       }
       return m_renderModification->RemovePublisher(errmsg);
    }

    template<class U>
    inline int DDSManager<U>::CreateRenderModificationSubscriber(
       U *parentClass, void (U::*onEvent)(AMM::RenderModification &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isRendModInit) return 1;
       return m_renderModification->CreateSubscriber((ListenerInterface *) this, parentClass, onEvent);
    }

    template<class U>
    inline int DDSManager<U>::CreateRenderModificationSubscriber(
       std::string &errmsg, U *parentClass,
       void (U::*onEvent)(AMM::RenderModification &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isRendModInit) {
          errmsg = "Render Modification is not properly initialized.";
          return 1;
       }
       return m_renderModification->CreateSubscriber(errmsg, (ListenerInterface *) this, onEvent);
    }

    template<class U>
    inline int DDSManager<U>::RemoveRenderModificationSubscriber() {
       if (!m_isRendModInit) return 1;
       return m_renderModification->RemoveSubscriber();
    }

    template<class U>
    inline int DDSManager<U>::RemoveRenderModificationSubscriber(std::string &errmsg) {
       if (!m_isRendModInit) {
          errmsg = "Render Modification is not properly initialized.";
          return 1;
       }
       return m_renderModification->RemoveSubscriber(errmsg);
    }

    template<class U>
    inline int DDSManager<U>::WriteRenderModification(AMM::RenderModification &a) {
       if (!m_isRendModInit) return 1;
       return m_renderModification->Write(a);
    }

    template<class U>
    inline int DDSManager<U>::WriteRenderModification(std::string &errmsg, AMM::RenderModification &a) {
       if (!m_isRendModInit) {
          errmsg = "Render Modification is not properly initialized.";
          return 1;
       }
       return m_renderModification->Write(errmsg, a);
    }

    template<class U>
    inline void DDSManager<U>::onNewRenderModification(
       AMM::RenderModification rendMod, eprosima::fastrtps::SampleInfo_t *info
    ) {
       m_renderModification->OnEvent(rendMod, info);
    }

    template<class U>
    inline int DDSManager<U>::DecommissionRenderModification() {
       if (!m_isRendModInit) return 0;

       int err = m_renderModification->Delete();
       if (err == 0) m_isRendModInit = false;

       return err;
    }

    template<class U>
    inline int DDSManager<U>::DecommissionRenderModification(std::string &errmsg) {
       if (!m_isRendModInit) {
          errmsg = "Render Modification is already decommissioned.";
          return 0;
       }

       int err = m_renderModification->Delete(errmsg);
       if (err == 0) m_isRendModInit = false;

       return err;
    }


// - - - Simulation Control - - -

    template<class U>
    inline int DDSManager<U>::InitializeSimulationControl() {

       if (m_isSimControlInit) return 0;

       int err = 0;

       m_simulationControl = new AmmDataType<SMCN_TYPE, SMCN_LTNR, SMCN, U>(
          err, SMCN_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isSimControlInit = true;

       return err;
    }

    template<class U>
    inline int DDSManager<U>::InitializeSimulationControl(std::string &errmsg) {

       if (m_isSimControlInit) {
          errmsg = "Simulation Control is already initialized";
          return 0;
       }

       int err = 0;

       m_simulationControl = new AmmDataType<SMCN_TYPE, SMCN_LTNR, SMCN, U>(
          err, errmsg, SMCN_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isSimControlInit = true;

       return err;
    }

    template<class U>
    inline int DDSManager<U>::CreateSimulationControlPublisher() {
       if (!m_isSimControlInit) return 1;
       return m_simulationControl->CreatePublisher();
    }

    template<class U>
    inline int DDSManager<U>::CreateSimulationControlPublisher(std::string &errmsg) {
       if (!m_isSimControlInit) {
          errmsg = "Simulation Control is not properly initialized.";
          return 1;
       }
       return m_simulationControl->CreatePublisher(errmsg);
    }

    template<class U>
    inline int DDSManager<U>::RemoveSimulationControlPublisher() {
       if (!m_isSimControlInit) return 1;
       return m_simulationControl->RemovePublisher();
    }

    template<class U>
    inline int DDSManager<U>::RemoveSimulationControlPublisher(std::string &errmsg) {
       if (!m_isSimControlInit) {
          errmsg = "Simulation Control is not properly initialized.";
          return 1;
       }
       return m_simulationControl->RemovePublisher(errmsg);
    }

    template<class U>
    inline int DDSManager<U>::CreateSimulationControlSubscriber(
       U *parentClass, void (U::*onEvent)(AMM::SimulationControl &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isSimControlInit) return 1;
       return m_simulationControl->CreateSubscriber((ListenerInterface *) this, parentClass, onEvent);
    }

    template<class U>
    inline int DDSManager<U>::CreateSimulationControlSubscriber(
       std::string &errmsg, U *parentClass,
       void (U::*onEvent)(AMM::SimulationControl &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isSimControlInit) {
          errmsg = "Simulation Control is not properly initialized.";
          return 1;
       }
       return m_simulationControl->CreateSubscriber(errmsg, (ListenerInterface *) this, onEvent);
    }

    template<class U>
    inline int DDSManager<U>::RemoveSimulationControlSubscriber() {
       if (!m_isSimControlInit) return 1;
       return m_simulationControl->RemoveSubscriber();
    }

    template<class U>
    inline int DDSManager<U>::RemoveSimulationControlSubscriber(std::string &errmsg) {
       if (!m_isSimControlInit) {
          errmsg = "Simulation Control is not properly initialized.";
          return 1;
       }
       return m_simulationControl->RemoveSubscriber(errmsg);
    }

    template<class U>
    inline int DDSManager<U>::WriteSimulationControl(AMM::SimulationControl &a) {
       if (!m_isSimControlInit) return 1;
       return m_simulationControl->Write(a);
    }

    template<class U>
    inline int DDSManager<U>::WriteSimulationControl(std::string &errmsg, AMM::SimulationControl &a) {
       if (!m_isSimControlInit) {
          errmsg = "Simulation Control is not properly initialized.";
          return 1;
       }
       return m_simulationControl->Write(errmsg, a);
    }

    template<class U>
    inline void DDSManager<U>::onNewSimulationControl(
       AMM::SimulationControl simControl, eprosima::fastrtps::SampleInfo_t *info
    ) {
       m_simulationControl->OnEvent(simControl, info);
    }

    template<class U>
    inline int DDSManager<U>::DecommissionSimulationControl() {
       if (!m_isSimControlInit) return 0;

       int err = m_simulationControl->Delete();
       if (err == 0) m_isSimControlInit = false;

       return err;
    }

    template<class U>
    inline int DDSManager<U>::DecommissionSimulationControl(std::string &errmsg) {
       if (!m_isSimControlInit) {
          errmsg = "Simulation Control is already decommissioned.";
          return 0;
       }

       int err = m_simulationControl->Delete(errmsg);
       if (err == 0) m_isSimControlInit = false;

       return err;
    }


// - - - Status - - -

    template<class U>
    inline int DDSManager<U>::InitializeStatus() {

       if (m_isStatusInit) return 0;

       int err = 0;

       m_status = new AmmDataType<STAT_TYPE, STAT_LTNR, STAT, U>(
          err, STAT_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isStatusInit = true;

       return err;
    }

    template<class U>
    inline int DDSManager<U>::InitializeStatus(std::string &errmsg) {

       if (m_isStatusInit) {
          errmsg = "Status is already initialized";
          return 0;
       }

       int err = 0;

       m_status = new AmmDataType<STAT_TYPE, STAT_LTNR, STAT, U>(
          err, errmsg, STAT_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isStatusInit = true;

       return err;
    }

    template<class U>
    inline bool DDSManager<U>::IsStatusInitialized() {
       if (m_isStatusInit) return m_status->IsTypeRegistered();
       return false;
    }

    template<class U>
    inline int DDSManager<U>::CreateStatusPublisher() {
       if (!m_isStatusInit) return 1;
       return m_status->CreatePublisher();
    }

    template<class U>
    inline int DDSManager<U>::CreateStatusPublisher(std::string &errmsg) {
       if (!m_isStatusInit) {
          errmsg = "Status is not properly initialized.";
          return 1;
       }
       return m_status->CreatePublisher(errmsg);
    }

    template<class U>
    inline int DDSManager<U>::RemoveStatusPublisher() {
       if (!m_isStatusInit) return 1;
       return m_status->RemovePublisher();
    }

    template<class U>
    inline int DDSManager<U>::RemoveStatusPublisher(std::string &errmsg) {
       if (!m_isStatusInit) {
          errmsg = "Status is not properly initialized.";
          return 1;
       }
       return m_status->RemovePublisher(errmsg);
    }

    template<class U>
    inline int DDSManager<U>::CreateStatusSubscriber(
       U *parentClass, void (U::*onEvent)(AMM::Status &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isStatusInit) return 1;
       return m_status->CreateSubscriber((ListenerInterface *) this, parentClass, onEvent);
    }

    template<class U>
    inline int DDSManager<U>::CreateStatusSubscriber(
       std::string &errmsg, U *parentClass, void (U::*onEvent)(AMM::Status &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isStatusInit) {
          errmsg = "Status is not properly initialized.";
          return 1;
       }
       return m_status->CreateSubscriber(errmsg, (ListenerInterface *) this, onEvent);
    }

    template<class U>
    inline int DDSManager<U>::RemoveStatusSubscriber() {
       if (!m_isStatusInit) return 1;
       return m_status->RemoveSubscriber();
    }

    template<class U>
    inline int DDSManager<U>::RemoveStatusSubscriber(std::string &errmsg) {
       if (!m_isStatusInit) {
          errmsg = "Status is not properly initialized.";
          return 1;
       }
       return m_status->RemoveSubscriber(errmsg);
    }

    template<class U>
    inline int DDSManager<U>::WriteStatus(AMM::Status &a) {
       if (!m_isStatusInit) return 1;
       return m_status->Write(a);
    }

    template<class U>
    inline int DDSManager<U>::WriteStatus(std::string &errmsg, AMM::Status &a) {
       if (!m_isStatusInit) {
          errmsg = "Status is not properly initialized.";
          return 1;
       }
       return m_status->Write(errmsg, a);
    }

    template<class U>
    inline void DDSManager<U>::onNewStatus(
       AMM::Status status, eprosima::fastrtps::SampleInfo_t *info
    ) {
       m_status->OnEvent(status, info);
    }

    template<class U>
    inline int DDSManager<U>::DecommissionStatus() {
       if (!m_isStatusInit) return 0;

       int err = m_status->Delete();
       if (err == 0) m_isStatusInit = false;

       return err;
    }

    template<class U>
    inline int DDSManager<U>::DecommissionStatus(std::string &errmsg) {
       if (!m_isStatusInit) {
          errmsg = "Status is already decommissioned.";
          return 0;
       }

       int err = m_status->Delete(errmsg);
       if (err == 0) m_isStatusInit = false;

       return err;
    }


// - - - Tick - - -

    template<class U>
    inline int DDSManager<U>::InitializeTick() {

       if (m_isTickInit) return 0;

       int err = 0;

       m_tick = new AmmDataType<TICK_TYPE, TICK_LTNR, TICK, U>(
          err, TICK_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isTickInit = true;
       return err;
    }

    template<class U>
    inline int DDSManager<U>::InitializeTick(std::string &errmsg) {

       if (m_isTickInit) {
          errmsg = "Tick is already initialized.";
          return 0;
       }

       int err = 0;

       m_tick = new AmmDataType<TICK_TYPE, TICK_LTNR, TICK, U>(
          err, errmsg, TICK_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isTickInit = true;
       return err;
    }

    template<class U>
    inline bool DDSManager<U>::IsTickInitialized() {
       if (m_isTickInit) return m_tick->IsTypeRegistered();
       return false;
    }

    template<class U>
    inline int DDSManager<U>::CreateTickPublisher() {
       if (!m_isTickInit) return 1;
       return m_tick->CreatePublisher();
    }

    template<class U>
    inline int DDSManager<U>::CreateTickPublisher(std::string &errmsg) {
       if (!m_isTickInit) {
          errmsg = "Tick is not properly initialized.";
          return 1;
       }
       return m_tick->CreatePublisher(errmsg);
    }

    template<class U>
    inline int DDSManager<U>::RemoveTickPublisher() {
       if (!m_isTickInit) return 1;
       return m_instrumentData->RemovePublisher();
    }

    template<class U>
    inline int DDSManager<U>::RemoveTickPublisher(std::string &errmsg) {
       if (!m_isTickInit) {
          errmsg = "Tick is not properly initialized.";
          return 1;
       }
       return m_instrumentData->RemovePublisher(errmsg);
    }

    template<class U>
    inline int DDSManager<U>::CreateTickSubscriber(
       U *parentClass, void (U::*onEvent)(AMM::Tick &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isTickInit) return 1;
       return m_tick->CreateSubscriber((ListenerInterface *) this, parentClass, onEvent);
    }

    template<class U>
    inline int DDSManager<U>::CreateTickSubscriber(
       std::string &errmsg, U *parentClass, void (U::*onEvent)(AMM::Tick &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isTickInit) {
          errmsg = "Tick is not properly initialized.";
          return 1;
       }
       return m_tick->CreateSubscriber(errmsg, (ListenerInterface *) this, onEvent);
    }

    template<class U>
    inline int DDSManager<U>::RemoveTickSubscriber() {
       if (!m_isTickInit) return 1;
       return m_tick->RemoveSubscriber();
    }

    template<class U>
    inline int DDSManager<U>::RemoveTickSubscriber(std::string &errmsg) {
       if (!m_isTickInit) {
          errmsg = "Tick is not properly initialized.";
          return 1;
       }
       return m_tick->RemoveSubscriber(errmsg);
    }

    template<class U>
    inline int DDSManager<U>::WriteTick(AMM::Tick &a) {
       if (!m_isTickInit) return 1;
       return m_tick->Write(a);
    }

    template<class U>
    inline int DDSManager<U>::WriteTick(std::string &errmsg, AMM::Tick &a) {
       if (!m_isTickInit) {
          errmsg = "Tick is not properly initialized.";
          return 1;
       }
       return m_tick->Write(a);
    }

    template<class U>
    inline void DDSManager<U>::onNewTick(
       AMM::Tick tick, eprosima::fastrtps::SampleInfo_t *info
    ) {
       m_tick->OnEvent(tick, info);
    }

    template<class U>
    inline int DDSManager<U>::DecommissionTick() {
       if (!m_isTickInit) return 0;

       int err = m_tick->Delete();
       if (err == 0) m_isTickInit = false;

       return err;
    }

    template<class U>
    inline int DDSManager<U>::DecommissionTick(std::string &errmsg) {
       if (!m_isTickInit) {
          errmsg = "Tick is already decommissioned.";
          return 0;
       }

       int err = m_tick->Delete(errmsg);
       if (err == 0) m_isTickInit = false;

       return err;
    }


// - - - Instrument Data - - -

    template<class U>
    inline int DDSManager<U>::InitializeInstrumentData() {

       if (m_isInstDataInit) return 0;

       int err = 0;

       m_instrumentData = new AmmDataType<IDAT_TYPE, IDAT_LTNR, IDAT, U>(
          err, IDAT_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isInstDataInit = true;
       return err;
    }

    template<class U>
    inline int DDSManager<U>::InitializeInstrumentData(std::string &errmsg) {

       if (m_isInstDataInit) {
          errmsg = "Instrument Data is already initialized.";
          return 0;
       }

       int err = 0;

       m_instrumentData = new AmmDataType<IDAT_TYPE, IDAT_LTNR, IDAT, U>(
          err, errmsg, IDAT_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isInstDataInit = true;
       return err;
    }

    template<class U>
    inline bool DDSManager<U>::IsInstrumentDataInitialized() {
       if (m_isInstDataInit) return m_instrumentData->IsTypeRegistered();
       return false;
    }

    template<class U>
    inline int DDSManager<U>::CreateInstrumentDataPublisher() {
       if (!m_isInstDataInit) return 1;
       return m_instrumentData->CreatePublisher();
    }

    template<class U>
    inline int DDSManager<U>::CreateInstrumentDataPublisher(std::string &errmsg) {
       if (!m_isInstDataInit) {
          errmsg = "Instrument Data is not properly initialized.";
          return 1;
       }
       return m_instrumentData->CreatePublisher(errmsg);
    }

    template<class U>
    inline int DDSManager<U>::RemoveInstrumentDataPublisher() {
       if (!m_isInstDataInit) return 1;
       return m_instrumentData->RemovePublisher();
    }

    template<class U>
    inline int DDSManager<U>::RemoveInstrumentDataPublisher(std::string &errmsg) {
       if (!m_isInstDataInit) {
          errmsg = "Instrument Data is not properly initialized.";
          return 1;
       }
       return m_instrumentData->RemovePublisher(errmsg);
    }

    template<class U>
    inline int DDSManager<U>::CreateInstrumentDataSubscriber(
       U *parentClass, void (U::*onEvent)(AMM::InstrumentData &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isInstDataInit) return 1;
       return m_instrumentData->CreateSubscriber((ListenerInterface *) this, parentClass, onEvent);
    }

    template<class U>
    inline int DDSManager<U>::CreateInstrumentDataSubscriber(
       std::string &errmsg, U *parentClass,
       void (U::*onEvent)(AMM::InstrumentData &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isInstDataInit) {
          errmsg = "Instrument Data is not properly initialized.";
          return 1;
       }
       return m_instrumentData->CreateSubscriber(errmsg, (ListenerInterface *) this, onEvent);
    }

    template<class U>
    inline int DDSManager<U>::RemoveInstrumentDataSubscriber() {
       if (!m_isInstDataInit) return 1;
       return m_instrumentData->RemoveSubscriber();
    }

    template<class U>
    inline int DDSManager<U>::RemoveInstrumentDataSubscriber(std::string &errmsg) {
       if (!m_isInstDataInit) {
          errmsg = "Instrument Data is not properly initialized.";
          return 1;
       }
       return m_instrumentData->RemoveSubscriber(errmsg);
    }

    template<class U>
    inline int DDSManager<U>::WriteInstrumentData(AMM::InstrumentData &a) {
       if (!m_isInstDataInit) return 1;
       return m_instrumentData->Write(a);
    }

    template<class U>
    inline int DDSManager<U>::WriteInstrumentData(std::string &errmsg, AMM::InstrumentData &a) {
       if (!m_isInstDataInit) {
          errmsg = "Instrument Data is not properly initialized.";
          return 1;
       }
       return m_instrumentData->Write(errmsg, a);
    }

    template<class U>
    inline void DDSManager<U>::onNewInstrumentData(
       AMM::InstrumentData instData, eprosima::fastrtps::SampleInfo_t *info
    ) {
       m_instrumentData->OnEvent(instData, info);
    }

    template<class U>
    inline int DDSManager<U>::DecommissionInstrumentData() {
       if (!m_isInstDataInit) return 0;

       int err = m_instrumentData->Delete();
       if (err == 0) m_isInstDataInit = false;

       return err;
    }

    template<class U>
    inline int DDSManager<U>::DecommissionInstrumentData(std::string &errmsg) {
       if (!m_isInstDataInit) {
          errmsg = "Instrument Data is already decommissioned.";
          return 0;
       }

       int err = m_instrumentData->Delete(errmsg);
       if (err == 0) m_isInstDataInit = false;

       return err;
    }


// - - - Command - - -

    template<class U>
    inline int DDSManager<U>::InitializeCommand() {

       if (m_isCommandInit) return 0;

       int err = 0;
       m_command = new AmmDataType<CMND_TYPE, CMND_LTNR, CMND, U>(
          err, CMND_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isCommandInit = true;
       return err;
    }

    template<class U>
    inline int DDSManager<U>::InitializeCommand(std::string &errmsg) {

       if (m_isCommandInit) {
          errmsg = "Command is already initialized.";
          return 0;
       }

       int err = 0;
       m_command = new AmmDataType<CMND_TYPE, CMND_LTNR, CMND, U>(
          err, errmsg, CMND_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isCommandInit = true;
       return err;
    }

    template<class U>
    inline bool DDSManager<U>::IsCommandInitialized() {
       if (m_isCommandInit) return m_command->IsTypeRegistered();
       return false;
    }

    template<class U>
    inline int DDSManager<U>::CreateCommandPublisher() {
       if (!m_isCommandInit) return 1;
       return m_command->CreatePublisher();
    }

    template<class U>
    inline int DDSManager<U>::CreateCommandPublisher(std::string &errmsg) {
       if (!m_isCommandInit) {
          errmsg = "Command is not properly initialized.";
          return 1;
       }
       return m_command->CreatePublisher(errmsg);
    }

    template<class U>
    inline int DDSManager<U>::RemoveCommandPublisher(std::string &errmsg) {
       if (!m_isCommandInit) {
          errmsg = "Command is not properly initialized.";
          return 1;
       }
       return m_command->RemovePublisher(errmsg);
    }

    template<class U>
    inline int DDSManager<U>::RemoveCommandPublisher() {
       if (!m_isCommandInit) return 1;
       return m_command->RemovePublisher();
    }

    template<class U>
    inline int DDSManager<U>::CreateCommandSubscriber(
       U *parentClass, void (U::*onEvent)(AMM::Command &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isCommandInit) return 1;
       return m_command->CreateSubscriber((ListenerInterface *) this, parentClass, onEvent);
    }

    template<class U>
    inline int DDSManager<U>::CreateCommandSubscriber(
       std::string &errmsg, U *parentClass, void (U::*onEvent)(AMM::Command &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isCommandInit) {
          errmsg = "Command is not properly initialized.";
          return 1;
       }
       return m_command->CreateSubscriber(errmsg, (ListenerInterface *) this, onEvent);
    }

    template<class U>
    inline int DDSManager<U>::RemoveCommandSubscriber() {
       if (!m_isCommandInit) return 1;
       return m_command->RemoveSubscriber();
    }

    template<class U>
    inline int DDSManager<U>::RemoveCommandSubscriber(std::string &errmsg) {
       if (!m_isCommandInit) {
          errmsg = "Command is not properly initialized.";
          return 1;
       }
       return m_command->RemoveSubscriber(errmsg);
    }

    template<class U>
    inline int DDSManager<U>::WriteCommand(AMM::Command &a) {
       if (!m_isCommandInit) return 1;
       return m_command->Write(a);
    }

    template<class U>
    inline int DDSManager<U>::WriteCommand(std::string &errmsg, AMM::Command &a) {
       if (!m_isCommandInit) {
          errmsg = "Command is not properly initialized.";
          return 1;
       }
       return m_command->Write(errmsg, a);
    }

    template<class U>
    inline void DDSManager<U>::onNewCommand(
       AMM::Command command, eprosima::fastrtps::SampleInfo_t *info
    ) {
       m_command->OnEvent(command, info);
    }

    template<class U>
    inline int DDSManager<U>::DecommissionCommand() {
       if (!m_isCommandInit) return 0;

       int err = m_command->Delete();
       if (err == 0) m_isCommandInit = false;

       return err;
    }

    template<class U>
    inline int DDSManager<U>::DecommissionCommand(std::string &errmsg) {
       if (!m_isCommandInit) {
          errmsg = "Command is already decommissioned.";
          return 0;
       }

       int err = m_command->Delete(errmsg);
       if (err == 0) m_isCommandInit = false;

       return err;
    }


/// Wrapper interface for managing AMM Data Types.
///
/// Specialization B<br>
/// This is the specialization template for handling the function pointer
/// of a stand alone function.
    template<>
    class DDSManager<void> : public ListenerInterface {

    private:

        /// Assessment type handler.
        /// Handler for registering, publishering, and subscribing data for Assessment.
        AmmDataType<ASMT_TYPE, ASMT_LTNR, ASMT> *m_assessment;

        /// Event Fragment type handler.
        /// Handler for registering, publishering, and subscribing data for Event Fragment.
        AmmDataType<EVFR_TYPE, EVFR_LTNR, EVFR> *m_eventFragment;

        /// Event Record type handler.
        /// Handler for registering, publishering, and subscribing data for Event Record.
        AmmDataType<EVRC_TYPE, EVRC_LTNR, EVRC> *m_eventRecord;

        /// Fragment Amendment Request type handler.
        /// Handler for registering, publishering, and subscribing data for Fragment Amendment Request.
        AmmDataType<FARQ_TYPE, FARQ_LTNR, FARQ> *m_fragmentAmendmentRequest;

        /// Log type handler.
        /// Handler for registering, publishering, and subscribing data for Log.
        AmmDataType<ALOG_TYPE, ALOG_LTNR, ALOG> *m_log;

        /// Module Configuration type handler.
        /// Handler for registering, publishering, and subscribing data for Module Configuration.
        AmmDataType<MOCF_TYPE, MOCF_LTNR, MOCF> *m_moduleConfiguration;

        /// Omitted Description type handler.
        /// Handler for registering, publishering, and subscribing data for Omitted Description.
        AmmDataType<OMEV_TYPE, OMEV_LTNR, OMEV> *m_omittedEvent;

        /// Operational Description type handler.
        /// Handler for registering, publishering, and subscribing data for Operational Description.
        AmmDataType<OPDS_TYPE, OPDS_LTNR, OPDS> *m_operationalDescription;

        /// Physiology Modification type handler.
        /// Handler for registering, publishering, and subscribing data for Physiology Modification.
        AmmDataType<PHMO_TYPE, PHMO_LTNR, PHMO> *m_physiologyModification;

        /// Physiology Value type handler.
        /// Handler for registering, publishering, and subscribing data for Physiology Value.
        AmmDataType<PHVA_TYPE, PHVA_LTNR, PHVA> *m_physiologyValue;

        /// Physiology Waveform type handler.
        /// Handler for registering, publishering, and subscribing data for Physiology Waveform.
        AmmDataType<PHWV_TYPE, PHWV_LTNR, PHWV> *m_physiologyWaveform;

        /// Render Modification type handler.
        /// Handler for registering, publishering, and subscribing data for Render Modification.
        AmmDataType<RDMO_TYPE, RDMO_LTNR, RDMO> *m_renderModification;

        /// Simulation Control type handler.
        /// Handler for registering, publishering, and subscribing data for Simulation Control.
        AmmDataType<SMCN_TYPE, SMCN_LTNR, SMCN> *m_simulationControl;

        /// Status type handler.
        /// Handler for registering, publishering, and subscribing data for Status.
        AmmDataType<STAT_TYPE, STAT_LTNR, STAT> *m_status;

        /// Tick type handler.
        /// Handler for registering, publishering, and subscribing data for Tick.
        AmmDataType<TICK_TYPE, TICK_LTNR, TICK> *m_tick;

        /// Instrument Data type handler.
        /// Handler for registering, publishering, and subscribing data for Instrument Data.
        AmmDataType<IDAT_TYPE, IDAT_LTNR, IDAT> *m_instrumentData;

        /// Command type handler.
        /// Handler for registering, publishering, and subscribing data for Command.
        AmmDataType<CMND_TYPE, CMND_LTNR, CMND> *m_command;

        /// Initializer flag for Assessment.
        /// State of whether the AMMDataType pointer for Assessment is valid.
        bool m_isAssessmentInit = false;

        /// Initializer flag for Event Fragment.
        /// State of whether the AMMDataType pointer for Event Fragment is valid.
        bool m_isEventFragInit = false;

        /// Initializer flag for Event Record.
        /// State of whether the AMMDataType pointer for Event Record is valid.
        bool m_isEventRecInit = false;

        /// Initializer flag for Fragment Amendment Request.
        /// State of whether the AMMDataType pointer for Fragment Amendment Request is valid.
        bool m_isFragAmendReqInit = false;

        /// Initializer flag for Log.
        /// State of whether the AMMDataType pointer for Log is valid.
        bool m_isLogInit = false;

        /// Initializer flag for Module Configuration.
        /// State of whether the AMMDataType pointer for Module Configuration is valid.
        bool m_isModConfigInit = false;

        /// Initializer flag for Omitted Event.
        /// State of whether the AMMDataType pointer for Omitted Event is valid.
        bool m_isOmitEventInit = false;

        /// Initializer flag for Operational Description.
        /// State of whether the AMMDataType pointer for Operational Description is valid.
        bool m_isOpDescriptInit = false;

        /// Initializer flag for Physiology Modification.
        /// State of whether the AMMDataType pointer for Physiology Modification is valid.
        bool m_isPhysModInit = false;

        /// Initializer flag for Physiology Value.
        /// State of whether the AMMDataType pointer for Physiology Value is valid.
        bool m_isPhysValInit = false;

        /// Initializer flag for Physiology Waveform.
        /// State of whether the AMMDataType pointer for Physiology Waveform is valid.
        bool m_isPhysWaveInit = false;

        /// Initializer flag for Render Modification.
        /// State of whether the AMMDataType pointer for Render Modification is valid.
        bool m_isRendModInit = false;

        /// Initializer flag for Simulation Control.
        /// State of whether the AMMDataType pointer for Simulation Control is valid.
        bool m_isSimControlInit = false;

        /// Initializer flag for Status.
        /// State of whether the AMMDataType pointer for Status is valid.
        bool m_isStatusInit = false;

        /// Initializer flag for Tick.
        /// State of whether the AMMDataType pointer for Tick is valid.
        bool m_isTickInit = false;

        /// Initializer flag for Instrument Data.
        /// State of whether the AMMDataType pointer for Instrument Data is valid.
        bool m_isInstDataInit = false;

        /// Initializer flag for Command.
        /// State of whether the AMMDataType pointer for Command is valid.
        bool m_isCommandInit = false;


    private:

        /// UUID of this module.
        std::string m_moduleId;

        /// Name of this module.
        std::string m_moduleName;

        /// Default domain ID for AMM Modules.
        const int DOMAIN_ID = 15;

        /// DDS Participant of this module.
        /// Each AMM Module has one Participant used to register their activity on the DDS network.
        /// A Participant is created at the time of the module's inception, and removed once a module
        /// shuts down.
        eprosima::fastrtps::Participant *m_participant;

        /// DDS Listener object for publishers.
        /// All publishers for each AMMDataType use the same publisher listener
        /// referenced from here.
        /// @note Is created at the time of the module's inception.
        DDS_Listeners::PubListener *m_pubListener;

    public:
        /// Default constructor taking in a module name defined by the user.
        /// @param moduleName String name of this module.
        DDSManager(std::string configFile);

        /// Default deconstructor.
        ~DDSManager() {};

        /// Default shutdown command for the module.
        /// Should always be used before exiting the executable, because this ensures all Participant activity
        /// is properly terminated and cleaned up for memory management sake on the DDS network.
        /// @note Shutdown routine will not stop if an error flag is raised. Will ignore and continue on.
        void Shutdown();

        /// Override shutdown outputting an error message if any error flags are raised suring shutdown.
        /// @param errmsg Error message output.
        /// @note Shutdown routine will not stop if an error flag is raised. Will ignore and continue on.
        void Shutdown(std::string &errmsg);

        /// Generates a random UUID.
        /// @returns A string form of a UUID.
        static std::string GenerateUuidString();

        /// Initializer routine for Assessment.
        /// Initializes m_assessment with a new AmmDataType pointer.
        /// @returns 0 if successful.
        int InitializeAssessment();

        /// Overload initializer routine for Assessment.
        /// Initializes m_assessment with a new AmmDataType pointer.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int InitializeAssessment(std::string &errmsg);

        /// State of whether Assessment is currently valid.
        /// @returns True if m_assessment is valid pointer.
        bool IsAssessmentInitialized();

        /// Create the data publisher for Assessment on this module.
        /// Allows Assessment data to be published to the DDS network.
        /// @returns 0 if successful.
        int CreateAssessmentPublisher();

        /// Create the data publisher for Assessment on this module.
        /// Allows Assessment data to be published to the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int CreateAssessmentPublisher(std::string &errmsg);

        /// Remove the publisher for Assessment on this module from the DDS network.
        /// @returns 0 if successful.
        int RemoveAssessmentPublisher();

        /// Remove the publisher for Assessment on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemoveAssessmentPublisher(std::string &errmsg);

        /// Create the data subscriber for Assessment published events on this module.
        /// Allows the module to receive Assessment data when it is published on the DDS network.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreateAssessmentSubscriber(
           void (*onEvent)(AMM::Assessment &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Create the data subscriber for Assessment published events on this module.
        /// Allows the module to receive Assessment data when it is published on the DDS network.
        /// @param errmsg Error message output.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreateAssessmentSubscriber(
           std::string &errmsg, void (*onEvent)(AMM::Assessment &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Remove the subscriber for Assessment on this module from the DDS network.
        /// @returns 0 if successful.
        int RemoveAssessmentSubscriber();

        /// Remove the subscriber for Assessment on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemoveAssessmentSubscriber(std::string &errmsg);

        /// Call upon the active publisher for Assessment to write data to the DDS network.
        /// @param a Reference to Assessment data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WriteAssessment(AMM::Assessment &a);

        /// Call upon the active publisher for Assessment to write data to the DDS network.
        /// @param errmsg Error message output.
        /// @param a Reference to Assessment data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WriteAssessment(std::string &errmsg, AMM::Assessment &a);

        /// Listener Interface override for handling Assessment subscribed events.
        /// Calls OnEvent on m_assessment passing along data to the handler defined by
        /// the user in CreateAssessmentSubscriber.
        /// @see AmmDataType::OnEvent
        /// @see ListenerInterface::onNewAssessment
        /// @param assessment incoming Assessment data from the DDS network.
        /// @param info FastRTPS sample info.
        void onNewAssessment(AMM::Assessment assessment, eprosima::fastrtps::SampleInfo_t *info) override;

        /// Clean up Assessment and set it to an inactive state.
        /// Calls Delete on m_assessment.
        /// @returns 0 if successful.
        int DecommissionAssessment();

        /// Clean up assessment and set it to an inactive state.
        /// Calls Delete on m_assessment.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int DecommissionAssessment(std::string &errmsg);

        // - - - Event Fragment - - -

        /// Initializer routine for Event Fragment.
        /// Initializes m_eventFragment with a new AmmDataType pointer.
        /// @returns 0 if successful.
        int InitializeEventFragment();

        /// Overload initializer routine for Event Fragment.
        /// Initializes m_eventFragment with a new AmmDataType pointer.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int InitializeEventFragment(std::string &errmsg);

        /// State of whether Event Fragment is currently valid.
        /// @returns True if m_eventFragment is valid pointer.
        bool IsEventFragmentInitialzied();

        /// Create the data publisher for Event Fragment on this module.
        /// Allows Event Fragment data to be published to the DDS network.
        /// @returns 0 if successful.
        int CreateEventFragmentPublisher();

        /// Create the data publisher for Event Fragment on this module.
        /// Allows Event Fragment data to be published to the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int CreateEventFragmentPublisher(std::string &errmsg);

        /// Remove the publisher for Event Fragment on this module from the DDS network.
        /// @returns 0 if successful.
        int RemoveEventFragmentPublisher();

        /// Remove the publisher for Event Fragment on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemoveEventFragmentPublisher(std::string &errmsg);

        /// Create the data subscriber for Event Fragment published events on this module.
        /// Allows the module to receive Event Fragment data when it is published on the DDS network.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreateEventFragmentSubscriber(
           void (*onEvent)(AMM::EventFragment &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Create the data subscriber for Event Fragment published events on this module.
        /// Allows the module to receive Event Fragment data when it is published on the DDS network.
        /// @param errmsg Error message output.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreateEventFragmentSubscriber(
           std::string &errmsg, void (*onEvent)(AMM::EventFragment &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Remove the subscriber for Event Fragment on this module from the DDS network.
        /// @returns 0 if successful.
        int RemoveEventFragmentSubscriber();

        /// Remove the subscriber for Event Fragment on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemoveEventFragmentSubscriber(std::string &errmsg);

        /// Call upon the active publisher for Event Fragment to write data to the DDS network.
        /// @param a Reference to Event Fragment data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WriteEventFragment(AMM::EventFragment &a);

        /// Call upon the active publisher for Event Fragment to write data to the DDS network.
        /// @param errmsg Error message output.
        /// @param a Reference to Event Fragment data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WriteEventFragment(std::string &errmsg, AMM::EventFragment &a);

        /// Listener Interface override for handling Assessment subscribed events.
        /// Calls OnEvent on m_eventFragment passing along data to the handler defined by
        /// the user in CreateEventFragmentSubscriber.
        /// @see AmmDataType::OnEvent
        /// @see DDSManager::m_aseessment
        /// @see ListenerInterface::onNewEventFragment
        /// @param eventFrag incoming Event Fragment data from the DDS network.
        /// @param info FastRTPS sample info.
        void onNewEventFragment(AMM::EventFragment eventFrag, eprosima::fastrtps::SampleInfo_t *info) override;

        /// Clean up Event Fragment and set it to an inactive state.
        /// Calls Delete on m_eventFragment.
        /// @returns 0 if successful.
        int DecommissionEventFragment();

        /// Clean up Event Fragment and set it to an inactive state.
        /// Calls Delete on m_eventFragment.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int DecommissionEventFragment(std::string &errmsg);

        // - - - Event Record - - -

        /// Initializer routine for Event Record.
        /// Initializes m_eventRecord with a new AmmDataType pointer.
        /// @returns 0 if successful.
        int InitializeEventRecord();

        /// Overload initializer routine for Event Record.
        /// Initializes m_eventRecord with a new AmmDataType pointer.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int InitializeEventRecord(std::string &errmsg);

        /// State of whether Event Record is currently valid.
        /// @returns True if m_eventRecord is valid pointer.
        bool IsEventRecordInitialized();

        /// Create the data publisher for Event Record on this module.
        /// Allows Event Record data to be published to the DDS network.
        /// @returns 0 if successful.
        int CreateEventRecordPublisher();

        /// Create the data publisher for Event Record on this module.
        /// Allows Event Fragment data to be published to the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int CreateEventRecordPublisher(std::string &errmsg);

        /// Remove the publisher for Event Record on this module from the DDS network.
        /// @returns 0 if successful.
        int RemoveEventRecordPublisher();

        /// Remove the publisher for Event Record on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemoveEventRecordPublisher(std::string &errmsg);

        /// Create the data subscriber for Event Record published events on this module.
        /// Allows the module to receive Event Record data when it is published on the DDS network.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreateEventRecordSubscriber(
           void (*onEvent)(AMM::EventRecord &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Create the data subscriber for Event Record published events on this module.
        /// Allows the module to receive Event Record data when it is published on the DDS network.
        /// @param errmsg Error message output.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreateEventRecordSubscriber(
           std::string &errmsg, void (*onEvent)(AMM::EventRecord &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Remove the subscriber for Event Record on this module from the DDS network.
        /// @returns 0 if successful.
        int RemoveEventRecordSubscriber();

        /// Remove the subscriber for Event Record on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemoveEventRecordSubscriber(std::string &errmsg);

        /// Call upon the active publisher for Event Record to write data to the DDS network.
        /// @param a Reference to Event Record data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WriteEventRecord(AMM::EventRecord &a);

        /// Call upon the active publisher for Event Record to write data to the DDS network.
        /// @param errmsg Error message output.
        /// @param a Reference to Event Record data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WriteEventRecord(std::string &errmsg, AMM::EventRecord &a);

        /// Listener Interface override for handling Event Record subscribed events.
        /// Calls OnEvent on m_eventRecord passing along data to the handler defined by
        /// the user in CreateEventRecordSubscriber.
        /// @see AmmDataType::OnEvent
        /// @see ListenerInterface::onNewEventRecord
        /// @param eventFrag incoming Event Record data from the DDS network.
        /// @param info FastRTPS sample info.
        void onNewEventRecord(AMM::EventRecord eventRec, eprosima::fastrtps::SampleInfo_t *info) override;

        /// Clean up Event Record and set it to an inactive state.
        /// Calls Delete on m_eventRecord.
        /// @returns 0 if successful.
        int DecommissionEventRecord();

        /// Clean up Event Record and set it to an inactive state.
        /// Calls Delete on m_eventRecord.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int DecommissionEventRecord(std::string &errmsg);

        // - - - Fragment Amendment Request - - -

        /// Initializer routine for Fragment Amendment Request.
        /// Initializes m_fragmentAmendmentRequest with a new AmmDataType pointer.
        /// @returns 0 if successful.
        int InitializeFragmentAmendmentRequest();

        /// Overload initializer routine for Fragment Amendment Request.
        /// Initializes m_fragmentAmendmentRequest with a new AmmDataType pointer.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int InitializeFragmentAmendmentRequest(std::string &errmsg);

        /// State of whether Fragment Amendment Request is currently valid.
        /// @returns True if m_fragmentAmendmentRequest is valid pointer.
        bool IsFragmentAmendmentRequestInitialized();

        /// Create the data publisher for Fragment Amendment Request on this module.
        /// Allows Fragment Amendment Request data to be published to the DDS network.
        /// @returns 0 if successful.
        int CreateFragmentAmendmentRequestPublisher();

        /// Create the data publisher for Fragment Amendment Request on this module.
        /// Allows Fragment Amendment Request data to be published to the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int CreateFragmentAmendmentRequestPublisher(std::string &errmsg);

        /// Remove the publisher for Fragment Amendment Request on this module from the DDS network.
        /// @returns 0 if successful.
        int RemoveFragmentAmendmentRequestPublisher();

        /// Remove the publisher for Fragment Amendment Request on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemoveFragmentAmendmentRequestPublisher(std::string &errmsg);

        /// Create the data subscriber for Fragment Amendment Request published events on this module.
        /// Allows the module to receive Fragment Amendment Request data when it is published on the DDS network.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreateFragmentAmendmentRequestSubscriber(
           void (*onEvent)(AMM::FragmentAmendmentRequest &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Create the data subscriber for Fragment Amendment Request published events on this module.
        /// Allows the module to receive Fragment Amendment Request data when it is published on the DDS network.
        /// @param errmsg Error message output.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreateFragmentAmendmentRequestSubscriber(
           std::string &errmsg, void (*onEvent)(AMM::FragmentAmendmentRequest &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Remove the subscriber for Fragment Amendment Request on this module from the DDS network.
        /// @returns 0 if successful.
        int RemoveFragmentAmendmentRequestSubscriber();

        /// Remove the subscriber for Fragment Amendment Request on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemoveFragmentAmendmentRequestSubscriber(std::string &errmsg);

        /// Call upon the active publisher for Fragment Amendment Request to write data to the DDS network.
        /// @param a Reference to Fragment Amendment Request data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WriteFragmentAmendmentRequest(AMM::FragmentAmendmentRequest &a);

        /// Call upon the active publisher for Fragment Amendmnet Request to write data to the DDS network.
        /// @param errmsg Error message output.
        /// @param a Reference to Fragment Amendment Request data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WriteFragmentAmendmentRequest(std::string &errmsg, AMM::FragmentAmendmentRequest &a);

        /// Listener Interface override for handling Fragment Amendment Request subscribed events.
        /// Calls OnEvent on m_fragmentAmendmentRequest passing along data to the handler defined by
        /// the user in CreateFragmentAmendmentRequestSubscriber.
        /// @see AmmDataType::OnEvent
        /// @see ListenerInterface::onNewFragmentAmendmentRequest
        /// @param ffar incoming Fragment Amendment Request data from the DDS network.
        /// @param info FastRTPS sample info.
        void onNewFragmentAmendmentRequest(AMM::FragmentAmendmentRequest ffar,
                                           eprosima::fastrtps::SampleInfo_t *info) override;

        /// Clean up Fragment Amendment Request and set it to an inactive state.
        /// Calls Delete on m_fragmentAmendmentRequest.
        /// @returns 0 if successful.
        int DecommissionFragmentAmendmentRequest();

        /// Clean up Fragment Amendment Request and set it to an inactive state.
        /// Calls Delete on m_fragmentAmendmentRequest.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int DecommissionFragmentAmendmentRequest(std::string &errmsg);

        // - - - Log - - -

        /// Initializer routine for Log.
        /// Initializes m_log with a new AmmDataType pointer.
        /// @returns 0 if successful.
        int InitializeLog();

        /// Overload initializer routine for Log.
        /// Initializes m_log with a new AmmDataType pointer.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int InitializeLog(std::string &errmsg);

        /// State of whether Log is currently valid.
        /// @returns True if m_log is valid pointer.
        bool IsLogInitialized();

        /// Create the data publisher for Log on this module.
        /// Allows Log data to be published to the DDS network.
        /// @returns 0 if successful.
        int CreateLogPublisher();

        /// Create the data publisher for Log on this module.
        /// Allows Log data to be published to the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int CreateLogPublisher(std::string &errmsg);

        /// Remove the publisher for Log on this module from the DDS network.
        /// @returns 0 if successful.
        int RemoveLogPublisher();

        /// Remove the publisher for Log on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemoveLogPublisher(std::string &errmsg);

        /// Create the data subscriber for Log published events on this module.
        /// Allows the module to receive Log data when it is published on the DDS network.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreateLogSubscriber(
           void (*onEvent)(AMM::Log &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Create the data subscriber for Log published events on this module.
        /// Allows the module to receive Log data when it is published on the DDS network.
        /// @param errmsg Error message output.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreateLogSubscriber(
           std::string &errmsg, void (*onEvent)(AMM::Log &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Remove the subscriber for Log on this module from the DDS network.
        /// @returns 0 if successful.
        int RemoveLogSubscriber();

        /// Remove the subscriber for Log on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemoveLogSubscriber(std::string &errmsg);

        /// Call upon the active publisher for Log to write data to the DDS network.
        /// @param a Reference to Log data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WriteLog(AMM::Log &a);

        /// Call upon the active publisher for Log to write data to the DDS network.
        /// @param errmsg Error message output.
        /// @param a Reference to Log data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WriteLog(std::string &errmsg, AMM::Log &a);

        /// Listener Interface override for handling Log subscribed events.
        /// Calls OnEvent on m_log passing along data to the handler defined by
        /// the user in CreateLogSubscriber.
        /// @see AmmDataType::OnEvent
        /// @see ListenerInterface::onNewLog
        /// @param log incoming Log data from the DDS network.
        /// @param info FastRTPS sample info.
        void onNewLog(AMM::Log eventRec, eprosima::fastrtps::SampleInfo_t *info) override;

        /// Clean up Log and set it to an inactive state.
        /// Calls Delete on m_log.
        /// @returns 0 if successful.
        int DecommissionLog();

        /// Clean up Log and set it to an inactive state.
        /// Calls Delete on m_log.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int DecommissionLog(std::string &errmsg);

        // - - - Module Configuration - - -

        /// Initializer routine for Module Configuration.
        /// Initializes m_moduleConfiguration with a new AmmDataType pointer.
        /// @returns 0 if successful.
        int InitializeModuleConfiguration();

        /// Overload initializer routine for Module Configuration.
        /// Initializes m_moduleConfiguration with a new AmmDataType pointer.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int InitializeModuleConfiguration(std::string &errmsg);

        /// State of whether Module Configuration is currently valid.
        /// @returns True if m_moduleConfiguration is valid pointer.
        bool IsModuleConfigurationInitialized();

        /// Create the data publisher for Module Configuration on this module.
        /// Allows Module Configuration data to be published to the DDS network.
        /// @returns 0 if successful.
        int CreateModuleConfigurationPublisher();

        /// Create the data publisher for Module Configuration on this module.
        /// Allows Module Configuration data to be published to the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int CreateModuleConfigurationPublisher(std::string &errmsg);

        /// Remove the publisher for Module Configuration on this module from the DDS network.
        /// @returns 0 if successful.
        int RemoveModuleConfigurationPublisher();

        /// Remove the publisher for Module Configuration on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemoveModuleConfigurationPublisher(std::string &errmsg);

        /// Create the data subscriber for Module Configuration published events on this module.
        /// Allows the module to receive Module Configuration data when it is published on the DDS network.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreateModuleConfigurationSubscriber(
           void (*onEvent)(AMM::ModuleConfiguration &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Create the data subscriber for Module Configuration published events on this module.
        /// Allows the module to receive Module Configuration data when it is published on the DDS network.
        /// @param errmsg Error message output.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreateModuleConfigurationSubscriber(
           std::string &errmsg, void (*onEvent)(AMM::ModuleConfiguration &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Remove the subscriber for Module Configuration on this module from the DDS network.
        /// @returns 0 if successful.
        int RemoveModuleConfigurationSubscriber();

        /// Remove the subscriber for Module Configuration on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemoveModuleConfigurationSubscriber(std::string &errmsg);

        /// Call upon the active publisher for Module Configuration to write data to the DDS network.
        /// @param a Reference to Module Configuration data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WriteModuleConfiguration(AMM::ModuleConfiguration &a);

        /// Call upon the active publisher for Module Configuration to write data to the DDS network.
        /// @param errmsg Error message output.
        /// @param a Reference to Module Configuration data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WriteModuleConfiguration(std::string &errmsg, AMM::ModuleConfiguration &a);

        /// Listener Interface override for handling Module Configuration subscribed events.
        /// Calls OnEvent on m_moduleConfiguration passing along data to the handler defined by
        /// the user in CreateModuleConfigurationSubscriber.
        /// @see AmmDataType::OnEvent
        /// @see ListenerInterface::onNewModuleConfiguration
        /// @param modConfig incoming Module Configuration data from the DDS network.
        /// @param info FastRTPS sample info.
        void
        onNewModuleConfiguration(AMM::ModuleConfiguration modConfig, eprosima::fastrtps::SampleInfo_t *info) override;

        /// Clean up Module Configuration and set it to an inactive state.
        /// Calls Delete on m_moduleConfiguration.
        /// @returns 0 if successful.
        int DecommissionModuleConfiguration();

        /// Clean up Module Configuration and set it to an inactive state.
        /// Calls Delete on m_moduleConfiguration.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int DecommissionModuleConfiguration(std::string &errmsg);

        // - - - Omitted Event - - -

        /// Initializer routine for Omitted Event.
        /// Initializes m_omittedEvent with a new AmmDataType pointer.
        /// @returns 0 if successful.
        int InitializeOmittedEvent();

        /// Overload initializer routine for Omitted Event.
        /// Initializes m_omittedEvent with a new AmmDataType pointer.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int InitializeOmittedEvent(std::string &errmsg);

        /// State of whether Omitted Event is currently valid.
        /// @returns True if m_omittedEvent is valid pointer.
        bool IsOmittedEventInitialized();

        /// Create the data publisher for Omitted Event on this module.
        /// Allows Omitted Event data to be published to the DDS network.
        /// @returns 0 if successful.
        int CreateOmittedEventPublisher();

        /// Create the data publisher for Omitted Event on this module.
        /// Allows Omitted Event data to be published to the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int CreateOmittedEventPublisher(std::string &errmsg);

        /// Remove the publisher for Omitted Event on this module from the DDS network.
        /// @returns 0 if successful.
        int RemoveOmittedEventPublisher();

        /// Remove the publisher for Omitted Event on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemoveOmittedEventPublisher(std::string &errmsg);

        /// Create the data subscriber for Omitted Event published events on this module.
        /// Allows the module to receive Omitted Event data when it is published on the DDS network.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreateOmittedEventSubscriber(
           void (*onEvent)(AMM::OmittedEvent &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Create the data subscriber for Omitted Event published events on this module.
        /// Allows the module to receive Omitted Event data when it is published on the DDS network.
        /// @param errmsg Error message output.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreateOmittedEventSubscriber(
           std::string &errmsg, void (*onEvent)(AMM::OmittedEvent &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Remove the subscriber for Omitted Event on this module from the DDS network.
        /// @returns 0 if successful.
        int RemoveOmittedEventSubscriber();

        /// Remove the subscriber for Omitted Event on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemoveOmittedEventSubscriber(std::string &errmsg);

        /// Call upon the active publisher for Omitted Event to write data to the DDS network.
        /// @param a Reference to Omitted Event data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WriteOmittedEvent(AMM::OmittedEvent &a);

        /// Call upon the active publisher for Omitted Event to write data to the DDS network.
        /// @param errmsg Error message output.
        /// @param a Reference to Omitted Event data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WriteOmittedEvent(std::string &errmsg, AMM::OmittedEvent &a);

        /// Listener Interface override for handling Omitted Event subscribed events.
        /// Calls OnEvent on m_omittedEvent passing along data to the handler defined by
        /// the user in CreateOmittedEventSubscriber.
        /// @see AmmDataType::OnEvent
        /// @see ListenerInterface::onNewOmittedEvent
        /// @param omittedEvent incoming Omitted Event data from the DDS network.
        /// @param info FastRTPS sample info..
        void onNewOmittedEvent(AMM::OmittedEvent omittedEvent, eprosima::fastrtps::SampleInfo_t *info) override;

        /// Clean up Omitted Event and set it to an inactive state.
        /// Calls Delete on m_omittedEvent.
        /// @returns 0 if successful.
        int DecommissionOmittedEvent();

        /// Clean up Omitted Event and set it to an inactive state.
        /// Calls Delete on m_omittedEvent.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int DecommissionOmittedEvent(std::string &errmsg);

        // - - - Operational Description - - -

        /// Initializer routine for Operational Description.
        /// Initializes m_operationalDescription with a new AmmDataType pointer.
        /// @returns 0 if successful.
        int InitializeOperationalDescription();

        /// Overload initializer routine for Operational Description.
        /// Initializes m_operationalDescription with a new AmmDataType pointer.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int InitializeOperationalDescription(std::string &errmsg);

        /// State of whether Operational Description is currently valid.
        /// @returns True if m_operationalDescription is valid pointer.
        bool IsOperationalDescriptionInitialized();

        /// Create the data publisher for Operational Description on this module.
        /// Allows Operational Description data to be published to the DDS network.
        /// @returns 0 if successful.
        int CreateOperationalDescriptionPublisher();

        /// Create the data publisher for Operational Desription on this module.
        /// Allows Operational Description data to be published to the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int CreateOperationalDescriptionPublisher(std::string &errmsg);

        /// Remove the publisher for Operational Description on this module from the DDS network.
        /// @returns 0 if successful.
        int RemoveOperationalDescriptionPublisher();

        /// Remove the publisher for Operational Description on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemoveOperationalDescriptionPublisher(std::string &errmsg);

        /// Create the data subscriber for Operational Description published events on this module.
        /// Allows the module to receive Operational Description data when it is published on the DDS network.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreateOperationalDescriptionSubscriber(
           void (*onEvent)(AMM::OperationalDescription &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Create the data subscriber for Operational Description published events on this module.
        /// Allows the module to receive Operational Description data when it is published on the DDS network.
        /// @param errmsg Error message output.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreateOperationalDescriptionSubscriber(
           std::string &errmsg, void (*onEvent)(AMM::OperationalDescription &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Remove the subscriber for Operation Description on this module from the DDS network.
        /// @returns 0 if successful.
        int RemoveOperationalDescriptionSubscriber();

        /// Remove the subscriber for Operational Description on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemoveOperationalDescriptionSubscriber(std::string &errmsg);

        /// Call upon the active publisher for Operational Description to write data to the DDS network.
        /// @param a Reference to Operational Description data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WriteOperationalDescription(AMM::OperationalDescription &a);

        /// Call upon the active publisher for Operational Description to write data to the DDS network.
        /// @param errmsg Error message output.
        /// @param a Reference to Operational Description data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WriteOperationalDescription(std::string &errmsg, AMM::OperationalDescription &a);

        /// Listener Interface override for handling Operational Description subscribed events.
        /// Calls OnEvent on m_operationalDescription passing along data to the handler defined by
        /// the user in CreateOperationalDescriptionSubscriber.
        /// @see AmmDataType::OnEvent
        /// @see ListenerInterface::onNewOperationalDescription
        /// @param opDescript incoming Operational Description data from the DDS network.
        /// @param info FastRTPS sample info.
        void onNewOperationalDescription(AMM::OperationalDescription opDescript,
                                         eprosima::fastrtps::SampleInfo_t *info) override;

        /// Clean up Operational Description and set it to an inactive state.
        /// Calls Delete on m_operationalDescription.
        /// @returns 0 if successful.
        int DecommissionOperationalDescription();

        /// Clean up Operational Description and set it to an inactive state.
        /// Calls Delete on m_operationalDescription.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int DecommissionOperationalDescription(std::string &errmsg);

        // - - - Physiology Modification - - -

        /// Initializer routine for Physiology Modification.
        /// Initializes m_physiologyModification with a new AmmDataType pointer.
        /// @returns 0 if successful.
        int InitializePhysiologyModification();

        /// Overload initializer routine for Physiology Modification.
        /// Initializes m_physiologyModification with a new AmmDataType pointer.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int InitializePhysiologyModification(std::string &errmsg);

        /// State of whether Physiology Modfication is currently valid.
        /// @returns True if m_physiologyModification is valid pointer.
        bool IsPhysiologyModificationInitialized();

        /// Create the data publisher for Physiology Modification on this module.
        /// Allows Physiology Modification data to be published to the DDS network.
        /// @returns 0 if successful.
        int CreatePhysiologyModificationPublisher();

        /// Create the data publisher for Physiology Modification on this module.
        /// Allows Physiology Modification data to be published to the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int CreatePhysiologyModificationPublisher(std::string &errmsg);

        /// Remove the publisher for Physiology Modification on this module from the DDS network.
        /// @returns 0 if successful.
        int RemovePhysiologyModificationPublisher();

        /// Remove the publisher for Physiology Modification on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemovePhysiologyModificationPublisher(std::string &errmsg);

        /// Create the data subscriber for Physiology Modification published events on this module.
        /// Allows the module to receive Physiology Modification data when it is published on the DDS network.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreatePhysiologyModificationSubscriber(
           void (*onEvent)(AMM::PhysiologyModification &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Create the data subscriber for Physiology Modification published events on this module.
        /// Allows the module to receive Physiology Modification data when it is published on the DDS network.
        /// @param errmsg Error message output.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreatePhysiologyModificationSubscriber(
           std::string &errmsg, void (*onEvent)(AMM::PhysiologyModification &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Remove the subscriber for Physiology Modification on this module from the DDS network.
        /// @returns 0 if successful.
        int RemovePhysiologyModificationSubscriber();

        /// Remove the subscriber for Physiology Modification on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemovePhysiologyModificationSubscriber(std::string &errmsg);

        /// Call upon the active publisher for Physiology Modification to write data to the DDS network.
        /// @param a Reference to Physiology Modification data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WritePhysiologyModification(AMM::PhysiologyModification &a);

        /// Call upon the active publisher for Physiology Modification to write data to the DDS network.
        /// @param errmsg Error message output.
        /// @param a Reference to Physiology Modification data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WritePhysiologyModification(std::string &errmsg, AMM::PhysiologyModification &a);

        /// Listener Interface override for handling Physiology Modification subscribed events.
        /// Calls OnEvent on m_physiologyModification passing along data to the handler defined by
        /// the user in CreatePhysiologyModificationSubscriber.
        /// @see AmmDataType::OnEvent
        /// @see ListenerInterface::onNewPhysiologyModification
        /// @param physMod incoming Physiology Modification data from the DDS network.
        /// @param info FastRTPS sample info.
        void onNewPhysiologyModification(AMM::PhysiologyModification physMod,
                                         eprosima::fastrtps::SampleInfo_t *info) override;

        /// Clean up Physiology Modification and set it to an inactive state.
        /// Calls Delete on m_physiologyModification.
        /// @returns 0 if successful.
        int DecommissionPhysiologyModification();

        /// Clean up Physiology Modification and set it to an inactive state.
        /// Calls Delete on m_physiologyModification.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int DecommissionPhysiologyModification(std::string &errmsg);

        // - - - Physioogy Value - - -

        /// Initializer routine for Physiology Value.
        /// Initializes m_physiologyValue with a new AmmDataType pointer.
        /// @returns 0 if successful.
        int InitializePhysiologyValue();

        /// Overload initializer routine for Physiology Value.
        /// Initializes m_physiologyValue with a new AmmDataType pointer.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int InitializePhysiologyValue(std::string &errmsg);

        /// State of whether Physiology Value is currently valid.
        /// @returns True if m_physiologyValue is valid pointer.
        bool IsPhysiologyValueInitialized();

        /// Create the data publisher for Physiology Value on this module.
        /// Allows Physiology Value data to be published to the DDS network.
        /// @returns 0 if successful.
        int CreatePhysiologyValuePublisher();

        /// Create the data publisher for Physiology Value on this module.
        /// Allows Physiology Value data to be published to the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int CreatePhysiologyValuePublisher(std::string &errmsg);

        /// Remove the publisher for Physiology Value on this module from the DDS network.
        /// @returns 0 if successful.
        int RemovePhysiologyValuePublisher();

        /// Remove the publisher for Physiology Value on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemovePhysiologyValuePublisher(std::string &errmsg);

        /// Create the data subscriber for Physiology Value published events on this module.
        /// Allows the module to receive Physiology Value data when it is published on the DDS network.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreatePhysiologyValueSubscriber(
           void (*onEvent)(AMM::PhysiologyValue &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Create the data subscriber for Physiology Value published events on this module.
        /// Allows the module to receive Physiology Value data when it is published on the DDS network.
        /// @param errmsg Error message output.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreatePhysiologyValueSubscriber(
           std::string &errmsg, void (*onEvent)(AMM::PhysiologyValue &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Remove the subscriber for Physiology Value on this module from the DDS network.
        /// @returns 0 if successful.
        int RemovePhysiologyValueSubscriber();

        /// Remove the subscriber for Physiology Value on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemovePhysiologyValueSubscriber(std::string &errmsg);

        /// Call upon the active publisher for Physiology Value to write data to the DDS network.
        /// @param a Reference to Physiology Value data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WritePhysiologyValue(AMM::PhysiologyValue &a);

        /// Call upon the active publisher for Physiology Value to write data to the DDS network.
        /// @param errmsg Error message output.
        /// @param a Reference to Physiology Value data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WritePhysiologyValue(std::string &errmsg, AMM::PhysiologyValue &a);

        /// Listener Interface override for handling Physiology Value subscribed events.
        /// Calls OnEvent on m_physiologyValue passing along data to the handler defined by
        /// the user in CreatePhysiologyValueSubscriber.
        /// @see AmmDataType::OnEvent
        /// @see ListenerInterface::onNewPhysiologyValue
        /// @param physVal incoming Physiology Value data from the DDS network.
        /// @param info FastRTPS sample info.
        void onNewPhysiologyValue(AMM::PhysiologyValue physVal, eprosima::fastrtps::SampleInfo_t *info) override;

        /// Clean up Physiology Value and set it to an inactive state.
        /// Calls Delete on m_physiologyValue.
        /// @returns 0 if successful.
        int DecommissionPhysiologyValue();

        /// Clean up Physiology Value and set it to an inactive state.
        /// Calls Delete on m_physiologyValue.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int DecommissionPhysiologyValue(std::string &errmsg);

        // - - - Physiology Waveform - - -

        /// Initializer routine for Physiology Waveform.
        /// Initializes m_physiologyWaveform with a new AmmDataType pointer.
        /// @returns 0 if successful.
        int InitializePhysiologyWaveform();

        /// Overload initializer routine for Physiology Waveform.
        /// Initializes m_physiolgyWaveform with a new AmmDataType pointer.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int InitializePhysiologyWaveform(std::string &errmsg);

        /// State of whether Physiology Waveform is currently valid.
        /// @returns True if m_physiologyWaveform is valid pointer.
        bool IsPhysiologyWaveformInitialized();

        /// Create the data publisher for Physiology Waveform on this module.
        /// Allows Physiology Waveform data to be published to the DDS network.
        /// @returns 0 if successful.
        int CreatePhysiologyWaveformPublisher();

        /// Create the data publisher for Physiology Waveform on this module.
        /// Allows Physiology Waveform data to be published to the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int CreatePhysiologyWaveformPublisher(std::string &errmsg);

        /// Remove the publisher for Physiology Waveform on this module from the DDS network.
        /// @returns 0 if successful.
        int RemovePhysiologyWaveformPublisher();

        /// Remove the publisher for Physiology Waveform on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemovePhysiologyWaveformPublisher(std::string &errmsg);

        /// Create the data subscriber for Physiology Waveform published events on this module.
        /// Allows the module to receive Physiology Waeform data when it is published on the DDS network.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreatePhysiologyWaveformSubscriber(
           void (*onEvent)(AMM::PhysiologyWaveform &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Create the data subscriber for Physiology Waveform published events on this module.
        /// Allows the module to receive Physiology Waveform data when it is published on the DDS network.
        /// @param errmsg Error message output.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreatePhysiologyWaveformSubscriber(
           std::string &errmsg, void (*onEvent)(AMM::PhysiologyWaveform &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Remove the subscriber for Physiology Waveform on this module from the DDS network.
        /// @returns 0 if successful.
        int RemovePhysiologyWaveformSubscriber();

        /// Remove the subscriber for Physiology Waveform on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemovePhysiologyWaveformSubscriber(std::string &errmsg);

        /// Call upon the active publisher for Physiology Waveform to write data to the DDS network.
        /// @param a Reference to Physiology Waveform data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WritePhysiologyWaveform(AMM::PhysiologyWaveform &a);

        /// Call upon the active publisher for Physiology Waveform to write data to the DDS network.
        /// @param errmsg Error message output.
        /// @param a Reference to Physiology Waveform data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WritePhysiologyWaveform(std::string &errmsg, AMM::PhysiologyWaveform &a);

        /// Listener Interface override for handling Physiology Waveform subscribed events.
        /// Calls OnEvent on m_physiologyWaveform passing along data to the handler defined by
        /// the user in CreatePhysiologyWaveformSubscriber.
        /// @see AmmDataType::OnEvent
        /// @see ListenerInterface::onNewPhysiologyWaveform
        /// @param eventFrag incoming Physiology Waveform data from the DDS network.
        /// @param info FastRTPS sample info.
        void onNewPhysiologyWaveform(AMM::PhysiologyWaveform physWave, eprosima::fastrtps::SampleInfo_t *info) override;

        /// Clean up Physiology Waveform and set it to an inactive state.
        /// Calls Delete on m_physiologyWaveform.
        /// @returns 0 if successful.
        int DecommissionPhysiologyWaveform();

        /// Clean up Physiology Waveform and set it to an inactive state.
        /// Calls Delete on m_physiologyWaveform.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int DecommissionPhysiologyWaveform(std::string &errmsg);

        // - - - Render Modification - - -

        /// Initializer routine for Render Modification.
        /// Initializes m_renderModification with a new AmmDataType pointer.
        /// @returns 0 if successful.
        int InitializeRenderModification();

        /// Overload initializer routine for Render Modification.
        /// Initializes m_renderModification with a new AmmDataType pointer.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int InitializeRenderModification(std::string &errmsg);

        /// State of whether Render Modification is currently valid.
        /// @returns True if m_renderModification is valid pointer.
        bool IsRenderModificationInitialized();

        /// Create the data publisher for Render Modification on this module.
        /// Allows Render Modification data to be published to the DDS network.
        /// @returns 0 if successful.
        int CreateRenderModificationPublisher();

        /// Create the data publisher for Render Modification on this module.
        /// Allows Render Modification data to be published to the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int CreateRenderModificationPublisher(std::string &errmsg);

        /// Remove the publisher for Render Modification on this module from the DDS network.
        /// @returns 0 if successful.
        int RemoveRenderModificationPublisher();

        /// Remove the publisher for Render Modification on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemoveRenderModificationPublisher(std::string &errmsg);

        /// Create the data subscriber for Render Modification published events on this module.
        /// Allows the module to receive Render Modification data when it is published on the DDS network.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreateRenderModificationSubscriber(
           void (*onEvent)(AMM::RenderModification &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Create the data subscriber for Render Modification published events on this module.
        /// Allows the module to receive Render Modification data when it is published on the DDS network.
        /// @param errmsg Error message output.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreateRenderModificationSubscriber(
           std::string &errmsg, void (*onEvent)(AMM::RenderModification &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Remove the subscriber for Render Modification on this module from the DDS network.
        /// @returns 0 if successful.
        int RemoveRenderModificationSubscriber();

        /// Remove the subscriber for Render Modification on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemoveRenderModificationSubscriber(std::string &errmsg);

        /// Call upon the active publisher for Render Modification to write data to the DDS network.
        /// @param a Reference to Render Modification data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WriteRenderModification(AMM::RenderModification &a);

        /// Call upon the active publisher for Render Modification to write data to the DDS network.
        /// @param errmsg Error message output.
        /// @param a Reference to Render Modification data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WriteRenderModification(std::string &errmsg, AMM::RenderModification &a);

        /// Listener Interface override for handling Render Modification subscribed events.
        /// Calls OnEvent on m_renderModification passing along data to the handler defined by
        /// the user in CreateRenderModificationSubscriber.
        /// @see AmmDataType::OnEvent
        /// @see ListenerInterface::onNewRenderModification
        /// @param eventFrag incoming Render Modification data from the DDS network.
        /// @param info FastRTPS sample info.
        void onNewRenderModification(AMM::RenderModification rendMod, eprosima::fastrtps::SampleInfo_t *info) override;

        /// Clean up Render Modification and set it to an inactive state.
        /// Calls Delete on m_renderModification.
        /// @returns 0 if successful.
        int DecommissionRenderModification();

        /// Clean up Render Modification and set it to an inactive state.
        /// Calls Delete on m_renderModification.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int DecommissionRenderModification(std::string &errmsg);

        // - - - Simulation Control - - -

        /// Initializer routine for Simulation Control.
        /// Initializes m_simulationControl with a new AmmDataType pointer.
        /// @returns 0 if successful.
        int InitializeSimulationControl();

        /// Overload initializer routine for Simulation Control.
        /// Initializes m_simulationControl with a new AmmDataType pointer.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int InitializeSimulationControl(std::string &errmsg);

        /// State of whether Simulation Control is currently valid.
        /// @returns True if m_simulationControl is valid pointer.
        bool IsSimulationControlInitialized();

        /// Create the data publisher for Simulation Control on this module.
        /// Allows Simulation Control data to be published to the DDS network.
        /// @returns 0 if successful.
        int CreateSimulationControlPublisher();

        /// Create the data publisher for Eve on this module.
        /// Allows Simulation Control data to be published to the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int CreateSimulationControlPublisher(std::string &errmsg);

        /// Remove the publisher for Simulation Control on this module from the DDS network.
        /// @returns 0 if successful.
        int RemoveSimulationControlPublisher();

        /// Remove the publisher for Simulation Control on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemoveSimulationControlPublisher(std::string &errmsg);

        /// Create the data subscriber for Simulation Control published events on this module.
        /// Allows the module to receive Simulation Control data when it is published on the DDS network.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreateSimulationControlSubscriber(
           void (*onEvent)(AMM::SimulationControl &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Create the data subscriber for Simulation Control published events on this module.
        /// Allows the module to receive Simulation Control data when it is published on the DDS network.
        /// @param errmsg Error message output.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreateSimulationControlSubscriber(
           std::string &errmsg, void (*onEvent)(AMM::SimulationControl &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Remove the subscriber for Simulation Control on this module from the DDS network.
        /// @returns 0 if successful.
        int RemoveSimulationControlSubscriber();

        /// Remove the subscriber for Simulation Control on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemoveSimulationControlSubscriber(std::string &errmsg);

        /// Call upon the active publisher for Simulation Control to write data to the DDS network.
        /// @param a Reference to Simulation Control data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WriteSimulationControl(AMM::SimulationControl &a);

        /// Call upon the active publisher for Simulation Control to write data to the DDS network.
        /// @param errmsg Error message output.
        /// @param a Reference to Simulation Control data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WriteSimulationControl(std::string &errmsg, AMM::SimulationControl &a);

        /// Listener Interface override for handling Simulation Control subscribed events.
        /// Calls OnEvent on m_simulationControl passing along data to the handler defined by
        /// the user in CreateSimulationControlSubscriber.
        /// @see AmmDataType::OnEvent
        /// @see ListenerInterface::onNewSimulationControl
        /// @param eventFrag incoming Simulation Control data from the DDS network.
        /// @param info FastRTPS sample info.
        void onNewSimulationControl(AMM::SimulationControl simControl, eprosima::fastrtps::SampleInfo_t *info) override;

        /// Clean up Simulation Control and set it to an inactive state.
        /// Calls Delete on m_simulationControl.
        /// @returns 0 if successful.
        int DecommissionSimulationControl();

        /// Clean up Simulation Control and set it to an inactive state.
        /// Calls Delete on m_simulationControl.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int DecommissionSimulationControl(std::string &errmsg);

        // - - - Status - - -

        /// Initializer routine for Status.
        /// Initializes m_stuatus with a new AmmDataType pointer.
        /// @returns 0 if successful.
        int InitializeStatus();

        /// Overload initializer routine for Status.
        /// Initializes m_status with a new AmmDataType pointer.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int InitializeStatus(std::string &errmsg);

        /// State of whether Status is currently valid.
        /// @returns True if m_status is valid pointer.
        bool IsStatusInitialized();

        /// Create the data publisher for Status on this module.
        /// Allows Status data to be published to the DDS network.
        /// @returns 0 if successful.
        int CreateStatusPublisher();

        /// Create the data publisher for Status on this module.
        /// Allows Status data to be published to the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int CreateStatusPublisher(std::string &errmsg);

        /// Remove the publisher for Status on this module from the DDS network.
        /// @returns 0 if successful.
        int RemoveStatusPublisher();

        /// Remove the publisher for Status on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemoveStatusPublisher(std::string &errmsg);

        /// Create the data subscriber for Status published events on this module.
        /// Allows the module to receive Status data when it is published on the DDS network.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreateStatusSubscriber(
           void (*onEvent)(AMM::Status &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Create the data subscriber for Status published events on this module.
        /// Allows the module to receive Status data when it is published on the DDS network.
        /// @param errmsg Error message output.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreateStatusSubscriber(
           std::string &errmsg, void (*onEvent)(AMM::Status &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Remove the subscriber for Status on this module from the DDS network.
        /// @returns 0 if successful.
        int RemoveStatusSubscriber();

        /// Remove the subscriber for Status on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemoveStatusSubscriber(std::string &errmsg);

        /// Call upon the active publisher for Status to write data to the DDS network.
        /// @param a Reference to Status data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WriteStatus(AMM::Status &a);

        /// Call upon the active publisher for Status to write data to the DDS network.
        /// @param errmsg Error message output.
        /// @param a Reference to Status data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WriteStatus(std::string &errmsg, AMM::Status &a);

        /// Listener Interface override for handling Status subscribed events.
        /// Calls OnEvent on m_status passing along data to the handler defined by
        /// the user in CreateStatusSubscriber.
        /// @see AmmDataType::OnEvent
        /// @see ListenerInterface::onNewStatus
        /// @param status incoming Status data from the DDS network.
        /// @param info FastRTPS sample info.
        void onNewStatus(AMM::Status status, eprosima::fastrtps::SampleInfo_t *info) override;

        /// Clean up Status and set it to an inactive state.
        /// Calls Delete on m_status.
        /// @returns 0 if successful.
        int DecommissionStatus();

        /// Clean up Status and set it to an inactive state.
        /// Calls Delete on m_status.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int DecommissionStatus(std::string &errmsg);

        // - - - Tick - - -

        /// Initializer routine for Tick.
        /// Initializes m_tick with a new AmmDataType pointer.
        /// @returns 0 if successful.
        int InitializeTick();

        /// Overload initializer routine for Tick.
        /// Initializes m_tick with a new AmmDataType pointer.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int InitializeTick(std::string &errmsg);

        /// State of whether Tick is currently valid.
        /// @returns True if m_tick is valid pointer.
        bool IsTickInitialized();

        /// Create the data publisher for Tick on this module.
        /// Allows Tick data to be published to the DDS network.
        /// @returns 0 if successful.
        int CreateTickPublisher();

        /// Create the data publisher for Tick on this module.
        /// Allows Tick data to be published to the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int CreateTickPublisher(std::string &errmsg);

        /// Remove the publisher for Tick on this module from the DDS network.
        /// @returns 0 if successful.
        int RemoveTickPublisher();

        /// Remove the publisher for Tick on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemoveTickPublisher(std::string &errmsg);

        /// Create the data subscriber for Tick published events on this module.
        /// Allows the module to receive Tick data when it is published on the DDS network.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreateTickSubscriber(
           void (*onEvent)(AMM::Tick &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Create the data subscriber for Tick published events on this module.
        /// Allows the module to receive Tick data when it is published on the DDS network.
        /// @param errmsg Error message output.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreateTickSubscriber(
           std::string &errmsg, void (*onEvent)(AMM::Tick &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Remove the subscriber for Tick on this module from the DDS network.
        /// @returns 0 if successful.
        int RemoveTickSubscriber();

        /// Remove the subscriber for Tick on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemoveTickSubscriber(std::string &errmsg);

        /// Call upon the active publisher for Tick to write data to the DDS network.
        /// @param a Reference to Tick data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WriteTick(AMM::Tick &a);

        /// Call upon the active publisher for Tick to write data to the DDS network.
        /// @param errmsg Error message output.
        /// @param a Reference to Tick data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WriteTick(std::string &errmsg, AMM::Tick &a);

        /// Listener Interface override for handling Tick subscribed events.
        /// Calls OnEvent on m_tick passing along data to the handler defined by
        /// the user in CreateTickSubscriber.
        /// @see AmmDataType::OnEvent
        /// @see ListenerInterface::onNewTick
        /// @param tick incoming Tick data from the DDS network.
        /// @param info FastRTPS sample info.
        void onNewTick(AMM::Tick tick, eprosima::fastrtps::SampleInfo_t *info) override;

        /// Clean up Tick and set it to an inactive state.
        /// Calls Delete on m_tick.
        /// @returns 0 if successful.
        int DecommissionTick();

        /// Clean up Tick and set it to an inactive state.
        /// Calls Delete on m_tick.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int DecommissionTick(std::string &errmsg);

        // - - - Instrument Data - - -

        /// Initializer routine for Instrument Data.
        /// Initializes m_instrumentData with a new AmmDataType pointer.
        /// @returns 0 if successful.
        int InitializeInstrumentData();

        /// Overload initializer routine for Instrument Data.
        /// Initializes m_instrumentData with a new AmmDataType pointer.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int InitializeInstrumentData(std::string &errmsg);

        /// State of whether Instrument Data is currently valid.
        /// @returns True if m_instrumentData is valid pointer.
        bool IsInstrumentDataInitialized();

        /// Create the data publisher for Instrument Data on this module.
        /// Allows Instrument Data data to be published to the DDS network.
        /// @returns 0 if successful.
        int CreateInstrumentDataPublisher();

        /// Create the data publisher for Instrument Data on this module.
        /// Allows Instrument Data data to be published to the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int CreateInstrumentDataPublisher(std::string &errmsg);

        /// Remove the publisher for Instrument Data on this module from the DDS network.
        /// @returns 0 if successful.
        int RemoveInstrumentDataPublisher();

        /// Remove the publisher for Instrument Data on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemoveInstrumentDataPublisher(std::string &errmsg);

        /// Create the data subscriber for Instrument Data published events on this module.
        /// Allows the module to receive Instrument Data data when it is published on the DDS network.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreateInstrumentDataSubscriber(
           void (*onEvent)(AMM::InstrumentData &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Create the data subscriber for Instrument Data published events on this module.
        /// Allows the module to receive Instrument Data data when it is published on the DDS network.
        /// @param errmsg Error message output.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreateInstrumentDataSubscriber(
           std::string &errmsg, void (*onEvent)(AMM::InstrumentData &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Remove the subscriber for Instrument Data on this module from the DDS network.
        /// @returns 0 if successful.
        int RemoveInstrumentDataSubscriber();

        /// Remove the subscriber for Instrument Data on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemoveInstrumentDataSubscriber(std::string &errmsg);

        /// Call upon the active publisher for Instrument Data to write data to the DDS network.
        /// @param a Reference to Instrument Data data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WriteInstrumentData(AMM::InstrumentData &a);

        /// Call upon the active publisher for Instrument Data to write data to the DDS network.
        /// @param errmsg Error message output.
        /// @param a Reference to Instrument Data data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WriteInstrumentData(std::string &errmsg, AMM::InstrumentData &a);

        /// Listener Interface override for handling Instrument Data subscribed events.
        /// Calls OnEvent on m_instrumentData passing along data to the handler defined by
        /// the user in CreateInstrumentDataSubscriber.
        /// @see AmmDataType::OnEvent
        /// @see ListenerInterface::onNewInstrumentData
        /// @param instData incoming Instrument Data data from the DDS network.
        /// @param info FastRTPS sample info.
        void onNewInstrumentData(AMM::InstrumentData instData, eprosima::fastrtps::SampleInfo_t *info) override;

        /// Clean up Instrument Data and set it to an inactive state.
        /// Calls Delete on m_instrumentData.
        /// @returns 0 if successful.
        int DecommissionInstrumentData();

        /// Clean up Instrument Data and set it to an inactive state.
        /// Calls Delete on m_instrumentData.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int DecommissionInstrumentData(std::string &errmsg);

        // - - - Command - - -

        /// Initializer routine for Command.
        /// Initializes m_command with a new AmmDataType pointer.
        /// @returns 0 if successful.
        int InitializeCommand();

        /// Overload initializer routine for Command.
        /// Initializes m_command with a new AmmDataType pointer.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int InitializeCommand(std::string &errmsg);

        /// State of whether Command is currently valid.
        /// @returns True if m_command is valid pointer.
        bool IsCommandInitialized();

        /// Create the data publisher for Command on this module.
        /// Allows Command data to be published to the DDS network.
        /// @returns 0 if successful.
        int CreateCommandPublisher();

        /// Create the data publisher for Command on this module.
        /// Allows Command data to be published to the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int CreateCommandPublisher(std::string &errmsg);

        /// Remove the publisher for Command on this module from the DDS network.
        /// @returns 0 if successful.
        int RemoveCommandPublisher();

        /// Remove the publisher for Command on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemoveCommandPublisher(std::string &errmsg);

        /// Create the data subscriber for Command published events on this module.
        /// Allows the module to receive Command data when it is published on the DDS network.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreateCommandSubscriber(
           void (*onEvent)(AMM::Command &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Create the data subscriber for Command published events on this module.
        /// Allows the module to receive Command data when it is published on the DDS network.
        /// @param errmsg Error message output.
        /// @param parentClass Reference to the object that is receiving the subscribed event callback.
        /// @param onEvent Method reference of parentClass that is be used as a callback for subscribed events.
        /// @returns 0 if successful.
        int CreateCommandSubscriber(
           std::string &errmsg, void (*onEvent)(AMM::Command &, eprosima::fastrtps::SampleInfo_t *)
        );

        /// Remove the subscriber for Command on this module from the DDS network.
        /// @returns 0 if successful.
        int RemoveCommandSubscriber();

        /// Remove the subscriber for Command on this module from the DDS network.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int RemoveCommandSubscriber(std::string &errmsg);

        /// Call upon the active publisher for Command to write data to the DDS network.
        /// @param a Reference to Command data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WriteCommand(AMM::Command &a);

        /// Call upon the active publisher for Command to write data to the DDS network.
        /// @param errmsg Error message output.
        /// @param a Reference to Command data to be written.
        /// @returns 0 if successful.
        /// @returns 1 if Publisher has not been created or if some other error occurred.
        int WriteCommand(std::string &errmsg, AMM::Command &a);

        /// Listener Interface override for handling Command subscribed events.
        /// Calls OnEvent on m_command passing along data to the handler defined by
        /// the user in CreateCommandSubscriber.
        /// @see AmmDataType::OnEvent
        /// @see ListenerInterface::onNewCommand
        /// @param command incoming Command data from the DDS network.
        /// @param info FastRTPS sample info.
        void onNewCommand(AMM::Command command, eprosima::fastrtps::SampleInfo_t *info) override;

        /// Clean up Command and set it to an inactive state.
        /// Calls Delete on m_command.
        /// @returns 0 if successful.
        int DecommissionCommand();

        /// Clean up Command and set it to an inactive state.
        /// Calls Delete on m_command.
        /// @param errmsg Error message output.
        /// @returns 0 if successful.
        int DecommissionCommand(std::string &errmsg);


    }; // class DDSManager <>


    inline DDSManager<void>::DDSManager(std::string configFile) {

       /*eprosima::fastrtps::ParticipantAttributes pa;
   pa.rtps.builtin.domainId = (uint32_t) DOMAIN_ID;
   pa.rtps.setName(moduleName.c_str());*/
       try {
          if (!eprosima::fastrtps::Domain::loadXMLProfilesFile(configFile)) {
             std::cout << "Unable to load XML file to create FastRTPS domain participant." << std::endl;
          }
          m_participant = eprosima::fastrtps::Domain::createParticipant("amm_participant");
       } catch (std::exception &e) {
          std::cerr << e.what() << std::endl;
       }
       if (m_participant == nullptr) {
          std::cout << "Unable to create FastRTPS domain participant." << std::endl;
          return;
       }

       m_pubListener = new DDS_Listeners::PubListener();

       m_moduleId = DDSManager::GenerateUuidString();
       m_moduleName = m_participant->getAttributes().rtps.getName();

    }

    inline void DDSManager<void>::Shutdown(std::string &errmsg) {
       int err = 0;

       /// Output from each decommission.
       std::string localerrmsg;

       if (DecommissionAssessment(localerrmsg) != 0) errmsg + localerrmsg + "\n";
       if (DecommissionEventFragment(localerrmsg) != 0) errmsg + localerrmsg + "\n";
       if (DecommissionEventRecord(localerrmsg) != 0) errmsg + localerrmsg + "\n";
       if (DecommissionFragmentAmendmentRequest(localerrmsg) != 0) errmsg + localerrmsg + "\n";
       if (DecommissionLog(localerrmsg) != 0) errmsg + localerrmsg + "\n";
       if (DecommissionModuleConfiguration(localerrmsg) != 0) errmsg + localerrmsg + "\n";
       if (DecommissionOmittedEvent(localerrmsg) != 0) errmsg + localerrmsg + "\n";
       if (DecommissionOperationalDescription(localerrmsg) != 0) errmsg + localerrmsg + "\n";
       if (DecommissionPhysiologyModification(localerrmsg) != 0) errmsg + localerrmsg + "\n";
       if (DecommissionPhysiologyValue(localerrmsg) != 0) errmsg + localerrmsg + "\n";
       if (DecommissionPhysiologyWaveform(localerrmsg) != 0) errmsg + localerrmsg + "\n";
       if (DecommissionRenderModification(localerrmsg) != 0) errmsg + localerrmsg + "\n";
       if (DecommissionSimulationControl(localerrmsg) != 0) errmsg + localerrmsg + "\n";
       if (DecommissionStatus(localerrmsg) != 0) errmsg + localerrmsg + "\n";
       if (DecommissionTick(localerrmsg) != 0) errmsg + localerrmsg + "\n";
       if (DecommissionInstrumentData(localerrmsg) != 0) errmsg + localerrmsg + "\n";
       if (DecommissionCommand(localerrmsg) != 0) errmsg + localerrmsg + "\n";

       eprosima::fastrtps::Domain::stopAll();
    }

    inline void DDSManager<void>::Shutdown() {
       DecommissionAssessment();
       DecommissionEventFragment();
       DecommissionEventRecord();
       DecommissionFragmentAmendmentRequest();
       DecommissionLog();
       DecommissionModuleConfiguration();
       DecommissionOmittedEvent();
       DecommissionOperationalDescription();
       DecommissionPhysiologyModification();
       DecommissionPhysiologyValue();
       DecommissionPhysiologyWaveform();
       DecommissionRenderModification();
       DecommissionSimulationControl();
       DecommissionStatus();
       DecommissionTick();
       DecommissionInstrumentData();
       DecommissionCommand();

       eprosima::fastrtps::Domain::stopAll();
    }

    inline std::string DDSManager<void>::GenerateUuidString() {
       boost::uuids::uuid uuid = boost::uuids::random_generator()();
       return boost::uuids::to_string(uuid);
    }


// - - - Assessment - - -

    inline int DDSManager<void>::InitializeAssessment() {

       if (m_isAssessmentInit) return 0;

       int err = 0;
       m_assessment = new AmmDataType<ASMT_TYPE, ASMT_LTNR, ASMT>(
          err, ASMT_STR, m_participant, m_pubListener
       );

       if (err != 0) return 1;

       m_isAssessmentInit = true;

       return 0;
    }

    inline int DDSManager<void>::InitializeAssessment(std::string &errmsg) {

       if (m_isAssessmentInit) {
          errmsg = "Assessment is already initialized.";
          return 0;
       }

       int err = 0;
       m_assessment = new AmmDataType<ASMT_TYPE, ASMT_LTNR, ASMT>(
          err, errmsg, ASMT_STR, m_participant, m_pubListener
       );

       if (err != 0) return 1;

       m_isAssessmentInit = true;

       return 0;
    }

    inline bool DDSManager<void>::IsAssessmentInitialized() {
       if (m_isAssessmentInit) return m_assessment->IsTypeRegistered();
       return false;
    }

    inline int DDSManager<void>::CreateAssessmentPublisher() {
       if (!m_isAssessmentInit) return 0;
       return m_assessment->CreatePublisher();
    }

    inline int DDSManager<void>::CreateAssessmentPublisher(std::string &errmsg) {
       if (!m_isAssessmentInit) {
          errmsg = "Assessment is not properly initialized";
          return 0;
       }
       return m_assessment->CreatePublisher(errmsg);
    }

    inline int DDSManager<void>::RemoveAssessmentPublisher() {
       if (!m_isAssessmentInit) return 1;
       return m_assessment->RemovePublisher();
    }

    inline int DDSManager<void>::RemoveAssessmentPublisher(std::string &errmsg) {
       if (!m_isAssessmentInit) {
          errmsg = "Assessment is not properly initialized";
          return 1;
       }
       return m_assessment->RemovePublisher(errmsg);
    }

    inline int DDSManager<void>::CreateAssessmentSubscriber(
       void (*onEvent)(AMM::Assessment &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isAssessmentInit) return 1;
       return m_assessment->CreateSubscriber((ListenerInterface *) this, onEvent);
    }

    inline int DDSManager<void>::CreateAssessmentSubscriber(
       std::string &errmsg, void (*onEvent)(AMM::Assessment &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isAssessmentInit) {
          errmsg = "Assessment is not properly initialized";
          return 1;
       }
       return m_assessment->CreateSubscriber(errmsg, (ListenerInterface *) this, onEvent);
    }

    inline int DDSManager<void>::RemoveAssessmentSubscriber() {
       if (!m_isAssessmentInit) return 1;
       return m_assessment->RemoveSubscriber();
    }

    inline int DDSManager<void>::RemoveAssessmentSubscriber(std::string &errmsg) {
       if (!m_isAssessmentInit) {
          errmsg = "Assessment is not properly initialized";
          return 1;
       }
       return m_assessment->RemoveSubscriber(errmsg);
    }

    inline int DDSManager<void>::WriteAssessment(AMM::Assessment &a) {
       if (!m_isAssessmentInit) return 1;
       return m_assessment->Write(a);
    }

    inline int DDSManager<void>::WriteAssessment(std::string &errmsg, AMM::Assessment &a) {
       if (!m_isAssessmentInit) {
          errmsg = "Assessment is not properly initialized.";
          return 1;
       }
       return m_assessment->Write(errmsg, a);
    }

    inline void DDSManager<void>::onNewAssessment(
       AMM::Assessment assessment, eprosima::fastrtps::SampleInfo_t *info
    ) {
       m_assessment->OnEvent(assessment, info);
    }

    inline int DDSManager<void>::DecommissionAssessment() {
       if (!m_isAssessmentInit) return 0;

       if (m_assessment->Delete() != 0) return 1;

       m_isAssessmentInit = false;
       return 0;
    }

    inline int DDSManager<void>::DecommissionAssessment(std::string &errmsg) {
       if (!m_isAssessmentInit) {
          errmsg = "Assessment is already decommissioned.";
          return 0;
       }

       if (m_assessment->Delete(errmsg) != 0) return 1;
       m_isAssessmentInit = false;

       return 0;
    }


// - - - Event Fragment - - -

    inline int DDSManager<void>::InitializeEventFragment() {

       if (m_isEventFragInit) return 0;

       int err = 0;

       m_eventFragment = new AmmDataType<EVFR_TYPE, EVFR_LTNR, EVFR>(
          err, EVFR_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isEventFragInit = true;

       return err;
    }

    inline int DDSManager<void>::InitializeEventFragment(std::string &errmsg) {

       if (m_isEventFragInit) {
          errmsg = "Event Fragment is already initialized.";
          return 0;
       }

       int err = 0;

       m_eventFragment = new AmmDataType<EVFR_TYPE, EVFR_LTNR, EVFR>(
          err, errmsg, EVFR_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isEventFragInit = true;

       return err;
    }

    inline bool DDSManager<void>::IsEventFragmentInitialzied() {
       if (m_isEventFragInit) return m_eventFragment->IsTypeRegistered();
       return false;
    }

    inline int DDSManager<void>::CreateEventFragmentPublisher() {
       if (!m_isEventFragInit) return 1;
       return m_eventFragment->CreatePublisher();
    }

    inline int DDSManager<void>::CreateEventFragmentPublisher(std::string &errmsg) {
       if (!m_isEventFragInit) {
          errmsg = "Event Fragment is not properly initialized.";
          return 1;
       }
       return m_eventFragment->CreatePublisher(errmsg);
    }

    inline int DDSManager<void>::RemoveEventFragmentPublisher() {
       if (!m_isEventFragInit) return 1;
       return m_eventFragment->RemovePublisher();
    }

    inline int DDSManager<void>::RemoveEventFragmentPublisher(std::string &errmsg) {
       if (!m_isEventFragInit) {
          errmsg = "Event Fragment is not properly initialized.";
          return 1;
       }
       return m_eventFragment->RemovePublisher(errmsg);
    }

    inline int DDSManager<void>::CreateEventFragmentSubscriber(
       void (*onEvent)(AMM::EventFragment &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isEventFragInit) return 1;
       return m_eventFragment->CreateSubscriber((ListenerInterface *) this, onEvent);
    }

    inline int DDSManager<void>::CreateEventFragmentSubscriber(
       std::string &errmsg, void (*onEvent)(AMM::EventFragment &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isEventFragInit) {
          errmsg = "Event Fragment is not properly initialized.";
          return 1;
       }
       return m_eventFragment->CreateSubscriber(errmsg, (ListenerInterface *) this, onEvent);
    }

    inline int DDSManager<void>::RemoveEventFragmentSubscriber() {
       if (!m_isEventFragInit) return 1;
       return m_eventFragment->RemoveSubscriber();
    }

    inline int DDSManager<void>::RemoveEventFragmentSubscriber(std::string &errmsg) {
       if (!m_isEventFragInit) {
          errmsg = "Event Fragment is not properly initialized.";
          return 1;
       }
       return m_eventFragment->RemoveSubscriber(errmsg);
    }

    inline int DDSManager<void>::WriteEventFragment(AMM::EventFragment &a) {
       if (!m_isEventFragInit) return 1;
       return m_eventFragment->Write(a);
    }

    inline int DDSManager<void>::WriteEventFragment(std::string &errmsg, AMM::EventFragment &a) {
       if (!m_isEventFragInit) {
          errmsg = "Event Fragment is not properly initialized.";
          return 1;
       }
       return m_eventFragment->Write(errmsg, a);
    }

    inline void DDSManager<void>::onNewEventFragment(
       AMM::EventFragment eventFragment, eprosima::fastrtps::SampleInfo_t *info
    ) {
       m_eventFragment->OnEvent(eventFragment, info);
    }

    inline int DDSManager<void>::DecommissionEventFragment() {
       if (!m_isEventFragInit) return 0;

       int err = m_eventFragment->Delete();
       if (err == 0) m_isEventFragInit = false;

       return err;
    }

    inline int DDSManager<void>::DecommissionEventFragment(std::string &errmsg) {
       if (!m_isEventFragInit) {
          errmsg = "Event Fragment is already decommissioned.";
          return 0;
       }

       int err = m_eventFragment->Delete(errmsg);
       if (err == 0) m_isEventFragInit = false;

       return err;
    }


// - - - Event Record - - -

    inline int DDSManager<void>::InitializeEventRecord() {

       if (m_isEventFragInit) return 0;

       int err = 0;

       m_eventRecord = new AmmDataType<EVRC_TYPE, EVRC_LTNR, EVRC>(
          err, EVRC_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isEventRecInit = true;

       return err;
    }

    inline int DDSManager<void>::InitializeEventRecord(std::string &errmsg) {

       if (m_isEventRecInit) {
          errmsg = "Event Record is already initialized.";
          return 0;
       }

       int err = 0;

       m_eventRecord = new AmmDataType<EVRC_TYPE, EVRC_LTNR, EVRC>(
          err, errmsg, EVRC_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isEventRecInit = true;

       return err;
    }

    inline bool DDSManager<void>::IsEventRecordInitialized() {
       if (m_isEventRecInit) return m_eventRecord->IsTypeRegistered();
       return false;
    }

    inline int DDSManager<void>::CreateEventRecordPublisher() {
       if (!m_isEventRecInit) return 1;
       return m_eventRecord->CreatePublisher();
    }

    inline int DDSManager<void>::CreateEventRecordPublisher(std::string &errmsg) {
       if (!m_isEventRecInit) {
          errmsg = "Event Record is not properly initialized.";
          return 1;
       }
       return m_eventRecord->CreatePublisher(errmsg);
    }

    inline int DDSManager<void>::RemoveEventRecordPublisher() {
       if (!m_isEventRecInit) return 1;
       return m_eventRecord->RemovePublisher();
    }

    inline int DDSManager<void>::RemoveEventRecordPublisher(std::string &errmsg) {
       if (!m_isEventRecInit) {
          errmsg = "Event Record is not properly initialized.";
          return 1;
       }
       return m_eventRecord->RemovePublisher(errmsg);
    }

    inline int DDSManager<void>::CreateEventRecordSubscriber(
       void (*onEvent)(AMM::EventRecord &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isEventRecInit) return 1;
       return m_eventRecord->CreateSubscriber((ListenerInterface *) this, onEvent);
    }

    inline int DDSManager<void>::CreateEventRecordSubscriber(
       std::string &errmsg, void (*onEvent)(AMM::EventRecord &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isEventRecInit) {
          errmsg = "Event Record is not properly initialized.";
          return 1;
       }
       return m_eventRecord->CreateSubscriber(errmsg, (ListenerInterface *) this, onEvent);
    }

    inline int DDSManager<void>::RemoveEventRecordSubscriber() {
       if (!m_isEventRecInit) return 1;
       return m_eventRecord->RemoveSubscriber();
    }

    inline int DDSManager<void>::RemoveEventRecordSubscriber(std::string &errmsg) {
       if (!m_isEventRecInit) {
          errmsg = "Event Record is not properly initialized.";
          return 1;
       }
       return m_eventRecord->RemoveSubscriber(errmsg);
    }

    inline int DDSManager<void>::WriteEventRecord(AMM::EventRecord &a) {
       if (!m_isEventRecInit) return 1;
       return m_eventRecord->Write(a);
    }

    inline int DDSManager<void>::WriteEventRecord(std::string &errmsg, AMM::EventRecord &a) {
       if (!m_isEventRecInit) {
          errmsg = "Event Record is not properly initialized.";
          return 1;
       }
       return m_eventRecord->Write(errmsg, a);
    }

    inline void DDSManager<void>::onNewEventRecord(
       AMM::EventRecord eventRecord, eprosima::fastrtps::SampleInfo_t *info
    ) {
       m_eventRecord->OnEvent(eventRecord, info);
    }

    inline int DDSManager<void>::DecommissionEventRecord() {
       if (!m_isEventRecInit) return 0;

       int err = m_eventRecord->Delete();
       if (err == 0) { m_isEventRecInit = false; }

       return err;
    }

    inline int DDSManager<void>::DecommissionEventRecord(std::string &errmsg) {
       if (!m_isEventRecInit) {
          errmsg = "Event Record is already decommissioned.";
          return 0;
       }

       int err = m_eventRecord->Delete(errmsg);
       if (err == 0) m_isEventRecInit = false;

       return err;
    }


// - - - Fragment Amendment Request - - -

    inline int DDSManager<void>::InitializeFragmentAmendmentRequest() {

       if (m_isFragAmendReqInit) return 0;

       int err = 0;

       m_fragmentAmendmentRequest = new AmmDataType<FARQ_TYPE, FARQ_LTNR, FARQ>(
          err, FARQ_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isFragAmendReqInit = true;

       return err;
    }

    inline int DDSManager<void>::InitializeFragmentAmendmentRequest(std::string &errmsg) {

       if (m_isFragAmendReqInit) {
          errmsg = "Fragment Amendment Request is already initialized.";
          return 0;
       }

       int err = 0;

       m_fragmentAmendmentRequest = new AmmDataType<FARQ_TYPE, FARQ_LTNR, FARQ>(
          err, errmsg, FARQ_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isFragAmendReqInit = true;

       return err;
    }

    inline bool DDSManager<void>::IsFragmentAmendmentRequestInitialized() {
       if (m_isFragAmendReqInit) return m_fragmentAmendmentRequest->IsTypeRegistered();
       return false;
    }

    inline int DDSManager<void>::CreateFragmentAmendmentRequestPublisher() {
       if (!m_isFragAmendReqInit) return 1;
       return m_fragmentAmendmentRequest->CreatePublisher();
    }

    inline int DDSManager<void>::CreateFragmentAmendmentRequestPublisher(std::string &errmsg) {
       if (!m_isFragAmendReqInit) {
          errmsg = "Fragment Amendment Request is not properly initialized.";
          return 1;
       }
       return m_fragmentAmendmentRequest->CreatePublisher(errmsg);
    }

    inline int DDSManager<void>::RemoveFragmentAmendmentRequestPublisher() {
       if (!m_isFragAmendReqInit) return 1;
       return m_fragmentAmendmentRequest->RemovePublisher();
    }

    inline int DDSManager<void>::RemoveFragmentAmendmentRequestPublisher(std::string &errmsg) {
       if (!m_isFragAmendReqInit) {
          errmsg = "Fragment Amendment Request is not properly initialized.";
          return 1;
       }
       return m_fragmentAmendmentRequest->RemovePublisher(errmsg);
    }

    inline int DDSManager<void>::CreateFragmentAmendmentRequestSubscriber(
       void (*onEvent)(AMM::FragmentAmendmentRequest &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isFragAmendReqInit) return 1;
       return m_fragmentAmendmentRequest->CreateSubscriber((ListenerInterface *) this, onEvent);
    }

    inline int DDSManager<void>::CreateFragmentAmendmentRequestSubscriber(
       std::string &errmsg, void (*onEvent)(AMM::FragmentAmendmentRequest &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isFragAmendReqInit) {
          errmsg = "Fragment Amendment Request is not properly initialized.";
          return 1;
       }
       return m_fragmentAmendmentRequest->CreateSubscriber(errmsg, (ListenerInterface *) this, onEvent);
    }

    inline int DDSManager<void>::RemoveFragmentAmendmentRequestSubscriber() {
       return m_fragmentAmendmentRequest->RemoveSubscriber();
    }

    inline int DDSManager<void>::RemoveFragmentAmendmentRequestSubscriber(std::string &errmsg) {
       if (!m_isFragAmendReqInit) {
          errmsg = "Fragment Amendment Request is not properly initialized.";
          return 1;
       }
       return m_fragmentAmendmentRequest->RemoveSubscriber(errmsg);
    }

    inline int DDSManager<void>::WriteFragmentAmendmentRequest(AMM::FragmentAmendmentRequest &a) {
       if (!m_isFragAmendReqInit) return 1;
       return m_fragmentAmendmentRequest->Write(a);
    }

    inline int DDSManager<void>::WriteFragmentAmendmentRequest(std::string &errmsg, AMM::FragmentAmendmentRequest &a) {
       if (!m_isFragAmendReqInit) {
          errmsg = "Fragment Amendment Request is not properly initialized.";
          return 1;
       }
       return m_fragmentAmendmentRequest->Write(errmsg, a);
    }

    inline void DDSManager<void>::onNewFragmentAmendmentRequest(
       AMM::FragmentAmendmentRequest ffar, eprosima::fastrtps::SampleInfo_t *info
    ) {
       m_fragmentAmendmentRequest->OnEvent(ffar, info);
    }

    inline int DDSManager<void>::DecommissionFragmentAmendmentRequest() {
       if (!m_isFragAmendReqInit) return 0;

       int err = m_fragmentAmendmentRequest->Delete();
       if (err == 0) m_isFragAmendReqInit = false;

       return err;
    }

    inline int DDSManager<void>::DecommissionFragmentAmendmentRequest(std::string &errmsg) {
       if (!m_isFragAmendReqInit) {
          errmsg = "Fragment Amendment Request is already decommissioned.";
          return 0;
       }

       int err = m_fragmentAmendmentRequest->Delete(errmsg);
       if (err == 0) m_isFragAmendReqInit = false;

       return err;
    }


// - - - Log - - -

    inline int DDSManager<void>::InitializeLog() {

       if (m_isLogInit) return 0;

       int err = 0;

       m_log = new AmmDataType<ALOG_TYPE, ALOG_LTNR, ALOG>(
          err, ALOG_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isLogInit = true;

       return err;
    }

    inline int DDSManager<void>::InitializeLog(std::string &errmsg) {

       if (m_isLogInit) {
          errmsg = "Log is already initialized.";
          return 0;
       }

       int err = 0;

       m_log = new AmmDataType<ALOG_TYPE, ALOG_LTNR, ALOG>(
          err, errmsg, ALOG_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isLogInit = true;

       return err;
    }

    inline bool DDSManager<void>::IsLogInitialized() {
       if (m_isLogInit) return m_log->IsTypeRegistered();
       return false;
    }

    inline int DDSManager<void>::CreateLogPublisher() {
       if (!m_isLogInit) return 1;
       return m_log->CreatePublisher();
    }

    inline int DDSManager<void>::CreateLogPublisher(std::string &errmsg) {
       if (!m_isLogInit) {
          errmsg = "Log is not properly initialized.";
          return 1;
       }
       return m_log->CreatePublisher(errmsg);
    }

    inline int DDSManager<void>::RemoveLogPublisher() {
       if (!m_isLogInit) return 1;
       return m_log->RemovePublisher();
    }

    inline int DDSManager<void>::RemoveLogPublisher(std::string &errmsg) {
       if (!m_isLogInit) {
          errmsg = "Log is not properly initialized.";
          return 1;
       }
       return m_log->RemovePublisher(errmsg);
    }

    inline int DDSManager<void>::CreateLogSubscriber(
       void (*onEvent)(AMM::Log &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isLogInit) return 1;
       return m_log->CreateSubscriber((ListenerInterface *) this, onEvent);
    }

    inline int DDSManager<void>::CreateLogSubscriber(
       std::string &errmsg, void (*onEvent)(AMM::Log &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isLogInit) {
          errmsg = "Log is not properly initialized.";
          return 1;
       }
       return m_log->CreateSubscriber(errmsg, (ListenerInterface *) this, onEvent);
    }

    inline int DDSManager<void>::RemoveLogSubscriber() {
       if (!m_isLogInit) return 1;
       return m_log->RemoveSubscriber();
    }

    inline int DDSManager<void>::RemoveLogSubscriber(std::string &errmsg) {
       if (!m_isLogInit) {
          errmsg = "Log is not properly initialized.";
          return 1;
       }
       return m_log->RemoveSubscriber(errmsg);
    }

    inline int DDSManager<void>::WriteLog(AMM::Log &a) {
       if (!m_isLogInit) return 1;
       return m_log->Write(a);
    }

    inline int DDSManager<void>::WriteLog(std::string &errmsg, AMM::Log &a) {
       if (!m_isLogInit) {
          errmsg = "Log is not properly initialized.";
          return 1;
       }
       return m_log->Write(errmsg, a);
    }

    inline void DDSManager<void>::onNewLog(
       AMM::Log log, eprosima::fastrtps::SampleInfo_t *info
    ) {
       m_log->OnEvent(log, info);
    }

    inline int DDSManager<void>::DecommissionLog() {
       if (!m_isLogInit) return 0;

       int err = m_log->Delete();
       if (err == 0) m_isLogInit = false;

       return err;
    }

    inline int DDSManager<void>::DecommissionLog(std::string &errmsg) {
       if (!m_isLogInit) {
          errmsg = "Log is already decommissioned.";
          return 0;
       }

       int err = m_log->Delete(errmsg);
       if (err == 0) m_isLogInit = false;

       return err;
    }


// - - - Module Configuration - - -

    inline int DDSManager<void>::InitializeModuleConfiguration() {

       if (m_isModConfigInit) return 0;

       int err = 0;

       m_moduleConfiguration = new AmmDataType<MOCF_TYPE, MOCF_LTNR, MOCF>(
          err, MOCF_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isModConfigInit = true;

       return err;
    }

    inline bool DDSManager<void>::IsModuleConfigurationInitialized() {
       if (m_isModConfigInit) return m_moduleConfiguration->IsTypeRegistered();
       return false;
    }

    inline int DDSManager<void>::CreateModuleConfigurationPublisher() {
       if (!m_isModConfigInit) return 1;
       return m_moduleConfiguration->CreatePublisher();
    }

    inline int DDSManager<void>::RemoveModuleConfigurationPublisher() {
       if (!m_isModConfigInit) return 1;
       return m_moduleConfiguration->RemovePublisher();
    }

    inline int DDSManager<void>::CreateModuleConfigurationSubscriber(
       void (*onEvent)(AMM::ModuleConfiguration &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isModConfigInit) return 1;
       return m_moduleConfiguration->CreateSubscriber((ListenerInterface *) this, onEvent);
    }

    inline int DDSManager<void>::RemoveModuleConfigurationSubscriber() {
       if (!m_isModConfigInit) return 1;
       return m_moduleConfiguration->RemoveSubscriber();
    }

    inline int DDSManager<void>::WriteModuleConfiguration(AMM::ModuleConfiguration &a) {
       if (!m_isModConfigInit) return 1;
       return m_moduleConfiguration->Write(a);
    }

    inline void DDSManager<void>::onNewModuleConfiguration(
       AMM::ModuleConfiguration modConfig, eprosima::fastrtps::SampleInfo_t *info
    ) {
       m_moduleConfiguration->OnEvent(modConfig, info);
    }

    inline int DDSManager<void>::DecommissionModuleConfiguration() {
       if (!m_isModConfigInit) return 0;

       int err = m_moduleConfiguration->Delete();
       if (err == 0) m_isModConfigInit = false;

       return err;
    }


// - - - Module Configuration Overloads - - -

    inline int DDSManager<void>::InitializeModuleConfiguration(std::string &errmsg) {

       if (m_isModConfigInit) {
          errmsg = "Module Configuration is already initialized.";
          return 0;
       }

       int err = 0;

       m_moduleConfiguration = new AmmDataType<MOCF_TYPE, MOCF_LTNR, MOCF>(
          err, errmsg, MOCF_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isModConfigInit = true;

       return err;
    }

    inline int DDSManager<void>::CreateModuleConfigurationPublisher(std::string &errmsg) {
       if (!m_isModConfigInit) {
          errmsg = "Module Configuration is not properly initialized.";
          return 1;
       }
       return m_moduleConfiguration->CreatePublisher(errmsg);
    }

    inline int DDSManager<void>::RemoveModuleConfigurationPublisher(std::string &errmsg) {
       if (!m_isModConfigInit) {
          errmsg = "Module Configuration is not properly initialized.";
          return 1;
       }
       return m_moduleConfiguration->RemovePublisher(errmsg);
    }

    inline int DDSManager<void>::CreateModuleConfigurationSubscriber(
       std::string &errmsg, void (*onEvent)(AMM::ModuleConfiguration &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isModConfigInit) {
          errmsg = "Module Configuration is not properly initialized.";
          return 1;
       }
       return m_moduleConfiguration->CreateSubscriber(errmsg, (ListenerInterface *) this, onEvent);
    }

    inline int DDSManager<void>::RemoveModuleConfigurationSubscriber(std::string &errmsg) {
       if (!m_isModConfigInit) {
          errmsg = "Module Configuration is not properly initialized.";
          return 1;
       }
       return m_moduleConfiguration->RemoveSubscriber(errmsg);
    }

    inline int DDSManager<void>::WriteModuleConfiguration(std::string &errmsg, AMM::ModuleConfiguration &a) {
       if (!m_isModConfigInit) {
          errmsg = "Module Configuration is not properly initialized.";
          return 1;
       }
       return m_moduleConfiguration->Write(errmsg, a);
    }

    inline int DDSManager<void>::DecommissionModuleConfiguration(std::string &errmsg) {
       if (!m_isModConfigInit) {
          errmsg = "Module Configuration is already decommissioned.";
          return 0;
       }

       int err = m_moduleConfiguration->Delete(errmsg);
       if (err == 0) m_isModConfigInit = false;

       return err;
    }


    inline int DDSManager<void>::InitializeOmittedEvent() {

       if (m_isOmitEventInit) return 0;

       int err = 0;

       m_omittedEvent = new AmmDataType<OMEV_TYPE, OMEV_LTNR, OMEV>(
          err, OMEV_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isOmitEventInit = true;

       return err;
    }

    inline int DDSManager<void>::InitializeOmittedEvent(std::string &errmsg) {

       if (m_isOmitEventInit) {
          errmsg = "Omitted Event is already initialized.";
          return 0;
       }

       int err = 0;

       m_omittedEvent = new AmmDataType<OMEV_TYPE, OMEV_LTNR, OMEV>(
          err, errmsg, OMEV_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isOmitEventInit = true;

       return err;
    }

    inline bool DDSManager<void>::IsOmittedEventInitialized() {
       if (m_isOmitEventInit) m_omittedEvent->IsTypeRegistered();
       return false;
    }

    inline int DDSManager<void>::CreateOmittedEventPublisher() {
       if (!m_isOmitEventInit) return 1;
       return m_omittedEvent->CreatePublisher();
    }

    inline int DDSManager<void>::CreateOmittedEventPublisher(std::string &errmsg) {
       if (!m_isOmitEventInit) {
          errmsg = "Omitted Event is not properly initialized.";
          return 1;
       }
       return m_omittedEvent->CreatePublisher(errmsg);
    }

    inline int DDSManager<void>::RemoveOmittedEventPublisher() {
       if (!m_isOmitEventInit) return 1;
       return m_omittedEvent->RemovePublisher();
    }

    inline int DDSManager<void>::RemoveOmittedEventPublisher(std::string &errmsg) {
       if (!m_isOmitEventInit) {
          errmsg = "Omitted Event is not properly initialized.";
          return 1;
       }
       return m_omittedEvent->RemovePublisher(errmsg);
    }

    inline int DDSManager<void>::CreateOmittedEventSubscriber(
       void (*onEvent)(AMM::OmittedEvent &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isOmitEventInit) return 1;
       return m_omittedEvent->CreateSubscriber((ListenerInterface *) this, onEvent);
    }

    inline int DDSManager<void>::CreateOmittedEventSubscriber(
       std::string &errmsg, void (*onEvent)(AMM::OmittedEvent &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isOmitEventInit) {
          errmsg = "Omitted Event is not properly initialized.";
          return 1;
       }
       return m_omittedEvent->CreateSubscriber(errmsg, (ListenerInterface *) this, onEvent);
    }

    inline int DDSManager<void>::RemoveOmittedEventSubscriber() {
       if (!m_isOmitEventInit) return 1;
       return m_omittedEvent->RemoveSubscriber();
    }

    inline int DDSManager<void>::RemoveOmittedEventSubscriber(std::string &errmsg) {
       if (!m_isOmitEventInit) {
          errmsg = "Omitted Event is not properly initialized.";
          return 1;
       }
       return m_omittedEvent->RemoveSubscriber(errmsg);
    }

    inline int DDSManager<void>::WriteOmittedEvent(AMM::OmittedEvent &a) {
       if (!m_isOmitEventInit) return 1;
       return m_omittedEvent->Write(a);
    }

    inline int DDSManager<void>::WriteOmittedEvent(std::string &errmsg, AMM::OmittedEvent &a) {
       if (!m_isOmitEventInit) {
          errmsg = "Omitted Event is not properly initialized.";
          return 1;
       }
       return m_omittedEvent->Write(errmsg, a);
    }

    inline void DDSManager<void>::onNewOmittedEvent(
       AMM::OmittedEvent omittedEvent, eprosima::fastrtps::SampleInfo_t *info
    ) {
       m_omittedEvent->OnEvent(omittedEvent, info);
    }

    inline int DDSManager<void>::DecommissionOmittedEvent() {
       if (!m_isOmitEventInit) return 0;

       int err = m_omittedEvent->Delete();
       if (err == 0) m_isOmitEventInit = false;

       return err;
    }

    inline int DDSManager<void>::DecommissionOmittedEvent(std::string &errmsg) {
       if (!m_isOmitEventInit) {
          errmsg = "Omitted Event is already decommissioned.";
          return 0;
       }

       int err = m_omittedEvent->Delete(errmsg);
       if (err == 0) m_isOmitEventInit = false;

       return err;
    }


// - - - Operational Description - - -

    inline int DDSManager<void>::InitializeOperationalDescription() {

       if (m_isOpDescriptInit) return 0;

       int err = 0;

       m_operationalDescription = new AmmDataType<OPDS_TYPE, OPDS_LTNR, OPDS>(
          err, OPDS_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isOpDescriptInit = true;

       return err;
    }

    inline int DDSManager<void>::InitializeOperationalDescription(std::string &errmsg) {

       if (m_isOpDescriptInit) {
          errmsg = "Operational Description is already initialized.";
          return 0;
       }

       int err = 0;

       m_operationalDescription = new AmmDataType<OPDS_TYPE, OPDS_LTNR, OPDS>(
          err, errmsg, OPDS_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isOpDescriptInit = true;

       return err;
    }

    inline bool DDSManager<void>::IsOperationalDescriptionInitialized() {
       if (m_isOpDescriptInit) return m_operationalDescription->IsTypeRegistered();
       return false;
    }

    inline int DDSManager<void>::CreateOperationalDescriptionPublisher() {
       if (!m_isOpDescriptInit) return 1;
       return m_operationalDescription->CreatePublisher();
    }

    inline int DDSManager<void>::CreateOperationalDescriptionPublisher(std::string &errmsg) {
       if (!m_isOpDescriptInit) {
          errmsg = "Operational Description is not properly initialized.";
          return 1;
       }
       return m_operationalDescription->CreatePublisher(errmsg);
    }

    inline int DDSManager<void>::RemoveOperationalDescriptionPublisher() {
       if (!m_isOpDescriptInit) return 1;
       return m_operationalDescription->RemovePublisher();
    }

    inline int DDSManager<void>::RemoveOperationalDescriptionPublisher(std::string &errmsg) {
       if (!m_isOpDescriptInit) {
          errmsg = "Operational Description is not properly initialized.";
          return 1;
       }
       return m_operationalDescription->RemovePublisher(errmsg);
    }

    inline int DDSManager<void>::CreateOperationalDescriptionSubscriber(
       void (*onEvent)(AMM::OperationalDescription &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isOpDescriptInit) return 1;
       return m_operationalDescription->CreateSubscriber((ListenerInterface *) this, onEvent);
    }

    inline int DDSManager<void>::CreateOperationalDescriptionSubscriber(
       std::string &errmsg, void (*onEvent)(AMM::OperationalDescription &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isOpDescriptInit) {
          errmsg = "Operational Description is not properly initialized.";
          return 1;
       }
       return m_operationalDescription->CreateSubscriber(errmsg, (ListenerInterface *) this, onEvent);
    }

    inline int DDSManager<void>::RemoveOperationalDescriptionSubscriber() {
       if (!m_isOpDescriptInit) return 1;
       return m_operationalDescription->RemoveSubscriber();
    }

    inline int DDSManager<void>::RemoveOperationalDescriptionSubscriber(std::string &errmsg) {
       if (!m_isOpDescriptInit) {
          errmsg = "Operational Description is not properly initialized.";
          return 1;
       }
       return m_operationalDescription->RemoveSubscriber(errmsg);
    }

    inline int DDSManager<void>::WriteOperationalDescription(AMM::OperationalDescription &a) {
       if (!m_isOpDescriptInit) return 1;
       return m_operationalDescription->Write(a);
    }

    inline int DDSManager<void>::WriteOperationalDescription(std::string &errmsg, AMM::OperationalDescription &a) {
       if (!m_isOpDescriptInit) {
          errmsg = "Operational Description is not properly initialized.";
          return 1;
       }
       return m_operationalDescription->Write(errmsg, a);
    }

    inline void DDSManager<void>::onNewOperationalDescription(
       AMM::OperationalDescription opDescript, eprosima::fastrtps::SampleInfo_t *info
    ) {
       m_operationalDescription->OnEvent(opDescript, info);
    }

    inline int DDSManager<void>::DecommissionOperationalDescription() {
       if (!m_isOpDescriptInit) return 0;

       int err = m_operationalDescription->Delete();
       if (err == 0) m_isOpDescriptInit = false;

       return err;
    }

    inline int DDSManager<void>::DecommissionOperationalDescription(std::string &errmsg) {
       if (!m_isOpDescriptInit) {
          errmsg = "Operational Description is already decommissed.";
          return 0;
       }

       int err = m_operationalDescription->Delete(errmsg);
       if (err == 0) m_isOpDescriptInit = false;

       return err;
    }



// - - - Physiology Modification - - -

    inline int DDSManager<void>::InitializePhysiologyModification() {

       if (m_isPhysModInit) return 0;

       int err = 0;

       m_physiologyModification = new AmmDataType<PHMO_TYPE, PHMO_LTNR, PHMO>(
          err, PHMO_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isPhysModInit = true;

       return err;
    }

    inline int DDSManager<void>::InitializePhysiologyModification(std::string &errmsg) {

       if (m_isPhysModInit) {
          errmsg = "Physiology Modification is already initialized.";
          return 0;
       }

       int err = 0;

       m_physiologyModification = new AmmDataType<PHMO_TYPE, PHMO_LTNR, PHMO>(
          err, errmsg, PHMO_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isPhysModInit = true;

       return err;
    }

    inline bool DDSManager<void>::IsPhysiologyModificationInitialized() {
       if (m_isPhysModInit) return m_physiologyModification->IsTypeRegistered();
       return false;
    }

    inline int DDSManager<void>::CreatePhysiologyModificationPublisher() {
       if (!m_isPhysModInit) return 1;
       return m_physiologyModification->CreatePublisher();
    }

    inline int DDSManager<void>::CreatePhysiologyModificationPublisher(std::string &errmsg) {
       if (!m_isPhysModInit) {
          errmsg = "Physiology Modification is not properly initialized.";
          return 1;
       }
       return m_physiologyModification->CreatePublisher(errmsg);
    }

    inline int DDSManager<void>::RemovePhysiologyModificationPublisher() {
       if (!m_isPhysModInit) return 1;
       return m_physiologyModification->RemovePublisher();
    }

    inline int DDSManager<void>::RemovePhysiologyModificationPublisher(std::string &errmsg) {
       if (!m_isPhysModInit) {
          errmsg = "Physiology Modification is not properly initialized.";
          return 1;
       }
       return m_physiologyModification->RemovePublisher(errmsg);
    }

    inline int DDSManager<void>::CreatePhysiologyModificationSubscriber(
       void (*onEvent)(AMM::PhysiologyModification &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isPhysModInit) return 1;
       return m_physiologyModification->CreateSubscriber((ListenerInterface *) this, onEvent);
    }

    inline int DDSManager<void>::CreatePhysiologyModificationSubscriber(
       std::string &errmsg, void (*onEvent)(AMM::PhysiologyModification &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isPhysModInit) {
          errmsg = "Physiology Modification is not properly initialized.";
          return 1;
       }
       return m_physiologyModification->CreateSubscriber(errmsg, (ListenerInterface *) this, onEvent);
    }

    inline int DDSManager<void>::RemovePhysiologyModificationSubscriber() {
       if (!m_isPhysModInit) return 1;
       return m_physiologyModification->RemoveSubscriber();
    }

    inline int DDSManager<void>::RemovePhysiologyModificationSubscriber(std::string &errmsg) {
       if (!m_isPhysModInit) {
          errmsg = "Physiology Modification is not properly initialized.";
          return 1;
       }
       return m_physiologyModification->RemoveSubscriber(errmsg);
    }

    inline int DDSManager<void>::WritePhysiologyModification(AMM::PhysiologyModification &a) {
       if (!m_isPhysModInit) return 1;
       return m_physiologyModification->Write(a);
    }

    inline int DDSManager<void>::WritePhysiologyModification(std::string &errmsg, AMM::PhysiologyModification &a) {
       if (!m_isPhysModInit) {
          errmsg = "Physiology Modification is not properly initialized.";
          return 1;
       }
       return m_physiologyModification->Write(errmsg, a);
    }

    inline void DDSManager<void>::onNewPhysiologyModification(
       AMM::PhysiologyModification physMod, eprosima::fastrtps::SampleInfo_t *info
    ) {
       m_physiologyModification->OnEvent(physMod, info);
    }

    inline int DDSManager<void>::DecommissionPhysiologyModification() {
       if (!m_isPhysModInit) return 0;
       int err = m_physiologyModification->Delete();
       if (err == 0) { m_isPhysModInit = false; }

       return err;
    }

    inline int DDSManager<void>::DecommissionPhysiologyModification(std::string &errmsg) {
       if (!m_isPhysModInit) {
          errmsg = "Physiology Modification is already decommissioned.";
          return 0;
       }

       int err = m_physiologyModification->Delete(errmsg);
       if (err == 0) m_isPhysModInit = false;

       return err;
    }


// - - - Physiology Value - - -

    inline int DDSManager<void>::InitializePhysiologyValue() {

       if (m_isPhysValInit) return 0;

       int err = 0;

       m_physiologyValue = new AmmDataType<PHVA_TYPE, PHVA_LTNR, PHVA>(
          err, PHVA_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isPhysValInit = true;

       return err;
    }

    inline int DDSManager<void>::InitializePhysiologyValue(std::string &errmsg) {

       if (m_isPhysValInit) {
          errmsg = "Physiology Value is already initialized.";
          return 0;
       }

       int err = 0;

       m_physiologyValue = new AmmDataType<PHVA_TYPE, PHVA_LTNR, PHVA>(
          err, errmsg, PHVA_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isPhysValInit = true;

       return err;
    }

    inline bool DDSManager<void>::IsPhysiologyValueInitialized() {
       if (m_isPhysValInit) return m_physiologyValue->IsTypeRegistered();
       return false;
    }

    inline int DDSManager<void>::CreatePhysiologyValuePublisher() {
       if (!m_isPhysValInit) return 1;
       return m_physiologyValue->CreatePublisher();
    }

    inline int DDSManager<void>::CreatePhysiologyValuePublisher(std::string &errmsg) {
       if (!m_isPhysValInit) {
          errmsg = "Physiology Value is not properly initialized.";
          return 1;
       }
       return m_physiologyValue->CreatePublisher(errmsg);
    }

    inline int DDSManager<void>::RemovePhysiologyValuePublisher() {
       if (!m_isPhysValInit) return 1;
       return m_physiologyValue->RemovePublisher();
    }

    inline int DDSManager<void>::RemovePhysiologyValuePublisher(std::string &errmsg) {
       if (!m_isPhysValInit) {
          errmsg = "Physiology Value is not properly initialized.";
          return 1;
       }
       return m_physiologyValue->RemovePublisher(errmsg);
    }

    inline int DDSManager<void>::CreatePhysiologyValueSubscriber(
       void (*onEvent)(AMM::PhysiologyValue &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isPhysValInit) return 1;
       return m_physiologyValue->CreateSubscriber((ListenerInterface *) this, onEvent);
    }

    inline int DDSManager<void>::CreatePhysiologyValueSubscriber(
       std::string &errmsg, void (*onEvent)(AMM::PhysiologyValue &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isPhysValInit) {
          errmsg = "Physiology Value is not properly initialized.";
          return 1;
       }
       return m_physiologyValue->CreateSubscriber(errmsg, (ListenerInterface *) this, onEvent);
    }

    inline int DDSManager<void>::RemovePhysiologyValueSubscriber() {
       if (!m_isPhysValInit) return 1;
       return m_physiologyValue->RemoveSubscriber();
    }

    inline int DDSManager<void>::RemovePhysiologyValueSubscriber(std::string &errmsg) {
       if (!m_isPhysValInit) {
          errmsg = "Physiology Value is not properly initialized.";
          return 1;
       }
       return m_physiologyValue->RemoveSubscriber(errmsg);
    }

    inline int DDSManager<void>::WritePhysiologyValue(AMM::PhysiologyValue &a) {
       if (!m_isPhysValInit) return 1;
       return m_physiologyValue->Write(a);
    }

    inline int DDSManager<void>::WritePhysiologyValue(std::string &errmsg, AMM::PhysiologyValue &a) {
       if (!m_isPhysValInit) {
          errmsg = "Physiology Value is not properly initialized.";
          return 1;
       }
       return m_physiologyValue->Write(errmsg, a);
    }

    inline void DDSManager<void>::onNewPhysiologyValue(
       AMM::PhysiologyValue physValue, eprosima::fastrtps::SampleInfo_t *info
    ) {
       m_physiologyValue->OnEvent(physValue, info);
    }

    inline int DDSManager<void>::DecommissionPhysiologyValue() {
       if (!m_isPhysValInit) return 0;

       int err = m_physiologyValue->Delete();
       if (err == 0) m_isPhysValInit = false;

       return err;
    }

    inline int DDSManager<void>::DecommissionPhysiologyValue(std::string &errmsg) {
       if (!m_isPhysValInit) {
          errmsg = "Physiology Value is already decommissioned.";
          return 0;
       }

       int err = m_physiologyValue->Delete(errmsg);
       if (err == 0) m_isPhysValInit = false;

       return err;
    }


// - - - Physiology Waveform - - -

    inline int DDSManager<void>::InitializePhysiologyWaveform() {

       if (m_isPhysWaveInit) return 0;

       int err = 0;

       m_physiologyWaveform = new AmmDataType<PHWV_TYPE, PHWV_LTNR, PHWV>(
          err, PHWV_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isPhysWaveInit = true;

       return err;
    }

    inline int DDSManager<void>::InitializePhysiologyWaveform(std::string &errmsg) {

       if (m_isPhysWaveInit) {
          errmsg = "Physiology Waveform is already initialized.";
          return 0;
       }

       int err = 0;

       m_physiologyWaveform = new AmmDataType<PHWV_TYPE, PHWV_LTNR, PHWV>(
          err, errmsg, PHWV_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isPhysWaveInit = true;

       return err;
    }

    inline bool DDSManager<void>::IsPhysiologyWaveformInitialized() {
       if (m_isPhysWaveInit) return m_physiologyWaveform->IsTypeRegistered();
       return false;
    }

    inline int DDSManager<void>::CreatePhysiologyWaveformPublisher() {
       if (!m_isPhysWaveInit) return 1;
       return m_physiologyWaveform->CreatePublisher();
    }

    inline int DDSManager<void>::CreatePhysiologyWaveformPublisher(std::string &errmsg) {
       if (!m_isPhysWaveInit) {
          errmsg = "Physiology Waveform is not properly initialized.";
          return 1;
       }
       return m_physiologyWaveform->CreatePublisher(errmsg);
    }

    inline int DDSManager<void>::RemovePhysiologyWaveformPublisher() {
       if (!m_isPhysWaveInit) return 1;
       return m_physiologyWaveform->RemovePublisher();
    }

    inline int DDSManager<void>::RemovePhysiologyWaveformPublisher(std::string &errmsg) {
       if (!m_isPhysWaveInit) {
          errmsg = "Physiology Waveform is not properly initialized.";
          return 1;
       }
       return m_physiologyWaveform->RemovePublisher(errmsg);
    }

    inline int DDSManager<void>::CreatePhysiologyWaveformSubscriber(
       void (*onEvent)(AMM::PhysiologyWaveform &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isPhysWaveInit) return 1;
       return m_physiologyWaveform->CreateSubscriber((ListenerInterface *) this, onEvent);
    }

    inline int DDSManager<void>::CreatePhysiologyWaveformSubscriber(
       std::string &errmsg, void (*onEvent)(AMM::PhysiologyWaveform &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isPhysWaveInit) {
          errmsg = "Physiology Waveform is not properly initialized.";
          return 1;
       }
       return m_physiologyWaveform->CreateSubscriber(errmsg, (ListenerInterface *) this, onEvent);
    }

    inline int DDSManager<void>::RemovePhysiologyWaveformSubscriber() {
       if (!m_isPhysWaveInit) return 1;
       return m_physiologyWaveform->RemoveSubscriber();
    }

    inline int DDSManager<void>::RemovePhysiologyWaveformSubscriber(std::string &errmsg) {
       if (!m_isPhysWaveInit) {
          errmsg = "Physiology Waveform is not properly initialized.";
          return 1;
       }
       return m_physiologyWaveform->RemoveSubscriber(errmsg);
    }

    inline int DDSManager<void>::WritePhysiologyWaveform(AMM::PhysiologyWaveform &a) {
       if (!m_isPhysWaveInit) return 1;
       return m_physiologyWaveform->Write(a);
    }

    inline int DDSManager<void>::WritePhysiologyWaveform(std::string &errmsg, AMM::PhysiologyWaveform &a) {
       if (!m_isPhysWaveInit) {
          errmsg = "Physiology Waveform is not properly initialized.";
          return 1;
       }
       return m_physiologyWaveform->Write(errmsg, a);
    }

    inline void DDSManager<void>::onNewPhysiologyWaveform(
       AMM::PhysiologyWaveform physWave, eprosima::fastrtps::SampleInfo_t *info
    ) {
       m_physiologyWaveform->OnEvent(physWave, info);
    }

    inline int DDSManager<void>::DecommissionPhysiologyWaveform() {
       if (!m_isPhysWaveInit) return 0;

       int err = m_physiologyWaveform->Delete();
       if (err == 0) m_isPhysWaveInit = false;

       return err;
    }

    inline int DDSManager<void>::DecommissionPhysiologyWaveform(std::string &errmsg) {
       if (!m_isPhysWaveInit) {
          errmsg = "Physiology Waveform is already decommissioned.";
          return 0;
       }

       int err = m_physiologyWaveform->Delete(errmsg);
       if (err == 0) m_isPhysWaveInit = false;

       return err;
    }


// - - - Render Modification - - -

    inline int DDSManager<void>::InitializeRenderModification() {

       if (m_isRendModInit) return 0;

       int err = 0;

       m_renderModification = new AmmDataType<RDMO_TYPE, RDMO_LTNR, RDMO>(
          err, RDMO_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isRendModInit = true;

       return err;
    }

    inline int DDSManager<void>::InitializeRenderModification(std::string &errmsg) {

       if (m_isRendModInit) {
          errmsg = "Render Modification is already initialized";
          return 0;
       }

       int err = 0;

       m_renderModification = new AmmDataType<RDMO_TYPE, RDMO_LTNR, RDMO>(
          err, errmsg, RDMO_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isRendModInit = true;

       return err;
    }

    inline bool DDSManager<void>::IsRenderModificationInitialized() {
       if (m_isRendModInit) return m_renderModification->IsTypeRegistered();
       return false;
    }

    inline int DDSManager<void>::CreateRenderModificationPublisher() {
       if (!m_isRendModInit) return 1;
       return m_renderModification->CreatePublisher();
    }

    inline int DDSManager<void>::CreateRenderModificationPublisher(std::string &errmsg) {
       if (!m_isRendModInit) {
          errmsg = "Render Modification is not properly initialized.";
          return 1;
       }
       return m_renderModification->CreatePublisher(errmsg);
    }

    inline int DDSManager<void>::RemoveRenderModificationPublisher() {
       if (!m_isRendModInit) return 1;
       return m_renderModification->RemovePublisher();
    }

    inline int DDSManager<void>::RemoveRenderModificationPublisher(std::string &errmsg) {
       if (!m_isRendModInit) {
          errmsg = "Render Modification is not properly initialized.";
          return 1;
       }
       return m_renderModification->RemovePublisher(errmsg);
    }

    inline int DDSManager<void>::CreateRenderModificationSubscriber(
       void (*onEvent)(AMM::RenderModification &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isRendModInit) return 1;
       return m_renderModification->CreateSubscriber((ListenerInterface *) this, onEvent);
    }

    inline int DDSManager<void>::CreateRenderModificationSubscriber(
       std::string &errmsg, void (*onEvent)(AMM::RenderModification &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isRendModInit) {
          errmsg = "Render Modification is not properly initialized.";
          return 1;
       }
       return m_renderModification->CreateSubscriber(errmsg, (ListenerInterface *) this, onEvent);
    }

    inline int DDSManager<void>::RemoveRenderModificationSubscriber() {
       if (!m_isRendModInit) return 1;
       return m_renderModification->RemoveSubscriber();
    }

    inline int DDSManager<void>::RemoveRenderModificationSubscriber(std::string &errmsg) {
       if (!m_isRendModInit) {
          errmsg = "Render Modification is not properly initialized.";
          return 1;
       }
       return m_renderModification->RemoveSubscriber(errmsg);
    }

    inline int DDSManager<void>::WriteRenderModification(AMM::RenderModification &a) {
       if (!m_isRendModInit) return 1;
       return m_renderModification->Write(a);
    }

    inline int DDSManager<void>::WriteRenderModification(std::string &errmsg, AMM::RenderModification &a) {
       if (!m_isRendModInit) {
          errmsg = "Render Modification is not properly initialized.";
          return 1;
       }
       return m_renderModification->Write(errmsg, a);
    }

    inline void DDSManager<void>::onNewRenderModification(
       AMM::RenderModification rendMod, eprosima::fastrtps::SampleInfo_t *info
    ) {
       m_renderModification->OnEvent(rendMod, info);
    }

    inline int DDSManager<void>::DecommissionRenderModification() {
       if (!m_isRendModInit) return 0;

       int err = m_renderModification->Delete();
       if (err == 0) m_isRendModInit = false;

       return err;
    }

    inline int DDSManager<void>::DecommissionRenderModification(std::string &errmsg) {
       if (!m_isRendModInit) {
          errmsg = "Render Modification is already decommissioned.";
          return 0;
       }

       int err = m_renderModification->Delete(errmsg);
       if (err == 0) m_isRendModInit = false;

       return err;
    }




// - - - Simulation Control - - -

    inline int DDSManager<void>::InitializeSimulationControl() {

       if (m_isSimControlInit) return 0;

       int err = 0;

       m_simulationControl = new AmmDataType<SMCN_TYPE, SMCN_LTNR, SMCN>(
          err, SMCN_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isSimControlInit = true;

       return err;
    }

    inline int DDSManager<void>::InitializeSimulationControl(std::string &errmsg) {

       if (m_isSimControlInit) {
          errmsg = "Simulation Control is already initialized";
          return 0;
       }

       int err = 0;

       m_simulationControl = new AmmDataType<SMCN_TYPE, SMCN_LTNR, SMCN>(
          err, errmsg, SMCN_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isSimControlInit = true;

       return err;
    }

    inline int DDSManager<void>::CreateSimulationControlPublisher() {
       if (!m_isSimControlInit) return 1;
       return m_simulationControl->CreatePublisher();
    }

    inline int DDSManager<void>::CreateSimulationControlPublisher(std::string &errmsg) {
       if (!m_isSimControlInit) {
          errmsg = "Simulation Control is not properly initialized.";
          return 1;
       }
       return m_simulationControl->CreatePublisher(errmsg);
    }

    inline int DDSManager<void>::RemoveSimulationControlPublisher() {
       if (!m_isSimControlInit) return 1;
       return m_simulationControl->RemovePublisher();
    }

    inline int DDSManager<void>::RemoveSimulationControlPublisher(std::string &errmsg) {
       if (!m_isSimControlInit) {
          errmsg = "Simulation Control is not properly initialized.";
          return 1;
       }
       return m_simulationControl->RemovePublisher(errmsg);
    }

    inline int DDSManager<void>::CreateSimulationControlSubscriber(
       void (*onEvent)(AMM::SimulationControl &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isSimControlInit) return 1;
       return m_simulationControl->CreateSubscriber((ListenerInterface *) this, onEvent);
    }

    inline int DDSManager<void>::CreateSimulationControlSubscriber(
       std::string &errmsg, void (*onEvent)(AMM::SimulationControl &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isSimControlInit) {
          errmsg = "Simulation Control is not properly initialized.";
          return 1;
       }
       return m_simulationControl->CreateSubscriber(errmsg, (ListenerInterface *) this, onEvent);
    }

    inline int DDSManager<void>::RemoveSimulationControlSubscriber() {
       if (!m_isSimControlInit) return 1;
       return m_simulationControl->RemoveSubscriber();
    }

    inline int DDSManager<void>::RemoveSimulationControlSubscriber(std::string &errmsg) {
       if (!m_isSimControlInit) {
          errmsg = "Simulation Control is not properly initialized.";
          return 1;
       }
       return m_simulationControl->RemoveSubscriber(errmsg);
    }

    inline int DDSManager<void>::WriteSimulationControl(AMM::SimulationControl &a) {
       if (!m_isSimControlInit) return 1;
       return m_simulationControl->Write(a);
    }

    inline int DDSManager<void>::WriteSimulationControl(std::string &errmsg, AMM::SimulationControl &a) {
       if (!m_isSimControlInit) {
          errmsg = "Simulation Control is not properly initialized.";
          return 1;
       }
       return m_simulationControl->Write(errmsg, a);
    }

    inline void DDSManager<void>::onNewSimulationControl(
       AMM::SimulationControl simControl, eprosima::fastrtps::SampleInfo_t *info
    ) {
       m_simulationControl->OnEvent(simControl, info);
    }

    inline int DDSManager<void>::DecommissionSimulationControl() {
       if (!m_isSimControlInit) return 0;

       int err = m_simulationControl->Delete();
       if (err == 0) m_isSimControlInit = false;

       return err;
    }

    inline int DDSManager<void>::DecommissionSimulationControl(std::string &errmsg) {
       if (!m_isSimControlInit) {
          errmsg = "Simulation Control is already decommissioned.";
          return 0;
       }

       int err = m_simulationControl->Delete(errmsg);
       if (err == 0) m_isSimControlInit = false;

       return err;
    }


// - - - Status - - -

    inline int DDSManager<void>::InitializeStatus() {

       if (m_isStatusInit) return 0;

       int err = 0;

       m_status = new AmmDataType<STAT_TYPE, STAT_LTNR, STAT>(
          err, STAT_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isStatusInit = true;

       return err;
    }

    inline int DDSManager<void>::InitializeStatus(std::string &errmsg) {

       if (m_isStatusInit) {
          errmsg = "Status is already initialized";
          return 0;
       }

       int err = 0;

       m_status = new AmmDataType<STAT_TYPE, STAT_LTNR, STAT>(
          err, errmsg, STAT_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isStatusInit = true;

       return err;
    }

    inline bool DDSManager<void>::IsStatusInitialized() {
       if (m_isStatusInit) return m_status->IsTypeRegistered();
       return false;
    }

    inline int DDSManager<void>::CreateStatusPublisher() {
       if (!m_isStatusInit) return 1;
       return m_status->CreatePublisher();
    }

    inline int DDSManager<void>::CreateStatusPublisher(std::string &errmsg) {
       if (!m_isStatusInit) {
          errmsg = "Status is not properly initialized.";
          return 1;
       }
       return m_status->CreatePublisher(errmsg);
    }

    inline int DDSManager<void>::RemoveStatusPublisher() {
       if (!m_isStatusInit) return 1;
       return m_status->RemovePublisher();
    }

    inline int DDSManager<void>::RemoveStatusPublisher(std::string &errmsg) {
       if (!m_isStatusInit) {
          errmsg = "Status is not properly initialized.";
          return 1;
       }
       return m_status->RemovePublisher(errmsg);
    }

    inline int DDSManager<void>::CreateStatusSubscriber(
       void (*onEvent)(AMM::Status &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isStatusInit) return 1;
       return m_status->CreateSubscriber((ListenerInterface *) this, onEvent);
    }

    inline int DDSManager<void>::CreateStatusSubscriber(
       std::string &errmsg, void (*onEvent)(AMM::Status &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isStatusInit) {
          errmsg = "Status is not properly initialized.";
          return 1;
       }
       return m_status->CreateSubscriber(errmsg, (ListenerInterface *) this, onEvent);
    }

    inline int DDSManager<void>::RemoveStatusSubscriber() {
       if (!m_isStatusInit) return 1;
       return m_status->RemoveSubscriber();
    }

    inline int DDSManager<void>::RemoveStatusSubscriber(std::string &errmsg) {
       if (!m_isStatusInit) {
          errmsg = "Status is not properly initialized.";
          return 1;
       }
       return m_status->RemoveSubscriber(errmsg);
    }

    inline int DDSManager<void>::WriteStatus(AMM::Status &a) {
       if (!m_isStatusInit) return 1;
       return m_status->Write(a);
    }

    inline int DDSManager<void>::WriteStatus(std::string &errmsg, AMM::Status &a) {
       if (!m_isStatusInit) {
          errmsg = "Status is not properly initialized.";
          return 1;
       }
       return m_status->Write(errmsg, a);
    }

    inline void DDSManager<void>::onNewStatus(
       AMM::Status status, eprosima::fastrtps::SampleInfo_t *info
    ) {
       m_status->OnEvent(status, info);
    }

    inline int DDSManager<void>::DecommissionStatus() {
       if (!m_isStatusInit) return 0;

       int err = m_status->Delete();
       if (err == 0) m_isStatusInit = false;

       return err;
    }

    inline int DDSManager<void>::DecommissionStatus(std::string &errmsg) {
       if (!m_isStatusInit) {
          errmsg = "Status is already decommissioned.";
          return 0;
       }

       int err = m_status->Delete(errmsg);
       if (err == 0) m_isStatusInit = false;

       return err;
    }


// - - - Tick - - -

    inline int DDSManager<void>::InitializeTick() {

       if (m_isTickInit) return 0;

       int err = 0;

       m_tick = new AmmDataType<TICK_TYPE, TICK_LTNR, TICK>(
          err, TICK_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isTickInit = true;
       return err;
    }

    inline int DDSManager<void>::InitializeTick(std::string &errmsg) {

       if (m_isTickInit) {
          errmsg = "Tick is already initialized.";
          return 0;
       }

       int err = 0;

       m_tick = new AmmDataType<TICK_TYPE, TICK_LTNR, TICK>(
          err, errmsg, TICK_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isTickInit = true;
       return err;
    }

    inline bool DDSManager<void>::IsTickInitialized() {
       if (m_isTickInit) return m_tick->IsTypeRegistered();
       return false;
    }

    inline int DDSManager<void>::CreateTickPublisher() {
       if (!m_isTickInit) return 1;
       return m_tick->CreatePublisher();
    }

    inline int DDSManager<void>::CreateTickPublisher(std::string &errmsg) {
       if (!m_isTickInit) {
          errmsg = "Tick is not properly initialized.";
          return 1;
       }
       return m_tick->CreatePublisher(errmsg);
    }

    inline int DDSManager<void>::RemoveTickPublisher() {
       if (!m_isTickInit) return 1;
       return m_instrumentData->RemovePublisher();
    }

    inline int DDSManager<void>::RemoveTickPublisher(std::string &errmsg) {
       if (!m_isTickInit) {
          errmsg = "Tick is not properly initialized.";
          return 1;
       }
       return m_instrumentData->RemovePublisher(errmsg);
    }

    inline int DDSManager<void>::CreateTickSubscriber(
       void (*onEvent)(AMM::Tick &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isTickInit) return 1;
       return m_tick->CreateSubscriber((ListenerInterface *) this, onEvent);
    }

    inline int DDSManager<void>::CreateTickSubscriber(
       std::string &errmsg, void (*onEvent)(AMM::Tick &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isTickInit) {
          errmsg = "Tick is not properly initialized.";
          return 1;
       }
       return m_tick->CreateSubscriber(errmsg, (ListenerInterface *) this, onEvent);
    }

    inline int DDSManager<void>::RemoveTickSubscriber() {
       if (!m_isTickInit) return 1;
       return m_tick->RemoveSubscriber();
    }

    inline int DDSManager<void>::RemoveTickSubscriber(std::string &errmsg) {
       if (!m_isTickInit) {
          errmsg = "Tick is not properly initialized.";
          return 1;
       }
       return m_tick->RemoveSubscriber(errmsg);
    }

    inline int DDSManager<void>::WriteTick(AMM::Tick &a) {
       if (!m_isTickInit) return 1;
       return m_tick->Write(a);
    }

    inline int DDSManager<void>::WriteTick(std::string &errmsg, AMM::Tick &a) {
       if (!m_isTickInit) {
          errmsg = "Tick is not properly initialized.";
          return 1;
       }
       return m_tick->Write(a);
    }

    inline void DDSManager<void>::onNewTick(
       AMM::Tick tick, eprosima::fastrtps::SampleInfo_t *info
    ) {
       m_tick->OnEvent(tick, info);
    }

    inline int DDSManager<void>::DecommissionTick() {
       if (!m_isTickInit) return 0;

       int err = m_tick->Delete();
       if (err == 0) m_isTickInit = false;

       return err;
    }

    inline int DDSManager<void>::DecommissionTick(std::string &errmsg) {
       if (!m_isTickInit) {
          errmsg = "Tick is already decommissioned.";
          return 0;
       }

       int err = m_tick->Delete(errmsg);
       if (err == 0) m_isTickInit = false;

       return err;
    }


// - - - Instrument Data - - -

    inline int DDSManager<void>::InitializeInstrumentData() {

       if (m_isInstDataInit) return 0;

       int err = 0;

       m_instrumentData = new AmmDataType<IDAT_TYPE, IDAT_LTNR, IDAT>(
          err, IDAT_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isInstDataInit = true;
       return err;
    }

    inline int DDSManager<void>::InitializeInstrumentData(std::string &errmsg) {

       if (m_isInstDataInit) {
          errmsg = "Instrument Data is already initialized.";
          return 0;
       }

       int err = 0;

       m_instrumentData = new AmmDataType<IDAT_TYPE, IDAT_LTNR, IDAT>(
          err, errmsg, IDAT_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isInstDataInit = true;
       return err;
    }

    inline bool DDSManager<void>::IsInstrumentDataInitialized() {
       if (m_isInstDataInit) return m_instrumentData->IsTypeRegistered();
       return false;
    }

    inline int DDSManager<void>::CreateInstrumentDataPublisher() {
       if (!m_isInstDataInit) return 1;
       return m_instrumentData->CreatePublisher();
    }

    inline int DDSManager<void>::CreateInstrumentDataPublisher(std::string &errmsg) {
       if (!m_isInstDataInit) {
          errmsg = "Instrument Data is not properly initialized.";
          return 1;
       }
       return m_instrumentData->CreatePublisher(errmsg);
    }

    inline int DDSManager<void>::RemoveInstrumentDataPublisher() {
       if (!m_isInstDataInit) return 1;
       return m_instrumentData->RemovePublisher();
    }

    inline int DDSManager<void>::RemoveInstrumentDataPublisher(std::string &errmsg) {
       if (!m_isInstDataInit) {
          errmsg = "Instrument Data is not properly initialized.";
          return 1;
       }
       return m_instrumentData->RemovePublisher(errmsg);
    }

    inline int DDSManager<void>::CreateInstrumentDataSubscriber(
       void (*onEvent)(AMM::InstrumentData &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isInstDataInit) return 1;
       return m_instrumentData->CreateSubscriber((ListenerInterface *) this, onEvent);
    }

    inline int DDSManager<void>::CreateInstrumentDataSubscriber(
       std::string &errmsg, void (*onEvent)(AMM::InstrumentData &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isInstDataInit) {
          errmsg = "Instrument Data is not properly initialized.";
          return 1;
       }
       return m_instrumentData->CreateSubscriber(errmsg, (ListenerInterface *) this, onEvent);
    }

    inline int DDSManager<void>::RemoveInstrumentDataSubscriber() {
       if (!m_isInstDataInit) return 1;
       return m_instrumentData->RemoveSubscriber();
    }

    inline int DDSManager<void>::RemoveInstrumentDataSubscriber(std::string &errmsg) {
       if (!m_isInstDataInit) {
          errmsg = "Instrument Data is not properly initialized.";
          return 1;
       }
       return m_instrumentData->RemoveSubscriber(errmsg);
    }

    inline int DDSManager<void>::WriteInstrumentData(AMM::InstrumentData &a) {
       if (!m_isInstDataInit) return 1;
       return m_instrumentData->Write(a);
    }

    inline int DDSManager<void>::WriteInstrumentData(std::string &errmsg, AMM::InstrumentData &a) {
       if (!m_isInstDataInit) {
          errmsg = "Instrument Data is not properly initialized.";
          return 1;
       }
       return m_instrumentData->Write(errmsg, a);
    }

    inline void DDSManager<void>::onNewInstrumentData(
       AMM::InstrumentData instData, eprosima::fastrtps::SampleInfo_t *info
    ) {
       m_instrumentData->OnEvent(instData, info);
    }

    inline int DDSManager<void>::DecommissionInstrumentData() {
       if (!m_isInstDataInit) return 0;

       int err = m_instrumentData->Delete();
       if (err == 0) m_isInstDataInit = false;

       return err;
    }

    inline int DDSManager<void>::DecommissionInstrumentData(std::string &errmsg) {
       if (!m_isInstDataInit) {
          errmsg = "Instrument Data is already decommissioned.";
          return 0;
       }

       int err = m_instrumentData->Delete(errmsg);
       if (err == 0) m_isInstDataInit = false;

       return err;
    }


// - - - Command - - -

    inline int DDSManager<void>::InitializeCommand() {

       if (m_isCommandInit) return 0;

       int err = 0;
       m_command = new AmmDataType<CMND_TYPE, CMND_LTNR, CMND>(
          err, CMND_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isCommandInit = true;
       return err;
    }

    inline int DDSManager<void>::InitializeCommand(std::string &errmsg) {

       if (m_isCommandInit) {
          errmsg = "Command is already initialized.";
          return 0;
       }

       int err = 0;
       m_command = new AmmDataType<CMND_TYPE, CMND_LTNR, CMND>(
          err, errmsg, CMND_STR, m_participant, m_pubListener
       );

       if (err == 0) m_isCommandInit = true;
       return err;
    }

    inline bool DDSManager<void>::IsCommandInitialized() {
       if (m_isCommandInit) return m_command->IsTypeRegistered();
       return false;
    }

    inline int DDSManager<void>::CreateCommandPublisher() {
       if (!m_isCommandInit) return 1;
       return m_command->CreatePublisher();
    }

    inline int DDSManager<void>::CreateCommandPublisher(std::string &errmsg) {
       if (!m_isCommandInit) {
          errmsg = "Command is not properly initialized.";
          return 1;
       }
       return m_command->CreatePublisher(errmsg);
    }

    inline int DDSManager<void>::RemoveCommandPublisher() {
       if (!m_isCommandInit) return 1;
       return m_command->RemovePublisher();
    }

    inline int DDSManager<void>::RemoveCommandPublisher(std::string &errmsg) {
       if (!m_isCommandInit) {
          errmsg = "Command is not properly initialized.";
          return 1;
       }
       return m_command->RemovePublisher(errmsg);
    }

    inline int DDSManager<void>::CreateCommandSubscriber(
       void (*onEvent)(AMM::Command &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isCommandInit) return 1;
       return m_command->CreateSubscriber((ListenerInterface *) this, onEvent);
    }

    inline int DDSManager<void>::CreateCommandSubscriber(
       std::string &errmsg, void (*onEvent)(AMM::Command &, eprosima::fastrtps::SampleInfo_t *)
    ) {
       if (!m_isCommandInit) {
          errmsg = "Command is not properly initialized.";
          return 1;
       }
       return m_command->CreateSubscriber(errmsg, (ListenerInterface *) this, onEvent);
    }

    inline int DDSManager<void>::RemoveCommandSubscriber() {
       if (!m_isCommandInit) return 1;
       return m_command->RemoveSubscriber();
    }

    inline int DDSManager<void>::RemoveCommandSubscriber(std::string &errmsg) {
       if (!m_isCommandInit) {
          errmsg = "Command is not properly initialized.";
          return 1;
       }
       return m_command->RemoveSubscriber(errmsg);
    }

    inline int DDSManager<void>::WriteCommand(AMM::Command &a) {
       if (!m_isCommandInit) return 1;
       return m_command->Write(a);
    }

    inline int DDSManager<void>::WriteCommand(std::string &errmsg, AMM::Command &a) {
       if (!m_isCommandInit) {
          errmsg = "Command is not properly initialized.";
          return 1;
       }
       return m_command->Write(errmsg, a);
    }

    inline void DDSManager<void>::onNewCommand(
       AMM::Command command, eprosima::fastrtps::SampleInfo_t *info
    ) {
       m_command->OnEvent(command, info);
    }

    inline int DDSManager<void>::DecommissionCommand() {
       if (!m_isCommandInit) return 0;

       int err = m_command->Delete();
       if (err == 0) m_isCommandInit = false;

       return err;
    }

    inline int DDSManager<void>::DecommissionCommand(std::string &errmsg) {
       if (!m_isCommandInit) {
          errmsg = "Command is already decommissioned.";
          return 0;
       }

       int err = m_command->Delete(errmsg);
       if (err == 0) m_isCommandInit = false;

       return err;
    }


} // namespace AMM
