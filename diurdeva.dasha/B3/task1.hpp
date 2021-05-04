#ifndef TASK1_HPP
#define TASK1_HPP

#include "phonebookInterface.hpp"

namespace diurdeva {
  void parseCommand(PhonebookManager& phoneBook, const std::string& command, std::stringstream& sin);
  void task1();
}

#endif
