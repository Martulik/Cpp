#include <stdexcept>
#include <iostream>
#include "task1.hpp"
#include "task2.hpp"

int main(int argc, char* argv[])
{
  try
  { 
    if (argc != 2)
    {
      throw std::invalid_argument("Invalid arguments");
    }

    char* ptr = nullptr;
    int taskNumber = std::strtol(argv[1], &ptr, 0);
    if (*ptr || (taskNumber != 1 && taskNumber != 2))
    {
      throw std::invalid_argument("Invalid arguments");
    }

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
