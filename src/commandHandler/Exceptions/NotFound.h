#pragma once
#include <exception>

namespace CommandHandling {

class NotFound : public std::exception {
  public:
   explicit NotFound(const std::string& command) : commandInCause_{command} {}
   const char* what() const noexcept override { return "Command not found"; }

   inline std::string getCommand() const { return commandInCause_; }

  private:
   std::string commandInCause_;
};
}  // namespace CommandHandling
