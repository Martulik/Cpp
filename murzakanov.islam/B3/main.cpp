#include <iostream>

#include "tasks.hpp"

int main(int argc, char* argv[])
{
  if (argc < 2)
  {
    std::cerr << "";
    return -1;
  }

  if (atoi(argv[1]) == 1)
  {
    murzakanov::task1();
  }

  if (atoi(argv[1]) == 2)
  {
    murzakanov::task2();
  }
  return 0;
}
