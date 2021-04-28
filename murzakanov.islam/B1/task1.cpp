#include "tasks.hpp"

#include <vector>
#include <iostream>
#include <forward_list>
#include <functional>

#include "strategy.hpp"
#include "sorting.hpp"
#include "tools.hpp"

int murzakanov::task1(const char* order)
{
  if (strcmp(order, "ascending") && strcmp(order, "descending"))
  {
    std::cerr << "Wrong order\n";
    return 1;
  }

  int x = 0;
  std::vector< int > firstVector;
  while (std::cin >> x)
  {
    firstVector.push_back(x);
  }

  if (std::cin.fail() && !std::cin.eof())
  {
    std::cerr << "Read error\n";
    return 1;
  }

  std::vector< int > secondVector(firstVector);
  std::forward_list< int > list(firstVector.begin(), firstVector.end());
  std::function< bool(int, int) > cmp = murzakanov::getSortMode< int >(order);

  sort< StrategyBrackets< int >, int >(firstVector, cmp);
  sort< StrategyAt< int >, int >(secondVector, cmp);
  sort< StrategyIter< int >, int >(list, cmp);

  print(firstVector, std::cout);
  print(secondVector, std::cout);
  print(list, std::cout);
  return 0;
}
