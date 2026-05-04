#pragma once
#include <filesystem>
#include <iostream>
#include <string>
#include <vector>

class ExecutableRunner {
  public:
   static bool find(const std::string& command) {
      bool found{false};
      if (std::getenv("PATH") not_eq NULL) {
         const char* pathEnv = std::getenv("PATH");
         if (pathEnv != nullptr) {
            std::string pathStr(pathEnv);
            std::istringstream iss(pathStr);
            std::string dir;
            while (std::getline(iss, dir, ':')) {
               std::filesystem::path executable = std::filesystem::path(dir) / command;
               if (std::filesystem::exists(executable) &&
                   (std::filesystem::status(executable).permissions() & std::filesystem::perms::owner_exec) != std::filesystem::perms::none) {
                  found = true;
                  break;
               }
            }
         }
      }
      return found;
   }

   static void run(const std::string& command, const std::vector<std::string>& args) {
      std::string sysArgument{command + " "};
      for (const std::string& arg : args) {
         sysArgument += arg + " ";
      }
      std::system(sysArgument.c_str());
   }
};
