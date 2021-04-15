#include <iostream>
#include <vector>
#include "tasks.hpp"
#include "functions.hpp"

namespace iva = ivanova;

void pushVec(std::vector<int> &vector)
{
  int in;
  while (std::cin >> in)
  {
    vector.push_back(in);
  }
}

int iva::task1(const char *kindOfSort)
{
  if (strcmp(kindOfSort, "ascending") && strcmp(kindOfSort, "descending"))
  {
    throw std::invalid_argument("Wrong argument");
  }
  std::vector<int> collection;
  pushVec(collection);
  if (!std::cin.eof() && std::cin.fail())
  {
    throw std::logic_error("Reading failed");
  }
  if (collection.empty())
  {
    return 0;
  }
  std::vector<int> bracketsVector(collection);
  std::forward_list<int> iteratorForwardList(collection.begin(), collection.end());
  sortAndPrint < iva::strategyBrackets < int > > (collection, kindOfSort);
  sortAndPrint <  iva::strategyAt < int > > (bracketsVector, kindOfSort);
  sortAndPrint <  iva::strategyList < int > > (iteratorForwardList, kindOfSort);
  return 0;
}
