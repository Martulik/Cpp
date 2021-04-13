#include "tasks.hpp"
#include <iostream>
#include <vector>
#include "strategies.hpp"
#include "functions.hpp"

void borisova::doTask3()
{
  std::vector < int > collection;
  int number = 1;
  while (std::cin && !(std::cin >> number).eof())
  {
    if (std::cin.fail() || std::cin.bad())
    {
      std::cerr << "Incorrect input\n";
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

  if (number != 0)
  {
    std::cerr << "Last value must be 0\n";
  }

  std::vector< int >::iterator iter = collection.begin();
  if (!collection.empty() && collection.back() == 1)
  {
    while (iter != collection.end())
    {
      if (*iter % 2 == 1)
      {
        iter++;
      }
      else
      {
        collection.erase(iter);
      }
    }
  }
  else if (!collection.empty() && collection.back() == 2)
  {
    while (iter != collection.end())
    {
      if (*iter % 3 == 0)
      {
        iter = collection.insert(++iter, 3, 1);
        iter += 2;
      }
      iter++;
    }
  }
  borisova::print(collection, std::cout);
}
