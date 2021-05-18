#include "functions.hpp"
#include <string>
#include <iostream>
#include "maps.hpp"
#include "common-functions.hpp"

void dushechkina::runCommand(Phonebook& phonebook, MarkList& marks, std::istream& in, std::ostream& out)
{
  std::string input;
  if (!std::getline(in, input))
  {
    return;
  }

  dushechkina::checkForFailInput(in);
  dushechkina::checkForEmptyInput(input);

  std::istringstream stream(input);
  std::string command;
  stream >> command;

  if (dushechkina::commandName.find(command) == dushechkina::commandName.end())
  {
    std::cout << INVALID_COMMAND;
  }

  dushechkina::commandName.at(command)(phonebook, marks, stream, out);
}

void dushechkina::add(dushechkina::Phonebook& phonebook, MarkList& marks, std::istream& in, std::ostream& out)
{
  std::string phoneNumber;
  std::string name;

  try
  {
    phoneNumber = getPhoneNumber(in);
    name = getName(in);
  }
  catch (const std::invalid_argument& error)
  {
    out << error.what();
    return;
  }

  dushechkina::Phonebook::Record newRecord = { phoneNumber, name };
  addRecord(phonebook, marks, newRecord);
}

void dushechkina::store(dushechkina::Phonebook&, MarkList& marks, std::istream& in, std::ostream& out)
{
  std::string markName;
  std::string newMarkName;

  try
  {
    markName = getMarkName(in);
    newMarkName = getMarkName(in);

    if (markName == newMarkName)
    {
      return;
    }
    auto mark = findMark(marks, markName);
    marks[newMarkName] = mark->second;
  }
  catch (const std::invalid_argument& error)
  {
    out << error.what();
    return;
  }
}

void dushechkina::insert(dushechkina::Phonebook& phonebook, MarkList& marks, std::istream& in, std::ostream& out)
{
  std::string place;
  in >> place;

  std::string markName;
  std::string phoneNumber;
  std::string name;

  try
  {
    markName = getMarkName(in);
    phoneNumber = getPhoneNumber(in);
    name = getName(in);

    dushechkina::Phonebook::Record newRecord = { phoneNumber, name };
    if (phonebook.isEmpty())
    {
      addRecord(phonebook, marks, newRecord);
      return;
    }
    auto mark = findMark(marks, markName);

    if (place == "before")
    {
      phonebook.insertBeforeCurrentRecord(mark->second, newRecord);
      return;
    }
    if (place == "after")
    {
      phonebook.insertAfterCurrentRecord(mark->second, newRecord);
      return;
    }
    out << INVALID_COMMAND;
  }
  catch (const std::invalid_argument& error)
  {
    out << error.what();
    return;
  }
}

void dushechkina::remove(dushechkina::Phonebook& phonebook, MarkList& marks, std::istream& in, std::ostream& out)
{
  std::string markName;

  try
  {
    markName = getMarkName(in);

    auto removedRecord = findMark(marks, markName)->second;
    for (auto& mark: marks)
    {
      if (mark.second == removedRecord)
      {
        mark.second = std::next(removedRecord);
      }
    }
    phonebook.removeCurrentRecord(removedRecord);
    for (auto& mark: marks)
    {
      if (mark.second == phonebook.end())
      {
        mark.second = std::prev(phonebook.end());
      }
    }
  }
  catch (const std::invalid_argument& error)
  {
    out << error.what();
    return;
  }
}

void dushechkina::show(dushechkina::Phonebook& phonebook, MarkList& marks, std::istream& in, std::ostream& out)
{
  std::string markName;

  try
  {
    markName = getMarkName(in);
    auto record = findMark(marks, markName)->second;
    if (phonebook.isEmpty())
    {
      out << EMPTY;
      return;
    }
    out << record->phoneNumber << " " << record->name << "\n";
  }
  catch (const std::invalid_argument& error)
  {
    out << error.what();
    return;
  }
}

void dushechkina::move(dushechkina::Phonebook& phonebook, MarkList& marks, std::istream& in, std::ostream& out)
{
  std::string markName;
  std::string steps;

  try
  {
    markName = getMarkName(in);

    in >> std::ws >> steps;

    auto mark = findMark(marks, markName);
    if (steps == "first")
    {
      mark->second = phonebook.begin();
      return;
    }
    if (steps == "last")
    {
      mark->second = std::prev(phonebook.end());
      return;
    }
    std::advance(marks[markName], convertOffsetToNumber(steps));
  }
  catch (const std::invalid_argument& error)
  {
    out << error.what();
    return;
  }
}

std::string dushechkina::getPhoneNumber(std::istream& in)
{
  std::string phoneNumber;
  in >> std::ws >> phoneNumber;

  if (phoneNumber.empty())
  {
    throw std::invalid_argument(INVALID_COMMAND);
  }

  for (char i : phoneNumber)
  {
    if (!isdigit(i))
    {
      throw std::invalid_argument(INVALID_COMMAND);
    }
  }
  return phoneNumber;
}

std::string dushechkina::getName(std::istream& in)
{
  std::string name;
  in >> std::ws;
  std::getline(in, name);

  if (name.empty() || name.front() != '\"' || (name.back() != '\"'))
  {
    throw std::invalid_argument(INVALID_COMMAND);
  }
  name.erase(name.begin());

  for (size_t i = 0; (i < name.size()) && (name[i] != '\"'); ++i)
  {
    if (name[i] == '\\')
    {
      if ((name[i + 1] != '\"') || (i + 2 >= name.size()))
      {
        throw std::invalid_argument(INVALID_COMMAND);
      }
      name.erase(i, 1);
    }
  }
  name.pop_back();

  return name;
}

std::string dushechkina::getMarkName(std::istream& in)
{
  std::string markName;
  in >> std::ws >> markName;

  if (markName.empty())
  {
    throw std::invalid_argument(INVALID_COMMAND);
  }

  for (char i : markName)
  {
    if ((!isalnum(i)) && (i != '-'))
    {
      throw std::invalid_argument(INVALID_COMMAND);
    }
  }
  return markName;
}

dushechkina::MarkList::iterator dushechkina::findMark(dushechkina::MarkList& marks, const std::string& markName)
{
  auto mark = marks.find(markName);

  if (mark == marks.end())
  {
    throw std::invalid_argument(INVALID_BOOKMARK);
  }
  return mark;
}

int dushechkina::convertOffsetToNumber(const std::string& steps)
{
  try
  {
    int step = std::stoi(steps);
    return step;
  }
  catch (const std::invalid_argument&)
  {
    throw std::invalid_argument(INVALID_STEP);
  }
}

void dushechkina::addRecord(dushechkina::Phonebook& phonebook, MarkList& marks, const Phonebook::Record& newRecord)
{
  if (phonebook.isEmpty())
  {
    phonebook.insertAtTheEnd(newRecord);
    marks["current"] = phonebook.begin();
    return;
  }
  phonebook.insertAtTheEnd(newRecord);
}
