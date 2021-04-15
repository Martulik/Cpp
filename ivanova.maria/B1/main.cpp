#include <string>
#include <iostream>

#include "tasks.hpp"

namespace iva = ivanova;

namespace ivanova
{
  int convNum(char* string)
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
  std::string errMsg = " ";
  if (argc < 2)
  {
    exitCode = 1;
    throw std::invalid_argument("Function must have more arguments");
  }
  const int number = iva::convNum(argv[1]);
  if (!number)
  {
    exitCode = 1;
    errMsg = "Task number must be integer";
  }
  if (number == 1 && argc == 3)
  {
    exitCode = iva::task1< int >(argv[2]);
  }
  else if (number == 2 && argc == 2)
  {
    exitCode = iva::task2(argv[2]);
  }
  else if (number == 3 && argc == 1)
  {
    exitCode = iva::task3(std::cin, std::cout);
  }
  else if (number == 4 && argc == 4)
  {
    std::string order = argv[2];
    exitCode = iva::task4(argv[2], atoi(argv[3]));
  }
  else
  {
    exitCode = 1;
    throw std::invalid_argument("Wrong arguments");
  }
  std::cerr << errMsg;
  return exitCode;
}
