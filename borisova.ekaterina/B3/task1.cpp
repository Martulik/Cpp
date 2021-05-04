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
    int step;

    if (command == "add")
    {
      std::cin >> temp.number_ >> temp.name_;
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
      std::cin >> markName1 >> markName1;
      value.store(markName1, markName2);
    }
    else if (command == "insert")
    {
      std::cin >> type >> markName1 >> temp.number_ >> temp.name_;
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
      std::cin >> markName1;
      value.deleteMark(markName1);
    }
    else if (command == "show")
    {
      std::cin >> markName1;
      value.show(markName1);
    }
    else if (command == "move")
    {
      std::cin >> markName1 >> step;
      value.move(markName1, step);
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
  if ((src.name_[0] != '\"') || (src.name_[0] != '\"'))
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


