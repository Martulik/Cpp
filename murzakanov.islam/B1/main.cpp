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
  switch (exNum)
  {
    case 1:
    {
      std::string order = argv[2];
      murzakanov::task1(order);
      break;
    }
    case 2:
    {
      std::string name = argv[2];
      murzakanov::task2(name);
      break;
    }
    case 3:
    {
      murzakanov::task3();
      break;
    }
    case 4:
    {
      std::string order = argv[2];
      int size = atoi(argv[3]);
      murzakanov::task4(order, size);
      break;
    }
    default:
    {
      throw std::invalid_argument("Wrong task number");
    }
  }
 
  return 0;
}
