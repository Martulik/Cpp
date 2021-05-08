#include <iostream>
#include <ctime>
#include <functional>
#include <sstream>
#include <stdexcept>

#include "compare.hpp"
#include "tasks.hpp"
#include "functions.hpp"
#include "sort.hpp"

int main(int argc, char* argv[])
{
  srand(time(NULL));
  if ((argc < 2) || (argc > 4))
  {
    std::cerr << "Incorrect arguments provided";
    return 1;
  }
  int taskNum = 0;

  if (dushechkina::checkIsNumber(argv[1]))
  {
    taskNum = std::atoi(argv[1]);
  }
  try
  {
    if (taskNum == 0)
    {
      std::cerr << "Incorrect input of task number";
      return 1;
    }
    else if (taskNum == 1)
    {
      if (argc != 3)
      {
        std::cerr << "Incorrect number of arguments";
        return 1;
      }
      std::function< bool(const int&, const int&) > comparator = dushechkina::getSortingOrder< int >(argv[2]);
      dushechkina::task1(comparator);
    }
    else if (taskNum == 2)
    {
      if (argc != 3)
      {
        std::cerr << "Incorrect number of arguments";
        return 1;
      }
      dushechkina::task2(argv[2]);
    }
    else if (taskNum == 3)
    {
      if (argc != 2)
      {
        std::cerr << "Incorrect number of arguments";
        return 1;
      }
      dushechkina::task3();
    }
    else if (taskNum == 4)
    {
      if (argc != 4)
      {
        std::cerr << "Incorrect number of arguments";
        return 1;
      }
      std::function< bool(double, double) > comparator = dushechkina::getSortingOrder< double >(argv[2]);
      int size = 0;
      std::stringstream stream(argv[3]);
      stream >> size;
      if (!stream.eof())
      {
        std::cerr << "Incorrect input of size";
        return 1;
      }
      dushechkina::task4(comparator, size);
    }
    else
    {
      std::cerr << "Incorrect task number";
      return 1;
    }
  }
  catch (const std::exception& error)
  {
    std::cerr << error.what() << "\n";
    return 1;
  }
  return 0;
}
