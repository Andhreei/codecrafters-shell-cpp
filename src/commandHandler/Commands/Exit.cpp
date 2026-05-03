#include "Exit.h"

namespace CommandHandling {

void Exit::execute(const std::vector<std::string>& args) {
   int code{args.empty() ? 0 : std::stoi(args[0])};
   exit(code);
}
}  // namespace CommandHandling
