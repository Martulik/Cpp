#include <iostream>
#include "tools.hpp"
#include "tasks.hpp"

int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    std::cerr << "\nWrong number of arguments\n";
    return 1;
  }

  std::string number = argv[1];

  if (number.length() != 1)
  {
    std::cerr << "\nInvalid argument\n";
    return 1;
  }

  int num = std::atoi(argv[1]);

  if (num == 1)
  {
    borisova::doTask1();
    return 0;
  }
  else if (num == 2)
  {
    borisova::doTask2();
    return 0;
  }
  std::cerr << "\nInvalid argument\n";
  return 1;
}
