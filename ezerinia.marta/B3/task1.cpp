#include "task1.hpp"
#include <string>
#include <iostream>
#include "UserInterface.hpp"

const std::string invalidCommand = "<INVALID COMMAND>\n";
const std::string invalidStep = "<INVALID STEP>\n";

void task1()
{
  UserInterface phoneBook;
  std::string string;

  while (std::getline(std::cin, string)) {
    if (std::cin.fail()) {
      throw std::runtime_error("Read fail");
    }
    std::stringstream input(string);
    std::string inputCommand;
    input >> inputCommand;

    if (inputCommand == "add") {
      add(phoneBook, input);
    } else if (inputCommand == "store") {
      store(phoneBook, input);
    } else if (inputCommand == "insert") {
      insert(phoneBook, input);
    } else if (inputCommand == "delete") {
      deleteRecord(phoneBook, input);
    } else if (inputCommand == "show") {
      show(phoneBook, input);
    } else if (inputCommand == "move") {
      move(phoneBook, input);
    } else {
      std::cout << invalidCommand;
    }
  }
}

std::string getName(std::string &name)
{
  if ((name.empty()) || (name.front() != '\"') || (name.back() != '\"')) {
    return "";
  }
  name.erase(name.begin());
  size_t i = 0;
  while ((i < name.size()) && (name[i] != '\"')) {
    if (name[i] == '\\') {
      if ((name[i + 1] == '\"') && (i + 2 < name.size())) {
        name.erase(i, 1);
      } else {
        return "";
      }
    }
    ++i;
  }
  if (i == name.size()) {
    return "";
  }
  name.erase(i);
  if (name.empty()) {
    return "";
  }
  return name;
}

std::string getNumber(std::string &number)
{
  if (number.empty()) {
    return "";
  }
  for (size_t i = 0; i < number.size(); i++) {
    if (!std::isdigit(number[i])) {
      return "";
    }
  }
  return number;
}

std::string getMarkName(std::string &name)
{
  if (name.empty()) {
    return "";
  }
  for (size_t i = 0; i < name.size(); i++) {
    if ((!isalnum(name[i])) && (name[i] != '-')) {
      return "";
    }
  }
  return name;
}

void add(UserInterface &phoneBook, std::stringstream &input)
{
  std::string number;
  std::string name;
  std::string line;

  input >> std::ws >> number;
  std::getline(input >> std::ws, name);

  number = getNumber(number);
  name = getName(name);

  if (name.empty() || number.empty()) {
    std::cout << invalidCommand;
    return;
  }
  PhoneBook::data pair = std::make_pair(number, name);
  phoneBook.add(pair);
}

void store(UserInterface &phoneBook, std::stringstream &input)
{
  std::string markName;
  std::string newMarkName;

  input >> std::ws >> markName;
  markName = getMarkName(markName);

  input >> std::ws >> newMarkName;
  newMarkName = getMarkName(newMarkName);

  if (markName.empty() || newMarkName.empty()) {
    std::cout << invalidCommand;
    return;
  }
  phoneBook.store(markName, newMarkName);
}

void insert(UserInterface &phoneBook, std::stringstream &input)
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
    return;
  }
  PhoneBook::data pair = std::make_pair(number, name);
  if (direction == "before" || direction == "after") {
    phoneBook.insert(direction, markName, pair);
  } else {
    std::cout << invalidCommand;
  }
}

void deleteRecord(UserInterface &phoneBook, std::stringstream &input)
{
  std::string markName;
  input >> std::ws >> markName;
  markName = getMarkName(markName);
  if (markName.empty()) {
    std::cout << invalidCommand;
    return;
  }
  phoneBook.deleteRecord(markName);
}

void show(UserInterface &phoneBook, std::stringstream &input)
{
  std::string markName;
  input >> std::ws >> markName;
  markName = getMarkName(markName);
  if (markName.empty()) {
    std::cout << invalidCommand;
    return;
  }
  phoneBook.show(markName);
}

void move(UserInterface &phoneBook, std::stringstream &input)
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
      int numberSign = -1;
      num.erase(num.begin());
    } else if (num[0] == '+') {
      num.erase(num.begin());
    }
    num = getNumber(num);
    if (num.empty()) {
      std::cout << invalidStep;
      return;
    }
    phoneBook.move(markName, numberSign * stoi(num));
  }
}
