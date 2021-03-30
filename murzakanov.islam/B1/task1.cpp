#include <vector>
#include <list>
#include <iostream>
#include "sorting.hpp"
#include "strategy.hpp"

void task1(const std::string& order)
{
  int x;
  std::vector< int > firstVector;
  while(!std::cin.eof())
  {
    std::cin >> x;
    firstVector.push_back(x);
  }
  int i = 0;
  while (i < firstVector.size() - 1)
  {
    std::cout << firstVector.at(i++) << " ";
  }
  std::cout << "\n";
  std::vector< int > secondVector(firstVector);
  sort< StrategyBrackets< int > >(firstVector, order);
  sort< StrategyAt< int > >(secondVector, order);
  i = 0;
  while (i < firstVector.size() - 1)
  {
    std::cout << firstVector.at(i++) << " ";
  }
  std::cout << "\n";
  i = 0;
  while (i < secondVector.size() - 1)
  {
    std::cout << secondVector.at(i++) << " ";
  }
}
