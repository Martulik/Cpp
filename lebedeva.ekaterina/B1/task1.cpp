#include <vector>
#include <forward_list>
#include <iostream>
#include "tasks.hpp"
#include "functions.hpp"

void lebedeva::doTask1(char* argv[])
{
  std::vector< int > brackVec;
  int data = 0;
  while (std::cin >> data)
  {
    brackVec.push_back(data);
  }
  if (std::cin.bad() || (std::cin.fail() && !std::cin.eof()))
  {
    throw std::runtime_error("Invalid input");
  }
  std::function< bool(int, int) > comp = getSortOrder< int >(argv[2]);

  std::vector< int > atVec(brackVec);
  std::forward_list< int > iterList(brackVec.begin(), brackVec.end());

  sort< bracketsAccess >(brackVec, comp);
  sort< atAccess >(atVec, comp);
  sort< iteratorAccess >(iterList, comp);

  print(brackVec, std::cout, " ", 1);
  print(atVec, std::cout, " ", 1);
  print(iterList, std::cout, " ", 1);
}

