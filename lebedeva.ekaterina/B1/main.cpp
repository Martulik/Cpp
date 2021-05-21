#include <iostream>
#include <ctime>
#include <stdexcept>
#include "functions.hpp"
#include "tasks.hpp"

int main(int argc, char* argv[])
{
  std::srand(time(NULL));
  try
  {
    if ((argc < 2) || (argc > 4))
    {
      throw std::invalid_argument("Invalid arguments\n");
    }

    int task = 0;
    if (!lebedeva::isNumber(argv[1]))
    {
      throw std::invalid_argument("Invalid first argument\n");
    }
    task = std::atoi(argv[1]);

    if ((task <= 0) || (task > 4))
    {
      throw std::invalid_argument("Invalid task number\n");
    }
    if (task == 1)
    {
      lebedeva::checkNumOfArgs(argc, 3);
      lebedeva::doTask1(argv, std::cin, std::cout);
    }
    if (task == 2)
    {
      lebedeva::checkNumOfArgs(argc, 3);
      lebedeva::doTask2(argv, std::cout);
    }
    if (task == 3)
    {
      lebedeva::checkNumOfArgs(argc, 2);
      lebedeva::doTask3(std::cin, std::cout);
    }
    if (task == 4)
    {
      lebedeva::checkNumOfArgs(argc, 4);
      if (!lebedeva::isNumber(argv[3]))
      {
        throw std::invalid_argument("Invalid vector size in task 4\n");
      }
      lebedeva::doTask4(argv, std::cout);
    }
  }
  catch (const std::exception& error)
  {
    std::cerr << error.what() << "\n";
    return 1;
  }

  return 0;
}
