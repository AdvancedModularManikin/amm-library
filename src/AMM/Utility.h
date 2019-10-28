#pragma once

#include <fstream>
#include <sstream>
#include <streambuf>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>

#include <boost/algorithm/string.hpp>
#include <boost/archive/iterators/base64_from_binary.hpp>
#include <boost/archive/iterators/binary_from_base64.hpp>
#include <boost/archive/iterators/transform_width.hpp>

namespace AMM {

   class Utility {

   public:
      /**
      * Read a file into a string
      *
      * @param filename
      * @return
      */
      static std::string read_file_to_string(const std::string &filename);

      /**
      * Add an element to a vector.  Remove any previous matching element.
      *
      * @param vec
      * @param element
      */
      static void add_once(std::vector<std::string> &vec, const std::string &element);

      /**
      * Explode a string to a vector of strings based on a delimiter
      *
      * @param delimiter
      * @param str
      * @return
      */
      static std::vector<std::string> explode(const std::string &delimiter, const std::string &str);

      /**
      * Decode a string from base64
      *
      * @param val
      * @return
      */
      static std::string decode64(const std::string &val);

      /**
      * Encode a string as base64
      *
      * @param val
      * @return
      */
      static std::string encode64(const std::string &val);

      /**
      * Get a filename with an embedded now timestamp
      *
      * @param basePathname
      * @param ext
      * @return
      */
      static std::string getTimestampedFilename(const std::string &basePathname, const std::string &ext);

      /**
      * Parse KVP pairs into an STL map
      *
      * @param kv
      * @return
      */
      static std::map<std::string, std::vector<uint8_t>> parse_key_value(std::vector<uint8_t> kv);


      /// Returns the string repensentation of an Assessment Value.
      static std::string EAssessmentValueStr (int value);

      /// Returns the string repensentation of an Event Agent Type.
      static std::string EEventAgentTypeStr (int value);

      /// Returns the string repensentation of an FAR Status.
      static std::string EFarStatusStr (int value);

      /// Returns the string repensentation of an Log Level.
      static std::string ELogLevelStr (int value);

      /// Returns the string repensentation of an Control Type.
      static std::string EControlTypeStr (int value);

      /// Returns the string repensentation of an Status Value.
      static std::string EStatusValueStr (int value);



   }; // class Utility

} // namespace AMM
