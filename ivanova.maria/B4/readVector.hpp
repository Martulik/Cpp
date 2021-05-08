#ifndef B4_READVECTOR_HPP
#define B4_READVECTOR_HPP

#include <vector>
#include <iosfwd>
#include <string>

#include "struct.hpp"
#include "tools.hpp"

namespace ivanova
{
  bool readVector(std::vector < DataStruct > &vector)
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
    if (vector.empty())
    {
      return false;
    }
    return true;
  }
}
#endif
