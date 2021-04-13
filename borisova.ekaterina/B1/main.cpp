#include <iostream>
#include "functions.hpp"
#include "tasks.hpp"
#include "strategies.hpp"

int main()
{
  int numberTask;
  std::string line;
  int size;
  std::cin >> numberTask;

  switch (numberTask)
  {
  case 1:
    std::cin >> line;
    borisova::doTask1(line);
    break;
  case 2:
    std::cin >> line;
    borisova::doTask2(line);
    break;
  case 3:
    borisova::doTask3();
    break;
  case 4:
    std::cin >> line >> size;
    borisova::doTask4(line, size);
    break;
  default:
    std::cerr << "Unknown task";
  }
}
