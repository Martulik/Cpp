#include <iostream>

#include "PhoneBook.hpp"
#include "tasks.hpp"

namespace lab = shkurov;

int main(int argc, char* argv[])
{
  try {
    if (argc == 2)
    {
      if (atoi(argv[1]) == 1)
      {
        return lab::task1(std::cin, std::cout);
      }
      else if (atoi(argv[1]) == 2)
      {
        lab::task2(std::cout);
      }
      else
      {
        throw std::invalid_argument("Task number is either 1 or 2.");
      }
    }
    else
    {
      throw std::invalid_argument("Only one argument allowed: task number.");
    }
  }
  catch(const std::exception& ex)
  {
    std::cerr << ex.what() << '\n';
    return 1;
  }

  return 0;
}
