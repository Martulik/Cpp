#include <iostream>

#include "tasks.h"

namespace lysenko
{
  bool correctData(char* argv);
}

int main(int argc, char* argv[])
{
  if ((argc == 2)&&(lysenko::correctData(argv[1])))
  {
    int taskNumber = std::atoi(argv[1]);
    if (taskNumber == 1)
    {
      return lysenko::task1();
    }
    else if (taskNumber == 2)
    {
      return lysenko::task2();
    }
  }

  return 1;
}

bool lysenko::correctData(char* argv)
{
  int j = 0;
  while (argv[j] != '\0')
  {
    if (argv[j] == ' ')
    {
      std::cerr << "Invalid  argument";
      return 0;
    }
    j += 1;
  }
  return 1;
}
