#ifndef RECORD_T_HPP
#define RECORD_T_HPP

#include <iostream>

namespace diurdeva {
  struct record_t {
    std::string number;
    std::string name;
  };
}

std::istream& operator>>(std::istream& in, diurdeva::record_t& src);
std::ostream& operator<<(std::ostream& out, const diurdeva::record_t& src);

#endif
