#include <iostream>
#include <string>
#include "tasks.hpp"

int main(int argc, char* argv[])
{
  try
  {
    if (argc != 2)
    {
      throw std::invalid_argument("Invalid arguments\n");
    }

    std::string firstArg = argv[1];
    if (firstArg.length() != 1)
    {
      throw std::invalid_argument("Invalid arguments\n");
    }

    if (!std::isdigit(firstArg[0]))
    {
      throw std::invalid_argument("Invalid first argument\n");
    }
    int task = std::stoi(firstArg);

    if (task == 1)
    {
      lebedeva::doTask1(std::cin, std::cout);
    }
    else if (task == 2)
    {
      lebedeva::doTask2(std::cout);
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
