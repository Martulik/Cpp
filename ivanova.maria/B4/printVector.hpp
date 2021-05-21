#ifndef B4_PRINTVECTOR_HPP
#define B4_PRINTVECTOR_HPP

#include <vector>
#include <iosfwd>
#include <iterator>
#include "struct.hpp"

namespace ivanova
{
  template < typename T > void printVector(std::vector < T > &vector, std::ostream &out)
  {
    std::copy(vector.begin(), vector.end(), std::ostream_iterator< DataStruct > (out));
  }
}
#endif
