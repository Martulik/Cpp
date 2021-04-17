#ifndef SORT_HPP
#define SORT_HPP

#include <algorithm>

template <typename S>
void sort(typename S::ContType& cont, bool isAscending)
{
  using IterType = typename S::IterType;
  IterType max;
  IterType searchRangeEnd = S::end(cont);
  for (IterType i = S::begin(cont); i != S::end(cont); i++)
  {
    max = S::begin(cont);
    for (IterType j = S::begin(cont); j != searchRangeEnd; j++)
    {
      if (isAscending)
      {
        max = (S::getElem(cont, j) < S::getElem(cont, max)) ? max : j;
      }
      else
      {
        max = (S::getElem(cont, j) > S::getElem(cont, max)) ? max : j;
      }
    }
    std::swap(S::getElem(cont, max), S::getElem(cont, S::getIterPrev(searchRangeEnd)));
    searchRangeEnd--;
  }
}

#endif
