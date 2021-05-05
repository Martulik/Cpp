#include "tasks.hpp"

#include <iostream>
#include <forward_list>
#include <vector>

#include "strategy.hpp"
#include "sorting.hpp"
#include "functions.hpp"

template <typename T >
std::function < bool(T, T) > getSortOrder(const char* order)
{
  std::string ascending = "ascending";
  std::string descending = "descending";
  if (order == nullptr)
  {
    throw std::invalid_argument("Incorrect order");
  }
  if (order == ascending)
  {
    return std::greater< T >();
  }
  if (order == descending)
  {
    return std::less< T >();
  }
  else
  {
    throw std::invalid_argument("Incorrect order");
  }
}

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
