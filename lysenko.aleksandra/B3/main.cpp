#include <iostream>

#include "tasks.h"

int main(int argc, char* argv[])
{
  if (argc == 2)
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
