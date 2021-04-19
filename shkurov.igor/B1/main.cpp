#include <iostream>
#include <cstring>
#include <stdlib.h>

#include "tasks.hpp"

namespace lab = shkurov;

int main(int argc, char* argv[])
{
  if ((argc == 3) && atoi(argv[1]) == 1)
  {
    lab::taskOne(argv[2]);
  }
  else if ((argc == 3) && atoi(argv[1]) == 2)
  {
    lab::taskTwo(argv[2]);
  }
  else
  {
    std::cerr << "incorrect input";
  }

  return 0;
}