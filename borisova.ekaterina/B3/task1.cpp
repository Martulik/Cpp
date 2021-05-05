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
  Note temp;
  std::string markName1;
  std::string markName2;
  std::string type;
  std::string step;
  while (std::getline(std::cin, line) && !line.empty())
  {
    std::istringstream in(line);
    in >> command;
    int n = 0;
    int flag = 1;

    if (command == "add")
    {
      in >> std::ws >> temp.number_;
      std::getline(in >> std::ws, temp.name_);

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
      in >> std::ws >> markName1;
      in >> std::ws >> markName2;

      value.store(markName1, markName2);
    }
    else if (command == "insert")
    {
      in >> std::ws >> type;
      in >> std::ws >> markName1;
      in >> std::ws >> temp.number_;
      getline(in >> std::ws, temp.name_);

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
      in >> std::ws >> markName1;
      value.deleteMark(markName1);
    }
    else if (command == "show")
    {
      in >> std::ws >> markName1;
      value.show(markName1);
    }
    else if (command == "move")
    {
      in >> std::ws >> markName1;
      in >> std::ws >> step;
      if (step == "first" || step == "last")
      {
        value.move(markName1, step);
      }
      else
      {
        size_t k = 0;
        if (!isdigit(step[0]) && (step[0] != '-') && (step[0] != '+'))
        {
          std::cout << lab::invalidStep;
        }
        else
        {
          if (isdigit(step[0]))
          {
            n += step[0] - '0';
          }
          else if (step[0] == '-')
          {
            flag = -1;
          }
          for (size_t i = 1; i < step.length(); i++)
          {
            if (!isdigit(step[i]))
            {
              std::cout << lab::invalidStep;
              break;
            }
            else
            {
              n *= 10;
              n += step[i] - '0';
              k++;
            }
          }
        }
        if (k == step.length()-1)
        {
          value.move(markName1, n * flag);
        }
      }

    }
    else
    {
      std::cout << lab::invalidStep;
    }
  }
}

bool lab::correctName(Note& src)
{
  if (src.name_.empty() || src.name_.front() != '\"' || src.name_.back() != '\"')
  {
    return false;
  }
  src.name_.erase(src.name_.begin());
  src.name_.erase(--src.name_.end());

  for (size_t i = 0; i < src.name_.length(); i++)
  {
    if (src.name_[i] == '\\')
    {
      src.name_.erase(i, 1);
    }
  }
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
