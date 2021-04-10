#ifndef TASK4_HPP
#define TASK4_HPP

#include <iostream>
#include "tools.hpp"
#include "errors.hpp"

namespace ezerinia {
  template< typename C >
  error task4(C sort_mode, const int size)
  {
    if (size < 0) {
      return error::input;
    }
    std::vector< double > vec(size);
    fillRandom(&vec[0], size);
    print(vec, std::cout);
    sortAndPrint< indexVec< double > >(vec, sort_mode);
    return error::success;
  }
}
#endif
