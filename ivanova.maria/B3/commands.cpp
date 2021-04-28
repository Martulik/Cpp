#include <cctype>
#include <iostream>
#include "commands.hpp"

namespace iva = ivanova;

int iva::doCommand(std::string &command, iva::Bookmarks &bookmarks, std::stringstream &input)
{
  int (*fncPtr1)(iva::Bookmarks &bookmarks, std::stringstream &input);
  int (*fncPtr2)(iva::Bookmarks &bookmarks, std::stringstream &input);
  int (*fncPtr3)(iva::Bookmarks &bookmarks, std::stringstream &input);
  int (*fncPtr4)(iva::Bookmarks &bookmarks, std::stringstream &input);
  int (*fncPtr5)(iva::Bookmarks &bookmarks, std::stringstream &input);
  int (*fncPtr6)(iva::Bookmarks &bookmarks, std::stringstream &input);
  const std::map< std::string, int (*)(iva::Bookmarks &, std::stringstream &) > commands
  {
    std::make_pair("add", fncPtr1 = doAdd),
    std::make_pair("store", fncPtr2 = doStore),
    std::make_pair("insert", fncPtr3 = doInsert),
    std::make_pair("delete", fncPtr4 = doDelete),
    std::make_pair("show", fncPtr5 = doShow),
    std::make_pair("move", fncPtr6 = doMove)
  };
  auto iter = commands.find(command);
  std::cout << "\ncommand is " << iter->first << std::endl;
  if (iter != commands.end())
  {
    return (*iter->second)(bookmarks, input);
  }
  else
  {
    std::cout << "<1INVALID COMMAND>\n";
    return 1;
  }
}

int iva::doAdd(iva::Bookmarks &bookmarks, std::stringstream &input)
{
  std::string number;
  input >> std::ws >> number;
  std::string name;
  std::getline(input >> std::ws, name);
  if ((!name.empty()) && (name.back() == '\r'))
  {
    name.pop_back();
  }
  name = iva::getName(name);
  if (name.empty() || !iva::checkNumber(number))
  {
    std::cout << "<2INVALID COMMAND>\n";
    return 1;
  }
  pair info = {number, name};
  bookmarks.add(info);
  return 1;
}

int iva::doStore(iva::Bookmarks &bookmarks, std::stringstream &input)
{
  std::string nameOfMark;
  input >> std::ws >> nameOfMark;
  std::string newNameOfMark;
  std::getline(input >> std::ws, newNameOfMark);
  if ((!newNameOfMark.empty()) && (newNameOfMark.back() == '\r'))
  {
    newNameOfMark.pop_back();
  }
  if (!iva::checkMark(nameOfMark) || !iva::checkMark(newNameOfMark))
  {
    std::cerr << "<3INVALID COMMAND>\n";
    return {};
  }
  bookmarks.store({nameOfMark, newNameOfMark});
  return 0;
}

int iva::doInsert(iva::Bookmarks &bookmarks, std::stringstream &input)
{
  std::string position;
  input >> std::ws >> position;
  std::string mark;
  input >> std::ws >> mark;
  std::string number;
  input >> std::ws >> number;
  std::string name;
  std::getline(input >> std::ws, name);
  name = iva::getName(name);
  if (!iva::checkMark(mark) || !iva::checkNumber(number) || name.empty())
  {
    std::cerr << "<4INVALID COMMAND>\n";
    return {};
  }
  if (name.back() == '\r')
  {
    name.pop_back();
  }
  pair info = {name, number};
  if (bookmarks.isEmpty())
  {
    bookmarks.add(info);
  }
  else
  {
    if (position == "before")
    {
      bookmarks.insert(iva::Bookmarks::BEFORE, mark, info);
    }
    else if (position == "after")
    {
      bookmarks.insert(iva::Bookmarks::AFTER, mark,info);
    }
    else
    {
      std::cerr << "<5INVALID COMMAND>\n";
      return 1;
    }
  }
  return 0;
}

int iva::doDelete(iva::Bookmarks &bookmarks, std::stringstream &input)
{
  std::string mark;
  std::getline(input >> std::ws, mark);
  if ((!mark.empty()) && (mark.back() == '\r'))
  {
    mark.pop_back();
  }
  if (!iva::checkMark(mark))
  {
    std::cerr << "<6INVALID COMMAND>\n";
    return 1;
  }
  else
  {
    bookmarks.deleteMark(mark);
    return 0;
  }
}

int iva::doShow(iva::Bookmarks &bookmarks, std::stringstream &input)
{
  std::string mark;
  std::getline(input >> std::ws, mark);
  if (!mark.empty() && mark.back() == '\r')
  {
    mark.pop_back();
  }
  if (!iva::checkMark(mark))
  {
    std::cerr << "<7INVALID COMMAND>\n";
    return 1;
  }
  else
  {
    bookmarks.show(mark);
    return 0;
  }
}

int iva::doMove(iva::Bookmarks &bookmarks, std::stringstream &input)
{
  std::string nameOfMark;
  input >> std::ws >> nameOfMark;
  std::string steps;
  std::getline(input >> std::ws, steps);
  if ((!steps.empty()) && (steps.back() == '\r'))
  {
    steps.pop_back();
  }
  if (!iva::checkMark(nameOfMark))
  {
    std::cerr <<"<8INVALID COMMAND>\n";
    return 1;
  }
  else if (steps == "first")
  {
    bookmarks.move(nameOfMark, iva::Bookmarks::FIRST);
  }
  else if (steps == "last")
  {
    bookmarks.move(nameOfMark, iva::Bookmarks::LAST);
  }
  else if (steps[0] == '-' || steps[0] == '+')
  {
    std::string tempStr;
    tempStr = steps.substr(1, steps.length() - 1);
    if (!iva::checkNumber(tempStr))
    {
      std::cerr << "<9INVALID STEP>\n";
      return 1;
    }
    bookmarks.move(nameOfMark, std::stoi(steps));
  }
  else
  {
    if (!iva::checkNumber(steps))
    {
      std::cerr << "<10INVALID STEP>\n";
      return 1;
    }
    bookmarks.move(nameOfMark, std::stoi(steps));
  }
  if (steps.empty())
  {
    std::cerr << "<11INVALID COMMAND>\n";
    return 1;
  }
  return 0;
}

namespace ivanova
{
  bool checkNumber(const std::string &number)
  {
    if (number.empty())
    {
      return false;
    }
    for (char i: number)
    {
      if (!isdigit(i))
      {
        return false;
      }
    }
    return true;
  }

  std::string getName(std::string &name)
  {
    if (name.empty())
    {
      return "";
    }
    if (name.front() != '\"')
    {
      return "";
    }
    name.erase(name.begin());
    size_t i = 0;
    for (i = 0; (i < name.size()) && (name[i] != '\"'); i++)
    {
      if (name[i] == '\\')
      {
        if ((name[i + 1] == '\"') && (i + 2 < name.size()))
        {
          name.erase(i, 1);
        }
        else
        {
          return "";
        }
      }
    }
    if (i == name.size())
    {
      return "";
    }
    name.erase(i);
    if (name.empty())
    {
      return "";
    }
    return name;
  }

  bool checkMark(const std::string &mark)
  {
    if (mark.empty())
    {
      return false;
    }
    for (char i: mark)
    {
      if ((!isalnum(i)) && (i != '-'))
      {
        return false;
      }
    }
    return true;
  }
}
