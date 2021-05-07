#ifndef ENTRY_HPP
#define ENTRY_HPP

#include <iosfwd>
#include <string>
#include "name.hpp"

namespace doroshin
{
  struct Entry
  {
    using number_t = unsigned long long;
    number_t number;
    Name name;
  };

  std::istream& operator>>(std::istream&, Entry&);
  std::ostream& operator<<(std::ostream&, const Entry&);
}

#endif //ENTRY_HPP
