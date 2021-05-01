#ifndef TASK4_HPP
#define TASK4_HPP

#include <iostream>
#include "task4.hpp"
#include "functions.hpp"

namespace ivanova
{
  template< typename S >
  int task4(const S sort, const int size)
  {
    if (size < 0)
    {
      return 1;
    }
    else
    {
      std::vector< double > vec(size);
      fillRandom(vec.data(), size);
      print(vec, std::cout);
      sortAndPrint< strategyBrackets < double > >(vec, sort);
      return 0;
    }
  }
}
#endif
