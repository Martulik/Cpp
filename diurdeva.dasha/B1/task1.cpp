#include "tasks.hpp"
#include <vector>
#include <forward_list>
#include <iostream>
#include "tools.hpp"

int diurdeva::task1(const std::function< bool(int, int) > compare, Error &error_obj)
{
  std::vector< int > vectorBr;
  int num = 0;
  while (std::cin && !(std::cin >> num).eof()) {
    if (std::cin.fail() || std::cin.bad()) {
      error_obj.set("Error reading file\n");
      return 1;
    }
    vectorBr.push_back(num);
  }

  std::vector< int > vectorAt = vectorBr;
  std::forward_list< int > listIt(vectorBr.begin(), vectorBr.end());

  printAndSort< indexAccess< int > >(vectorBr, compare);
  printAndSort< atAccess< int > >(vectorAt, compare);
  printAndSort< iteratorAccess< int > >(listIt, compare);
  return 0;
}
