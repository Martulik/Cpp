#include <stdexcept>
#include <cstring>
#include <iostream>

namespace lysenko
{
  bool correctNumberOfArgs(int argc);///провер€ем что argc в диапазоне от 2 до 4, если нет выбрасываем исключение
  bool correctData(char* argv);///провер€ем не содержит ли строка в себе пробелов
  bool isTypeOfSort(char* argv);///провер€ем на ascending/descending и возвращаем 1 в случае совпадени€, в противном случае возвращаем 0
}

int main(int argc, char* argv[])
{
  if (lysenko::correctNumberOfArgs(argc))
  {
    if (argc == 2)
    {
      ///вызов 3 задани€
    }
    else if (argc == 3)
    {
      if (lysenko::correctData(argv[1])) 
      {
        if (lysenko::isTypeOfSort(argv[2]))
        {
          std::cout << "Yohooo";
          ///вызов 1 задани€
        }
        else
        {
          //вызов 2 задани€
        }
      }
      throw std::invalid_argument("Format of task's number is not correct");
    }
    else
    {
      ///вызов 4 задани€
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