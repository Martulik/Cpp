#include "tasks.hpp"
#include <string>
#include <cstring>
#include <iostream>
#include "sort.hpp"
#include "strategies.hpp"

void task1(char* argv[])
{
  const int VALUES[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  std::string asc = "ascending";
  std::string desc = "descending";
  bool isAscending;
  std::cout << argv[0] << '\n';
  if (strcmp(argv[0], asc.c_str()))
  {
    isAscending = true;
  }
  else if (strcmp(argv[0], desc.c_str()))
  {
    isAscending = false;
  }
  else
  {
    throw -1; //
  }
  std::vector<int> vector;
  for (unsigned int i = 0; i < sizeof(VALUES) / sizeof(VALUES[0]); i++)
  {
    vector.push_back(VALUES[i]);
  }
  sort<IndexStrategy<int>>(vector, isAscending);
  for (unsigned int i = 0; i < vector.size(); i++)
  {
    std::cout << vector[i] << ' ';
  }
  std::cout << '\n';
}
