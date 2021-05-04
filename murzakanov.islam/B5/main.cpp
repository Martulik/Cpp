#include <iostream>

#include "tasks.hpp"

int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    std::cerr << "\n";
    return 1;
  }
  int task = argv[1][0] - '0';
  if (task == 1)
  {
    murzakanov::task1(std::cin, std::cout);
  }
  else if (task == 2)
  {
    murzakanov::task2(std::cin, std::cout);
  }
  return 0;
}
