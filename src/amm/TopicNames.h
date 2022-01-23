#pragma once

#include <string>

// Standardized topic names to keep naming across modules consistent.
// When referencing a topic by proper name, these constants should be
// used instead of raw strings.

// NOTE:
// Being depreciated in favor of #define strings in DDS Manager 2.

namespace AMM {

   namespace TopicNames {
       // AMM 1.0 Standard Data types
      const std::string Assessment               = "Assessment";
      const std::string EventFrag                = "Event Fragment";
      const std::string EventFragment            = "Event Fragment";
      const std::string EventRec                 = "Event Record";
      const std::string EventRecord              = "Event Record";
      const std::string Far                      = "Fragment Amendment Request";
      const std::string FragmentAmendmentRequest = "Fragment Amendment Request";
      const std::string Log                      = "Log";
      const std::string ModConfig                = "Module Configuration";
      const std::string ModuleConfig             = "Module Configuration";
      const std::string ModuleConfiguration      = "Module Configuration";
      const std::string OmittedEvent             = "Omitted Event";
      const std::string AmmVersion               = "AMM Version";
      const std::string OpDescript               = "Operational Description";
      const std::string OperationalDescription   = "Operational Description";
      const std::string PhysMod                  = "Physiology Modification";
      const std::string PhysiologyModification   = "Physiology Modification";
      const std::string PhysVal                  = "Physiology Value";
      const std::string PhysiologyValue          = "Physiology Value";
      const std::string PhysWave                 = "Physiology Waveform";
      const std::string PhysiologyWave           = "Physiology Waveform";
      const std::string PhysiologyWaveform       = "Physiology Waveform";
      const std::string RendMod                  = "Render Modification";
      const std::string RenderModification       = "Render Modification";
      const std::string SimControl               = "Simulation Control";
      const std::string SimulationControl        = "Simulation Control";
      const std::string Status                   = "Status";

      // AMM 1.0 Extended Data types
      const std::string Tick           = "Tick";
      const std::string Command        = "Command";
      const std::string InstrumentData = "InstrumentData";
   }

} // namespace AMM
