#include <iostream>
#include <vector>
#include "tasks.hpp"
#include "functions.hpp"

namespace iva = ivanova;

void pushVec(std::vector< int > &vector)
{
  char in;
  while (std::cin >> in)
  {
    if (isdigit(in) || in == '-' || in == '+')
    {
      vector.push_back(in);
    }
    else
    {
      std::cerr << ("Invalid Number In A Middle");
      exit(1);
    }
  }
  if (std::cin.fail() && !std::cin.eof())
  {
    std::cerr << ("Invalid character!");
    exit(1);
  }
}

int iva::task1(const char *kindOfSort)
{
  if (kindOfSort == nullptr)
  {
    std::cerr << (" Missing Sort Order");
    return 1;
  }
  if (strcmp(kindOfSort, "ascending") && strcmp(kindOfSort, "descending"))
  {
    std::cerr << ("Invalid Sort Order");
    return 1;
  }
  std::vector< int > collection;
  pushVec(collection);
  if (!std::cin.eof() && std::cin.fail())
  {
    std::cerr << ("Reading failed");
    return 1;
  }
  if (collection.empty())
  {
    return 0;
  }
  std::vector< int > bracketsVector(collection);
  std::forward_list< int > iteratorForwardList(collection.begin(), collection.end());
  sortAndPrint < iva::strategyBrackets < int > > (collection, kindOfSort);
  sortAndPrint <  iva::strategyAt < int > > (bracketsVector, kindOfSort);
  sortAndPrint <  iva::strategyList < int > > (iteratorForwardList, kindOfSort);
  return 0;
}
