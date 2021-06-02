#include <iostream>
#include <stdexcept>
#include <cstring>

#include "tasks.hpp"

int main(int argc, char* argv[])
{
  try
  {
    if (argc != 2)
    {
      throw std::invalid_argument("Incorrect atguments count");
    }
    if (!strcmp(argv[1], "1"))
    {
      razukrantov::wordsTask(std::cin, std::cout);
    }
    else if (!strcmp(argv[1], "2"))
    {
      razukrantov::shapeTask(std::cin, std::cout);
    }
    else
    {
      throw std::invalid_argument("Incorrect arguments");
    }
  }
  catch (std::exception& error)
  {
    std::cerr << error.what() << "\n";
    return 1;
  }
}
