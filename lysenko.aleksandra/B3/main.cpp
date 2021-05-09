#include <iostream>

#include "tasks.h"

int main(int argc, char* argv[])
{
  int conditionCode = 1;

  if (argc == 2)
  {
    int taskNumber = std::atoi(argv[1]);
    if (taskNumber == 1)
    {
      conditionCode = lysenko::task1();
    }
    else if (taskNumber == 2)
    {
      conditionCode = lysenko::task2();
    }
  }

  return conditionCode;
}
