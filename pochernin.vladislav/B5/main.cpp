#include <iostream>
#include <stdexcept>

#include "functions.hpp"

int main(int argc, char* argv[])
{
  try
  {
    if (argc != 2)
    {
      throw(std::invalid_argument("Incorrect count of arguments"));
    }

    int taskNumber = pochernin::getTaskNumber(argv[1]);
    if (taskNumber == 1)
    {
      //pochernin::task1
    }
    else if (taskNumber == 2)
    {
      //pochernin::task2
    }
    else
    {
      throw(std::invalid_argument("Incorrect argument (task number)"));
    }
  }
  catch (std::exception& error)
  {
    std::cerr << error.what() << "\n";
    return 1;
  }
}
