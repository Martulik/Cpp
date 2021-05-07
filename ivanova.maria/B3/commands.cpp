#include <iostream>
#include "commands.hpp"

namespace iva = ivanova;

namespace ivanova
{
  int doAdd(Bookmarks &bookmarks, std::stringstream &input);
  int doStore(Bookmarks &bookmarks, std::stringstream &input);
  int doInsert(Bookmarks &bookmarks, std::stringstream &input);
  int doDelete(Bookmarks &bookmarks, std::stringstream &input);
  int doShow(Bookmarks &bookmarks, std::stringstream &input);
  int doMove(Bookmarks &bookmarks, std::stringstream &input);
}

int iva::doCommand(std::string &command, iva::Bookmarks &bookmarks, std::stringstream &input)
{
  const std::map< std::string, int (*)(iva::Bookmarks &, std::stringstream &) > commands
  {
    std::make_pair("add", doAdd),
    std::make_pair("store", doStore),
    std::make_pair("insert", doInsert),
    std::make_pair("delete", doDelete),
    std::make_pair("show", doShow),
    std::make_pair("move", doMove)
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
  Record info;
  input >> info;
  if (info.data.second.empty() || !iva::checkNumber(info.data.first))
  {
    std::cout << "<INVALID COMMAND>\n";
    return 1;
  }
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
  pair data= {nameOfMark, newNameOfMark};
  bookmarks.store(data);
  return 0;
}

int iva::doInsert(iva::Bookmarks &bookmarks, std::stringstream &input)
{
  std::string position;
  input >> std::ws >> position;
  std::string mark;
  input >> std::ws >> mark;
  Record info;
  input >> info;
  if (!iva::checkMark(mark) || !iva::checkNumber(info.data.first) || info.data.second.empty())
  {
    std::cout << "<INVALID COMMAND>\n";
    return {};
  }
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
