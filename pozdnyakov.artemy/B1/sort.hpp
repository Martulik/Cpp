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
    IterType max;
    IterType searchRangeEnd = S::end(cont);
    for (IterType i = S::begin(cont); i != S::end(cont); i++)
    {
      max = S::begin(cont);
      for (IterType j = S::begin(cont); j != searchRangeEnd; j++)
      {
        max = (compare(S::getElem(cont, j), S::getElem(cont, max))) ? j : max;
      }
      std::swap(S::getElem(cont, max), S::getElem(cont, S::getIterPrev(searchRangeEnd)));
      searchRangeEnd--;
    }
  }
}

#endif
