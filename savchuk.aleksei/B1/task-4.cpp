#include "tasks.hpp"

#include <cstddef>
#include <vector>
#include <iostream> 

#include "access-policies.hpp"
#include "sort.hpp"
#include "tools.hpp"

namespace lab = savchuk;

void lab::doTask4(const char* order, const char* size)
{
  std::function< bool(const int&, const int&) > cmp = getCompare< int >(order);
  size_t sz = convertToNumber(size);
  std::vector< double > vec(sz);
  fillRandom(vec.data(), sz);
  selectionSort< double, IndexVectorPolicy >(vec, cmp);
  print(vec.cbegin(), vec.cend(), std::cout, " ");
}