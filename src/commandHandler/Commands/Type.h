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
      CommandHandler& commandHandler = CommandHandler::getInstance();
      for (const auto& arg : args) {
         if (commandHandler.isValidCommand(arg)) {
            std::cout << std::format("{} is a shell builtin\n", arg);
         } else {
            std::cout << std::format("{}: not found\n", arg);
         }
      }
   }
};
}  // namespace CommandHandling
