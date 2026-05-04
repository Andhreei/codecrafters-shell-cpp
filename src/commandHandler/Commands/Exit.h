#pragma once
#include "../Interfaces/BuiltInCommand.h"

namespace CommandHandling {

/**
 * Implementation of "exit" command
 */
class Exit : public BuiltInCommand {
  public:
   inline void execute(const std::vector<std::string>& args) override { exit(0); }
};
}  // namespace CommandHandling
