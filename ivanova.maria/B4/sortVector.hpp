#ifndef B4_SORTVECTOR_HPP
#define B4_SORTVECTOR_HPP

#include <vector>
#include <string>
#include "struct.hpp"
#include "tools.hpp"

namespace ivanova
{
  void sortVector(std::vector< DataStruct > &vector)
  {
    for (size_t k = 0; k < vector.size() - 1; k++)
    {
      for (size_t i = k + 1; i < vector.size(); i++)
      {
        if (ivanova::compare(vector.at(k), vector.at(i)))
        {
          std::swap(vector.at(k), vector.at(i));
        }
      }
    }
  }
}
#endif
