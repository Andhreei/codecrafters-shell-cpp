#pragma once
#include <algorithm>
#include <functional>
#include <memory>
#include <string>
#include <unordered_map>

#include "Interfaces/BuiltIn.h"

namespace CommandHandling {

using commandsMap = std::unordered_map<std::string, std::unique_ptr<BuiltIn>>;

class CommandHandler {
  public:
   inline CommandHandler() { initShell(); }
   bool isValidCommand(const std::string& command);
   void runCommand(const std::string& command, const std::vector<std::string>& args);

  private:
   void initShell();
   commandsMap builtins_;
};
}  // namespace CommandHandling
