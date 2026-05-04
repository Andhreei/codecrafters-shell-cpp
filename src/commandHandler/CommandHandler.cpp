#include "CommandHandler.h"

#include <algorithm>
#include <iostream>

#include "Commands/Echo.h"
#include "Commands/Exit.h"
#include "Commands/Type.h"
#include "Exceptions/NotFound.h"

namespace CommandHandling {

CommandHandler& CommandHandler::getInstance() {
   static CommandHandler instance;
   return instance;
}

CommandHandler::CommandHandler() {
   if (builtins_.empty()) {
      initShellBuiltinCommands();
   }
}

void CommandHandler::initShellBuiltinCommands() {
   builtins_["exit"] = std::make_unique<Exit>();
   builtins_["echo"] = std::make_unique<Echo>();
   builtins_["type"] = std::make_unique<Type>();
}

bool CommandHandler::isBuiltInCommand(const std::string& command) const {
   return builtins_.find(command) not_eq builtins_.cend();
}

void CommandHandler::runCommand(const std::string& command, const std::vector<std::string>& args) {
   if (isBuiltInCommand(command)) {
      builtins_[command]->execute(args);
   } else if (ExecutableRunner::find(command)) {
      ExecutableRunner::run(command, args);
   } else {
      throw Exceptions::NotFound{command};
   }
}
}  // namespace CommandHandling
