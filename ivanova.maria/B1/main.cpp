#include <iostream>
#include <cstdlib>
#include "task1.hpp"
#include "task2.hpp"
#include "task3.hpp"
#include "task4.hpp"
namespace iva = ivanova;

int main(int argc, char* argv[])
{
  int exitCode = 0;
  if ((argc < 2) || (argc > 4))
  {
    std::cerr << ("Function must have more arguments");
    return 1;
  }
  else if (argv[1][1] != '\0')
  {
    std::cerr << "Incorrect task number!";
    return 1;
  }
  const int number = iva::charToInt(argv[1]);
  if (!number)
  {
    std::cerr << "Task number must be integer";
    return 1;
  }
  else if (number == 1 && argc == 3)
  {
    const std::function< bool(int, int) > &sort = iva::getSortMode< int >(argv[2]);
    exitCode = iva::task1(iva::getSortMode< int >(argv[2]));
  }
  else if (number == 2 && argc == 3)
  {
    exitCode = iva::task2(argv[2]);
  }
  else if (number == 3 && argc == 2)
  {
    exitCode = iva::task3();
  }
  else if (number == 4 && argc == 4)
  {
    if (iva::checkIsNumber(argv[3]))
    {
      exitCode = iva::task4(iva::getSortMode< double >(argv[2]), atoi(argv[3]));
    }
    else
    {
      std::cerr << " Number Count With Space";
      return 1;
    }
  }
  else
  {
    std::cerr << ("Wrong arguments number");
    return 1;
  }
  return exitCode;
}
