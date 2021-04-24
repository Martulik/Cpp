#ifndef TEST_FUNCTIONS_HPP
#define TEST_FUNCTIONS_HPP

#include <vector>
#include <list>
#include <functional>

namespace pozdnyakov
{
  using CompareFunc = std::function< bool(double, double) >;
  bool testSort(std::vector< double > vector, std::list< double > list, CompareFunc compare);
  template < typename IterType >
  bool compareContainers(IterType beginOrig, IterType endOrig, IterType begin, IterType end)
  {
    for (IterType i = begin; i != end; i++)
    {
      if (*beginOrig != *begin || begin == end)
      {
        return false;
      }
      begin++;
    }
    return true;
  }
}

#endif
