#include <iostream>
#include <stdexcept>

#include "tools.hpp"

namespace lab = savchuk;

int main(int argc, const char** argv)
{
  try
  {
    int task = lab::convertToNumber(argv[1]);
    if (task == 1 && argc == 3)
    {
      //lab::doTask1(argv[2]);
    }
    else if (task == 2 && argc == 3)
    {
      //lab::doTask2(argv[2]);
    }
    else if (task == 3 && argc == 2)
    {
      //lab::doTask3();
    }
    else if (task == 4 && argc == 4)
    {
      //lab::doTask4(argv[2], argv[3]);
    }
    else
    {
      throw std::invalid_argument("invalid command line arguments");
    }
  }
  catch (const std::invalid_argument& err)
  {
    std::cerr << err.what();
    return 1;
  }
  catch (...)
  {
    std::cerr << "Oops!.. Something went wrong";
    return 2;
  }
  return 0;
}