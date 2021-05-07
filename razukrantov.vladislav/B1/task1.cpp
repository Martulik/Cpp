#include "tasks.hpp"

#include <iostream>
#include <forward_list>
#include <vector>

#include "strategy.hpp"
#include "sorting.hpp"
#include "functions.hpp"

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
  if (vector.size() == 0)
  {
      return;
  }

  std::vector<int> atVector(vector);
  std::forward_list<int> forwardList(vector.begin(), vector.end());
  std::function< bool(int, int) > compare = getSortOrder< int >(order);

  razukrantov::sort< bracketsAccess< int >, int >(vector, compare);
  print(vector);
  razukrantov::sort< atAccess< int >, int >(atVector, compare);
  print(atVector);
  razukrantov::sort< iteratorAccess< int >, int >(forwardList, compare);
  print(forwardList);
}
