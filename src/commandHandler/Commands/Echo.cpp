#include "Echo.h"

#include <iostream>

void CommandHandling::Echo::execute(const std::vector<std::string>& args) {
   for (auto it{args.cbegin()}; it not_eq args.cend(); ++it) {
      if (it == args.cend() - 1) {
         std::cout << *it;
      } else {
         std::cout << *it << " ";
      }
   }
   std::cout << std::endl;
}
