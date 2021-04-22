#include "tasks.hpp"

int lysenko::task3()
{
  bool firstOne = 1;
  int currOne = 1;

  std::vector< int > myVect;

  while (currOne != 0)
  {
    if (std::cin.eof())
    {
      std::cerr << "Input can not be empty or not contain 0";
      return 1;
    }
    if (!firstOne)
    {
      myVect.push_back(currOne);
    }
    else
    {
      firstOne = 0;
    }
    std::cin >> currOne;
  }

  if (myVect.empty())
  {
    std::cerr << "Input can not contain only 0";
    return 1;
  }

  std::vector< int >::iterator iterator = myVect.begin();

  if (myVect.back() == 1)
  {
    while (iterator < myVect.end())
    {
      if (*iterator % 2 == 0)
      {
        myVect.erase(iterator);
      }
      iterator += 1;
    }
  }
  else if (myVect.back() == 2)
  {
    while (iterator < myVect.end())
    {
      if (*iterator % 3 == 0)
      {
        for (int i = 1; i < 3; ++i)
        {
          myVect.insert(iterator+i, 1);
        }
        iterator += 3;
      }
      iterator += 1;
    }
  }

  lysenko::print< lysenko::strategyForIndex, std::vector< int > >(myVect, 1);

  return 0;
}
