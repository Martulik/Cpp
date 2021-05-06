#ifndef B4_PRINTVECTOR_HPP
#define B4_PRINTVECTOR_HPP

#include <vector>
#include <iostream>
#include "struct.hpp"

namespace ivanova
{
  template < typename T > void printVector(std::vector < T > &vector)
  {
    for (size_t i = 0; i < vector.size(); i++)
    {
      DataStruct data = vector.at(i);
      std::cout << data.key1 << "," << data.key2 << "," << data.str << std::endl;
    }
  }
}
#endif
