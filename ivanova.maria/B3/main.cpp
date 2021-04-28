#include <iostream>
#include <cstdlib>
#include "task1.hpp"
#include "task2.hpp"
namespace iva = ivanova;

int main(int argc, char *argv[])
{
  int exitCode = 1;
  if (argc != 2)
  {
    std::cerr << "Incorrect number of parameters!";
    return exitCode;
  }
  char *endline = nullptr;
  const int taskNum = strtol(argv[1], &endline, 0);
  if (*endline || (taskNum != 1 && taskNum != 2))
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
