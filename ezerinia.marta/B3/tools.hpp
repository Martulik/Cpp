#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <iostream>
#include "UserInterface.hpp"

namespace ezerinia {
  std::string getMarkName(std::string markName);
  void add(UserInterface &phoneBook, std::stringstream &input);
  void store(UserInterface &phoneBook, std::stringstream &input);
  void insert(UserInterface &phoneBook, std::stringstream &input);
  void deleteRecord(UserInterface &phoneBook, std::stringstream &input);
  void show(UserInterface &phoneBook, std::stringstream &input);
  void move(UserInterface &phoneBook, std::stringstream &input);

  void invalidCommand(std::ostream &out);
  void invalidBookmark(std::ostream &out);
  void empty(std::ostream &out);
  void invalidStep(std::ostream &out);
}
#endif
