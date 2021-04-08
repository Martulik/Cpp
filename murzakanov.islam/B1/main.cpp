#include <iostream>
#include <string>
#include "tasks.hpp"

int main(int argc, char* argv[])
{
  if (argc < 2)
  {
    throw std::invalid_argument("Should be more parametrs");
  }
  int exNum = int(argv[1][0] - '0');
  if (exNum == 1)
  {
    std::string order = argv[2];
    task1(order);
  }
  if (exNum == 2)
  {
    std::string name = argv[2];
    task2(name);
  }
  return 0;
}
