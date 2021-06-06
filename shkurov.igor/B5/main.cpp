#include <cstring>
#include <iostream>

#include "shape.hpp"
#include "tasks.hpp"

namespace lab = shkurov;

int main(int argc, char* argv[])
{
  if (argc == 2)
  {
    try
    {
      if (!std::strcmp(argv[1], "1"))
      {
        lab::task1(std::cin, std::cout);
      }
      else if (!std::strcmp(argv[1], "2"))
      {
        lab::task2(std::cin, std::cout);
      }
      else
      {
        std::cerr << "\nArgument has to be either 1 or 2";
        return 1;
      }
    }
    catch (const std::invalid_argument& ex)
    {
      std::cerr << "\nInput error.";
      return 1;
    }
    catch (const std::exception& ex)
    {
      std::cerr << "\nUndefined error.";
      return 1;
    }
  }
  else
  {
    std::cerr << "\nWrong argument number";
    return 1;
  }

  return 0;
}
