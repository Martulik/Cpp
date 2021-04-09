#include <string>
#include <iostream>

#include "tasks.hpp"

int main(int argc, char* argv[])
{
  if (argc < 2)
  {
    throw std::invalid_argument("Should be more parametrs");
  }
  int exNum = int(argv[1][0] - '0');
  if (exNum == 1 && argc == 3) {
    std::string order = argv[2];
    murzakanov::task1(order);
  }
  else if (exNum == 2 && argc == 2) {
    std::string name = argv[2];
    murzakanov::task2(name);
  }
  else if (exNum == 3 && argc == 1) {
    murzakanov::task3();
  }
  else if (exNum == 4 && argc == 4) {
    std::string order = argv[2];
    int size = atoi(argv[3]);
    murzakanov::task4(order, size);
  }
  else {
    throw std::invalid_argument("Wrong arguments");
  }
  return 0;
}
