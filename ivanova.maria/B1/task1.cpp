#include <iostream>
#include <vector>
#include "tasks.hpp"
#include "functions.hpp"

namespace iva = ivanova;

int iva::task1(const char *kindOfSort)
{
  std::vector<int> collection;
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
//  if (strcmp(kindOfSort, "ascending") && strcmp(kindOfSort, "descending"))
//  {
//    std::cerr << ("Invalid Sort Order");
//    return 1;
//  }
//
//  int x = 0;
//  std::vector< int > collection;
//  while (std::cin >> x)
//  {
//    collection.push_back(x);
//  }
//
//  if (std::cin.fail() && !std::cin.eof())
//  {
//    std::cerr << "Read error\n";
//    return 1;
//  }
//
//  if (collection.empty())
//  {
//    return 0;
//  }
  std::vector< int > bracketsVector(collection);
  std::forward_list< int > iteratorForwardList(collection.begin(), collection.end());
  sortAndPrint < iva::strategyBrackets < int > > (collection, kindOfSort);
  sortAndPrint <  iva::strategyAt < int > > (bracketsVector, kindOfSort);
  sortAndPrint <  iva::strategyList < int > > (iteratorForwardList, kindOfSort);
  return 0;
}
