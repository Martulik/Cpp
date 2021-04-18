#include "task1.hpp"
#include <string>
#include <iostream>
#include "UserInterface.hpp"

const std::string invalidCommand = "<INVALID COMMAND>\n";
const std::string invalidStep = "<INVALID STEP>\n";
const std::string emptyStr = "";

namespace lab = ezerinia;

void lab::task1()
{
  lab::UserInterface phoneBook;
  std::string string;

  while (std::getline(std::cin, string)) {
    if (std::cin.fail()) {
      throw std::runtime_error("Read fail");
    }
    std::stringstream input(string);
    std::string command;
    input >> command;
    if (command == "add") {
      add(phoneBook, input);
    } else if (command == "store") {
      store(phoneBook, input);
    } else if (command == "insert") {
      insert(phoneBook, input);
    } else if (command == "delete") {
      deleteRecord(phoneBook, input);
    } else if (command == "show") {
      show(phoneBook, input);
    } else if (command == "move") {
      move(phoneBook, input);
    } else {
      std::cout << invalidCommand;
    }
  }
}

std::string lab::getName(std::string &name)
{
  if ((name.empty()) || (name.front() != '\"') || (name.back() != '\"')) {
    return emptyStr;
  }
  name.erase(name.begin());
  size_t i = 0;
  while ((i < name.size()) && (name[i] != '\"')) {
    if (name[i] == '\\') {
      if ((name[i + 1] == '\"') && (i + 2 < name.size())) {
        name.erase(i, 1);
      } else {
        return emptyStr;
      }
    }
    i++;
  }
  if (i == name.size()) {
    return emptyStr;
  }
  name.erase(i);
  if (name.empty()) {
    return emptyStr;
  }
  return name;
}

std::string lab::getNumber(std::string &number)
{
  if (number.empty()) {
    return emptyStr;
  }
  for (size_t i = 0; i < number.size(); i++) {
    if (!std::isdigit(number[i])) {
      return emptyStr;
    }
  }
  return number;
}

std::string lab::getMarkName(std::string &markName)
{
  if (markName.empty()) {
    return emptyStr;
  }
  for (size_t i = 0; i < markName.size(); i++) {
    if ((!isalnum(markName[i])) && (markName[i] != '-')) {
      return emptyStr;
    }
  }
  return markName;
}

void lab::add(UserInterface &phoneBook, std::stringstream &input)
{
  std::string number;
  std::string name;

  input >> std::ws >> number;
  std::getline(input >> std::ws, name);

  number = getNumber(number);
  name = getName(name);

  if (name.empty() || number.empty()) {
    std::cout << invalidCommand;
  } else {
    PhoneBook::data pair = std::make_pair(number, name);
    phoneBook.add(pair);
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

  if (oldMarkName.empty() || newMarkName.empty()) {
    std::cout << invalidCommand;
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

  std::string number;
  input >> std::ws >> number;
  number = getNumber(number);

  std::string name;
  std::getline(input >> std::ws, name);
  name = getName(name);

  if (markName.empty() || number.empty() || name.empty()) {
    std::cout << invalidCommand;
  } else {
    PhoneBook::data pair = std::make_pair(number, name);
    if (direction == "before" || direction == "after") {
      phoneBook.insert(direction, markName, pair);
    } else {
      std::cout << invalidCommand;
    }
  }
}

void lab::deleteRecord(UserInterface &phoneBook, std::stringstream &input)
{
  std::string markName;
  input >> std::ws >> markName;
  markName = getMarkName(markName);
  if (markName.empty()) {
    std::cout << invalidCommand;
  } else {
    phoneBook.deleteRecord(markName);
  }
}

void lab::show(UserInterface &phoneBook, std::stringstream &input)
{
  std::string markName;
  input >> std::ws >> markName;
  markName = getMarkName(markName);
  if (markName.empty()) {
    std::cout << invalidCommand;
  } else {
    phoneBook.show(markName);
  }
}

void lab::move(UserInterface &phoneBook, std::stringstream &input)
{
  std::string markName;
  input >> std::ws >> markName;
  markName = getMarkName(markName);
  if (markName.empty()) {
    std::cout << invalidCommand;
    return;
  }
  std::string num;
  input >> std::ws >> num;
  if (num == "first" || num == "last") {
    phoneBook.move(markName, num);
  } else {
    int numberSign = 1;
    if (num[0] == '-') {
      numberSign = -1;
      num.erase(num.begin());
    } else if (num[0] == '+') {
      num.erase(num.begin());
    }
    num = getNumber(num);
    if (num.empty()) {
      std::cout << invalidStep;
    } else {
      phoneBook.move(markName, stoi(num) * numberSign);
    }
  }
}
