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

  void invalidCommand(std::ostream& out);
  void invalidBookmark(std::ostream& out);
  void empty(std::ostream& out);
  void invalidStep(std::ostream& out);
}

#endif
