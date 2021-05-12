#include "commands.h"

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>

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

bool lysenko::checkIfThisMarkNameContains(std::string& markName, lysenko::UsersInterface& myInterface)
{
  UsersInterface::iteratorMark newBookMark = myInterface.findThisMark(markName);
  if (newBookMark == myInterface.getEndOfBookMarks())
  {
    InvalidBookmark error;
    std::cout << error.what() << "\n";
    return 0;
  }
  return 1;
}

void lysenko::readCommand(const std::string& inputCommand, lysenko::UsersInterface& myInterface)
{
  std::istringstream in{ inputCommand };
  std::string command;

  in >> command >> std::ws;
  iteratorInt iter = commandsMap.find(command);

  if (iter == commandsMap.end())
  {
    InvalidCommand error;
    std::cout << error.what() << "\n";
    return;
  }

  iter->second(in, myInterface);
}

void lysenko::executeAdd(std::istream& input, lysenko::UsersInterface& myInterface)
{
  std::string name;
  std::string number;

  input >> number >> std::ws;
  name = readString(input);

  if (checkCorrectNumberAndName(name, number))
  {
    myInterface.addNumber(name, number);
  }
}

void lysenko::executeStore(std::istream& input, lysenko::UsersInterface& myInterface)
{
  std::string oldMarkName;
  std::string newMarkName;

  input >> std::ws >> oldMarkName;
  input >> std::ws >> newMarkName;

  if (checkIfThisMarkNameContains(oldMarkName, myInterface))
  {
    myInterface.createNewBookMarkHere(oldMarkName, newMarkName);
  }
}

void lysenko::executeInsert(std::istream& input, lysenko::UsersInterface& myInterface)
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

  if ((checkIfThisMarkNameContains(markName, myInterface) && (checkCorrectNumberAndName(name, number))))
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
    myInterface.insertNoteNextToBookMark(beforeBool, markName, name, number);
  }
}

void lysenko::executeDelete(std::istream& input, lysenko::UsersInterface& myInterface)
{
  std::string markName;

  input >> std::ws >> markName;

  if (checkIfThisMarkNameContains(markName, myInterface))
  {
    myInterface.deleteThisNote(markName);
  }
}

void lysenko::executeShow(std::istream& input, lysenko::UsersInterface& myInterface)
{
  if (myInterface.telephoneBookIsEmpty())
  {
    std::cout << "<EMPTY>" << "\n";
  }
  else
  {
    std::string markName;

    input >> std::ws >> markName;

    if (checkIfThisMarkNameContains(markName, myInterface))
    {
      myInterface.showThisNote(markName);
    }
  }
}

void lysenko::executeMove(std::istream& input, lysenko::UsersInterface& myInterface)
{
  std::string markName;
  std::string steps;

  input >> std::ws >> markName;
  input >> std::ws >> steps;

  if (checkIfThisMarkNameContains(markName, myInterface))
  {
    if (steps == "first")
    {
      myInterface.removeThisBookMark(markName, 1, 0, 0, steps);
    }

    else if (steps == "last")
    {
      myInterface.removeThisBookMark(markName, 0, 1, 0, steps);
    }

    else if (std::stoi(steps))
    {
      int stepsInt = std::stoi(steps);
      if (stepsInt > 0)
      {
        myInterface.removeThisBookMark(markName, 0, 0, 1, steps);
      }
      else
      {
        myInterface.removeThisBookMark(markName, 0, 0, 0, steps);
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
