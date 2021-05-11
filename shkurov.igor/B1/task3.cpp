#include "tasks.hpp"

#include "functions.hpp"

namespace lab = shkurov;

void lab::taskThree()
{
  std::vector< int > vec;

  int x = 0;
  while (std::cin >> x)
  {
    if (x == 0)
    {
      break;
    }
    vec.push_back(x);
  }

  if (std::cin.fail() && !(std::cin.eof()))
  {
    throw std::invalid_argument("Incorrect input.");
  }

  if (x != 0)
  {
    throw std::invalid_argument("Last number must be zero.");
  }

  if (vec.empty())
  {
    return;
  }

  using iterator_t = std::vector< int >::iterator;
  int flag = vec.back();
  for (iterator_t it = vec.begin(); it != vec.end(); it++)
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
