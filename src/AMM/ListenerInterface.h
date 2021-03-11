#pragma once


#include <fastrtps/Domain.h>
#include <fastrtps/participant/Participant.h>
#include <fastrtps/publisher/Publisher.h>
#include <fastrtps/publisher/PublisherListener.h>
#include <fastrtps/subscriber/SampleInfo.h>
#include <fastrtps/subscriber/Subscriber.h>
#include <fastrtps/subscriber/SubscriberListener.h>

#include <fastrtps/rtps/RTPSDomain.h>
#include <fastrtps/rtps/builtin/data/WriterProxyData.h>

#include <fastrtps/rtps/reader/ReaderListener.h>

#include <fastrtps/fastrtps_fwd.h>
#include <fastrtps/participant/ParticipantListener.h>
#include <fastrtps/rtps/builtin/data/ReaderProxyData.h>

#include <fastrtps/rtps/builtin/BuiltinProtocols.h>
#include <fastrtps/rtps/builtin/liveliness/WLP.h>

#include <fastrtps/rtps/resources/AsyncWriterThread.h>

#include <fastrtps/rtps/reader/StatelessReader.h>
#include <fastrtps/rtps/writer/StatelessWriter.h>

#include <fastrtps/rtps/history/ReaderHistory.h>
#include <fastrtps/rtps/history/WriterHistory.h>

#include <fastrtps/utils/TimeConversion.h>

#include <fastrtps/rtps/participant/RTPSParticipant.h>

#include "AMM_StandardPubSubTypes.h"
#include "AMM_ExtendedPubSubTypes.h"

using namespace eprosima;
using namespace eprosima::fastrtps;
using namespace eprosima::fastrtps::rtps;

// NOTE:
// Should Listener Interface be in namespace AMM?

/// Common listeners that can be implemented.
///
/// To receive data from subscribed topics, an object must implement this
/// interface and override one of the methods.
/// @note This interface is already implemented on DDS Manager where helper methods
/// facilitate the exchange of data. If a user doesn't wish to use DDS Manager (which is recommended)
/// then this interface must be manually implemented.
class ListenerInterface : public ReaderListener {
public:
   ListenerInterface() = default;
   ~ListenerInterface() override {};

   /// Event handler for incoming Assessment data.
   virtual void onNewAssessment(AMM::Assessment assessment, SampleInfo_t *info) {};

   /// Event handler for incoming Event Fragment data.
   virtual void onNewEventFragment(AMM::EventFragment eventFrag, SampleInfo_t *info) {};

   /// Event handler for incoming Event Record data.
   virtual void onNewEventRecord(AMM::EventRecord eventRec, SampleInfo_t *info) {};

   /// Event handler for incoming Fragment Amendment Request data.
   virtual void onNewFragmentAmendmentRequest(AMM::FragmentAmendmentRequest ffar, SampleInfo_t *info) {};

   /// Event handler for incoming Log data.
   virtual void onNewLog(AMM::Log log, SampleInfo_t *info) {};

   /// Event handler for incoming Module Configuration data.
   virtual void onNewModuleConfiguration(AMM::ModuleConfiguration modConfig, SampleInfo_t *info) {};

   /// Event handler for incoming Omitted Event data.
   virtual void onNewOmittedEvent(AMM::OmittedEvent omittedEvent, SampleInfo_t *info) {};

   /// Event handler for incoming Operational Description data.
   virtual void onNewOperationalDescription(AMM::OperationalDescription opDescript, SampleInfo_t *info) {};

   /// Event handler for incoming Physiology Modification data.
   virtual void onNewPhysiologyModification(AMM::PhysiologyModification physMod, SampleInfo_t *info) {};

   /// Event handler for incoming Physiology Value data.
   virtual void onNewPhysiologyValue(AMM::PhysiologyValue physValue, SampleInfo_t *info) {};

   /// Event handler for incoming Physiology Waveform data.
   virtual void onNewPhysiologyWaveform(AMM::PhysiologyWaveform physWave, SampleInfo_t *info) {};

   /// Event handler for incoming Render Modification data.
   virtual void onNewRenderModification(AMM::RenderModification rendMod, SampleInfo_t *info) {};

   /// Event handler for incoming Simulation Control data.
   virtual void onNewSimulationControl(AMM::SimulationControl simControl, SampleInfo_t *info) {};

   /// Event handler for incoming Status data.
   virtual void onNewStatus(AMM::Status status, SampleInfo_t *info) {};

   /// Event handler for incoming Tick data.
   virtual void onNewTick (AMM::Tick tick, eprosima::fastrtps::SampleInfo_t* info) {};

   /// Event handler for incoming Instrument Data data.
   virtual void onNewInstrumentData (AMM::InstrumentData instData, eprosima::fastrtps::SampleInfo_t* info) {};

   /// Event handler for incoming Command data.
   virtual void onNewCommand (AMM::Command command, eprosima::fastrtps::SampleInfo_t* info) {};

   /// TODO
   std::string sysPrefix = "[SYS]";

   /// TODO
   std::string actPrefix = "[ACT]";

   /// TODO
   std::string loadPrefix = "LOAD_STATE:";

   /// TODO
   std::string loadScenarioPrefix = "LOAD_SCENARIO:";
};
