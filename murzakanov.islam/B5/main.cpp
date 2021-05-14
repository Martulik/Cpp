#include <iostream>

#include "tasks.hpp"

int main(int argc, char* argv[])
{
  int code = 0;
  if (argc != 2)
  {
    std::cerr << "Invalid argument\n";
    code = 1;
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
  return code;
}
