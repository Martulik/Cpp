#ifndef SORT_HPP
#define SORT_HPP

#include <algorithm>
#include <functional>

namespace pozdnyakov
{
  template <typename S>
  void sort(typename S::ContType& cont, std::function< bool(double, double) > compare)
  {
    using IterType = typename S::IterType;
    IterType min;
    IterType searchRangeBegin = S::begin(cont);
    for (IterType i = S::begin(cont); i != S::end(cont); i++)
    {
      min = S::begin(cont);
      for (IterType j = searchRangeBegin; j != S::end(cont); j++)
      {
        min = (compare(S::getElem(cont, j), S::getElem(cont, min))) ? j : min;
      }
      std::swap(S::getElem(cont, min), S::getElem(cont, searchRangeBegin));
      searchRangeBegin++;
    }
  }
}

#endif
