#include <cstring>
#include <iostream>
#include <stdexcept>

#include "tasks.hpp"

namespace lab = savchuk;

int main(int argc, char* argv[])
{
  try
  {
    if (argc == 2 && !strcmp(argv[1], "1"))
    {
      lab::doTask1(std::cin, std::cout);
    }
    else if (argc == 2 && !strcmp(argv[1], "2"))
    {
      lab::doTask2(std::cin, std::cout);
    }
    else
    {
      std::cerr << "Invalid command line arguments\n";
      return 1;
    }
  }
  catch (const std::runtime_error& e)
  {
    std::cerr << e.what() << '\n';
    return 1;
  }
}
