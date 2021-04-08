#include <vector>
#include <string>
#include <iostream>
#include <forward_list>

#include "tasks.hpp"
#include "strategy.hpp"
#include "sorting.hpp"

void murzakanov::task1(const std::string& order)
{
  int x;
  std::vector< int > firstVector;
  while (!(std::cin >> x).eof())
  {
    if (std::cin.fail())
    {
      throw std::invalid_argument("Wrong input\n");
    }
    firstVector.push_back(x);
  }

  unsigned int i = 0;
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
