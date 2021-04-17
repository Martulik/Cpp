#ifndef TASK1_HPP
#define TASK1_HPP

#include <sstream>
#include "UserInterface.hpp"

namespace ezerinia {
  void task1();
  std::string getName(std::string &name);
  std::string getNumber(std::string &number);
  std::string getMarkName(std::string &markName);
  void add(UserInterface &phoneBook, std::stringstream &input);
  void store(UserInterface &phoneBook, std::stringstream &input);
  void insert(UserInterface &phoneBook, std::stringstream &input);
  void deleteRecord(UserInterface &phoneBook, std::stringstream &input);
  void show(UserInterface &phoneBook, std::stringstream &input);
  void move(UserInterface &phoneBook, std::stringstream &input);
}
#endif
