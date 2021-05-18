#include "commands.h"

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>

#include "Exceptions.h"
#include "PhoneBook.h"
#include "Contacts.h"

bool readDelimiter(std::istream& in, char delimiter)
{
  in >> std::ws;
  if (in.peek() != delimiter)
  {
    in.setstate(std::istream::failbit);
    return 0;
  }
  char c;
  in >> c;
  return 1;
}

std::string readString(std::istream& in)
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

bool lysenko::isDigitsOnly(const std::string& number)
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

bool lysenko::checkCorrectNumberAndName(const std::string& name, const std::string& number)
{
  if ((!name.empty()) && (isDigitsOnly(number)))
  {
    return 1;
  }
  else
  {
    throw InvalidCommand();
  }
}

void lysenko::readCommand(const std::string& inputCommand, std::ostream& out,
  lysenko::PhoneBook& myBook)
{
  std::istringstream in{ inputCommand };
  std::string command;

  in >> command >> std::ws;

  using myFunc = std::map < std::string, std::function< void(std::istream&, lysenko::PhoneBook&) > >;
  using constCommandIter = myFunc::const_iterator;

  constCommandIter iter = commandsMap.find(command);

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
    throw InvalidCommand();
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
    myBook.addNumber( { name, number } );
  }
}

void lysenko::executeStore(std::istream& input, lysenko::PhoneBook& myBook)
{
  std::string oldMarkName;
  std::string newMarkName;

  input >> std::ws >> oldMarkName;
  input >> std::ws >> newMarkName;

  if (myBook.checkIfThisMarkNameContains(oldMarkName))
  {
    myBook.createNewbookMarkHere(oldMarkName, newMarkName);
  }
  else
  {
    throw InvalidbookMark();
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

  if ((myBook.checkIfThisMarkNameContains(markName) && (checkCorrectNumberAndName(name, number))))
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
      throw InvalidCommand();
    }
    myBook.insertNoteNextTobookMark(beforeBool, markName, { name, number });
  }
  if (!(myBook.checkIfThisMarkNameContains(markName)))
  {
    throw InvalidbookMark();
  }
}

void lysenko::executeDelete(std::istream& input, lysenko::PhoneBook& myBook)
{
  std::string markName;

  input >> std::ws >> markName;

  if (myBook.checkIfThisMarkNameContains(markName))
  {
    myBook.deleteThisNote(markName);
  }
  else
  {
     throw InvalidbookMark();
  }
}

void lysenko::executeShow(std::istream& input, std::ostream& out, lysenko::PhoneBook& myBook)
{
  std::string markName;

  input >> std::ws >> markName;

  if (myBook.checkIfThisMarkNameContains(markName))
  {
    if (myBook.noContacts())
    {
      std::cout << "<EMPTY>" << "\n";
    }
    else
    {
      Contacts::constIteratorNote thisNote = myBook.showThisNote(markName);
      out << thisNote->number << " " << thisNote->name << "\n";
    }
  }
  else
  {
    throw InvalidbookMark();
  }
}

void lysenko::executeMove(std::istream& input, lysenko::PhoneBook& myBook)
{
  std::string markName;
  std::string steps;

  input >> std::ws >> markName;
  input >> std::ws >> steps;

  std::string cuttedOne = steps.substr(1, steps.size() - 1);

  if (myBook.checkIfThisMarkNameContains(markName))
  {
    if (steps == "first")
    {
      myBook.removeThisBookMark(markName, 1);
    }

    else if (steps == "last")
    {
      myBook.removeThisBookMark(markName, 0);
    }

    else if ((((steps[0] == '+') || (steps[0] == '-')) && (isDigitsOnly(cuttedOne))) || (isDigitsOnly(steps)))
    {
      int stepsInt = std::stoi(steps);
      if (stepsInt > 0)
      {
        myBook.removeThisBookMark(markName, 1, stepsInt);
      }
      else
      {
        myBook.removeThisBookMark(markName, 0, stepsInt);
      }
    }
    else
    {
      throw InvalidStep();
    }
  }
  else
  {
    throw InvalidbookMark();
  }
}
