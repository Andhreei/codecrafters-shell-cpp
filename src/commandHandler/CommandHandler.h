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
   inline CommandHandler() {
      if (builtins_.empty()) {
         initShellCommands();
      }
   }
   static bool isValidCommand(const std::string& command);
   void runCommand(const std::string& command, const std::vector<std::string>& args);

  private:
   static void initShellCommands();
   static commandsMap builtins_;
};
}  // namespace CommandHandling
