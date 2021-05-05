#ifndef B4_SORTVECTOR_HPP
#define B4_SORTVECTOR_HPP

#include <vector>
#include <string>
#include "struct.hpp"

namespace ivanova
{
  template< typename T >
  void sortVector(std::vector < T > &vector)
  {
    for (size_t k = 0; k < vector.size(); k++)
    {
      for (size_t i = 1; i < vector.size() - 1; i++)
      {
        if (vector.at(k) > vector.at(i))
        {
          std::swap(vector.at(k), vector.at(i));
        }
      }
    }
  }
}
#endif
