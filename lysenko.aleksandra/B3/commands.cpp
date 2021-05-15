#include "commands.h"

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>

#include "Exceptions.h"
#include "PhoneBook.h"
#include "Contacts.h"

static bool readDelimiter(std::istream& in, char delimiter)
{
  in >> std::ws;
  if (in.peek() != delimiter)
  {
    in.setstate(std::istream::failbit);
    return false;
  }
  char c;
  in >> c;
  return true;
}

static std::string readString(std::istream& in)
{
  std::string result;
  std::string buffer;

  if (!readDelimiter(in, '\"'))
  {
    return result;
  }
  do
  {
    getline(in, buffer, '\"');
    result += buffer;
    if (!result.empty() && (result.back() == '\\'))
    {
      result.back() = '\"';
    }
  } while (in && !result.empty() && (result.back() == '\"'));
  return result;
}

bool lysenko::isDigitsOnly(std::string& number)
{
  if (number == "")
  {
    return 0;
  }
  for (long unsigned int i = 0; i < number.length();++i)
  {
    if ((number[i] < '0') || (number[i] > '9'))
    {
      return 0;
    }
  }
  return 1;
}

bool lysenko::checkCorrectNumberAndName(std::string& name, std::string& number)
{
  if ((!name.empty()) && (isDigitsOnly(number)))
  {
    return 1;
  }
  else
  {
    InvalidCommand error;
    std::cout << error.what() << "\n";
    return 0;
  }
}

bool lysenko::checkIfThisMarkNameContains(std::string& markName, lysenko::PhoneBook& myBook)
{
  PhoneBook::iteratorMark newbookMark = findThisMark(markName, myBook);
  if (newbookMark == getEndOfbookMarks(myBook))
  {
    InvalidbookMark error;
    std::cout << error.what() << "\n";
    return 0;
  }
  return 1;
}

void lysenko::readCommand(const std::string& inputCommand, std::ostream& out,lysenko::PhoneBook& myBook)
{
  std::istringstream in{ inputCommand };
  std::string command;

  in >> command >> std::ws;
  iteratorInt iter = commandsMap.find(command);

  if (command == "show")
  {
    executeShow(in, out, myBook);
  }
  else if (iter != commandsMap.end())
  {
    iter->second(in, myBook);
  }
  else
  {
    InvalidCommand error;
      out << error.what() << "\n";
      return;
  }
}

void lysenko::executeAdd(std::istream& input, lysenko::PhoneBook& myBook)
{
  std::string name;
  std::string number;

  input >> number >> std::ws;
  name = readString(input);

  if (checkCorrectNumberAndName(name, number))
  {
    myBook.addNumber(name, number);
  }
}

void lysenko::executeStore(std::istream& input, lysenko::PhoneBook& myBook)
{
  std::string oldMarkName;
  std::string newMarkName;

  input >> std::ws >> oldMarkName;
  input >> std::ws >> newMarkName;

  if (checkIfThisMarkNameContains(oldMarkName, myBook))
  {
    myBook.createNewbookMarkHere(oldMarkName, newMarkName);
  }
}

void lysenko::executeInsert(std::istream& input, lysenko::PhoneBook& myBook)
{
  bool beforeBool = 1;
  std::string before;
  std::string markName;
  std::string number;
  std::string name;

  input >> std::ws >> before;
  input >> std::ws >> markName;
  input >> std::ws >> number;
  name = readString(input);

  if ((checkIfThisMarkNameContains(markName, myBook) && (checkCorrectNumberAndName(name, number))))
  {
    if (before == "before")
    {
      beforeBool = 1;
    }
    else if (before == "after")
    {
      beforeBool = 0;
    }
    else
    {
      InvalidCommand error;
      std::cout << error.what() << "\n";
      return;
    }
    myBook.insertNoteNextTobookMark(beforeBool, markName, name, number);
  }
}

void lysenko::executeDelete(std::istream& input, lysenko::PhoneBook& myBook)
{
  std::string markName;

  input >> std::ws >> markName;

  if (checkIfThisMarkNameContains(markName, myBook))
  {
    myBook.deleteThisNote(markName);
  }
}

void lysenko::executeShow(std::istream& input, std::ostream& out, lysenko::PhoneBook& myBook)
{
  std::string markName;

  input >> std::ws >> markName;

  if (checkIfThisMarkNameContains(markName, myBook))
  {
    if (noContacts(myBook))
    {
      std::cout << "<EMPTY>" << "\n";
    }
    else
    {
      Contacts::constIterator thisNote = myBook.showThisNote(markName);
      out << thisNote->number << " " << thisNote->name << "\n";
    }
  }
}

void lysenko::executeMove(std::istream& input, lysenko::PhoneBook& myBook)
{
  std::string markName;
  std::string steps;

  input >> std::ws >> markName;
  input >> std::ws >> steps;

  std::string cuttedOne = steps.substr(1, steps.size() - 1);

  if (checkIfThisMarkNameContains(markName, myBook))
  {
    if (steps == "first")
    {
      myBook.removeThisbookMark(markName, 1, 0, 0, steps);
    }

    else if (steps == "last")
    {
      myBook.removeThisbookMark(markName, 0, 1, 0, steps);
    }

    else if ((((steps[0] == '+') || (steps[0] == '-')) && (isDigitsOnly(cuttedOne))) || (isDigitsOnly(steps)))
    {
      int stepsInt = std::stoi(steps);
      if (stepsInt > 0)
      {
        myBook.removeThisbookMark(markName, 0, 0, 1, steps);
      }
      else
      {
        myBook.removeThisbookMark(markName, 0, 0, 0, steps);
      }
    }

    else
    {
      InvalidStep error;
      std::cout << error.what() << "\n";
      return;
    }
  }
}
