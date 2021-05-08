#include <iostream>
#include <stdexcept>

#include "tasks.hpp"
#include "functions.hpp"

int main(int argc, char* argv[])
{
  srand(time(0));
  try
  {
    if ((argc < 2) || (argc > 4))
    {
    throw(std::invalid_argument("Incorrect arguments count"));
    }
    switch (atoi(argv[1]))
    {
    case 1:
      if (argc != 3)
      {
        throw(std::invalid_argument("Incorrect arguments count in task1"));
      }
      razukrantov::task1(argv[2]);
	  break;
    case 2:
      if (argc != 3)
      {
        throw(std::invalid_argument("Incorrect arguments count in task2"));
      }
      razukrantov::task2(argv[2]);
      break;
    case 3:
      if (argc != 2)
      {
        throw(std::invalid_argument("Incorrect arguments count in task3"));
      }
      razukrantov::task3();
      break;
    case 4:
      if (argc != 4)
      {
        throw(std::invalid_argument("Incorrect arguments count in task4"));
      }
      if (razukrantov::isNumber(argv[3]))
      {
        razukrantov::task4(argv[2], atoi(argv[3]));
        break;
      }
      else
      {
        throw(std::invalid_argument("Incorrect argument in task 4"));
      }
    default:
      throw(std::invalid_argument("incorrect number of task"));
      break;
    }
  }
  catch (std::exception& err)
  {
    std::cerr << err.what() << "\n";
    return 1;
  }
  return 0;
}
