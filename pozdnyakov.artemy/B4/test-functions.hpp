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
    std::vector< T > exp;
    std::transform(vector.begin(), vector.end(), std::back_inserter(exp), getter);
    std::sort(exp.begin(), exp.end(), tComp);
    std::sort(vector.begin(), vector.end(), comparator);
    std::vector< T > got;
    std::transform(vector.begin(), vector.end(), std::back_inserter(got), getter);
    return got == exp;
  }
}

#endif
