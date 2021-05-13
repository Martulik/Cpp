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
      std::cerr << "Invalid arguments";
      return 1;
    }

    int task = 0;
    if (lebedeva::isNumber(argv[1]))
    {
      task = std::atoi(argv[1]);
    }

    if ((task <= 0) || (task > 4))
    {
      std::cerr << "Invalid task number";
      return 1;
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
  std::cerr << "...and here we go again\n";
  return 0;
}
