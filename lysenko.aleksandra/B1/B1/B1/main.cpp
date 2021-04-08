#include <stdexcept>

bool correctNumberOfArgs(int argc);///провер€ем что argc в диапазоне от 2 до 4, если нет выбрасываем исключение
bool correctData(char* argv);///провер€ем не содержит ли строка в себе пробелов
bool isTypeOfSort(char* argv);///провер€ем на ascending/descending и возвращаем 1 в случае совпадени€, в противном случае возвращаем 0

int main(int argc, char* argv[])
{
  if (correctNumberOfArgs(argc))
  {
    if (argc == 2)
    {
      ///вызов 3 задани€
    }
    else if (argc == 3)
    {
      if (correctData(argv[1])) 
      {
        if (isTypeOfSort(argv[2]))
        {
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
