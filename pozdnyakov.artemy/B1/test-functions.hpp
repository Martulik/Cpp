#ifndef TEST_FUNCTIONS_HPP
#define TEST_FUNCTIONS_HPP

#include <vector>
#include <list>
#include <functional>
#include <limits>
#include <random>

namespace pozdnyakov
{
  using CompareFunc = std::function< bool(double, double) >;
  using Viterator = typename std::vector< double >::iterator;
  using Literator = typename std::list< double >::iterator;
  bool testVectorSort(std::vector< double > vector, CompareFunc compare);
  bool testListSort(std::list< double > vector, CompareFunc compare);
  template < typename Container >
  Container makeRandomContainer(int size)
  {
    const double MIN = std::numeric_limits< double >::min();
    const double MAX = std::numeric_limits< double >::max();
    std::uniform_real_distribution< double > dis(MIN, MAX);
    std::random_device device;
    Container cont;
    for (int i = 0; i < size; i++)
    {
      cont.push_back(dis(device));
    }
    return cont;
  }
  template < typename IterType >
  bool compareContainers(IterType beginOrig, IterType endOrig, IterType begin, IterType end)
  {
    if (beginOrig == endOrig && begin == end)
    {
      return true;
    }
    for (IterType i = beginOrig; i != endOrig; i++)
    {
      if (*i != *begin || begin == end)
      {
        return false;
      }
      begin++;
    }
    return true;
  }
}

#endif
