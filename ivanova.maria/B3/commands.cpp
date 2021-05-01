#include <cctype>
#include <iostream>
#include "commands.hpp"

namespace iva = ivanova;

int iva::doCommand(std::string &command, iva::Bookmarks &bookmarks, std::stringstream &input)
{
  int (*add)(iva::Bookmarks &bookmarks, std::stringstream &input) = doAdd;
  int (*store)(iva::Bookmarks &bookmarks, std::stringstream &input) = doStore;
  int (*insert)(iva::Bookmarks &bookmarks, std::stringstream &input) = doInsert;
  int (*deleteBM)(iva::Bookmarks &bookmarks, std::stringstream &input) = doDelete;
  int (*show)(iva::Bookmarks &bookmarks, std::stringstream &input) = doShow;
  int (*move)(iva::Bookmarks &bookmarks, std::stringstream &input) = doMove;
  const std::map< std::string, int (*)(iva::Bookmarks &, std::stringstream &) > commands
  {
    std::make_pair("add", add),
    std::make_pair("store", store),
    std::make_pair("insert", insert),
    std::make_pair("delete", deleteBM),
    std::make_pair("show", show),
    std::make_pair("move", move)
  };
  auto iter = commands.find(command);
  if (iter != commands.end())
  {
    return (*iter->second)(bookmarks, input);
  }
  else
  {
    std::cout << "<INVALID COMMAND>\n";
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
    std::cout << "<INVALID COMMAND>\n";
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
    std::cerr << "<INVALID COMMAND>\n";
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
    std::cout << "<INVALID COMMAND>\n";
    return {};
  }
  if (name.back() == '\r')
  {
    name.pop_back();
  }
  pair info = {number, name};
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
      std::cerr << "<INVALID COMMAND>\n";
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
    std::cerr << "<INVALID COMMAND>\n";
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
  if (iva::checkMark(mark))
  {
    if (mark.back() == '\r')
    {
      mark.pop_back();
    }
    bookmarks.show(mark);
    return 0;
  }
  else
  {
    std::cout << "<INVALID COMMAND>\n";
    return 1;
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
    std::cerr <<"<INVALID COMMAND>\n";
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
      std::cout << "<INVALID STEP>\n";
      return 1;
    }
    bookmarks.move(nameOfMark, std::stoi(steps));
  }
  else
  {
    if (!iva::checkNumber(steps))
    {
      std::cout << "<INVALID STEP>\n";
      return 1;
    }
    bookmarks.move(nameOfMark, std::stoi(steps));
  }
  if (steps.empty())
  {
    std::cout << "<INVALID COMMAND>\n";
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
    for (i; (i < name.size()) && (name[i] != '\"'); i++)
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
