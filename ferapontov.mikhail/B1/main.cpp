#include <iostream>
#include <random>

#include "tasks.hpp"
#include "functions.hpp"

namespace fer = ferapontov;

int main(int argc, char *argv[])
{
  std::random_device rd;
  if (argc < 2)
  {
    std::cerr << "Invalid Arguments";
    std::exit(1);
  }
  fer::checkNumber(argv[1]);
  int TaskNumber = std::atoi(argv[1]);

  if (TaskNumber > 4 || TaskNumber < 1)
  {
    std::cerr << "Invalid number of the Task";
    std::exit(1);
  }
  else if (TaskNumber == 1)
  {
    if (argc < 3)
    {
      std::cerr << "Invalid Arguments";
      std::exit(1);
    }
    fer::checkSpaces(argv[2]);
    const char* mode = argv[2];
    fer::task1(mode);
  }
  else if (TaskNumber == 2)
  {
    if (argc < 3)
    {
      std::cerr << "Invalid Arguments";
      std::exit(1);
    }
    fer::checkSpaces(argv[2]);
    const char* file = argv[2];
    fer::task2(file);
  }
  else if (TaskNumber == 3)
  {
    fer::task3();
  }
  else if (TaskNumber == 4)
  {
    if (argc < 4)
    {
      std::cerr << "Invalid Arguments";
      std::exit(1);
    }
    fer::checkSpaces(argv[2]);
    const char* mode = argv[2];
    fer::checkNumber(argv[3]);
    int size = std::atoi(argv[3]);
    fer::task4(mode, size);
  }
  return 0;
}
