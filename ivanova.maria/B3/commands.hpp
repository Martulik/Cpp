#ifndef B3_COMMANDS_HPP
#define B3_COMMANDS_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <functional>

#include "bookmarks.hpp"

namespace ivanova
{
  using pair = std::pair< std::string, std::string >;
  std::string getName(std::string &name);
  bool checkNumber(const std::string &number);
  bool checkMark(const std::string &mark);
  int doCommand(std::string &command, Bookmarks &bookmarks, std::stringstream &input);
  int doAdd(Bookmarks &bookmarks, std::stringstream &input);
  int doStore(Bookmarks &bookmarks, std::stringstream &input);
  int doInsert(Bookmarks &bookmarks, std::stringstream &input);
  int doDelete(Bookmarks &bookmarks, std::stringstream &input);
  int doShow(Bookmarks &bookmarks, std::stringstream &input);
  int doMove(Bookmarks &bookmarks, std::stringstream &input);
}
#endif
