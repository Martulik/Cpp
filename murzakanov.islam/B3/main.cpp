#include <iostream>
#include <algorithm>

#include "tasks.hpp"
#include "tools.hpp"

int main(int argc, char* argv[])
{
  int code = 0;
  if (argc != 2)
  {
    code = 1;
  }
  int taskNum = 0;
  try
  {
    std::string argument(argv[1]);
    if (argument.length() != 1)
    {
      code = 1;
    }
    taskNum = std::stoi(argument);
  }
  catch(const std::exception& e)
  {
    code = 1;
  }
  if (!code && taskNum == 1)
  {
    murzakanov::task1(std::cin, std::cout);
  }
  else if (!code && taskNum == 2)
  {
    murzakanov::task2(std::cout);
  }
  else
  {
    std::cerr << "Invalid arguments\n";
    code = 1;
  }
  return code;
}
