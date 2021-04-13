#include "tasks.hpp"
#include <iostream>
#include <vector>
#include "functions.hpp"
#include "strategies.hpp"

int borisova::doTask1(const int argc, const std::string& mode)
{
  if (argc != 3)
  {
    std::cerr << "Incorrect number of arguments";
    return 2;
  }
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
  else
  {
    return exitCode1;
  }

  std::vector< int > atVec(collection);
  int exitCode2 = sort< atStrategy< int > >(atVec, mode);
  if (!exitCode2)
  {
    print(atVec, std::cout);
  }
  else
  {
    return exitCode2;
  }
  std::forward_list< int > iterList(collection.begin(), collection.end());
  int exitCode3 = sort< listStrategy< int > >(iterList, mode);
  if (!exitCode3)
  {
    print(iterList, std::cout);
  }
  else
  {
    return exitCode3;
  }
  return 0;
}
