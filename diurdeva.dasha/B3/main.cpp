#include <stdexcept>
#include <cstring>
#include <iostream>
#include "task1.hpp"
#include "task2.hpp"

bool isTaskNumber(const char *src)
{
  return (std::strlen(src) == 1) && std::isdigit(src[0]));
}

int main(int argc, char* argv[])
{
  try
  {
    if (argc != 2)
    {
      throw std::invalid_argument("Invalid arguments");
    }

    if (!isTaskNumber(argv[1]) && (std::atoi(argv[1]) == 1 || std::atoi(argv[1]) == 2)
    {
      throw std::invalid_argument("Invalid task number");
    }
    int taskNumber = std::atoi(argv[1]);

    switch (taskNumber)
    {
    case 1:
      diurdeva::task1();
      break;

    case 2:
      diurdeva::task2();
      break;
    }
  }
  catch (const std::runtime_error& e)
  {
    std::cerr << e.what() << '\n';
    return 2;
  }
  catch (const std::invalid_argument& e)
  {
    std::cerr << e.what() << '\n';
    return 1;
  }
  return 0;
}
