#include <format>
#include <iostream>
#include <string>

#include "commandHandler/CommandHandler.h"
#include "commandHandler/Exceptions/NotFound.h"

int main() {
   // Flush after every std::cout / std:cerr
   std::cout << std::unitbuf;
   std::cerr << std::unitbuf;

   while (std::cin.good()) {
      try {
         std::cout << "$ ";

         std::string command;
         std::getline(std::cin, command);
         if (not command.empty()) {
            CommandHandling::CommandHandler commandHandler;
            commandHandler.runCommand(command, {});
         }
      } catch (const CommandHandling::NotFound& exception) {
         std::cout << std::format("{}: command not found\n", exception.getCommand());
      }
   }
}
