#include "tools.hpp"
#include <string>
#include <sstream>
#include "record_t.hpp"

namespace lab = ezerinia;

std::string lab::getMarkName(std::string markName)
{
  if (markName.empty()) {
    return "";
  }
  for (char i : markName) {
    if ((!isalnum(i)) && (i != '-')) {
      return "";
    }
  }
  return markName;
}

void lab::add(UserInterface &phoneBook, std::stringstream &input)
{
  record_t record;
  input >> record;

  if (record.name.empty() || record.number.empty()) {
    invalidCommand(std::cout);
  } else {
    phoneBook.add(record);
  }
}

void lab::store(UserInterface &phoneBook, std::stringstream &input)
{
  std::string oldMarkName;
  input >> std::ws >> oldMarkName;
  oldMarkName = getMarkName(oldMarkName);

  std::string newMarkName;
  input >> std::ws >> newMarkName;
  newMarkName = getMarkName(newMarkName);

  if (oldMarkName.empty() || newMarkName.empty() || !phoneBook.containsBookmark(oldMarkName)) {
    invalidCommand(std::cout);
  } else {
    phoneBook.store(oldMarkName, newMarkName);
  }
}

void lab::insert(UserInterface &phoneBook, std::stringstream &input)
{
  std::string direction;
  input >> std::ws >> direction;

  std::string markName;
  input >> std::ws >> markName;
  markName = getMarkName(markName);

  record_t record;
  input >> record;

  if (markName.empty() || !phoneBook.containsBookmark(markName) || record.number.empty() || record.name.empty()) {
    invalidCommand(std::cout);
  } else {
    if (direction == "before") {
      phoneBook.insert(lab::UserInterface::posOfInsert::before, markName, record);
    } else if (direction == "after") {
      phoneBook.insert(lab::UserInterface::posOfInsert::after, markName, record);
    } else {
      invalidCommand(std::cout);
    }
  }
}

void lab::deleteRecord(UserInterface &phoneBook, std::stringstream &input)
{
  std::string markName;
  input >> std::ws >> markName;
  markName = getMarkName(markName);
  if (markName.empty() || !phoneBook.containsBookmark(markName)) {
    invalidCommand(std::cout);
  } else {
    phoneBook.deleteRecord(markName);
  }
}

void lab::show(UserInterface &phoneBook, std::stringstream &input, std::ostream &out)
{
  std::string markName;
  input >> std::ws >> markName;
  markName = getMarkName(markName);
  if (markName.empty()) {
    invalidCommand(out);
  } else if (!phoneBook.containsBookmark(markName)) {
    invalidBookmark(out);
  } else if (phoneBook.empty()) {
    empty(out);
  } else {
    phoneBook.show(markName, out);
  }
}

void lab::move(UserInterface &phoneBook, std::stringstream &input)
{
  std::string markName;
  input >> std::ws >> markName;
  markName = getMarkName(markName);
  if (markName.empty() || !phoneBook.containsBookmark(markName)) {
    invalidCommand(std::cout);
    return;
  }
  std::string num;
  input >> std::ws >> num;
  if (num == "first") {
    phoneBook.move(markName, lab::UserInterface::posOfMove::first);
  } else if (num == "last") {
    phoneBook.move(markName, lab::UserInterface::posOfMove::last);
  } else {
    try {
      int steps = std::stoi(num);
      phoneBook.move(markName, steps);
    }
    catch (const std::invalid_argument &) {
      invalidStep(std::cout);
    }
  }
}

void lab::invalidCommand(std::ostream &out)
{
  out << "<INVALID COMMAND>\n";
}

void lab::invalidBookmark(std::ostream &out)
{
  out << "<INVALID BOOKMARK>\n";
}

void lab::empty(std::ostream &out)
{
  out << "<EMPTY>\n";
}

void lab::invalidStep(std::ostream &out)
{
  out << "<INVALID STEP>\n";
}
