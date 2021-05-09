#include "tasks.hpp"
#include <iostream>

namespace poz = pozdnyakov;

int main(int argc, char* argv[])
{
  try
  {
    if (argc == 2 && argv[0][1] != '\n')
    {
      poz::task1(std::cin, std::cout);
    }
  }
  catch(std::exception& exc)
  {
    std::cerr << exc.what() << '\n';
    return 2;
  }
}
