#include <stdexcept>
#include <cstring>
#include <iostream>

#include "tasks.hpp"

namespace lysenko
{
  bool correctNumberOfArgs(int argc);
  bool correctData(int argc, char* argv[]);
  bool isTypeOfSort(char* argv);
  bool accurateTaskNumber(char* argv, const char* reference);
}

int main(int argc, char* argv[])
{
  int conditionCode = 1;
  if (lysenko::correctNumberOfArgs(argc))
  {
    if (lysenko::correctData(argc, argv))
    {
      if ((argc == 2) && (lysenko::accurateTaskNumber(argv[1], "3")))
      {
        conditionCode = lysenko::task3();
      }
      else if (argc == 3)
      {
        if ((lysenko::isTypeOfSort(argv[2])) && (lysenko::accurateTaskNumber(argv[1], "1")))
        {
          conditionCode = lysenko::task1(argv[2]);
        }
        else if (!(lysenko::isTypeOfSort(argv[2])) &&(lysenko::accurateTaskNumber(argv[1], "2")))
        {
          conditionCode = lysenko::task2(argv[2]);
        }
      }
      else if ((argc == 4) && (lysenko::isTypeOfSort(argv[2]) && (lysenko::accurateTaskNumber(argv[1], "4"))))
      {
        conditionCode = lysenko::task4(argv[2], argv[3]);
      }
    }
  }

  return conditionCode;
}

bool lysenko::correctNumberOfArgs(int argc)
{
  if ((argc > 1) && (argc < 5))
  {
    return 1;
  }

  std::cerr << "Invalid number of arguments";
  return 0;
}

bool lysenko::correctData(int argc, char* argv[])
{
  for (int i = 1; i < argc; ++i)
  {
    int j = 0;
    while (argv[i][j] != '\0')
    {
      if (argv[i][j] == ' ')
      {
        std::cerr << "Invalid  argument";
        return 0;
      }
      j += 1;
    }
  }
  return 1;
}

bool lysenko::isTypeOfSort(char* argv)
{
  if (strcmp(argv, "ascending") == 0)
  {
    return 1;
  }
  else if (strcmp(argv, "descending") == 0)
  {
    return 1;
  }
  return 0;
}

bool lysenko::accurateTaskNumber(char* argv, const char* reference)
{
  if (strcmp(argv, reference) == 0)
  {
    return 1;
  }

  std::cerr << "Illegal task's number for these arguments";
  return 0;
}
