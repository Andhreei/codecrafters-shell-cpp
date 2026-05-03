#include "CommandHandler.h"

#include <algorithm>
#include <iostream>

#include "Commands/Echo.h"
#include "Commands/Exit.h"
#include "Commands/Type.h"
#include "Exceptions/NotFound.h"

namespace CommandHandling {
commandsMap CommandHandler::builtins_;

void CommandHandler::initShellCommands() {
   builtins_["exit"] = std::make_unique<Exit>();
   builtins_["echo"] = std::make_unique<Echo>();
   builtins_["type"] = std::make_unique<Type>();
}

bool CommandHandler::isValidCommand(const std::string& command) {
   return builtins_.find(command) not_eq builtins_.cend();
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
