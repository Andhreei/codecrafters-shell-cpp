#include <format>
#include <iostream>
#include <string>

int main() {
   // Flush after every std::cout / std:cerr
   std::cout << std::unitbuf;
   std::cerr << std::unitbuf;

   std::cout << "$ ";

   std::string command;
   std::getline(std::cin, command);
   if (not command.empty()) {
      std::cout << std::format("{}: command not found", command);
   }
}
