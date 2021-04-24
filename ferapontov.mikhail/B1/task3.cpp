#include "tasks.hpp"
#include <iostream>
#include "functions.hpp"

void ferapontov::task3()
{
  int number = 0;
  std::vector< int > vec;

  while (std::cin >> number)
  {
    if (number == 0)
    {
      break;
    }
    vec.push_back(number);
  }

  if (std::cin.fail() && !(std::cin.eof()))
  {
    std::cerr << "Read error";
    std::exit(2);
  }
  if (number != 0)
  {
    std::cerr << "Invalid end of user insert";
    std::exit(2);
  }


  if(!(vec.empty()))
  {
    std::vector< int >::iterator it = vec.begin();
    int lastElem = vec.back();

    if (lastElem == 1)
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
    if (lastElem == 2)
    {
      while (it != vec.end())
      {
        if (*it % 3 == 0)
        {
          it = vec.insert(++it, 3, 1);
          it += 1;
        }
          it++;
      }
    }
    print(vec);
  }
}
