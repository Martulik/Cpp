#include <iostream>
#include <exception>
#include <cstring>
#include "tasks.hpp"

int main(int argc, char* argv[])
{
  try
  {
    if (argc != 2)
    {
      throw std::runtime_error("<Invalid number of arguments>");
    }

    int taskNumber = 0;
    if (strlen(argv[1]) == 1)
    {
      taskNumber = std::atoi(argv[1]);
    }
    if (taskNumber != 1 && taskNumber != 2)
    {
      throw std::runtime_error("<Invalid TaskNumber>");
    }
    else if (taskNumber == 1)
    {
      ferapontov::task1(std::cin, std::cout);
    }
    else
    {
      ferapontov::task2(std::cout);
    }
  }
  catch (std::runtime_error& e)
  {
    std::cerr << e.what();
    std::exit(1);
  }
  return 0;
}
