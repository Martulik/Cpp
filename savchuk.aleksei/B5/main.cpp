#include <cstring>
#include <iostream>
#include <stdexcept>

#include "tasks.hpp"

namespace lab = savchuk;

int main(int argc, char** argv)
{
  try
  {
    if (argc != 2)
    {
      throw std::runtime_error("Invalid command line arguments");
    }
    if (!strcmp(argv[1], "1"))
    {
      lab::doTask1(std::cin, std::cout);
    }
    else if (!strcmp(argv[1], "2"))
    {
      // lab::doTask2(std::cin, std::cout);
    }
    else
    {
      throw std::runtime_error("Invalid command line arguments");
    }
  }
  catch (const std::runtime_error& e)
  {
    std::cerr << e.what() << '\n';
    return 1;
  }
}
