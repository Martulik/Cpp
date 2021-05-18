#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <sstream>
#include <iosfwd>
#include <unordered_map>
#include "phonebook.hpp"

#define INVALID_STEP "<INVALID STEP>\n"

namespace dushechkina
{
  using MarkList = std::unordered_map<std::string, dushechkina::Phonebook::iterator>;

  void runCommand(Phonebook& phonebook, MarkList& marks, std::istream &, std::ostream &);
  void add(Phonebook& phonebook, MarkList& marks, std::istream &, std::ostream &);
  void store(Phonebook&, MarkList& marks, std::istream &, std::ostream &);
  void insert(Phonebook& phonebook, MarkList& marks, std::istream &, std::ostream &);
  void remove(Phonebook& phonebook, MarkList& marks, std::istream &, std::ostream &);
  void show(Phonebook& phonebook, MarkList& marks, std::istream &, std::ostream &);
  void move(Phonebook& phonebook, MarkList& marks, std::istream &, std::ostream &);

  std::string getPhoneNumber(std::istream& in);
  std::string getName(std::istream& in);
  std::string getMarkName(std::istream& in);
  MarkList::iterator findMark(MarkList& marks, const std::string& markName);
  int convertOffsetToNumber(const std::string& steps);
  void addRecord(dushechkina::Phonebook& phonebook, MarkList& marks, const Phonebook::Record& newRecord);
}

#endif
