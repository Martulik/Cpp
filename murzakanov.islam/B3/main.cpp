#include <iostream>

#include "tasks.hpp"
#include "tools.hpp"

int main(int argc, char* argv[])
{
  int code = 0;
  if (argc != 2)
  {
    code = 1;
  }
  int index = 0;
  try
  {
    index = std::stoi(argv[1]);
  }
  catch(const std::exception& e)
  {
    code = 1;
  }
  if (!code && index == 1)
  {
    murzakanov::task1();
  }
  else if (!code && index == 2)
  {
    murzakanov::task2();
  }
  else
  {
    std::cerr << "Invalid arguments\n";
    code = 1;
  }
  return code;
}
