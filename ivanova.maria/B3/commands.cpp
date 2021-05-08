#include <iostream>
#include "commands.hpp"

namespace iva = ivanova;

int iva::Commands::doCommand(std::string &command, iva::Bookmarks &bookmarks, std::stringstream &input)
{
  auto iter = commands.find(command);
  if (iter != commands.end())
  {
    return (*iter->second)(bookmarks, input);
  }
  else
  {
    invalidCommand(std::cout);
    return 1;
  }
}

int iva::doAdd(iva::Bookmarks &bookmarks, std::stringstream &input)
{
  Record info;
  input >> info;
  if (info.data.second.empty() || !iva::checkNumber(info.data.first))
  {
    invalidCommand(std::cout);
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
    invalidCommand(std::cout);
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
    invalidCommand(std::cout);
    return {};
  }
  if (bookmarks.isEmpty())
  {
    bookmarks.add(info);
  }
  else
  {
    if (!position.empty() && (position == "before" || position == "after"))
    {
      auto beforeOrAfter = getInsertType(position);
      bookmarks.insert(beforeOrAfter, mark, info);
    }
    else
    {
      invalidCommand(std::cout);
      return {};
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
    invalidCommand(std::cout);
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
    invalidCommand(std::cout);
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
    invalidCommand(std::cout);
    return 1;
  }
  else if (steps[0] == '-' || steps[0] == '+')
  {
    std::string tempStr;
    tempStr = steps.substr(1, steps.length() - 1);
    if (!iva::checkNumber(tempStr))
    {
      invalidStep(std::cout);
      return 1;
    }
    bookmarks.move(nameOfMark, std::stoi(steps));
  }
  else if (iva::checkNumber(steps))
  {
    bookmarks.move(nameOfMark, std::stoi(steps));
  }
  else
  {
    if (steps.empty() || (steps != "last" && steps != "first"))
    {
      invalidStep(std::cout);
      return 1;
    }
    auto firstOrLast = getPosition(steps);
    bookmarks.move(nameOfMark, firstOrLast);
  }
  return 0;
}

iva::Bookmarks::positionMove ivanova::getPosition(std::string &str)
{
  if (str == "first")
  {
    return iva::Bookmarks::FIRST;
  }
  else if (str == "last")
  {
    return iva::Bookmarks::LAST;
  }
  else
  {
    invalidStep(std::cout);
    return {};
  }
}

iva::Bookmarks::InsertType iva::getInsertType(std::string &str)
{
  if (str == "before")
  {
    return iva::Bookmarks::BEFORE;
  }
  else if (str == "after")
  {
    return iva::Bookmarks::AFTER;
  }
  else
  {
    invalidStep(std::cout);
    return {};
  }
}


