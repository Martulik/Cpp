#include <iostream>
#include <cctype>
#include "tasks.hpp"

int main(int argc, char* argv[])
{
  try
  {
    if (argc != 2)
    {
      throw std::invalid_argument("Invalid arguments\n");
    }

    char* firstArg = argv[1];
    if (sizeof(firstArg) != 1)
    {
      throw std::invalid_argument("Invalid arguments\n");
    }

    if (!std::isdigit(firstArg[0]))
    {
      throw std::invalid_argument("Invalid first arguments\n");
    }
    int task = std::atoi(firstArg);

    if (task == 1)
    {
      lebedeva::doTask1(std::cin, std::cout);
    }
    else
    {
      throw std::invalid_argument("Invalid arguments\n");
    }
  }
  catch (const std::exception& error)
  {
    std::cerr << error.what() << "\n";
    return 1;
  }
  return 0;
}
