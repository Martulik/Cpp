#include "tasks.hpp"

#include "functions.hpp"

namespace lab = shkurov;

void lab::taskThree()
{
  std::vector< int > vec;

  int x;
  while (std::cin >> x && x != 0)
  {
    vec.push_back(x);
  }

  if (std::cin.fail() || x != 0)
  {
    throw std::invalid_argument("Incorrect input.");
  }
  if (vec.empty())
  {
    throw std::length_error("Vector can not be empty.");
  }

  std::vector< int >::iterator it;
  int flag = vec.back();
  for (it = vec.begin(); it != vec.end(); it++)
  {
    if (flag == 1)
    {
      if (*it % 2 == 0)
      {
        it = vec.erase(it) - 1;
      }
    }
    else if (flag == 2)
    {
      if (*it % 3 == 0)
      {
        it = vec.insert(it + 1, 3, 1) + 2;
      }
    }
  }

  printContainer(vec, " ");
}
