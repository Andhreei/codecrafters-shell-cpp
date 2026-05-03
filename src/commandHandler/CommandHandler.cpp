#include "CommandHandler.h"

#include <algorithm>
#include <iostream>

#include "Commands/Exit.h"
#include "Exceptions/NotFound.h"

namespace CommandHandling {

void CommandHandler::initShell() {
   builtins_["exit"] = std::make_unique<Exit>();
}

bool CommandHandler::isValidCommand(const std::string& command) {
   bool isValid{false};
   if (builtins_.find(command) not_eq builtins_.cend()) {
      isValid = true;
   }
   return isValid;
}

void CommandHandler::runCommand(const std::string& command, const std::vector<std::string>& args) {
   bool isValid{isValidCommand(command)};
   if (isValid) {
      builtins_[command]->execute(args);
   } else {
      throw NotFound{command};
   }
}
}  // namespace CommandHandling
