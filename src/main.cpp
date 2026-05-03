#include <format>
#include <iostream>
#include <string>

#include "InputParser/InputParser.h"
#include "commandHandler/CommandHandler.h"
#include "commandHandler/Exceptions/NotFound.h"

int main() {
   // Flush after every std::cout / std:cerr
   std::cout << std::unitbuf;
   std::cerr << std::unitbuf;

   CommandHandling::CommandHandler commandHandler;
   while (std::cin.good()) {
      try {
         std::cout << "$ ";

         std::string input;
         std::getline(std::cin, input);
         InputParsing::InputParser parser{input};
         std::vector<std::string> words{parser.parse()};
         if (not words.empty()) {
            std::string command{words[0]};
            std::vector<std::string> args{words.begin() + 1, words.end()};
            commandHandler.runCommand(command, args);
         }
      } catch (const CommandHandling::NotFound& exception) {
         std::cout << std::format("{}: command not found\n", exception.getCommand());
      }
   }
}
