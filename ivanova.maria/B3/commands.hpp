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
  int doCommand(std::string &command, Bookmarks &bookmarks, std::stringstream &input);
}
#endif
