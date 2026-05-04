#pragma once
#include <filesystem>
#include <format>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "../Interfaces/BuiltInCommand.h"

namespace CommandHandling {

/**
 * Implementation of "type" command
 */
class Type : public BuiltInCommand {
  public:
   void execute(const std::vector<std::string>& args) override {
      CommandHandler& commandHandler = CommandHandler::getInstance();
      for (const auto& arg : args) {
         bool found{false};
         if (commandHandler.isValidCommand(arg)) {
            std::cout << std::format("{} is a shell builtin\n", arg);
            break;
         } else if (std::getenv("PATH") not_eq NULL) {
            const char* pathEnv = std::getenv("PATH");
            if (pathEnv != nullptr) {
               std::string pathStr(pathEnv);
               std::istringstream iss(pathStr);
               std::string dir;
               while (std::getline(iss, dir, ':')) {
                  std::filesystem::path executable = std::filesystem::path(dir) / arg;
                  if (std::filesystem::exists(executable) &&
                      (std::filesystem::status(executable).permissions() & std::filesystem::perms::owner_exec) != std::filesystem::perms::none) {
                     std::cout << std::format("{} is {}\n", arg, executable.string());
                     found = true;
                     break;
                  }
               }
            }
         }
         if (not found) {
            std::cout << std::format("{}: not found\n", arg);
         }
      }
   }
};
}  // namespace CommandHandling
