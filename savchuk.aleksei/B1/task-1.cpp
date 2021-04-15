#include "task.hpp"

#include <vector>
#include <forward_list>
#include <iostream>

#include "access-policy.hpp"
#include "sort.hpp"
#include "tools.hpp"

namespace lab = savchuk;

void lab::doTask1(const char* order)
{
  std::function< bool(const int&, const int&) > cmp = lab::getCompare< int >(order);
  std::vector< int > v1 = { 1, 2, 3 };
  std::vector< int > v2 = v1;
  std::forward_list< int > fwl(v1.cbegin(), v1.cend());
  lab::selectionSort< int, IndexVectorPolicy >(v1, cmp);
  lab::selectionSort< int, AtVectorPolicy >(v2, cmp);
  lab::selectionSort< int, IteratorFwListPolicy >(fwl, cmp);
  print(v1.cbegin(), v1.cend(), std::cout);
  print(v2.cbegin(), v2.cend(), std::cout);
  print(fwl.cbegin(), fwl.cend(), std::cout);
}