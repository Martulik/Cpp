#include <iostream>
#include <stdexcept>
#include <stdlib.h>

#include "tasks.hpp"
#include "functions.hpp"

namespace lab = shkurov;

int main(int argc, char* argv[])
{
  try
  {
    srand(time(NULL));

    if (lab::containsSpaces(argc, argv))
    {
      throw std::invalid_argument("No spaces allowed in arguments.");
    }

    if (!lab::isNumber(argv[1]))
    {
      throw std::invalid_argument("First argument is always numeric representing task number.");
    }

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
      if (!lab::isNumber(argv[3]))
      {
        throw std::invalid_argument("Array size should be a number.");
      }
      lab::taskFour(argv[2], atoi(argv[3]));
    }
    else
    {
      throw std::invalid_argument("Mismatched arguments.");
    }
  }
  catch (const std::exception& ex)
  {
    std::cerr << ex.what() << '\n';
    return 1;
  }

  return 0;
}
