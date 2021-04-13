#include <iostream>
#include "functions.hpp"
#include "tasks.hpp"
#include "strategies.hpp"

int main(int argc, char* argv[])
{
  int exitCode = 1;
  if (argc < 2)
  {
    std::cerr << "Arguments isn't find";
    return exitCode;
  }
  int numberTask = int(argv[1][0] - '0');
  if (!borisova::checkNumber(argv[1]))
  {
    return exitCode;
  }
  std::string line = "";
  int size = 0;

  switch (numberTask)
  {
  case 1:
    if (argc != 3)
    {
      exitCode = 1;
      break;
    }
    line = argv[2];
    exitCode = borisova::doTask1(line);
    break;

  case 2:
    if (argc != 4)
    {
      exitCode = 1;
      break;
    }
    line = argv[2];
    exitCode = borisova::doTask2(line);
    break;

  case 3:
    if (argc != 2)
    {
      exitCode = 1;
      break;
    }
    exitCode = borisova::doTask3();
    break;

  case 4:
    if (argc != 4)
    {
      exitCode = 1;
      break;
    }
    line = argv[2];
    size = borisova::toInt(argv[3]);
    exitCode = borisova::doTask4(line, size);
    break;

  default:
    std::cerr << "Unknown task";
    exitCode = 1;
    break;
  }

  return exitCode;
}
