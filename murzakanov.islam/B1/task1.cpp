#include "tasks.hpp"

#include <vector>
#include <string>
#include <iostream>
#include <forward_list>

#include "strategy.hpp"
#include "sorting.hpp"
#include "tools.hpp"

int murzakanov::task1(const std::string& order)
{
  if (order != "ascending" && order != "descending")
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

  if (firstVector.empty())
  {
    return 0;
  }

  std::vector< int > secondVector(firstVector);
  std::forward_list< int > list(firstVector.begin(), firstVector.end());
  sort< StrategyBrackets< int > >(firstVector, order);
  sort< StrategyAt< int > >(secondVector, order);
  sort< StrategyIter< int > >(list, order);

  print(firstVector, std::cout);
  print(secondVector, std::cout);
  print(list, std::cout);
  return 0;
}
