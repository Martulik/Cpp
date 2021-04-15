#include <string>
#include <iostream>

#include "tasks.hpp"
#include "functions.hpp"
namespace iva = ivanova;

namespace ivanova
{
  int charToInt(char* string)
  {
    std::string str = string;
    int result = 0;
    if (str.empty())
    {
      return {};
    }
    for (std::string::const_iterator i = str.cbegin(); i < str.cend(); i++)
    {
      if (*i < '0' || *i > '9')
      {
        return {};
      }
      result += *i - '0';
    }
    return result;
  }
}

int main(int argc, char* argv[])
{
  int exitCode = 0;
  if ((argc < 2) || (argc > 4))
  {
    std::cerr << ("Function must have more arguments");
    return 1;
  }
  if (argv[1][1] != '\0')
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
  if (number == 1 && argc == 3)
  {
    exitCode = iva::task1(argv[2]);
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
    if (iva::checkForSpaces(argv[3]))
    {
      exitCode = iva::task4(argv[2], atoi(argv[3]));
    }
    else
    {
      std::cerr << " Number Count With Space";
      exitCode = 1;
    }
  }
  else
  {
    std::cerr << ("Wrong arguments number");
    exitCode = 1;
  }
  return exitCode;
}
