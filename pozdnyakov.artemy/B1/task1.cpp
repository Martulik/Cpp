#include "tasks.hpp"
#include <string>
#include <stdexcept>
#include <cstring>
#include <iostream>
#include "sort.hpp"
#include "strategies.hpp"
#include "functions.hpp"

namespace poz = pozdnyakov;

void poz::task1(char* argv[])
{
  std::string asc = "ascending";
  std::string desc = "descending";
  std::function< bool(double, double) > compare;
  if (!strcmp(argv[0], asc.c_str()))
  {
    compare = std::less< double >();
  }
  else if (!strcmp(argv[0], desc.c_str()))
  {
    compare = std::greater< double >();
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
  if (!std::cin.good() && !std::cin.eof())
  {
    throw std::runtime_error("Invalid input");
  }
  std::vector< int > indexVector(vector);
  std::vector< int > atVector(vector);
  std::list< int > list(vector.begin(), vector.end());
  poz::sort< poz::IndexStrategy< int > >(indexVector, compare);
  poz::sort< poz::VectorAtStrategy< int > >(atVector, compare);
  poz::sort< poz::ListStrategy< int > >(list, compare);
  poz::print(indexVector, std::cout);
  poz::print(atVector, std::cout);
  poz::print(list, std::cout);
}
