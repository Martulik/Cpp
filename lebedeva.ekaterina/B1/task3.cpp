#include <vector>
#include "tasks.hpp"
#include "functions.hpp"

void lebedeva::doTask3(const int argc)
{
  checkNumOfArgs(argc, 2);
  std::vector< int > inVec;

  int data = 0;
  while (std::cin >> data)
  {
    if (data == 0)
    {
      break;
    }
    inVec.push_back(data);
  }
  if ((data != 0) || (!std::cin.eof() && std::cin.fail()) || std::cin.bad())
  {
    throw(std::runtime_error("Incorrect input in task3\n"));
  }

  std::vector< int >::iterator i = inVec.begin();
  if (1 == inVec.back())
  {
    while (i != inVec.end())
    {
      if (0 == (*i % 2))
      {
        inVec.erase(i);
      }
      else
      {
        ++i;
      }
    }
  }
  if (2 == inVec.back())
  {
    if (0 == (*i % 3))
    {
      inVec.insert(i + 1, 3, 1);
      i += 2;
    }
    else
    {
      ++i;
    }
  }

  print(inVec, std::cout);
}

