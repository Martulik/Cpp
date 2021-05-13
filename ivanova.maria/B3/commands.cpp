#include <iostream>
#include "commands.hpp"

namespace iva = ivanova;

namespace ivanova
{
  int doAdd(Bookmarks &bookmarks, std::stringstream &input, std::ostream &out);
  int doStore(Bookmarks &bookmarks, std::stringstream &input, std::ostream &out);
  int doInsert(Bookmarks &bookmarks, std::stringstream &input, std::ostream &out);
  int doDelete(Bookmarks &bookmarks, std::stringstream &input, std::ostream &out);
  int doShow(Bookmarks &bookmarks, std::stringstream &input, std::ostream &out);
  int doMove(Bookmarks &bookmarks, std::stringstream &input, std::ostream &out);
  Bookmarks::positionMove getPosition(std::string &str);
  Bookmarks::InsertType getInsertType(std::string &str);
}

int iva::Commands::doCommand(std::string &command, std::stringstream &input)
{
  auto iter = commands_.find(command);
  if (iter != commands_.end())
  {
    return (*iter->second)(marks_, input, out_);
  }
  else
  {
    invalidCommand(std::cout);
    return 1;
  }
}

ivanova::Commands::Commands(std::ostream &out):
  out_(out),
  commands_(
    {
      std::make_pair("add", doAdd),
      std::make_pair("store", doStore),
      std::make_pair("insert", doInsert),
      std::make_pair("delete", doDelete),
      std::make_pair("show", doShow),
      std::make_pair("move", doMove)
    })
{

}

int iva::doAdd(iva::Bookmarks &bookmarks, std::stringstream &input, std::ostream &out)
{
  Record info;
  input >> info;
  if (info.data.second.empty() || !iva::checkNumber(info.data.first))
  {
    invalidCommand(out);
    return 1;
  }
  bookmarks.add(info);
  return 1;
}

int iva::doStore(iva::Bookmarks &bookmarks, std::stringstream &input, std::ostream &out)
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
    invalidCommand(out);
    return {};
  }
  Record data = {{nameOfMark, newNameOfMark}};
  bookmarks.store(data);
  return 0;
}

int iva::doInsert(iva::Bookmarks &bookmarks, std::stringstream &input, std::ostream &out)
{
  std::string position;
  input >> std::ws >> position;
  std::string mark;
  input >> std::ws >> mark;
  Record info;
  input >> info;
  if (!iva::checkMark(mark) || !iva::checkNumber(info.data.first) || info.data.second.empty())
  {
    invalidCommand(out);
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
      bookmarks.insert(info, beforeOrAfter, mark);
    }
    else
    {
      invalidCommand(out);
      return {};
    }

  }
  return 0;
}

int iva::doDelete(iva::Bookmarks &bookmarks, std::stringstream &input, std::ostream &out)
{
  std::string mark;
  std::getline(input >> std::ws, mark);
  if ((!mark.empty()) && (mark.back() == '\r'))
  {
    mark.pop_back();
  }
  if (!iva::checkMark(mark))
  {
    invalidCommand(out);
    return 1;
  }
  else
  {
    bookmarks.deleteMark(mark);
    return 0;
  }
}

int iva::doShow(iva::Bookmarks &bookmarks, std::stringstream &input, std::ostream &out)
{
  std::string mark;
  std::getline(input >> std::ws, mark);
  if (iva::checkMark(mark))
  {
    if (mark.back() == '\r')
    {
      mark.pop_back();
    }
    if (bookmarks.findMark(mark))
    {
      out << *bookmarks.getMark(mark)->second;
      return 0;
    }
    else
    {
      empty(out);
      return 1;
    }
  }
  else
  {
    invalidCommand(out);
    return 1;
  }
}

int iva::doMove(iva::Bookmarks &bookmarks, std::stringstream &input, std::ostream &out)
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
    invalidCommand(out);
    return 1;
  }
  else if (steps[0] == '-' || steps[0] == '+')
  {
    std::string tempStr;
    tempStr = steps.substr(1, steps.length() - 1);
    if (!iva::checkNumber(tempStr))
    {
      invalidStep(out);
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
      invalidStep(out);
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

void ivanova::invalidCommand(std::ostream &out)
{
  out << "<INVALID COMMAND>\n";
}

void ivanova::empty(std::ostream &out)
{
  out << "<EMPTY>\n";
}

void ivanova::invalidBookmark(std::ostream &out)
{
  out << "<INVALID BOOKMARK>\n";
}

void ivanova::invalidStep(std::ostream &out)
{
  out << "<INVALID STEP>\n";
}


