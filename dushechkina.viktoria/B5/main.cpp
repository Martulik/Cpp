#include <iostream>
#include "tasks.hpp"

int main(int argc, char* argv[])
{
  try
  {
    if (argc != 2)
    {
      std::cerr << "Incorrect number of arguments\n";
      return 1;
    }
    std::string number(argv[1]);
    if (number == "1")
    {
      dushechkina::task1(std::cin, std::cout);
    }
    else if (number == "2")
    {
      dushechkina::task2(std::cin, std::cout);
    }
    else
    {
      std::cerr << "Incorrect parametres\n";
      return 1;
    }
  }
  catch (const std::exception& error)
  {
    std::cerr << error.what() << '\n';
    return 2;
  }
}
