#include <string>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "tasks.hpp"
#include "functions.hpp"

namespace poz = pozdnyakov;

int main(int argc, char* argv[])
{
  try
  {
    if (argc < 2)
    {
      throw std::invalid_argument("Not enough arguments");
    }
    if (strlen(argv[1]) > 1)
    {
      throw std::invalid_argument("Invalid argument");
    }
    {
      bool result = true;
      for (int i = 0; i < argc - 1; i++)
      {
        result &= !poz::findSpaces(argv[i]);
      }
      if (!result)
      {
        throw std::invalid_argument("Spaces in arguments");
      }
    }
    int task = atoi(std::addressof(argv[1][0]));
    if (task == 1 && argc == 3)
    {
      poz::task1(argv + 2);
    }
    else if (task == 2 && argc == 3)
    {
      poz::task2(argv + 2);
    }
    else if (task == 3 && argc == 2)
    {
      poz::task3();
    }
    else if (task == 4 && argc == 4)
    {
      poz::task4(argv + 2);
    }
    else
    {
      throw std::invalid_argument("Wrong argument");
    }
  }
  catch(std::exception& exc)
  {
    std::cerr << exc.what() << '\n';
    return -1;
  }
  return 0;
}
