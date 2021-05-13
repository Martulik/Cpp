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
      throw std::invalid_argument("Invalid arguments");
    }

    int task = 0;
    if (lebedeva::isNumber(argv[1]))
    {
      task = std::atoi(argv[1]);
    }
    else
    {
      throw std::invalid_argument("Not a number");
    }

    if ((task <= 0) || (task > 4))
    {
      throw std::invalid_argument("Invalid task number");

    }
    if (task == 1)
    {
      lebedeva::doTask1(argc, argv);
    }
    if (task == 2)
    {
      lebedeva::doTask2(argc, argv);
    }
    if (task == 3)
    {
      lebedeva::doTask3(argc);
    }
    if (task == 4)
    {
      lebedeva::doTask4(argc, argv);
    }
  }
  catch (const std::exception& error)
  {
    std::cerr << error.what() << "\n";
    return 1;
  }

  return 0;
}
