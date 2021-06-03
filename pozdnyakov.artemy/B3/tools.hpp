#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <memory>
#include "phonebook.hpp"

namespace pozdnyakov
{
  Phonebook::const_iterator getEntryByNumber(std::unique_ptr< Phonebook >& book, std::string number);
  bool checkNumber(std::unique_ptr< Phonebook >& book, std::string number);
}

#endif
