#include "tasks.hpp"

int lysenko::task3()
{
  size_t numberOfMuplipleOfThree = 0;
  int numberOfOperation = 1;
  int currOne = 1;

  std::vector< int > myVect;

  while (currOne != 0)
  {
    std::cin >> currOne;

    if (std::cin.fail() && (numberOfOperation != 1))
    {
      std::cerr << "Input error";
      return 1;
    }

    if (std::cin.fail() && (numberOfOperation == 1))
    {
      return 0;
    }
     
    myVect.push_back(currOne);

    if (currOne % 3 == 0)
    {
      numberOfMuplipleOfThree += 1;
    }

    numberOfOperation += 1;
  }

  myVect.pop_back();
  numberOfMuplipleOfThree -= 1;

  if (myVect.empty())
  {
    return 0;
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
      else
      {
        iterator += 1;
      }
    }
  }
  else if (myVect.back() == 2)
  {
    std::vector<int>::iterator iterator = myVect.begin();
    myVect.reserve(myVect.size() + numberOfMuplipleOfThree * 3);
    iterator = myVect.begin();
    while (iterator != myVect.end())
    {
      if ((*iterator) % 3 == 0)
      {
        iterator = myVect.insert(++iterator, 3, 1);
        iterator += 3;
      }
      else
      {
        ++iterator;
      }
    }
  }

  lysenko::print< lysenko::strategyForIndex, std::vector< int > >(myVect, 1);

  return 0;
}
