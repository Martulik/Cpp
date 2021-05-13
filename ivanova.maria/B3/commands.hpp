#ifndef B3_COMMANDS_HPP
#define B3_COMMANDS_HPP

#include <iosfwd>
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
    using comm = std::function< int() >;
    comm doCommand(std::string &command, std::stringstream &input);
  private:
    Bookmarks marks_;
    std::ostream &out_;
    using str = std::string;
    const std::map< str, std::function< int() >(*)(Bookmarks &, std::stringstream &, std::ostream &) > commands_;
  };

  bool checkMark(const std::string &mark);
  void invalidCommand(std::ostream& out);
  void empty(std::ostream &out);
  void invalidBookmark(std::ostream &out);
  void invalidStep(std::ostream &out);
}
#endif
