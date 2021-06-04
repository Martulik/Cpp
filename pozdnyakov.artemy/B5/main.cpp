#include <stdexcept>
#include <iostream>
#include "tasks.hpp"

namespace poz = pozdnyakov;

int main(int argc, char* argv[])
{
  try
  {
    if (argc != 2 || std::string(argv[1]).length() != 1)
    {
      throw std::invalid_argument("Invalid parameter");
    }
    if (argv[1][0] == '1')
    {
      poz::task1(std::cin, std::cout);
    }
    else if (argv[1][0] == '2')
    {
      poz::task2(std::cin, std::cout);
    }
    else
    {
      throw std::invalid_argument("Invalid parameter");
    }
  }
  catch(std::exception& exc)
  {
    std::cerr << exc.what() << '\n';
    return -2;
  }
  return 0;
}
