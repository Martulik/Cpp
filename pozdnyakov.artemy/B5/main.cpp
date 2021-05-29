#include <stdexcept>
#include <string>
#include <iostream>
#include "tasks.hpp"

namespace poz = pozdnyakov;

int main(int argc, char* argv[])
{
  try
  {
    if (argc < 2)
    {
      return -2;
    }
    int taskNumber = std::stoi(argv[1]);
    if (argc == 3 && taskNumber == 1)
    {
      poz::task1(std::string(argv[2]));
    }
  }
  catch(std::exception& exc)
  {
    std::cout << exc.what() << '\n';
    return -2;
  }
  return 0;
}
