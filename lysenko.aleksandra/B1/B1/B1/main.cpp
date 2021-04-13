#include <stdexcept>
#include <cstring>
#include <iostream>

namespace lysenko
{
  bool correctNumberOfArgs(int argc);///��������� ��� argc � ��������� �� 2 �� 4, ���� ��� ����������� ����������
  bool correctData(char* argv);///��������� �� �������� �� ������ � ���� ��������
  bool isTypeOfSort(char* argv);///��������� �� ascending/descending � ���������� 1 � ������ ����������, � ��������� ������ ���������� 0
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
          std::cout << "Yohooo";
          ///����� 1 �������
        }
        else
        {
          //����� 2 �������
        }
      }
      throw std::invalid_argument("Format of task's number is not correct");
    }
    else
    {
      ///����� 4 �������
    }
  }
  else
  {
    throw std::invalid_argument("Invalid number of arguments");
  }
  return 0;
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