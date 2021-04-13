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
  int exitCode1 = sort< bracketStrategy< int > >(indVec, mode);
  if (!exitCode1)
  {
    print(indVec, std::cout);
  }

  std::vector< int > atVec(collection);
  int exitCode2 = sort< atStrategy< int > >(atVec, mode);
  if (!exitCode2)
  {
    print(atVec, std::cout);
  }
  std::forward_list< int > iterList(collection.begin(), collection.end());
  int exitCode3 = sort< listStrategy< int > >(iterList, mode);
  if (!exitCode3)
  {
    print(iterList, std::cout);
  }
  return (exitCode1 || exitCode2 || exitCode3);
}
