#ifndef B3_COMMANDS_HPP
#define B3_COMMANDS_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <functional>

#include "bookmarks.hpp"

namespace ivanova
{
  class Commands
  {
  public:
    explicit Commands(std::ostream& out);
    int doCommand(std::string &command, std::stringstream &input);
  private:
    Bookmarks marks_;
    std::ostream &out_;
    const std::map< std::string, int (*)(Bookmarks &, std::stringstream &, std::ostream &) > commands_;
  };

  void invalidCommand(std::ostream& out);
  void empty(std::ostream &out);
  void invalidBookmark(std::ostream &out);
  void invalidStep(std::ostream &out);
}
#endif
