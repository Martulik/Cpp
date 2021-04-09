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

int main(int argc, char* argv[])
{
  int exNum = int(argv[1][0] - '0');
  if (exNum == 1 && argc == 3) {
    std::string order = argv[2];
    code = murzakanov::task1(order);
  }
  else if (exNum == 2 && argc == 3) {
    std::string name = argv[2];
    code = murzakanov::task2(name);
  }
  else if (exNum == 3 && argc == 2) {
    code = murzakanov::task3();
  }
  else if (exNum == 4 && argc == 4) {
    std::string order = argv[2];
    try
    {
    int size = std::stoi(argv[3]);
    code = murzakanov::task4(order, size);
    }
    catch(std::invalid_argument& err)
    {
      setError("Invalid argument");
    }
  }
  else {
    setError("Invalid arguments");
    std::cerr << error;
  }
  return code;
}
