#include "tasks.hpp"
#include <vector>
#include <iostream>
#include "print.hpp"
#include "vector-operations.hpp"

namespace poz = pozdnyakov;

void poz::task3()
{
  std::vector< int > vector;
  int n;
  while (std::cin >> n && n != 0)
  {
    if (std::cin.fail() && !std::cin.eof())
    {
      throw std::runtime_error("Invalid input");
    }
    vector.push_back(n);
  }
  if (*std::prev(vector.end()) == 1)
  {
    poz::eraseEven(vector);
  }
  else if (*std::prev(vector.end()) == 2)
  {
    poz::addOnes(vector);
  }
  poz::print(vector, std::cout);
}
