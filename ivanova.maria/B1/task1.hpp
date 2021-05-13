#include <iostream>
#include <vector>

#include "functions.hpp"

namespace ivanova
{
  template< typename S >
  int task1(const S sort)
  {
    std::vector< int > collection;
    int element = 0;
    while (!std::cin.eof() && (std::cin >> element))
    {
    collection.push_back(element);
    }
    if (!std::cin.eof())
    {
      std::cerr << ("Invalid character!");
      return 1;
    }
    std::vector< int > bracketsVector(collection);
    std::forward_list< int > iteratorForwardList(collection.begin(), collection.end());
    sortAndPrint< strategyBrackets< int > >(collection, sort);
    sortAndPrint< strategyAt< int > >(bracketsVector, sort);
    sortAndPrint< strategyList< int > >(iteratorForwardList, sort);
    return 0;
  }
}
