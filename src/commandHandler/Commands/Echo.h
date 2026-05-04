#pragma once
#include "../Interfaces/BuiltInCommand.h"

namespace CommandHandling {

/**
 * Implementation of "echo" command
 */
class Echo : public BuiltInCommand {
  public:
   void execute(const std::vector<std::string>& args) override {
      for (auto it{args.cbegin()}; it not_eq args.cend(); ++it) {
         if (it == args.cend() - 1) {
            std::cout << *it;
         } else {
            std::cout << *it << " ";
         }
      }
      std::cout << std::endl;
   }
};
}  // namespace CommandHandling
