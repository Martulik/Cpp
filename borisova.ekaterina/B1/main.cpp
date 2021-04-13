#include <iostream>
#include "functions.hpp"
#include "tasks.hpp"
#include "strategies.hpp"

int main(int argc, char* argv[])
{
  if (argc < 2)
  {
    std::cerr << "Arguments isn't find";
    return 1;
  }
  int numberTask = int(argv[1][0] - '0');
  std::string line = "";
  int size = 0;

  switch (numberTask)
  {
  case 1:
    line = argv[2];
    borisova::doTask1(line);
    break;
  case 2:
    line = argv[2];
    borisova::doTask2(line);
    break;
  case 3:
    borisova::doTask3();
    break;
  case 4:
    line = argv[2];
    size = int(argv[3][0] - '0');
    borisova::doTask4(line, size);
    break;
  default:
    std::cerr << "Unknown task";
    break;
  }
}
