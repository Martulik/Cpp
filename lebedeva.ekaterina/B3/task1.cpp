#include "tasks.hpp"
#include <string>
#include <iterator>
#include <sstream>
#include <vector>
#include <algorithm>
#include "phonebook_interface.hpp"
#include "error-messages.hpp"
#include "line.hpp"

namespace lebedeva
{
  using constIter = std::map< std::string, lebedeva::PhoneBook::constIter >::const_iterator;
  void commandProcessing(std::string str);
  //std::ostream& output;
  Interface obj;
  std::string myOut = "";
}

void lebedeva::doTask1(std::istream& in, std::ostream& out)
{
  std::istream_iterator< Line > inIterFirst(in);
  std::istream_iterator< Line > inIterLast;
  std::vector< std::string > inVec(inIterFirst, inIterLast);
  //output.copyfmt(out);
  //std::vector< std::string >::iterator it = inVec.begin();
  std::for_each(inVec.begin(), inVec.end(), commandProcessing);
  out << lebedeva::myOut;
}

void lebedeva::commandProcessing(std::string str)
{
  std::stringstream input(str);
  std::string command;
  input >> std::ws >> command;

  if (command == "add")
  {
    record_t recToAdd;
    input >> std::ws >> recToAdd.phoneNumber;
    if (checkNumber(recToAdd.phoneNumber))
    {
      std::getline(input >> std::ws, recToAdd.name);
      if (isName(recToAdd.name))
      {
        extractName(recToAdd.name);
        if (!recToAdd.name.empty())
        {
          obj.add(recToAdd);
        }
        else
        {
          myOut += invalidCommand();
        }
      }
      else
      {
        myOut += invalidCommand();
      }
    }
    else
    {
      myOut += invalidCommand();
    }
  }
  else if (command == "store")
  {
    std::string markName;
    std::string newMarkName;

    input >> std::ws >> markName;
    input >> std::ws >> newMarkName;

    constIter iter = obj.find(markName);
    if (iter != obj.end())
    {
      obj.store(markName, newMarkName);
    }
    else
    {
      myOut += invalidCommand();
    }
  }
  else if (command == "insert")
  {
    std::string whr;
    std::string markName;
    record_t recToIns;

    input >> std::ws >> whr;
    input >> std::ws >> markName;
    input >> std::ws >> recToIns.phoneNumber;
    std::getline(input >> std::ws, recToIns.name);
    if (isName(recToIns.name))
    {
      extractName(recToIns.name);
      if (!(recToIns.name.empty()) && checkNumber(recToIns.phoneNumber))
      {
        constIter iter = obj.find(markName);
        if (iter != obj.end())
        {
          if (whr == "before")
          {
            obj.insert(Interface::Where::before, markName, recToIns);
          }
          else if (whr == "after")
          {
            obj.insert(Interface::Where::after, markName, recToIns);
          }
          else
          {
            myOut += invalidCommand();
          }
        }
        else
        {
          myOut += invalidCommand();
        }
      }
      else
      {
        myOut += invalidCommand();
      }
    }
    else
    {
      myOut += invalidCommand();
    }
  }
  else if (command == "delete")
  {
    std::string markName;
    input >> std::ws >> markName;
    constIter iter = obj.find(markName);
    if (iter != obj.end())
    {
      obj.deleteRec(markName);
    }
    else
    {
      myOut += invalidCommand();
    }
  }
  else if (command == "show")
  {
    std::string markName;
    input >> std::ws >> markName;

    constIter iter = obj.find(markName);
    if (iter != obj.end())
    {
      if (!obj.empty())
      {
        myOut += (*iter->second).phoneNumber;
        myOut += " ";
        myOut += (*iter->second).name;
        myOut += "\n";
      }
      else
      {
        myOut += empty();
      }
    }
    else
    {
      myOut += invalidBookmark();
    }
  }
  else if (command == "move")
  {
    std::string markName;
    std::string steps;
    input >> std::ws >> markName;
    std::getline(input >> std::ws, steps);

    constIter iter = obj.find(markName);
    if (iter != obj.end())
    {
      if (!(steps.empty()))
      {
        if (checkNumber(steps))
        {
          int iSteps = std::stoi(steps);
          obj.move(markName, iSteps);
        }
        else if (steps == "first")
        {
          obj.move(markName, Interface::Steps::first);
        }
        else if (steps == "last")
        {
          obj.move(markName, Interface::Steps::last);
        }
        else
        {
          myOut += invalidStep();
        }
      }
      else
      {
        myOut += invalidCommand();
      }
    }
    else
    {
      myOut += invalidCommand();
    }
  }
  else
  {
  myOut += invalidCommand();
  }
}
