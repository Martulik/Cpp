#include "tasks.hpp"
#include <iostream>
#include <sstream>
#include <string>

namespace lab = borisova;

void lab::doTask1()
{
  Interface value;
  std::string command;
  std::string line;

  while (std::getline(std::cin, line) && !line.empty())
  {
    std::istringstream in(line);
    std::string command;
    in >> command;

    Note temp;
    std::string markName1;
    std::string markName2;
    std::string type;
    std::string step;
    int n = 0;

    if (command == "add")
    {
      in >> temp.number_ >> temp.name_;
      if (correctName(temp) && correctNumder(temp))
      {
        value.add(temp);
      }
      else
      {
        std::cout << lab::invalidCommand;
      }
    }
    else if (command == "store")
    {
      in >> markName1 >> markName1;
      value.store(markName1, markName2);
    }
    else if (command == "insert")
    {
      in >> type >> markName1 >> temp.number_ >> temp.name_;
      if (correctName(temp) && correctNumder(temp))
      {
        if (type == "before")
        {
          value.insertBefore(markName1, temp);
        }
        else if (type == "after")
        {
          value.insertAfter(markName1, temp);
        }
      }
      else
      {
        std::cout << lab::invalidCommand;
      }
    }
    else if (command == "delete")
    {
      in >> markName1;
      value.deleteMark(markName1);
    }
    else if (command == "show")
    {
      in >> markName1;
      value.show(markName1);
    }
    else if (command == "move")
    {
      in >> markName1 >> step;
      if (step == "first" || step == "last")
      {
        value.move(markName1, step);
      }
      else
      {
         size_t k = 0;
        for (size_t i = 0; i < step.length(); i++)
        {
          if (!isdigit(step[i]))
          {
            std::cout << lab::invalidCommand;
          }
          else
          {
            n *= 10;
            n += step[i] - '0';
            k++;
          }
        }
        if (k == step.length())
        {
          value.move(markName1, n);
        }
      }

    }
    else
    {
      std::cout << lab::invalidCommand;
    }
  }
}

bool lab::correctName(Note& src)
{
  if (src.name_.length() < 1)
  {
    return false;
  }

  src.name_.erase(src.name_.begin());
  for (size_t i = 0; i < src.name_.length(); i++)
  {
    if (src.name_[i] == '\\')
    {
      if ((src.name_[i + 1] == '\"') && (i + 2 < src.name_.length()))
      {
        src.name_.erase(i, 1);
      }
      else
      {
        return false;
      }
    }
  }
  if (src.name_.length() == 0)
  {
    return false;
  }
  src.name_.erase(src.name_.length()-1);
  if (src.name_.empty())
  {
    return false;
  }
  return true;
}

bool lab::correctNumder(Note& src)
{
  if (src.number_.length() < 1)
  {
    return false;
  }
  for (size_t i = 0; i < src.number_.length(); i++)
  {
    if (!isdigit(src.number_[i]))
    {
      return false;
    }
  }
  return true;
}
