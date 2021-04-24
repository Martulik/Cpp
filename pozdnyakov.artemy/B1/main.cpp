#include <string>
#include <iostream>
#include <stdlib.h>
#include "tasks.hpp"

namespace poz = pozdnyakov;

int main(int argc, char* argv[])
{
  try
  {
    if (argc < 2)
    {
      throw std::invalid_argument("Not enough arguments");
    }
    int task = std::atoi(std::addressof(argv[1][0]));
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
