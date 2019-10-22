#pragma once

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
    };

} // namespace AMM
