#include "tasks.hpp"

#include <vector>
#include <iostream>

#include "tools.hpp"

namespace lab = savchuk;

void lab::doTask3()
{
  std::vector< int > vec;
  int x = 0;
  while (std::cin >> x && x != 0)
  {
    vec.push_back(x);
  }
  if ((std::cin.fail() && !std::cin.eof()) || x != 0)
  {
    throw std::runtime_error("Incorrect input format");
  }
  if (!vec.empty())
  {
    if (vec.back() == 1)
    {
      removeEvenNumbers(vec);
    }
    else if (vec.back() == 2)
    {
      addExtraNumbers(vec);
    }
  }
  print(vec.cbegin(), vec.cend(), std::cout, " ");
}
