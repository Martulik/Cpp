#include "comands.hpp"
#include <iostream>
#include <sstream>
#include "detail.hpp"

void diurdeva::add(PhonebookManager &phoneBook, std::stringstream &input)
{
  std::string number;
  input >> std::ws >> number;

  std::string name;
  std::getline(input >> std::ws, name);

  if (!isNumberValid(number) || !refactorAndCheckName(name)) {
    std::cout << "<INVALID COMMAND>\n";
    return;
  }
  Phonebook::record_t mark = {name, number};
  phoneBook.add(mark);
}

void diurdeva::store(PhonebookManager &phoneBook, std::stringstream &input)
{
  std::string markName;
  input >> std::ws >> markName;

  std::string newMarkName;
  input >> std::ws >> newMarkName;

  if (!input.eof() || !isBookmarkValid(markName) || !isBookmarkValid(newMarkName)) {
    std::cout << "<INVALID COMMAND\n>";
    return;
  }
  phoneBook.store(markName, newMarkName);
}

void diurdeva::insert(PhonebookManager &phoneBook, std::stringstream &input)
{
  std::string direction;
  std::string bookmark;
  std::string number;
  input >> std::ws >> direction;
  input >> std::ws >> bookmark;
  input >> std::ws >> number;
  std::string name;
  getline(input >> std::ws, name);

  if (!isBookmarkValid(bookmark) || !isNumberValid(number) || !refactorAndCheckName(name)) {
    std::cout << "<INVALID COMMAND>\n";
    return;
  }

  Phonebook::record_t mark = {name, number};
  PhonebookManager::InsertPosition dir;
  if (direction == "before") {
    dir = PhonebookManager::InsertPosition::BEFORE;
  } else if (direction == "after") {
    dir = PhonebookManager::InsertPosition::AFTER;
  } else {
    std::cout << "<INVALID COMMAND>\n";
    return;
  }
  phoneBook.insert(dir, bookmark, mark);
}

void diurdeva::deleteRecord(PhonebookManager &phoneBook, std::stringstream &input)
{
  std::string bookmark;
  input >> std::ws >> bookmark;

  if (!input.eof() || !isBookmarkValid(bookmark)) {
    std::cout << "<INVALID COMMAND>\n";
  } else {
    phoneBook.deleteNote(bookmark);
  }
}

void diurdeva::show(PhonebookManager &phoneBook, std::stringstream &input)
{
  std::string bookmark;
  input >> std::ws >> bookmark;

  if (!input.eof() || !isBookmarkValid(bookmark)) {
    std::cout << "<INVALID COMMAND>\n";
  } else {
    phoneBook.show(bookmark);
  }
}

void diurdeva::move(PhonebookManager &phoneBook, std::stringstream &input)
{
  std::string bookmark;
  input >> std::ws >> bookmark;

  if (!isBookmarkValid(bookmark)) {
    std::cout << "<INVALID COMMAND>\n";
    return;
  }

  std::string steps;
  input >> std::ws >> steps;

  if (!input.eof()) {
    std::cout << "<INVALID COMMAND>\n";
  } else if (steps == "first") {
    phoneBook.move(bookmark, PhonebookManager::MovePosition::FIRST);
  } else if (steps == "last") {
    phoneBook.move(bookmark, PhonebookManager::MovePosition::LAST);
  } else {
    if (steps.empty()) {
      std::cout << "INVALID STEP\n";
      return;
    }

    int sign = 1;

    if (steps[0] == '-') {
      sign = -1;
      steps.erase(steps.begin());
    } else if (steps[0] == '+') {
      steps.erase(steps.begin());
    }

    if (!isNumberValid(steps)) {
      std::cout << "INVALID STEP\n";
    } else {
      phoneBook.move(bookmark, stoi(steps) * sign);
    }
  }
}
