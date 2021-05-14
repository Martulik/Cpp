#ifndef LABS_FUNCTIONS_HPP
#define LABS_FUNCTIONS_HPP
#include <sstream>
#include <iostream>
#include <unordered_map>
#include "phonebook.hpp"

#define EMPTY "<EMPTY>\n"
#define INVALID_COMMAND "<INVALID COMMAND>\n"
#define INVALID_BOOKMARK "<INVALID BOOKMARK>\n"
#define INVALID_STEP "<INVALID STEP>\n"

namespace dushechkina
{
  using MarkList = std::unordered_map<std::string, dushechkina::Phonebook::iterator>;

  void runCommand(Phonebook& phonebook, MarkList& marks, std::istream & = std::cin, std::ostream & = std::cout);

  void add(Phonebook& phonebook, MarkList& marks, std::istream & = std::cin, std::ostream & = std::cout);
  void store(Phonebook&, MarkList& marks, std::istream & = std::cin, std::ostream & = std::cout);
  void insert(Phonebook& phonebook, MarkList& marks, std::istream & = std::cin, std::ostream & = std::cout);
  void remove(Phonebook& phonebook, MarkList& marks, std::istream & = std::cin, std::ostream & = std::cout);
  void show(Phonebook& phonebook, MarkList& marks, std::istream & = std::cin, std::ostream & = std::cout);
  void move(Phonebook& phonebook, MarkList& marks, std::istream & = std::cin, std::ostream & = std::cout);

  std::string getPhoneNumber(std::istream& in);
  std::string getName(std::istream& in);
  std::string getMarkName(std::istream& in);
  MarkList::iterator findMark(MarkList& marks, const std::string& markName);
  int convertOffsetToNumber(const std::string& steps);
  void addRecord(dushechkina::Phonebook& phonebook, MarkList& marks, const Phonebook::Record& newRecord);
}

#endif
