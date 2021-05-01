#include <iostream>
#include <random>

#include "tasks.hpp"
#include "tools.hpp"

int main(int argc, char* argv[])
{
  namespace mur = murzakanov;
  srand(time(0));
  int code = 0;

  if (argc < 2)
  {
    code = 1;
  }

  int exNum = 0;
  if (!code)
  {
    exNum = (argv[1][0] - '0');
    if (mur::checkForSpaces(argv[1]))
    {
      code = 1;
    }
  }

  if (!code && exNum == 1 && argc == 3)
  {
    code = mur::task1(argv[2]);
  }
  else if (!code && exNum == 2 && argc == 3)
  {
    code = mur::task2(argv[2]);
  }
  else if (!code && exNum == 3 && argc == 2)
  {
    code = mur::task3();
  }
  else if (!code && exNum == 4 && argc == 4)
  {
    if (mur::checkIsNumber(argv[3]))
    {
      int size = std::atoi(argv[3]);
      code = mur::task4(argv[2], size);
    }
    else
    {
      code = 1;
      std::cerr << "Invalid arguments\n";
    }
  }
  else
  {
    code = 1;
    std::cerr << "Invalid arguments\n";
  }
  return code;
}
