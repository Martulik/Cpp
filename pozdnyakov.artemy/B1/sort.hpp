#ifndef SORT_HPP
#define SORT_HPP

#include <algorithm>

template <typename S>
void sort(typename S::ContType cont, bool isAscending)
{
  using IterType = typename S::IterType;
  IterType max;
  IterType searchRangeEnd = S::end(cont);
  for (IterType i = S::begin(cont); i != S::end(cont); i++)
  {
    max = S::begin(cont);
    for (IterType j = S::begin(cont) + 1; j != searchRangeEnd; j++)
    {
      if ((S::getElem(j) > S::getElem(max)) == isAscending)
      {
        *S::getElem(max) = *S::getElem(j);
      }
    }
    std::swap(*S::getElem(max), *S::getElem(searchRangeEnd));
    searchRangeEnd--;
  }
}

#endif
