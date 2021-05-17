#include "tasks.hpp"
#include <vector>
#include "functions.hpp"

void lebedeva::doTask3(std::istream& in, std::ostream& out)
{
  std::vector< int > inVec;

  int data = 0;
  while (in >> data)
  {
    if (data == 0)
    {
      break;
    }
    inVec.push_back(data);
  }
  if ((data != 0) || (!in.eof() && in.fail()) || in.bad())
  {
    throw(std::runtime_error("Incorrect input in task3\n"));
  }

  if (inVec.empty())
  {
    return;
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
  else if (inVec.back() == 2)
  {
    while (i != inVec.end())
    {
      if ((*i % 3) == 0)
      {
        i = inVec.insert(++i, 3, 1);
        i += 2;
      }
      else
      {
        ++i;
      }
    }
  }

  print(inVec, out, " ", 1);
}

