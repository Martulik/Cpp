#ifndef RECORD_T_HPP
#define RECORD_T_HPP

#include <iosfwd>
#include <string>

namespace ezerinia {
  struct record_t {
    std::string number;
    std::string name;
  };
  std::istream &operator>>(std::istream &in, record_t &src);
  std::ostream &operator<<(std::ostream &out, const record_t &src);
}

#endif
