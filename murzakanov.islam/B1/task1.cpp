#include <vector>
#include <string>
#include <iostream>
#include <forward_list>

#include "tasks.hpp"
#include "strategy.hpp"
#include "sorting.hpp"
#include "tools.hpp"

void murzakanov::task1(const std::string& order)
{
  if (order != "ascending" && order != "descending")
  {
    throw std::invalid_argument("Wrong order");
  }
  int x = 0;
  std::vector< int > firstVector;
  while (std::cin >> x)
  {
    firstVector.push_back(x);
  }
  if (std::cin.fail() && !std::cin.eof())
  {
    throw std::invalid_argument("Read error");
  }
  if (firstVector.empty())
  {
    return;
  }
  std::vector< int > secondVector(firstVector);
  std::forward_list< int > list(firstVector.begin(), firstVector.end());
  sort< StrategyBrackets< int > >(firstVector, order);
  sort< StrategyAt< int > >(secondVector, order);
  sort< StrategyIter< int > >(list, order);

  print(firstVector, std::cout);
  print(secondVector, std::cout);
  print(list, std::cout);
}
