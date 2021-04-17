#include "task.hpp"

#include <vector>
#include <iostream>
#include "tools.hpp"

namespace lab = savchuk;

template< typename T >
void removeEvenNumbers(std::vector< T >& vec)
{
  using iterator = typename std::vector< T >::iterator;
  std::vector< T > tmp = vec;
  for (iterator it = tmp.begin(); it != tmp.end();)
  {
    if (*it % 2 == 0)
    {
      it = tmp.erase(it);
    }
    else
    {
      ++it;
    }
  }
  vec.swap(tmp);
}

template< typename T >
void addExtraNumbers(std::vector< T >& vec)
{
  using iterator = typename std::vector< T >::iterator;
  std::vector< T > tmp = vec;
  size_t count = 0;
  for (iterator it = tmp.begin(); it != tmp.end(); ++it)
  {
    if (*it % 3 == 0)
    {
      ++count;
    }
  }
  tmp.reserve(tmp.size() + 3 * count);
  for (iterator it = tmp.begin(); it != tmp.end();)
  {
    if (*it % 3 == 0)
    {
      it = tmp.insert(++it, { 1, 1, 1 });
    }
    else
    {
      ++it;
    }
  }
  vec.swap(tmp);
}

void lab::doTask3()
{
  std::vector< int > vec;
  int x;
  while (std::cin >> x)
  {
    if (x == 0)
    {
      break;
    }
    vec.push_back(x);
  }
  if (std::cin.fail())
  {
    throw std::runtime_error("incorrect input format");
  }
  if (vec.empty())
  {
    throw std::runtime_error("array can't be empty");
  }
  if (vec.back() == 1)
  {
    removeEvenNumbers(vec);
  }
  else if (vec.back() == 2)
  {
    addExtraNumbers(vec);
  }
  print(vec.cbegin(), vec.cend(), std::cout);
}