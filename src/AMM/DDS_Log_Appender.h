#pragma once

#include "DDSManager2.h"

#include <boost/algorithm/string.hpp>
#include <plog/Formatters/FuncMessageFormatter.h>
#include <plog/Log.h>

#include <codecvt>
#include <locale>
#include <string>

namespace plog {

/// TODO
template<class Formatter>
class DDS_Log_Appender : public IAppender {
public:
   explicit DDS_Log_Appender(AMM::DDSManager2<void> *mgr)
   : m_mgr(mgr) {
      m_mgr->InitializeLog();
      m_mgr->CreateLogPublisher();
   }

   /// TODO
   AMM::LogLevel convert(const std::string &str) {
      if (str == "FATAL") return AMM::L_FATAL;
      else if (str == "ERROR") return AMM::L_ERROR;
      else if (str == "WARNING") return AMM::L_WARN;
      else if (str == "INFO")return AMM::L_INFO;
      else if (str == "DEBUG")return AMM::L_DEBUG;
      else if (str == "TRACE")return AMM::L_TRACE;

   }

   /// TODO
   virtual void write(const Record &record) {
      std::ostringstream message;
      const char *cSeverity = plog::severityToString(record.getSeverity());
      message << record.getMessage();
      std::string severity = std::string(cSeverity);
      const std::string &smessage = message.str();
      const std::string &sseverity = severity;

      if (boost::starts_with(smessage, "Serial debug:")) return;

      try {
         AMM::Log logInstance;
         logInstance.level(convert(severity));
         logInstance.message(smessage);
         m_mgr->WriteLog(logInstance);
      }
      catch (std::exception &e) {
         LOG_ERROR << e.what();
      }
   }

private:
   /// TODO
   AMM::DDSManager2<void> *m_mgr;
};

} // namepace plog
