#include <iostream>
#include <vector>
#include "tasks.hpp"
#include "functions.hpp"

namespace ivanova
{
  void pushVec(std::vector< int > &vector)
  {
    int in;
    while (std::cin >> in)
    {
      vector.push_back(in);
    }
  }

  int task1(const char* kindOfSort)
  {
    int exitCode = 0;
    if (strcmp(kindOfSort, "ascending") && strcmp(kindOfSort, "discending"))
    {
      throw std::invalid_argument("Wrong argument");
    }
    std::vector< int > collection;
    pushVec(collection);
    if (!std::cin.eof() && std::cin.fail())
    {
      exitCode = 1;
      throw std::logic_error("Reading failed");
    }
    if (collection.empty())
    {
      exitCode = 0;
    }
    std::vector< int > bracketsVector(collection);
    std::forward_list<int> iteratorForwardList(collection.begin(), collection.end());
    sortAndPrint< strategyBrackets< int > >(collection, kindOfSort);
    sortAndPrint< strategyAt< int > >(bracketsVector, kindOfSort);
    sortAndPrint< strategyList< int > >(iteratorForwardList, kindOfSort);
    return exitCode;
  }
}
