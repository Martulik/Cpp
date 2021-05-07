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
  int doAdd(Bookmarks &bookmarks, std::stringstream &input);
  int doStore(Bookmarks &bookmarks, std::stringstream &input);
  int doInsert(Bookmarks &bookmarks, std::stringstream &input);
  int doDelete(Bookmarks &bookmarks, std::stringstream &input);
  int doShow(Bookmarks &bookmarks, std::stringstream &input);
  int doMove(Bookmarks &bookmarks, std::stringstream &input);

  class Commands
  {
  public:
    int doCommand(std::string &command, Bookmarks &bookmarks, std::stringstream &input);
  private:
    const std::map< std::string, int (*)(Bookmarks &, std::stringstream &) > commands
    {
      std::make_pair("add", doAdd),
      std::make_pair("store", doStore),
      std::make_pair("insert", doInsert),
      std::make_pair("delete", doDelete),
      std::make_pair("show", doShow),
      std::make_pair("move", doMove)
    };
  };
}
#endif
