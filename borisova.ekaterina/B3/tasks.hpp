#ifndef TASKS_HPP
#define TASKS_HPP

#include <iosfwd>

#include "interface.hpp"

namespace borisova
{
  void doTask1(std::istream& input, std::ostream& output);
  void doTask2(std::ostream& output);
  void invalidCommand(std::ostream& out);
  void invalidBookMark(std::ostream& out);
  void invalidStep(std::ostream& out);
  void empty(std::ostream& out);
}

#endif
