#include <iostream>
#include <algorithm>
#include <fstream>
#include "task1.hpp"
#include "task2.hpp"
namespace iva = ivanova;

int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    std::cerr << "invalid task number";
    return 1;
  }
  if (std::stoi(argv[1]) == 1)
  {
    std::ifstream in(*argv);
    if (!in.is_open() || in.eof())
    {
      std::cerr << "Failed reading";
      return 1;
    }
    else
    {
      return iva::task1(std::cin, std::cout);
    }
  }
  else
  {
    return iva::task2(std::cin, std::cout);
  }
}

