#include <string>
#include <iostream>

#include "tasks.hpp"

std::string error;
int code = 0;

void setError(std::string err)
{
  error = err;
  code = 1;
}

bool checkIsNumber(std::string& str)
{
  for (int i = 0; i < int(str.length()); i++)
  {
    if (str[i] < '0' || str[i] > '9')
    {
      return false;
    }
  }
  return true;
}

bool checkForSpaces(std::string& str)
{
  if (str.find(' '))
  {
    return true;
  }
  return false;
}

int main(int argc, char* argv[])
{
  bool inArg = true;
  std::string firstArg = argv[1];
  if (checkForSpaces(firstArg))
  {
    inArg = false;
  }
  if (argc < 2) {
    inArg = false;
  }
  int exNum = int(argv[1][0] - '0');
  if (inArg && exNum == 1 && argc == 3) {
    std::string order = argv[2];
    code = murzakanov::task1(order);
  }
  else if (inArg && exNum == 2 && argc == 3) {
    std::string name = argv[2];
    code = murzakanov::task2(name);
  }
  else if (inArg && exNum == 3 && argc == 2) {
    code = murzakanov::task3();
  }
  else if (inArg && exNum == 4 && argc == 4) {
    std::string order = argv[2];
    std::string size = argv[3];
    if (checkIsNumber(size))
    {
      int size = std::atoi(argv[3]);
      code = murzakanov::task4(order, size);
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
