#include "tasks.hpp"
#include <iostream>
#include <cstring>
#include <stdexcept>

namespace poz = pozdnyakov;

int main(int argc, char* argv[])
{
  try
  {
    if (argc != 2 || std::string(argv[1]).length() != 1)
    {
      return -2;
    }
    if (argv[1][0] == '1')
    {
      poz::task1(std::cin, std::cout);
    }
    else if (argv[1][0] == '2')
    {
      poz::task2();
    }
    else
    {
      return -2;
    }
  }
  catch(std::exception& exc)
  {
    std::cerr << exc.what() << '\n';
    return 2;
  }
}
