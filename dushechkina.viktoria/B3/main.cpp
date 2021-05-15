#include <stdexcept>
#include <iostream>
#include "maps.hpp"

int main(int argc, char* argv[])
{
  try
  {
    if (argc != 2)
    {
      std::cerr << "Incorrect number of arguments\n";
      return 1;
    }
    if (dushechkina::taskNumber.find(argv[1]) == dushechkina::taskNumber.end())
    {
      std::cerr << "Incorrect task number\n";
      return 1;
    }
    dushechkina::taskNumber.at(argv[1])(std::cin, std::cout);
  }
  catch (const std::exception& error)
  {
    std::cerr << error.what() << '\n';
    return 2;
  }
}
