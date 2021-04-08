#include "tasks.hpp"

#include <vector>
#include <forward_list>
#include <iostream>

#include "sorting.hpp"
#include "strategy.hpp"

void task1(const std::string& order)
{
  int x;
  std::vector< int > firstVector;
  while (std::cin >> x && !std::cin.eof())
  {
    firstVector.push_back(x);
  }
  unsigned int i = 0;
  while (i < firstVector.size())
  {
    std::cout << firstVector.at(i++) << " ";
  }
  std::cout << "\n";
  std::vector< int > secondVector(firstVector);
  std::forward_list< int > list(firstVector.begin(), firstVector.end());
  sort< StrategyBrackets< int > >(firstVector, order);
  sort< StrategyAt< int > >(secondVector, order);
  sort< StrategyIter< int > >(list, order);

  i = 0;
  while (i < firstVector.size())
  {
    std::cout << firstVector.at(i++) << " ";
  }
  std::cout << "\n";
  i = 0;
  while (i < secondVector.size())
  {
    std::cout << secondVector.at(i++) << " ";
  }
  std::cout << "\n";
  auto it = list.begin();
  while (it != list.end())
  {
    std::cout << *it << " ";
    it++;
  }
  std::cout << "\n";
}
