#include "commands.hpp"
#include <iostream>

namespace iva = ivanova;


namespace ivanova
{
  Commands::comm doAdd(Bookmarks &bookmarks, std::stringstream &input, std::ostream &out);
  Commands::comm doStore(Bookmarks &bookmarks, std::stringstream &input, std::ostream &out);
  Commands::comm doInsert(Bookmarks &bookmarks, std::stringstream &input, std::ostream &out);
  Commands::comm doDelete(Bookmarks &bookmarks, std::stringstream &input, std::ostream &out);
  Commands::comm doShow(Bookmarks &bookmarks, std::stringstream &input, std::ostream &out);
  Commands::comm doMove(Bookmarks &bookmarks, std::stringstream &input, std::ostream &out);
  Bookmarks::positionMove getPosition(std::string &str);
  Bookmarks::InsertType getInsertType(std::string &str);
  Commands::comm returnCode1();
}

iva::Commands::comm iva::Commands::doCommand(std::string &command, std::stringstream &input)
{
  auto iter = commands_.find(command);
  if (iter != commands_.end())
  {
    return (iter->second)(marks_, input, out_);
  }
  else
  {
    invalidCommand(std::cout);
    return returnCode1();
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


iva::Commands::comm iva::doAdd(iva::Bookmarks &bookmarks, std::stringstream &input, std::ostream &out)
{
  Record info;
  input >> info;
  if (info.data.second.empty() || !iva::checkNumber(info.data.first))
  {
    invalidCommand(out);
    return returnCode1();
  }
  bookmarks.add(info);
  return 0;
}

iva::Commands::comm iva::doStore(iva::Bookmarks &bookmarks, std::stringstream &input, std::ostream &out)
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
    return returnCode1();
  }
  Record data = {{nameOfMark, newNameOfMark}};
  bookmarks.store(data);
  return 0;
}

iva::Commands::comm iva::doInsert(iva::Bookmarks &bookmarks, std::stringstream &input, std::ostream &out)
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
    return returnCode1();
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
      return returnCode1();
    }

  }
  return 0;
}

iva::Commands::comm iva::doDelete(iva::Bookmarks &bookmarks, std::stringstream &input, std::ostream &out)
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
    return returnCode1();
  }
  else
  {
    bookmarks.deleteMark(mark);
    return 0;
  }
}

iva::Commands::comm iva::doShow(iva::Bookmarks &bookmarks, std::stringstream &input, std::ostream &out)
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
      if (!bookmarks.isEmpty())
      {
        auto iter = bookmarks.getMark(mark);
        out << *iter->second;
        return 0;
      }
      else
      {
        empty(out);
        return returnCode1();
      }
    }
    else
    {
      invalidBookmark(out);
      return returnCode1();
    }
  }
  else
  {
    invalidCommand(out);
    return returnCode1();
  }
}

iva::Commands::comm iva::doMove(iva::Bookmarks &bookmarks, std::stringstream &input, std::ostream &out)
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
    return returnCode1();
  }
  if (!bookmarks.findMark(nameOfMark))
  {
    invalidBookmark(out);
    return returnCode1();
  }
  else if (steps[0] == '-' || steps[0] == '+')
  {
    std::string tempStr;
    tempStr = steps.substr(1, steps.length() - 1);
    if (!iva::checkNumber(tempStr))
    {
      invalidStep(out);
      return returnCode1();
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
      return returnCode1();
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

ivanova::Commands::comm ivanova::returnCode1()
{
  return []()
  {
    return 1;
  };
}

bool iva::checkMark(const std::string &mark)
{
  if (mark.empty())
  {
    return false;
  }
  for (char i: mark)
  {
    if ((!std::isalnum(i)) && (i != '-'))
    {
      return false;
    }
  }
  return true;
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


