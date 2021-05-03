#include <iostream>

#include "tasks.hpp"

int main(int argc, char* argv[])
{
  int code = 0;
  if (argc != 2)
  {
    std::cerr << "Invalid arguments";
    code = 1;
  }

  if (atoi(argv[1]) == 1)
  {
    murzakanov::task1();
  }
  else if (atoi(argv[1]) == 2)
  {
  murzakanov::task2();
  }
  else
  {
    std::cerr << "Invalid arguments";
    code = 1;
  }
  return code;
}
