#pragma once
#include <filesystem>
#include <iostream>

#include "../Interfaces/BuiltInCommand.h"

namespace CommandHandling {

/**
 * Implementation of "exit" command
 */
class PrintWorkingDirectory : public BuiltInCommand {
  public:
   inline void execute(const std::vector<std::string>& args) override { std::cout << std::filesystem::current_path().string() << '\n'; }
};
}  // namespace CommandHandling
