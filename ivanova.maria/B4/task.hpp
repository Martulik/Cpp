#ifndef B4_TASK_HPP
#define B4_TASK_HPP
#include <vector>
#include <algorithm>

#include "readVector.hpp"
#include "printVector.hpp"

namespace ivanova
{
  template < typename T > int task(std::vector < T > &vector)
  {
    if (readVector(vector) == 0)
    {
      std::sort(vector.begin(), vector.end(), compare);
      printVector(vector);
      return 0;
    }
    else
    {
      return 1;
    }
  }
}

#endif
