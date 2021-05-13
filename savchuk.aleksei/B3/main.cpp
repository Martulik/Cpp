#include <iostream>
#include <cstring>
#include <stdexcept>

#include "tasks.hpp"

namespace lab = savchuk;

int main(int argc, char** argv)
{
  try
  {
    if (argc != 2)
    {
      throw std::invalid_argument("Invalid command line arguments");
    }
    if (!std::strcmp(argv[1], "1"))
    {
      lab::task1(std::cin, std::cout);
    }
    else if (!std::strcmp(argv[1], "2"))
    {
      lab::task2(std::cout);
    }
    else
    {
      throw std::invalid_argument("Invalid command line arguments");
    }
  }
  catch (const std::invalid_argument& err)
  {
    std::cerr << err.what() << '\n';
    return 1;
  }
  catch (const std::runtime_error& err)
  {
    std::cerr << err.what() << '\n';
    return 2;
  }
  catch (...)
  {
    std::cerr << "Internal program error\n";
    return 2;
  }
}
