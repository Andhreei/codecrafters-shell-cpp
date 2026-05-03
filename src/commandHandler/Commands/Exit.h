#pragma once
#include "../Interfaces/BuiltIn.h"

namespace CommandHandling {

class Exit : public BuiltIn {
  public:
   void execute(const std::vector<std::string>& args) override;
};
}  // namespace CommandHandling
