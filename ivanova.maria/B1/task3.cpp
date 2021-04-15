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
  int element = 1;
  while ((element != 0) && std::cin >> element)
  {
    vector.push_back(element);
  }

  if (!std::cin.eof() && std::cin.fail())
  {
    std::cerr << ("Incorrect data!");
    return 1;
  }
  if (element != 0)
  {
    std::cerr << ("The last element must be zero!");
    return 1;
  }
  if (vector.empty())
  {
    std::cerr << "Invalid Number";
    return 1;
  }
  std::vector< int >::iterator i = vector.begin();
  if (vector.back() == 1)!
  {
    while (i != vector.end())
    {
      if (*i % 2)
      {
        i++;
      }
      else
      {
        vector.erase(i);
      }
    }
  }
  else if (vector.back() == 2)
  {
    while (i != vector.end())
    {
      if (*i % 3 == 0)
      {
        i = vector.insert(++i, 3, 1) + 2;
      }
      else
      {
        i++;
      }
    }
  }
  iva::print(vector, std::cout);
  return 0;
}
#endif
