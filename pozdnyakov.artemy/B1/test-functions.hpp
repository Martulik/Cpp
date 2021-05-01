#ifndef TEST_FUNCTIONS_HPP
#define TEST_FUNCTIONS_HPP

#include <vector>
#include <forward_list>
#include <functional>
#include <limits>
#include <random>

namespace pozdnyakov
{
  using CompareFunc = std::function< bool(double, double) >;
  using Viterator = typename std::vector< double >::iterator;
  using Literator = typename std::forward_list< double >::iterator;
  bool testVectorSort(std::vector< double > vector, CompareFunc compare);
  bool testListSort(std::forward_list< double > vector, CompareFunc compare);
  bool testAddOnes(std::vector< int > vector);
  bool testEraseEven(std::vector< int > vector);
}

#endif
