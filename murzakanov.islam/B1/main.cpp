#include <iostream>
#include <string>
#include "tasks.hpp"

int main(int argc, char* argv[])
{
  if (argc < 3)
  {
    throw std::invalid_argument("Should be more parametrs");
  }
  int exNum = int(argv[1][0] - '0');
  if (exNum == 1)
  {
    std::string order = argv[2];
    task1(order);
  }
}

