#ifndef B1_TASK3_CPP
#define B1_TASK3_CPP

#include "tasks.hpp"

#include <vector>
#include <istream>
#include "functions.hpp"

int task3()
{
  int exitCode = 0;
  std::vector< int > vector;
  int element = 0;
  while (std::cin >> element)
  {
    if (element == 0)
    {
      break;
    }
    vector.push_back(element);
  }
  if (!std::cin.eof() && std::cin.fail())
  {
    exitCode = 1;
    throw std::invalid_argument("Incorrect data!");
  }
  if (element != 0)
  {
    exitCode = 1;
    throw std::invalid_argument("The last element must be zero!");
  }
  if (vector.empty())
  {
    return exitCode;
  }
  if (vector.back() == 1)
  {
    for (std::vector< int >::iterator i = vector.begin(); i != vector.end(); i++)
    {
      if (*i % 2 == 0)
      {
       i++;
      }
      else vector.erase(i);
    }
  }
  else if (vector.back() == 2)
  {
    for (std::vector< int >::iterator i = vector.begin(); i != vector.end(); i++)
    {
      if (*i % 3 == 0)
      {
        i = vector.insert(++i, 3, 1) + 2;
      }
    }
  }
  ivanova::print(vector, std::cout);
  return exitCode;
}
#endif
