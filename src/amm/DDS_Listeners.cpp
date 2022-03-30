#include "DDS_Listeners.h"

using namespace std;

namespace AMM {

void DDS_Listeners::DefaultSubListener::onSubscriptionMatched(Subscriber *sub, MatchingInfo &info) {
   if (info.status == MATCHED_MATCHING) {
      n_matched++;
   } else {
      n_matched--;
   }
}

void DDS_Listeners::DefaultSubListener::onNewDataMessage(Subscriber *sub) {}


void DDS_Listeners::TickListener::onNewDataMessage(Subscriber *sub) {
   AMM::Tick a;
   if (sub->takeNextData(&a, &m_info)) {
      if (m_info.sampleKind == ALIVE) {
         if (upstream != nullptr) {
            upstream->onNewTick(a, &m_info);
         }
         ++n_msg;
      }
   }
}

void DDS_Listeners::InstrumentDataListener::onNewDataMessage(Subscriber *sub) {
   AMM::InstrumentData a;
   if (sub->takeNextData(&a, &m_info)) {
      if (m_info.sampleKind == ALIVE) {
         if (upstream != nullptr) {
            upstream->onNewInstrumentData(a, &m_info);
         }
         ++n_msg;
      }
   }
}

void DDS_Listeners::CommandListener::onNewDataMessage(Subscriber *sub) {
   AMM::Command a;
   if (sub->takeNextData(&a, &m_info)) {
      if (m_info.sampleKind == ALIVE) {
         if (upstream != nullptr) {
            upstream->onNewCommand(a, &m_info);
         }
         ++n_msg;
      }
   }
}

void DDS_Listeners::AssessmentListener::onNewDataMessage(Subscriber *sub) {
   AMM::Assessment a;
   if (sub->takeNextData(&a, &m_info)) {
      if (m_info.sampleKind == ALIVE) {
         if (upstream != nullptr) {
            upstream->onNewAssessment(a, &m_info);
         }
         ++n_msg;
      }
   }
}

void DDS_Listeners::EventFragmentListener::onNewDataMessage(Subscriber *sub) {
   AMM::EventFragment ef;
   if (sub->takeNextData(&ef, &m_info)) {
      if (m_info.sampleKind == ALIVE) {
         if (upstream != nullptr) {
            upstream->onNewEventFragment(ef, &m_info);
         }
         ++n_msg;
      }
   }
}


void DDS_Listeners::EventRecordListener::onNewDataMessage(Subscriber *sub) {
   AMM::EventRecord er;
   if (sub->takeNextData(&er, &m_info)) {
      if (m_info.sampleKind == ALIVE) {
         if (upstream != nullptr) {
            upstream->onNewEventRecord(er, &m_info);
         }
         ++n_msg;
      }
   }
}

void DDS_Listeners::FragmentAmendmentRequestListener::onNewDataMessage(Subscriber *sub) {
   AMM::FragmentAmendmentRequest fragAmendReq;
   if (sub->takeNextData(&fragAmendReq, &m_info)) {
      if (m_info.sampleKind == ALIVE) {
         if (upstream != nullptr) {
            upstream->onNewFragmentAmendmentRequest(fragAmendReq, &m_info);
         }
         ++n_msg;
      }
   }
}

void DDS_Listeners::LogListener::onNewDataMessage(Subscriber *sub) {
   AMM::Log l;
   if (sub->takeNextData(&l, &m_info)) {
      if (m_info.sampleKind == ALIVE) {
         if (upstream != nullptr) {
            upstream->onNewLog(l, &m_info);
         }
         ++n_msg;
      }
   }
}

void DDS_Listeners::ModuleConfigurationListener::onNewDataMessage(Subscriber *sub) {
   AMM::ModuleConfiguration mc;
   if (sub->takeNextData(&mc, &m_info)) {
      if (m_info.sampleKind == ALIVE) {
         if (upstream != nullptr) {
            upstream->onNewModuleConfiguration(mc, &m_info);
         }
         ++n_msg;
      }
   }
}

void DDS_Listeners::OmittedEventListener::onNewDataMessage(Subscriber *sub) {
   AMM::OmittedEvent oe;
   if (sub->takeNextData(&oe, &m_info)) {
      if (m_info.sampleKind == ALIVE) {
         if (upstream != nullptr) {
            upstream->onNewOmittedEvent(oe, &m_info);
         }
         ++n_msg;
      }
   }
}

void DDS_Listeners::OperationalDescriptionListener::onNewDataMessage(Subscriber *sub) {
   AMM::OperationalDescription od;
   if (sub->takeNextData(&od, &m_info)) {
      if (m_info.sampleKind == ALIVE) {
         if (upstream != nullptr) {
            upstream->onNewOperationalDescription(od, &m_info);
         }
         ++n_msg;
      }
   }
}

void DDS_Listeners::PhysiologyValueListener::onNewDataMessage(Subscriber *sub) {
   AMM::PhysiologyValue pv;
   if (sub->takeNextData(&pv, &m_info)) {
      if (m_info.sampleKind == ALIVE) {
         if (upstream != nullptr) {
            upstream->onNewPhysiologyValue(pv, &m_info);
         }
         ++n_msg;
      }
   }
}

void DDS_Listeners::PhysiologyWaveformListener::onNewDataMessage(Subscriber *sub) {
   AMM::PhysiologyWaveform pw;
   if (sub->takeNextData(&pw, &m_info)) {
      if (m_info.sampleKind == ALIVE) {
         if (upstream != nullptr) {
            upstream->onNewPhysiologyWaveform(pw, &m_info);
         }
         ++n_msg;
      }
   }
}

void DDS_Listeners::SimulationControlListener::onNewDataMessage(Subscriber *sub) {
   AMM::SimulationControl sc;
   if (sub->takeNextData(&sc, &m_info)) {
      if (m_info.sampleKind == ALIVE) {
         if (upstream != nullptr) {
            upstream->onNewSimulationControl(sc, &m_info);
         }
         ++n_msg;
      }
   }
}

void DDS_Listeners::StatusListener::onNewDataMessage(Subscriber *sub) {
   AMM::Status st;
   if (sub->takeNextData(&st, &m_info)) {
      if (m_info.sampleKind == ALIVE) {
         if (upstream != nullptr) {
            upstream->onNewStatus(st, &m_info);
         }
         ++n_msg;
      }
   }
}


void DDS_Listeners::PhysiologyModificationListener::onNewDataMessage(Subscriber *sub) {
   AMM::PhysiologyModification pm;
   if (sub->takeNextData(&pm, &m_info)) {
      ++n_msg;
      if (m_info.sampleKind == ALIVE) {
         if (upstream != nullptr) {
            upstream->onNewPhysiologyModification(pm, &m_info);
         }
      }
   }
}


void DDS_Listeners::RenderModificationListener::onNewDataMessage(Subscriber *sub) {
   AMM::RenderModification rm;
   if (sub->takeNextData(&rm, &m_info)) {
      ++n_msg;
      if (m_info.sampleKind == ALIVE) {
         if (upstream != nullptr) {
            upstream->onNewRenderModification(rm, &m_info);
         }
      }
   }
}

void DDS_Listeners::PubListener::onPublicationMatched(Publisher *pub, MatchingInfo &info) {
   if (info.status == MATCHED_MATCHING) {
      n_matched++;
   } else {
      n_matched--;
   }
}

} // namespace AMM
