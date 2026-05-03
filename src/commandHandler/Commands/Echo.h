#pragma once
#include "../Interfaces/BuiltInCommand.h"

namespace CommandHandling {

/**
 * Implementation of "echo" command
 */
class Echo : public BuiltInCommand {
  public:
   void execute(const std::vector<std::string>& args) override;
};
}  // namespace CommandHandling
