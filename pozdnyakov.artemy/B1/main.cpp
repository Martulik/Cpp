#include <string>
#include "tasks.hpp"

int main(int argc, char* argv[])
{
  std::string numbers = "1234";
  if (argv[1][0] == numbers.c_str()[0] && argc == 3)
  {
    task1(argv + 2);
  }
  else if (argv[1][0] == numbers.c_str()[1])
  {
    // do task 2
  }
  else if (argv[1][0] == numbers.c_str()[2])
  {
    // do task 3
  }
  else if (argv[1][0] == numbers.c_str()[3])
  {
    // do task 4
  }
  else
  {
    throw -1; // arg exception gmix
  }
}
