#ifndef TEST_FUNCTIONS_HPP
#define TEST_FUNCTIONS_HPP

#include <algorithm>
#include <iterator>
#include <vector>
#include <functional>
#include "data-struct.hpp"

namespace pozdnyakov
{
  bool testOut();
  template < typename T, typename Getter, typename Comparator >
  bool testSort(std::vector< DataStruct > vector, Getter getter, Comparator tComp)
  {
    std::vector< T > exp(vector.size());
    std::transform(vector.begin(), vector.end(), exp.begin(), getter);
    std::sort(exp.begin(), exp.end(), tComp);
    std::sort(vector.begin(), vector.end(), comparator);
    std::vector< T > got(vector.size());
    std::transform(vector.begin(), vector.end(), got.begin(), getter);
    return got == exp;
  }
}

#endif
