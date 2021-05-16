#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iosfwd>

namespace savchuk
{
  struct contact_t
  {
    std::string number;
    std::string name;
  };
  std::ostream& operator<<(std::ostream& os, const contact_t& contact);
}

#endif
