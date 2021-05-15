#include <iostream>
#include <string>

#include "tasks.h"

int main(int argc, std::string argv)
{
  if (argc == 2)
  {
    if (argv == "1")
    {
      return lysenko::task1();
    }
    else if (argv == "2")
    {
      return lysenko::task2();
    }
  }
  return 1;
}

