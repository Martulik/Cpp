#ifndef B1_TASK3_CPP
#define B1_TASK3_CPP

#include "tasks.hpp"

#include <vector>
#include <istream>
#include "functions.hpp"

namespace iva = ivanova;
int iva::task3()
{
  std::vector< int > vector;
  int element = 0;
  while (std::cin >> element && element != 0)
  {
    vector.push_back(element);
  }
  if (!std::cin.eof() && std::cin.fail())
  {
    std::cerr << "Incorrect data!";
    return 1;
  }

  if (element != 0)
  {
    std::cerr << "The last element must be zero!";
    return 1;
  }

  std::vector< int >::iterator i = vector.begin();
  if (!vector.empty() && vector.back() == 1)
  {
    while (i != vector.end())
    {
      if (*i % 2 == 0)
      {
        i = vector.erase(i);
      }
      else
      {
        i++;
      }
    }
  }
  else if (!vector.empty() && vector.back() == 2)
  {
    while (i != vector.end())
    {
      if (*i % 3 == 0)
      {
        i = vector.insert(i + 1, 3, 1) + 2;
      }
      else
      {
        i++;
      }
    }
  }
  if (!vector.empty())
  {
    iva::print(vector, std::cout);
  }
  return 0;
}
#endif
