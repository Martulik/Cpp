#include "tasks.hpp"

#include <iostream>
#include <forward_list>
#include <vector>

void razukrantov::task1(const char* order)
{
  std::vector<int> vector;
  int x = 0;
  while (std::cin >> x)
  {
    vector.push_back(x);
  }
  if (!std::cin.eof())
  {
    throw std::runtime_error("Incorrect input");
  }

  std::vector<int> atVector(vector);
  std::forward_list<int> forwardList(vector.begin(), vector.end());

}
