#include "tasks.hpp"

#include <iostream>
#include <vector>
#include "tools.hpp"

int murzakanov::task3()
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

  if (std::cin.fail() && !std::cin.eof())
  {
    std::cerr << "Read error\n";
    return 1;
  }

  if (vec.empty())
  {
    return 0;
  }

  if (x != 0)
  {
    std::cerr << "Wrong input\n";
    return 1;
  }

  std::vector< int >::iterator it = vec.begin();
  if (vec.back() == 1)
  {
    while (it != vec.end())
    {
      if (*it % 2 == 0)
      {
        it = vec.erase(it);
      }
      else
      {
        it++;
      }
    }
  }
  if (vec.back() == 2)
  {
    while (it != vec.end())
    {
      if (*it % 3 == 0)
      {
        it = vec.insert(it + 1, 3, 1) + 2;
      }
      else
      {
        it++;
      }
    }
  }
  print(vec, std::cout);
  return 0;
}
