#include <iostream>
#include <cstdlib>
#include "task1.hpp"
#include "task2.hpp"

namespace iva = ivanova;

int main(int argc, char *argv[])
{
  int exitCode = 2;
  if (argc != 2)
  {
    std::cerr << "Incorrect number of parameters!";
    return exitCode;
  }
  const int taskNum = std::atoi(argv[1]);
  if ((taskNum != 1 && taskNum != 2))
  {
    std::cerr << "Incorrect task number";
    return exitCode;
  }
  else if (taskNum == 1)
  {
    exitCode = iva::task1();
  }
  else
  {
    exitCode = iva::task2();
  }
  return exitCode;
}
