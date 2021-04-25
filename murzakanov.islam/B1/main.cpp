#include <string>
#include <iostream>
#include <random>

#include "tasks.hpp"
#include "tools.hpp"

std::string error = "Null";
int code = 0;

void setError(std::string err)
{
  error = err;
  code = 1;
}

int main(int argc, char* argv[])
{
  namespace mur = murzakanov;
  srand(time(0));

  if (argc < 2) {
    code = 1;
  }

  int exNum = 0;
  if (!code)
  {
    exNum = int(argv[1][0] - '0');
    std::string firstArg = argv[1];
    if (mur::checkForSpaces(firstArg))
    {
      code = 1;
    }
  }

  if (!code && exNum == 1 && argc == 3) {
    std::string order = argv[2];
    code = mur::task1(order);
  }
  else if (!code && exNum == 2 && argc == 3) {
    std::string name = argv[2];
    code = mur::task2(name);
  }
  else if (!code && exNum == 3 && argc == 2) {
    code = mur::task3();
  }
  else if (!code && exNum == 4 && argc == 4) {
    std::string order = argv[2];
    std::string size = argv[3];
    if (mur::checkIsNumber(size))
    {
      int size = std::atoi(argv[3]);
      code = mur::task4(order, size);
    }
    else
    {
      setError("Invalid arguments\n");
      std::cerr << error;
    }
  }
  else {
    setError("Invalid arguments\n");
    std::cerr << error;
  }
  return code;
}
