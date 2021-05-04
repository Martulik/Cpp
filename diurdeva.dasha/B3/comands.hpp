#ifndef COMANDS_HPP
#define COMANDS_HPP

#include "phonebookInterface.hpp"

namespace diurdeva {
  void add(PhonebookManager& phoneBook, std::stringstream& input);
  void store(PhonebookManager& phoneBook, std::stringstream& input);
  void insert(PhonebookManager& phoneBook, std::stringstream& input);
  void deleteRecord(PhonebookManager& phoneBook, std::stringstream& input);
  void show(PhonebookManager& phoneBook, std::stringstream& input);
  void move(PhonebookManager& phoneBook, std::stringstream& input);
}

#endif
