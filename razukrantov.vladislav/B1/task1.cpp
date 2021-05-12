#include "tasks.hpp"

#include <iostream>
#include <forward_list>
#include <vector>

#include "strategy.hpp"
#include "sorting.hpp"
#include "functions.hpp"

void razukrantov::task1(const char* order)
{
  std::function< bool(int, int) > compare = razukrantov::getSortOrder< int >(order);
  std::vector< int > vector;
  int x = 0;
  while (std::cin >> x)
  {
    vector.push_back(x);
  }
  if (!std::cin.eof())
  {
    throw(std::runtime_error("Incorrect input in task1\n"));
  }
  if (vector.empty())
  {
    return;
  }

  std::vector< int > atVector(vector);
  std::forward_list< int > forwardList(vector.begin(), vector.end());

  razukrantov::sort< razukrantov::bracketsAccess< int >, int >(vector, compare);
  razukrantov::print< razukrantov::bracketsAccess< int >, int >(vector, std::cout, " ");
  std::cout << "\n";
  razukrantov::sort< razukrantov::atAccess< int >, int >(atVector, compare);
  razukrantov::print< razukrantov::atAccess< int >, int >(vector, std::cout, " ");
  std::cout << "\n";
  razukrantov::sort< razukrantov::iteratorAccess< int >, int >(forwardList, compare);
  razukrantov::print< razukrantov::iteratorAccess< int >, int >(forwardList, std::cout, " ");
  std::cout << "\n";
}
