#pragma once
#include <string>
#include <vector>

namespace CommandHandling {

/**
 * Enables polymorphic behavior of commands
 */
class BuiltInCommand {
  public:
   virtual ~BuiltInCommand() = default;
   virtual void execute(const std::vector<std::string>& args) = 0;
};
}  // namespace CommandHandling
