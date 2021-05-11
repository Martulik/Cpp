#include "commands.h"

#include <iostream>
#include <sstream>
#include <string>

bool lysenko::checkCorrectNumberAndName(std::string& name, std::string& number)
{
  if ((name.size() != 2) && (stoi(number)))
  {
    name = name.substr(1, name.size() - 2);
    return 1;
  }

  else
  {
    if (name.size() == 2)
    {
      std::cerr << "Name can not be empty \n";
      return 0;
    }

    std::cerr << "Telephone's number must be a consequence of numbers \n";
    return 0;
  }
}

bool lysenko::checkIfThisMarkNameContains(std::string& markName, lysenko::UsersInterface& myInterface)
{
  try
  {
    UsersInterface::iteratorMark newBookMark = myInterface.findThisMark(markName);
    if (newBookMark == myInterface.getEndOfBookMarks())
    {
      InvalidBookmark error;
    }
    return 1;
  }
  catch (InvalidBookmark& err)
  {
    std::cout << err.what();
    return 0;
  }
}

void lysenko::readCommand(const std::string& inputCommand, lysenko::UsersInterface& myInterface)
{
  try
  {
    std::istringstream in{ inputCommand };
    std::string command;

    in >> command >> std::ws;
    iteratorInt iter = commandsMap.find(command);

    if (iter == commandsMap.end())
    {
      InvalidCommand error;
    }

    iter->second(in, myInterface);
  }
  catch (InvalidCommand& err)
  {
    std::cout << err.what();
    return;
  };
}

void lysenko::executeAdd(std::istream& input, lysenko::UsersInterface& myInterface)
{
  std::string name;
  std::string number;

  input >> name >> number;

  if (checkCorrectNumberAndName(name, number))
  {
    myInterface.addNumber(name, number);
  }
}

void lysenko::executeStore(std::istream& input, lysenko::UsersInterface& myInterface)
{
  std::string oldMarkName;
  std::string newMarkName;

  input >> oldMarkName >> newMarkName;

  if (checkIfThisMarkNameContains(oldMarkName, myInterface))
  {
    myInterface.createNewBookMarkHere(oldMarkName, newMarkName);
  }
}

void lysenko::executeInsert(std::istream& input, lysenko::UsersInterface& myInterface)
{
  bool beforeBool;
  std::string before;
  std::string markName;
  std::string number;
  std::string name;

  input >> before >> markName >> number >> name;

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
      return;///мб здесь надо выбрасывать INVALID_COMMAND
    }
    myInterface.insertNoteNextToBookMark(beforeBool, markName, name, number);
  }
}

void lysenko::executeDelete(std::istream& input, lysenko::UsersInterface& myInterface)
{
  std::string markName;

  input >> markName;

  if (checkIfThisMarkNameContains(markName, myInterface))
  {
    myInterface.deleteThisNote(markName);
  }
}

void lysenko::executeShow(std::istream& input, lysenko::UsersInterface& myInterface)
{
  if (myInterface.telephoneBookIsEmpty())
  {
    std::cout << "<EMPTY>";
  }
  else
  {
    std::string markName;

    input >> markName;

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

  input >> markName >> steps;

  if (checkIfThisMarkNameContains(markName, myInterface))
  {
    try
    {
      if (((std::stoi(steps) || (steps == "first") || (steps == "last"))))
      {
        if (std::stoi(steps))
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
        else if (steps == "first")
        {
          myInterface.removeThisBookMark(markName, 1, 0, 0, steps);
        }
        else
        {
          myInterface.removeThisBookMark(markName, 0, 1, 0, steps);
        }
      }
      else
      {
        InvalidStep error;
      }
    }
    catch (InvalidStep& err)
    {
      std::cout << err.what();
      return;
    };
  }
}
