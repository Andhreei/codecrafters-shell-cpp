#pragma once

#include <sstream>
#include <string>
#include <vector>

namespace InputParsing {

/**
 * Parses the input into command (first element) and arguments
 */
class InputParser {
  public:
   InputParser(const std::string& input) : input_{input} {}

   inline std::vector<std::string> parse() const { return split(input_, ' '); }

   inline std::vector<std::string> split(const std::string& s, char delim) const {
      std::vector<std::string> elems;
      split(s, delim, elems);
      return elems;
   }

  private:
   inline void split(const std::string& s, char delim, std::vector<std::string>& elems) const {
      std::stringstream ss(s);
      std::string item;
      while (getline(ss, item, delim)) {
         elems.push_back(item);
      }
   }

   std::string input_;
};
}  // namespace InputParsing
