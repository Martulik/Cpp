#include <iostream>
#include <cstring>
#include <stdexcept>

#include "tasks.hpp"

int main(int argc, char* argv[])
{
  try
  {
    if (args != 2)
    {
      throw(std::invalid_argument("incorrect arguments count"));
    }
    if (!std::strcmp(argv[1], "1"))
    {
      //razukrantov::taskPhoneBook();
    }
    else if (!std::strcmp(argv[1], "2"))
    {
      razukrantov::taskFactorial(std::cout);
    }
    else
    {
      throw(std::invalid_argument("incorrect arguments"))
    }
  }
  catch (std::invalid_argument& error)
  {
    std::cerr << error.what() << "\n";
    return 2;
  }

  return 0;
}
