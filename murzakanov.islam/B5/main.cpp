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
  if (!code && task == 1)
  {
    code = murzakanov::task1(std::cin, std::cout);
  }
  else if (!code && task == 2)
  {
    code = murzakanov::task2(std::cin, std::cout);
  }
  else
  {
    std::cerr << "Invalid task number\n";
    code = 1;
  }
  return code;
}
