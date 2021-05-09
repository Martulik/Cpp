#ifndef COMMAND_TABLE_HPP
#define COMMAND_TABLE_HPP

#include <string>
#include <vector>
#include <memory>
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
    using fhMapType = std::map< const std::string, std::unique_ptr< AbsField > >;
    std::vector< std::vector< std::string > > patterns_;
    static fhMapType fieldHandlersMap_;
    static fhMapType genMap();
  };
}

namespace poz = pozdnyakov;

template < typename... Patterns >
poz::CommandTable::CommandTable(Patterns... patterns):
  patterns_(patterns...)
{}

#endif
