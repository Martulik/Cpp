#include <iostream>

#include "tasks.hpp"

int main()
{
  int task = 0;
  std::cin >> task;
  if (task == 1)
  {
    murzakanov::task1(std::cin, std::cout);
  }
  return 0;
}
