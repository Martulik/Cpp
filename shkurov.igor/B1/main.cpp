#include <iostream>
#include <stdlib.h>
#include <stdexcept>

#include "tasks.hpp"

namespace lab = shkurov;

int main(int argc, char* argv[])
{
  try
  {
    srand(time(NULL));

    if ((argc == 3) && atoi(argv[1]) == 1)
    {
      lab::taskOne(argv[2]);
    }
    else if ((argc == 3) && atoi(argv[1]) == 2)
    {
      lab::taskTwo(argv[2]);
    }
    else if ((argc == 2) && atoi(argv[1]) == 3)
    {
      lab::taskThree();
    }
    else if ((argc == 4) && atoi(argv[1]) == 4)
    {
      lab::taskFour(argv[2], atoi(argv[3]));
    }
    else
    {
      throw std::invalid_argument("Mismatched arguments. ");
    }
  }
  catch (const std::exception& ex)
  {
    std::cerr << ex.what() << '\n';
  }

  return 0;
}
