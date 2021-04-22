#include "tasks.hpp"

int lysenko::task3()
{
  int currOne = 1;

  std::vector< int > myVect;

  while (currOne != 0)
  {
    std::cin >> currOne;
    if (currOne == 0)
    {
      std::cerr << "Input can not be empty";
      return 1;
    }
    myVect.push_back(currOne);
  }

  if (myVect.back() == 1)
  {
    std::vector< int >::iterator iterator = myVect.begin();
    while (iterator < myVect.end())
    {
      if (*iterator % 2 != 0)
      {
        myVect.erase(iterator);
      }
      iterator += 1;
    }
  }
  else if (myVect.back() == 2)
  {
    std::vector<int>::iterator iterator = myVect.begin();
    while (iterator < myVect.end())
    {
      if (*iterator % 3 == 0)
      {
        for (int i = 1; i < 3; ++i)
        {
          iterator += 1;
          myVect.insert(iterator, 1);
        }
      }
      iterator += 1;
    }
  }
  else
  {
    std::cerr << "Invalid last item";
    return 1;
  }

  lysenko::print< lysenko::strategyForIndex, std::vector< int > >(myVect, 1);

  return 0;
}
