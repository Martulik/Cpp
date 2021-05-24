#include <iostream>
#include "task.hpp"

int main()
{
  try
  {
    lebedeva::doTask1(std::cin, std::cout);
  }
  catch (const std::exception& error)
  {
    std::cerr << error.what() << "\n";
    return 1;
  }
  return 0;
}
