#include "tasks.hpp"

#include <string>
#include <iostream>
#include <memory>

#include "sorting.hpp"
#include "strategy.hpp"
#include "tools.hpp"

int murzakanov::task4(std::string& order, int size)
{
  if (order != "ascending" && order != "descending")
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
