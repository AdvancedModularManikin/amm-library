#pragma once

#include <fastrtps/attributes/ParticipantAttributes.h>
#include <fastrtps/participant/Participant.h>

#include <fastrtps/attributes/PublisherAttributes.h>
#include <fastrtps/publisher/Publisher.h>

#include <fastrtps/attributes/SubscriberAttributes.h>
#include <fastrtps/subscriber/Subscriber.h>

#include <fastrtps/Domain.h>

#include <fastrtps/utils/eClock.h>

#include <fastrtps/Domain.h>
#include <fastrtps/fastrtps_fwd.h>
#include <fastrtps/publisher/PublisherListener.h>
#include <fastrtps/subscriber/SampleInfo.h>
#include <fastrtps/subscriber/SubscriberListener.h>

#include "BaseLogger.h"

#include "AMM_StandardPubSubTypes.h"
#include "AMM_ExtendedPubSubTypes.h"

#include "ListenerInterface.h"

using namespace eprosima;
using namespace eprosima::fastrtps;

namespace AMM {

/// Container class for DDS event listeners.
class DDS_Listeners {

public:

   /// Default listener for publishers.
   ///
   /// @note A single instance of this class may be used for all publishers.
   class PubListener : public PublisherListener {
   public:
      PubListener() : n_matched(0) {};

      ~PubListener() override = default;

      void onPublicationMatched(Publisher *pub, MatchingInfo &info) override;

      int n_matched;

      void SetUpstream(ListenerInterface *l) { upstream = l; };
      ListenerInterface *upstream{};
   };

   /// Default listener for generic subscribers.
   ///
   /// @note Not very useful by it self. Used as a base class for other type-specifics listeners.
   class DefaultSubListener : public SubscriberListener {
   public:
      DefaultSubListener() : n_matched(0), n_msg(0) {};

      ~DefaultSubListener() override = default;

      void onSubscriptionMatched(Subscriber *sub, MatchingInfo &info) override;

      void onNewDataMessage(Subscriber *sub) override;

      SampleInfo_t m_info;
      int n_matched;
      int n_msg;

      void SetUpstream(ListenerInterface *l) { upstream = l; };
      ListenerInterface *upstream{};
   };

   /// Listener for Assessment data.
   class AssessmentListener : public DefaultSubListener {
   public:
      void onNewDataMessage(Subscriber *sub) override;
   };

   /// Listener for Event Fragment data.
   class EventFragmentListener : public DefaultSubListener {
   public:
      void onNewDataMessage(Subscriber *sub) override;
   };

   /// Listener for Event Record data.
   class EventRecordListener : public DefaultSubListener {
   public:
      void onNewDataMessage(Subscriber *sub) override;
   };

   /// Listener for Fragment Amendment Request data.
   class FragmentAmendmentRequestListener : public DefaultSubListener {
   public:
      void onNewDataMessage(Subscriber *sub) override;
   };

   /// Listener for Log data.
   class LogListener : public DefaultSubListener {
   public:
      void onNewDataMessage(Subscriber *sub) override;
   };

   /// Listener for Module Configuration data.
   class ModuleConfigurationListener : public DefaultSubListener {
   public:
      void onNewDataMessage(Subscriber *sub) override;
   };

   /// Listener for Omitted Event data.
   class OmittedEventListener : public DefaultSubListener {
   public:
      void onNewDataMessage(Subscriber *sub) override;
   };

   /// Listener for Operational Description data.
   class OperationalDescriptionListener : public DefaultSubListener {
   public:
      void onNewDataMessage(Subscriber *sub) override;
   };

   /// Listener for Physiology Modification data.
   class PhysiologyModificationListener : public DefaultSubListener {
   public:
      void onNewDataMessage(Subscriber *sub) override;
   };

   /// Listener for Physiology Value data.
   class PhysiologyValueListener : public DefaultSubListener {
   public:
      void onNewDataMessage(Subscriber *sub) override;
   };

   /// Listener for Physiology Waveform data.
   class PhysiologyWaveformListener : public DefaultSubListener {
   public:
      void onNewDataMessage(Subscriber *sub) override;
   };

   /// Listener for Render Modification data.
   class RenderModificationListener : public DefaultSubListener {
   public:
      void onNewDataMessage(Subscriber *sub) override;
   };

   /// Listener for Simulation Control data.
   class SimulationControlListener : public DefaultSubListener {
   public:
      void onNewDataMessage(Subscriber *sub) override;
   };

   /// Listener for Status data.
   class StatusListener : public DefaultSubListener {
   public:
      void onNewDataMessage(Subscriber *sub) override;
   };

   /// Listener for Tick data.
   class TickListener : public DefaultSubListener {
   public:
      void onNewDataMessage(Subscriber *sub) override;
   };

   /// Listener for Instrument Data data.
   class InstrumentDataListener : public DefaultSubListener {
   public:
      void onNewDataMessage(Subscriber *sub) override;
   };

   /// Listener for Command data.
   class CommandListener : public DefaultSubListener {
   public:
      void onNewDataMessage(Subscriber *sub) override;
   };

};

} // namespace AMM
