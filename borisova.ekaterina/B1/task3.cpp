#include "tasks.hpp"
#include <iostream>
#include <vector>
#include "strategies.hpp"
#include "functions.hpp"

int borisova::doTask3(const int argc)
{
  if (argc != 2)
  {
    std::cerr << "Incorrect number of arguments";
    return 2;
  }
  std::vector < int > collection;
  int number = 1;
  while (std::cin && !(std::cin >> number).eof())
  {
    if (std::cin.fail() || std::cin.bad())
    {
      std::cerr << "Incorrect input\n";
      return 1;
    }
    if (number != 0)
    {
      collection.push_back(number);
    }
    else
    {
      break;
    }
  }

  if (collection.empty())
  {
    return 0;
  }

  if (number != 0)
  {
    std::cerr << "Last value must be 0\n";
    return 1;
  }

  std::vector< int >::iterator iter = collection.begin();
  if (collection.back() == 1)
  {
    while (iter != collection.end())
    {
      if (*iter % 2 == 0)
      {
        iter = collection.erase(iter);
      }
      else
      {
        iter++;
      }
    }
  }
  else if (collection.back() == 2)
  {
    while (iter != collection.end())
    {
      if (*iter % 3 == 0)
      {
        iter++;
        iter = collection.insert(iter, 3, 1);
        iter += 2;
      }
      else
      {
        iter++;
      }
    }
  }

  borisova::print(collection, std::cout);
  return 0;
}
