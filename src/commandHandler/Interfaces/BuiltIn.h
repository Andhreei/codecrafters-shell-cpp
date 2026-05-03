#pragma once
#include <string>
#include <vector>

namespace CommandHandling {

class BuiltIn {
  public:
   virtual void execute(const std::vector<std::string>& args) = 0;
};
}  // namespace CommandHandling
