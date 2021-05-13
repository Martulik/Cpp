#ifndef B4_PRINTVECTOR_HPP
#define B4_PRINTVECTOR_HPP

#include <vector>
#include <iosfwd>
#include "struct.hpp"

namespace ivanova
{
  template < typename T > void printVector(std::vector < T > &vector, std::ostream &out)
  {
    size_t i = 0;
    while (i < vector.size())
    {
      DataStruct data = vector.at(i);
      out << data.key1 << "," << data.key2 << "," << data.str << std::endl;
      i++;
    }
  }
}
#endif
