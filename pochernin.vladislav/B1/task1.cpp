#include "tasks.hpp"

#include <vector>
#include <forward_list>
#include <iostream>

void pochernin::task1(const char* sortingDirection)
{
  std::vector<int> bracketsVector;
  int n = 0;
  while (std::cin >> n)
  {
    bracketsVector.push_back(n);
  }
  if ((!std::cin.eof() && std::cin.fail()) || std::cin.bad())
  {
    throw(std::runtime_error("Incorrect input in task1\n"));
  }

  std::vector<int> atVector(bracketsVector);
  std::forward_list<int> iteratorForwardList(bracketsVector.begin(), bracketsVector.end());


  std::cout << sortingDirection; // Это временно, чтобы компилилась программа!
}
