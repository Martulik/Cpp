#include "tasks.hpp"
#include <iostream>
#include <sstream>
#include <string>

namespace lab = borisova;
using constItr = std::map< std::string, lab::Book::constItr >::const_iterator;

void lab::doTask1(std::istream& input, std::ostream& output)
{
  Interface value;
  std::string line;
  while (std::getline(input, line) && !line.empty())
  {
    std::istringstream in(line);
    std::string command;

    in >> command;

    Note temp;
    std::string mark;
    int n = 0;
    int code = 1;

    if (command == "add")
    {
      std::string number;
      std::string name;
      in >> std::ws >> number;
      if (correctNumder(number))
      {
        std::getline(in >> std::ws, name);
        name = fixName(name);
        if (!(name.empty()))
        {
          temp = {name, number};
          value.add(temp);
        }
        else
        {
          lab::invalidCommand(output);
        }
      }
      else
      {
        lab::invalidCommand(output);
      }
    }
    else if (command == "store")
    {
      std::string markName1;
      std::string markName2;
      in >> std::ws >> markName1;
      in >> std::ws >> markName2;
      constItr iter = value.findMark(markName1);
      if (iter == value.getEnd())
      {
        lab::invalidBookMark(output);
      }
      value.store(markName1, markName2);
    }
    else if (command == "insert")
    {
      std::string type;
      std::string markName;
      std::string number1;
      std::string name1;

      in >> std::ws >> type;
      in >> std::ws >> markName;
      in >> std::ws >> number1;
      getline(in >> std::ws, name1);
      name1 = fixName(name1);
      if (!(name1.empty()) && correctNumder(number1))
      {
        temp = { name1, number1 };

        constItr iter = value.findMark(markName);
        if (iter == value.getEnd())
        {
          lab::invalidBookMark(output);
        }
        else if (type == "before")
        {
          value.insertBefore(markName, temp);
        }
        else if (type == "after")
        {

          value.insertAfter(markName, temp);
        }
      }
      else
      {
        lab::invalidCommand(output);
      }
    }
    else if (command == "delete")
    {
      in >> std::ws >> mark;
      value.deleteMark(mark);
    }
    else if (command == "show")
    {
      in >> std::ws >> mark;
      constItr iteratr = value.findMark(mark);

      if (iteratr != value.getEnd())
      {
        if (value.isEmpty())
        {
          lab::empty(output);
        }
        else
        {
          output << *iteratr->second;
        }
      }
      else
      {
        lab::invalidBookMark(output);
      }
    }
    else if (command == "move")
    {
      std::string step;
      in >> std::ws >> mark;
      in >> std::ws >> step;
      if (step == "first" || step == "last")
      {
        constItr iter = value.findMark(mark);
        if (iter == value.getEnd())
        {
          lab::invalidBookMark(output);
        }
        value.move(mark, step);
      }
      else
      {
        if (!isdigit(step[0]) && (step[0] != '-') && (step[0] != '+'))
        {
          lab::invalidStep(output);
        }
        else
        {
          for (size_t i = 1; i < step.length(); i++)
          {
            if (!isdigit(step[i]))
            {
              lab::invalidStep(output);
              code = 0;
              break;
            }
          }
          if (code)
          {
            n = std::stoi(step);
            constItr iter = value.findMark(mark);
            if (iter == value.getEnd())
            {
              lab::invalidBookMark(output);
            }
            value.move(mark, n);
          }
        }
      }
    }
    else
    {
      lab::invalidStep(output);
    }
  }
}

void lab::invalidCommand(std::ostream& out)
{
  out << "<INVALID COMMAND>\n";
}

void lab::invalidBookMark(std::ostream& out)
{
  out << "<INVALID BOOKMARK>\n";
}

void lab::invalidStep(std::ostream& out)
{
  out << "<INVALID STEP>\n";
}

void lab::empty(std::ostream& out)
{
  out << "<EMPTY>\n";
}
