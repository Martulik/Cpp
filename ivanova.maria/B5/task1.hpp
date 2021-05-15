#ifndef B5_TASK1_HPP
#define B5_TASK1_HPP
#include <iosfwd>
#include <string>

#include "Words.hpp"

namespace ivanova
{
  int task1(std::istream &in, std::ostream &out)
  {
    Words list;
    in >> list;
    if (in.fail() || !in.eof())
    {
      std::cerr << "failed reading";
      return 1;
    }
    out << list;
    return 0;
  }
}
#endif