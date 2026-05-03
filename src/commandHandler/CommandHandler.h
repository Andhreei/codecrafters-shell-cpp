#pragma once
#include <algorithm>
#include <functional>
#include <memory>
#include <string>
#include <unordered_map>

#include "Interfaces/BuiltInCommand.h"

namespace CommandHandling {

using commandsMap = std::unordered_map<std::string, std::unique_ptr<BuiltInCommand>>;

/**
 * Handles the dispatch of the command
 */
class CommandHandler {
  public:
   static CommandHandler& getInstance();

   CommandHandler(const CommandHandler&) = delete;
   CommandHandler& operator=(const CommandHandler&) = delete;
   CommandHandler(CommandHandler&&) = delete;
   CommandHandler& operator=(CommandHandler&&) = delete;

   bool isValidCommand(const std::string& command) const;
   void runCommand(const std::string& command, const std::vector<std::string>& args);

  private:
   CommandHandler();
   static void initShellCommands();
   static commandsMap builtins_;
};
}  // namespace CommandHandling
