#include "tasks.hpp"
#include <iostream>
#include <vector>
#include "functions.hpp"
#include "strategies.hpp"

int borisova::doTask1(const int argc, char* argv[])
{
  if (argc != 3)
  {
    std::cerr << "Incorrect number of arguments";
    return 2;
  }
  std::string mode = argv[2];
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
  int exitCode = sort< bracketStrategy< int > >(indVec, sortMode< int >(mode));
  if (!exitCode)
  {
    print(indVec, std::cout);
  }
  else
  {
    return exitCode;
  }

  std::vector< int > atVec(collection);
  exitCode = sort< atStrategy< int > >(atVec, sortMode< int >(mode));
  if (!exitCode)
  {
    print(atVec, std::cout);
  }
  else
  {
    return exitCode;
  }
  std::forward_list< int > iterList(collection.begin(), collection.end());
  exitCode = sort< listStrategy< int > >(iterList, sortMode< int >(mode));
  if (!exitCode)
  {
    print(iterList, std::cout);
  }
  else
  {
    return exitCode;
  }
  return 0;
}
