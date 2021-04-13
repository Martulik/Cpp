#include "tasks.hpp"

#include <vector>
#include <forward_list>
#include <iostream>

#include "accesses.hpp"
#include "functions.hpp"

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

  if (bracketsVector.size() == 0)
  {
    return;
  }

  std::vector<int> atVector(bracketsVector);
  std::forward_list<int> iteratorForwardList(bracketsVector.begin(), bracketsVector.end());

  pochernin::sort< bracketsAccess< int > >(bracketsVector, isAscending(sortingDirection));
  pochernin::print(bracketsVector, " ");

  pochernin::sort< atAccess< int > >(atVector, isAscending(sortingDirection));
  pochernin::print(atVector, " ");

  pochernin::sort< iteratorAccess< int > >(iteratorForwardList, isAscending(sortingDirection));
  pochernin::print(iteratorForwardList, " ");
}
