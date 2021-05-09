#ifndef B4_READVECTOR_HPP
#define B4_READVECTOR_HPP

#include <vector>
#include <iosfwd>
#include <string>

#include "struct.hpp"
#include "tools.hpp"

namespace ivanova
{
  int readVector(std::vector < DataStruct > &vector)
  {
    while (!std::cin.eof())
    {
      DataStruct data;
      std::cin >> data;
      if (!empty(data))
      {
        vector.push_back(data);
      }
    }
    if (!std::cin.eof())
    {
      std::cerr << "failed reading";
      return 1;
    }
    return 0;
  }
}
#endif
