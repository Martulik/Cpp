#include <iostream>

#include "tasks.hpp"
#include "tools.hpp"

int main(int argc, char* argv[])
{
  int code = 0;
  if (argc != 2)
  {
    code = 1;
  }
  if (!code && murzakanov::checkIsSpace(argv[1]))
  {
    code = 1;
  }
  if (!code && !murzakanov::checkIsNum(argv[1]))
  {
    code = 1;
  }
  if (!code && atoi(argv[1]) == 1)
  {
    murzakanov::task1();
  }
  else if (!code && atoi(argv[1]) == 2)
  {
    murzakanov::task2();
  }
  else
  {
    std::cerr << "Invalid arguments\n";
    code = 1;
  }
  return code;
}
