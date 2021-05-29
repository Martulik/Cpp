#include <iostream>
#include "tasks.hpp"

int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    std::cerr << "\nWrong number of arguments\n";
    return 1;
  }

  if (std::string{ argv[1] }.length() != 1)
  {
    std::cerr << "\nInvalid argument\n";
    return 1;
  }

  int num = std::atoi(argv[1]);
  try
  {
    if (num == 1)
    {
      borisova::doTask1(std::cin, std::cout);
      return 0;
    }
    else if (num == 2)
    {
      borisova::doTask2(std::cin, std::cout);
      return 0;
    }
  }
  catch (const std::invalid_argument& ex)
  {
    std::cerr << ex.what() << "\n";
    return -1;
  }
  std::cerr << "\nInvalid argument\n";
  return 1;
}
