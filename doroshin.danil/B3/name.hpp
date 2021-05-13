#ifndef NAME_HPP
#define NAME_HPP

#include <iosfwd>
#include <string>

namespace doroshin
{
  struct Name
  {
    std::string name_;
  };

  std::istream& operator>>(std::istream&, Name&);
  std::ostream& operator<<(std::ostream&, const Name&);
}

#endif
