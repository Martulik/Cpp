#include "comands.hpp"
#include <iostream>
#include <sstream>
#include "detail.hpp"

void diurdeva::add(PhonebookManager &phoneBook, std::stringstream &input)
{
  record_t record;
  input >> record;

  if (record.name.empty() || record.number.empty()) {
    invalidCommand(std::cout);
  } else {
    phoneBook.add(record);
  }
}

void diurdeva::store(PhonebookManager &phoneBook, std::stringstream &input)
{
  std::string markName;
  input >> std::ws >> markName;

  std::string newMarkName;
  input >> std::ws >> newMarkName;

  if (!input.eof() || !isBookmarkValid(markName) || !isBookmarkValid(newMarkName)) {
    invalidCommand(std::cout);
  } else if (!phoneBook.containsBookmark(markName)) {
    invalidBookmark(std::cout);
  } else {
    phoneBook.store(markName, newMarkName);
  }
}

void diurdeva::insert(PhonebookManager &phoneBook, std::stringstream &input)
{
  std::string direction;
  std::string bookmark;
  input >> std::ws >> direction;
  input >> std::ws >> bookmark;
  record_t record;
  input >> record;

  if (!isBookmarkValid(bookmark) || record.number.empty() || record.name.empty()) {
    invalidCommand(std::cout);
  } else if (!phoneBook.containsBookmark(bookmark)) {
    invalidBookmark(std::cout);
  } else if (direction == "before") {
    phoneBook.insert(PhonebookManager::InsertPosition::BEFORE, bookmark, record);
  } else if (direction == "after") {
    phoneBook.insert(PhonebookManager::InsertPosition::AFTER, bookmark, record);
  } else {
    invalidCommand(std::cout);
  }
}

void diurdeva::deleteRecord(PhonebookManager &phoneBook, std::stringstream &input)
{
  std::string bookmark;
  input >> std::ws >> bookmark;

  if (!input.eof() || !isBookmarkValid(bookmark)) {
    invalidCommand(std::cout);
  } else if (!phoneBook.containsBookmark(bookmark)) {
    invalidBookmark(std::cout);
  } else {
    phoneBook.deleteNote(bookmark);
  }
}

void diurdeva::show(PhonebookManager &phoneBook, std::stringstream &input)
{
  std::string bookmark;
  input >> std::ws >> bookmark;

  if (!input.eof() || !isBookmarkValid(bookmark)) {
    invalidCommand(std::cout);
  } else if (!phoneBook.containsBookmark(bookmark)) {
    invalidBookmark(std::cout);
  } else if (phoneBook.empty()) {
    empty(std::cout);
  } else {
    phoneBook.show(bookmark, std::cout);
  }
}

void diurdeva::move(PhonebookManager &phoneBook, std::stringstream &input)
{
  std::string bookmark;
  input >> std::ws >> bookmark;

  if (!isBookmarkValid(bookmark)) {
    invalidCommand(std::cout);
    return;
  } else if (!phoneBook.containsBookmark(bookmark)) {
    invalidBookmark(std::cout);
    return;
  }

  std::string steps;
  input >> std::ws >> steps;

  if (!input.eof()) {
    invalidCommand(std::cout);
  } else if (steps == "first") {
    phoneBook.move(bookmark, PhonebookManager::MovePosition::FIRST);
  } else if (steps == "last") {
    phoneBook.move(bookmark, PhonebookManager::MovePosition::LAST);
  } else {
    try {
      int stepInt = std::stoi(steps);
      phoneBook.move(bookmark, stepInt);
    }
    catch (const std::invalid_argument &) {
      invalidStep(std::cout);
    }
  }
}

void diurdeva::invalidCommand(std::ostream &out)
{
  out << "<INVALID COMMAND>\n";
}

void diurdeva::invalidBookmark(std::ostream &out)
{
  out << "<INVALID BOOKMARK>\n";
}

void diurdeva::empty(std::ostream &out)
{
  out << "<EMPTY>\n";
}

void diurdeva::invalidStep(std::ostream &out)
{
  out << "<INVALID STEP>\n";
}
