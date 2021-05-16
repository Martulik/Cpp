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
  if (inVec.back() == 1)
  {
    while (i != inVec.end())
    {
      if ((*i % 2) == 0)
      {
        inVec.erase(i);
      }
      else
      {
        ++i;
      }
    }
  }
  if (inVec.back() == 2)
  {
    while (i != inVec.end())
    {
      if ((*i % 3) == 0)
      {
        i++;
        inVec.emplace(i, 1);
        inVec.emplace(i, 1);
        inVec.emplace(i, 1);
      }
      else
      {
        ++i;
      }
    }
  }

  print(inVec, std::cout, " ");
}

