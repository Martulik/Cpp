#include <stdexcept>
#include <cstring>
#include <iostream>

#include "tasks.hpp"

namespace lysenko
{
  int conditionCode = 0;
  bool correctNumberOfArgs(int argc);///��������� ��� argc � ��������� �� 2 �� 4, ���� ��� ����������� ����������
  bool correctData(char* argv);///��������� �� �������� �� ������ � ���� ��������
  bool isTypeOfSort(char* argv);///��������� �� ascending/descending � ���������� 1 � ������ ����������, � ��������� ������ ���������� 0
  bool accurateTaskNumber(char* argv, const char* reference);
}

int main(int argc, char* argv[])
{
  if (lysenko::correctNumberOfArgs(argc))
  {
    if (argc == 2)
    {
      ///����� 3 �������
    }
    else if (argc == 3)
    {
      if (lysenko::correctData(argv[1]))
      {
        if (lysenko::isTypeOfSort(argv[2]))
        {
          if (lysenko::accurateTaskNumber(argv[1], "1"))
          {
            lysenko::conditionCode = lysenko::task1(argv[2]);
          }
        }
        else
        {
          if (lysenko::correctData(argv[2]))
          {
            if (lysenko::accurateTaskNumber(argv[1], "2"))
            {
              lysenko::conditionCode = lysenko::task2(argv[1]);
            }
          }
          else
          {
            std::cerr << "Invalid second argument";
            lysenko::conditionCode = 1;
          }
        }
      }
      else
      {
        std::cerr << "Format of task's number is not correct";
        lysenko::conditionCode = 1;
      }
    }
    else
    {
      ///����� 4 �������
    }
  }
  else
  {
    std::cerr << "Invalid number of arguments";
    lysenko::conditionCode = 1;
  }
  return lysenko::conditionCode;
}

bool lysenko::correctNumberOfArgs(int argc)
{
  if ((argc > 1) && (argc < 5))
  {
    return 1;
  }
  return 0;
}

bool lysenko::correctData(char* argv)
{
  size_t i = 0;
  while (argv[i] != '\0')
  {
    if (argv[i] == ' ')
    {
      return 0;
    }
    i += 1;
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
  else
  {
    std::cerr << "Illegal task's number for these arguments";
    lysenko::conditionCode = 1;
    return 0;
  }
}