#ifndef ISTREAM_FAIL_HPP
#define ISTREAM_FAIL_HPP

#include <iostream>

namespace doroshin
{
  inline std::istream& fail(std::istream& in)
  {
    in.setstate(in.rdstate() | std::ios::failbit);
    return in;
  }
}

#endif //ISTREAM_FAIL_HPP
