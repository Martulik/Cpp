#include <iostream>
#include <string>

#include "tasks.h"

int main(int argc, char* argv[])
{
  if (argc == 2)
  {
    std::string argument(argv[1]);
    if (argument == "1")
    {
      return lysenko::task1(std::cin, std::cout);
    }
   /* else if (argument == "2")
    {
      return lysenko::task2(std::cin, std::cout);
    }*/
  }
  return 1;
}
