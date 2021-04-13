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
  int numberTask = borisova::toInt(argv[1]);
  if (numberTask != -1)
  {
    return exitCode;
  }
  std::string line = "";
  int size = 0;

  switch (numberTask)
  {
  case 1:
    line = argv[2];
    return borisova::doTask1(argc, line);

  case 2:
    line = argv[2];
    return borisova::doTask2(argc, line);

  case 3:
    return borisova::doTask3(argc);

  case 4:
    line = argv[2];
    size = borisova::toInt(argv[3]);
    return borisova::doTask4(argc, line, size);

  default:
    std::cerr << "Unknown task";
    return exitCode;
    break;
  }

  return 0;
}
