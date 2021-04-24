#include "tasks.hpp"
#include <string>
#include <stdexcept>
#include <cstring>
#include <iostream>
#include "sort.hpp"
#include "strategies.hpp"
#include "print.hpp"

namespace poz = pozdnyakov;

void poz::task1(char* argv[])
{
  std::string asc = "ascending";
  std::string desc = "descending";
  bool isAscending;
  if (!strcmp(argv[0], asc.c_str()))
  {
    isAscending = true;
  }
  else if (!strcmp(argv[0], desc.c_str()))
  {
    isAscending = false;
  }
  else
  {
    throw std::invalid_argument("Wrong argument");
  }
  std::vector< int > vector;
  int n;
  while (std::cin >> n)
  {
    vector.push_back(n);
  }
  if (std::cin.fail() && !std::cin.eof())
  {
    throw std::runtime_error("Invalid file content");
  }
  std::vector< int > indexVector(vector);
  std::vector< int > atVector(vector);
  std::list< int > list(vector.begin(), vector.end());
  poz::sort< poz::IndexStrategy< int > >(indexVector, isAscending);
  poz::sort< poz::VectorAtStrategy< int > >(atVector, isAscending);
  poz::sort< poz::ListStrategy< int > >(list, isAscending);
  poz::print(indexVector, std::cout);
  poz::print(atVector, std::cout);
  poz::print(list, std::cout);
}
