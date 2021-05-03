#include <iostream>
#include <ctime>
#include "functions.hpp"
#include "tasks.hpp"
#include "strategies.hpp"

int main(int argc, char* argv[])
{
  srand(time(0));
  int exitCode = 1;
  if (argc < 2)
  {
    std::cerr << "Arguments aren't find";
    return exitCode;
  }
  int numberTask = -1;

  if (borisova::checkNumber(argv[1]))
  {
    numberTask = std::atoi(argv[1]);
  }

  if (numberTask == -1)
  {
    return exitCode;
  }

  switch (numberTask)
  {
  case 1:
    return borisova::doTask1(argc, argv);

  case 2:
    return borisova::doTask2(argc, argv);

  case 3:
    return borisova::doTask3(argc);

  case 4:
    return borisova::doTask4(argc, argv);

  default:
    std::cerr << "Unknown task";
    return exitCode;
    break;
  }

  return 0;
}
