#include "tasks.hpp"

#include <iostream>
#include <memory>

#include "sorting.hpp"
#include "strategy.hpp"
#include "tools.hpp"

int murzakanov::task4(const char* order, int size)
{
  if (strcmp(order, "ascending") && strcmp(order, "descending"))
  {
    std::cerr << "Wrong order\n";
    return 1;
  }
  std::vector < double > arr(size);
  murzakanov::fillRandom(std::addressof(arr[0]), size);
  std::vector< double > vec(arr);
  murzakanov::print(vec, std::cout);
  std::function< bool(double, double) > cmp = murzakanov::getSortMode< double >(order);
  murzakanov::sort< murzakanov::StrategyBrackets< double >, double >(vec, cmp);
  murzakanov::print(vec, std::cout);
  return 0;
}
