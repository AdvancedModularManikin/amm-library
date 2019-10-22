#pragma once

#include <plog/Log.h>
#include <plog/Appenders/ColorConsoleAppender.h>

// Map log-trace to verbose
#define LOG_TRACE                       LOG_DEBUG
#define LOGT                             LOG_DEBUG

namespace plog {

   /// TODO
   void InitializeLogger();
}
