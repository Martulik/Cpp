#include "tasks.hpp"
#include <iostream>
#include <sstream>
#include <string>

namespace lab = borisova;

void lab::doTask1(std::istream& input, std::ostream& output)
{
  std::string line;
  while (std::getline(input, line) && !line.empty())
  {
    std::istringstream in(line);
    std::string command;
    in >> command;

    Note temp;
    std::string mark;
    Interface value;
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
        if (correctName(name))
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

      value.store(markName1, markName2, output);
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

      if (correctName(name1) && correctNumder(number1))
      {
        temp = {name1, number1};
        if (type == "before")
        {
          value.insertBefore(markName, temp, output);
        }
        else if (type == "after")
        {
          value.insertAfter(markName, temp, output);
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
      value.show(mark, output);
    }
    else if (command == "move")
    {
      std::string step;
      in >> std::ws >> mark;
      in >> std::ws >> step;
      if (step == "first" || step == "last")
      {
        value.move(mark, step, output);
      }
      else
      {
        size_t k = 0;
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
            value.move(mark, n, output);
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
