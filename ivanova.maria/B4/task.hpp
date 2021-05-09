#ifndef B4_TASK_HPP
#define B4_TASK_HPP
#include <vector>

#include "sortVector.hpp"
#include "readVector.hpp"
#include "printVector.hpp"

namespace ivanova
{
  template < typename T > int task(std::vector < T > &vector)
  {
    if (readVector(vector) == 0)
    {
      sortVector(vector);
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
