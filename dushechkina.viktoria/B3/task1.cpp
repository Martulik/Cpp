#include "tasks.hpp"
#include <iostream>
#include <stdexcept>
#include <unordered_map>
#include "functions.hpp"

void dushechkina::task1(std::istream& in, std::ostream& out)
{
  dushechkina::Phonebook phonebook;
  std::unordered_map< std::string, dushechkina::Phonebook::iterator > marks;
  marks["current"] = phonebook.begin();

  while (!in.eof())
  {
    dushechkina::runCommand(phonebook, marks, in, out);
  }
}
