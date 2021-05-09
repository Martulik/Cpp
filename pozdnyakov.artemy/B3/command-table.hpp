#ifndef COMMAND_TABLE_HPP
#define COMMAND_TABLE_HPP

#include <string>
#include <vector>
#include <map>
#include "fields.hpp"

namespace pozdnyakov
{
  class CommandTable
  {
  public:
    template < typename... Patterns >
    CommandTable(Patterns... patters);
    bool checkCommand(std::vector< std::string > commandStr) const;
  private:
    std::vector< std::vector< std::string > > patterns_;
    static const std::map< std::string, AbsField* > fieldHandlers_;
  };
}

template < typename... Patterns >
pozdnyakov::CommandTable::CommandTable(Patterns... patterns):
  patterns_(patterns...)
{}

#endif
