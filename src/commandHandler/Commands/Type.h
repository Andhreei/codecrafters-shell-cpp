#pragma once
#include <format>

#include "../Interfaces/BuiltInCommand.h"

namespace CommandHandling {

/**
 * Implementation of "type" command
 */
class Type : public BuiltInCommand {
  public:
   inline void execute(const std::vector<std::string>& args) override {
      for (const auto& arg : args) {
         if (CommandHandler::isValidCommand(arg)) {
            std::cout << std::format("{} is a shell builtin\n", arg);
         } else {
            std::cout << std::format("{}: not found\n", arg);
         }
      }
   }
};
}  // namespace CommandHandling
