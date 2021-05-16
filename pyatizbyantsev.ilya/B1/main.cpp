#include <iostream>
#include <stdexcept>
#include <ctime>

#include "tasks.hpp"
#include "functions.hpp"

namespace lab = pyatizbyantsev;

int main(int argc, char* argv[])
{
  srand(time(NULL));
  try
  {
    for (int i = 1; i < argc; i++)
    {
      if (lab::checkSpaces(argv[i]))
      {
        throw std::invalid_argument("Spaces are not allowed in arguments");
      }
    }

    if ((argc > 1) && (!lab::checkNumber(argv[1])))
    {
      throw std::invalid_argument("The first argument must be the task number");
    }

    if ((argc == 3) && (atoi(argv[1]) == 1))
    {
      lab::taskOne(argv[2], std::cin);
    }
    else if ((argc == 3) && (atoi(argv[1]) == 2))
    {
      lab::taskTwo(argv[2], std::cout);
    }
    else if ((argc == 2) && (atoi(argv[1]) == 3))
    {
      lab::taskThree(std::cin);
    }
    else if ((argc == 4) && (atoi(argv[1]) == 4))
    {
      if (!lab::checkNumber(argv[3]))
      {
        throw std::invalid_argument("Invalid array size");
      }
      lab::taskFour(argv[2], atoi(argv[3]));
    }
    else
    {
      throw std::invalid_argument("Arguments aren't find");
    }
  }
  catch (const std::exception& ex)
  {
    std::cerr << ex.what() << '\n';
    return 1;
  }

  return 0;
}
