#include "tasks.hpp"
#include <iostream>
#include <vector>
#include "functions.hpp"
#include "strategies.hpp"

int borisova::doTask1(const std::string& mode)
{
  std::vector < int > collection;
  int number;
  while (std::cin && !(std::cin >> number).eof())
  {
    if (std::cin.fail() || std::cin.bad())
    {
      std::cerr << "Incorrect input\n";
      return 1;
    }
    collection.push_back(number);
  }
  std::vector< int > indVec(collection);
  sort< bracketStrategy< int > >(indVec, mode);
  print(indVec, std::cout);

  std::vector< int > atVec(collection);
  sort< atStrategy< int > >(atVec, mode);
  print(atVec, std::cout);

  std::forward_list< int > iterList(collection.begin(), collection.end());
  sort< listStrategy< int > >(iterList, mode);
  print(iterList, std::cout);
  return 0;
}
