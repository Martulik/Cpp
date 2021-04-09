#ifndef TASK4_HPP
#define TASK4_HPP

#include <iostream>
#include "tools.hpp"

namespace ezerinia {
  template< typename C >
  int task4(C sort_mode, const int size)
  {
    std::vector< double > vec(size);
    fillRandom(&vec[0], size);
    print(vec, std::cout);
    sortAndPrint< indexVec< double > >(vec, sort_mode);
    return 0;
  }
}
#endif
