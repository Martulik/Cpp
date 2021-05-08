#include "tasks.hpp"

#include <iostream>
#include <forward_list>
#include <vector>

#include "strategy.hpp"
#include "sorting.hpp"
#include "functions.hpp"

void razukrantov::task1(const char* order)
{
  if (strcmp(order, "ascending") && strcmp(order, "descending"))
  {
    throw (std::invalid_argument("Incorrect input un task1\n"));
  }
  std::vector<int> vector;
  int x = 0;
  while (std::cin >> x)
  {
    vector.push_back(x);
  }
  if (!std::cin.eof())
  {
    throw (std::runtime_error("Incorrect input in task1\n"));
  }
  if (vector.empty())
  {
    return;
  }

  std::vector<int> atVector(vector);
  std::forward_list<int> forwardList(vector.begin(), vector.end());
  std::function< bool(int, int) > compare = razukrantov::getSortOrder< int >(order);

  razukrantov::sort< razukrantov::bracketsAccess< int >, int >(vector, compare);
  razukrantov::print(vector);
  razukrantov::sort< razukrantov::atAccess< int >, int >(atVector, compare);
  razukrantov::print(atVector);
  razukrantov::sort< razukrantov::iteratorAccess< int >, int >(forwardList, compare);
  razukrantov::print(forwardList);
}
