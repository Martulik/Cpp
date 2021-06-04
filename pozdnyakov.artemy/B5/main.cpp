#include <stdexcept>
#include <iostream>
#include "tasks.hpp"

namespace poz = pozdnyakov;

int main(int argc, char* argv[])
{
  try
  {
    if (argc == 2)
    {
      if (!std::string(argv[1]).compare("1"))
      {
        poz::task1(std::cin, std::cout);
        return 0;
      }
      else if (!std::string(argv[1]).compare("2"))
      {
        poz::task2(std::cin, std::cout);
        return 0;
      }
    }
    throw std::invalid_argument("Invalid parameter");
  }
  catch (std::exception& exc)
  {
    std::cerr << exc.what() << '\n';
    return -2;
  }
}
