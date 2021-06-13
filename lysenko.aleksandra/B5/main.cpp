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
      lysenko::task1(std::cin, std::cout);
      return 0;
    }
    else if (argument == "2")
    {
      try
      {
        lysenko::task2(std::cin, std::cout);
        return 0;
      }
      catch (std::invalid_argument&err)
      {
        std::cerr << err.what();
        return 1;
      }
    }
  }
  return 1;
}
