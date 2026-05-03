#include "Exit.h"

namespace CommandHandling {

void Exit::execute([[maybe_unused]] const std::vector<std::string>& args) {
   exit(0);
}
}  // namespace CommandHandling
