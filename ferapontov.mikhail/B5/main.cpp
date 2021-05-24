#include <stdexcept>
#include <iostream>
#include <cstring>
#include "tasks.hpp"

int main(int argc, char* argv[])
{
  try
  {
    if (argc != 2)
    {
      throw std::invalid_argument("Invalid number of arguments");
    }

    int taskNumber = 0;
    if (strlen(argv[1]) == 1)
    {
      taskNumber = std::atoi(argv[1]);
    }
    else
    {
      throw std::invalid_argument("Invalid Args");
    }
    if (taskNumber != 1 && taskNumber != 2)
    {
      throw std::invalid_argument("Invalid TaskNumber");
    }
    else if (taskNumber == 1)
    {
      ferapontov::task1(std::cin, std::cout);
    }
    else
    {
      ferapontov::task2();
    }
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    return 1;
  }
  return 0;
}