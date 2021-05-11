#include "tasks.hpp"
#include <iostream>
#include <cstring>
#include <stdexcept>

namespace poz = pozdnyakov;

int main(int argc, char* argv[])
{
  try
  {
    if (strlen(argv[1]) != 1)
    {
      return -2;
    }
    if (argc == 2 && argv[1][0] == '1')
    {
      poz::task1(std::cin, std::cout);
    }
    else if (argc == 2 && argv[1][0] == '2')
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
