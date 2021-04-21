#include "tasks.hpp"

int lysenko::task3()
{
  unsigned int numberOfMultipleOfThree = 0;
  unsigned int currNumber = 0;
  bool firstSymbol = 1;
  int currOne = 1;
  size_t currCapacity = 1;

  std::unique_ptr< std::vector< int > > myVect = std::make_unique< std::vector< int > >(currCapacity);

  while ((firstSymbol) || (currOne != 0))
  {
    std::cin >> currOne;
    if ((firstSymbol) && (currOne == 0))
    {
      std::cerr << "Input can not be empty";
      return 1;
    }
    if (currOne % 3 == 0)
    {
      numberOfMultipleOfThree += 1;
    }
    if (currNumber < currCapacity)
    {
      myVect->push_back(currOne);
    }
    else
    {
      currCapacity *= 2;
      std::unique_ptr< std::vector < int > > copyOfMyVect = std::make_unique< std::vector < int > >(currCapacity);
      std::vector<int>::iterator iterator = myVect->begin();
      while (iterator < myVect->end())
      {
        copyOfMyVect->push_back(*iterator);
        iterator += 1;
      }
      copyOfMyVect->push_back(currOne);
      swap(copyOfMyVect, myVect);
    }
  }
  if (myVect->back() == 1)
  {
    std::vector<int>::iterator iterator = myVect->begin();
    while (iterator < myVect->end())
    {
      if (*iterator % 2 != 0)
      {
        myVect->erase(iterator);
      }
      iterator += 1;
    }
  }
  else if (myVect->back() == 2)
  {
    currCapacity = currNumber + numberOfMultipleOfThree*3;
    std::unique_ptr< std::vector < int > > copyOfMyVect = std::make_unique< std::vector < int >  >(currCapacity);
    std::vector<int>::iterator iterator = myVect->begin();
    while (iterator < myVect->end())
    {
      copyOfMyVect->push_back(*iterator);
      if (*iterator % 3 == 0)
      {
        for (int i = 1; i < 3; ++i)
        {
          iterator += 1;
          copyOfMyVect->insert(iterator, 1);
        }
      }
    }
    swap(copyOfMyVect, myVect);
  }
  else
  {
    std::cerr << "Invalid last item";
    return 1;
  }
  return 0;
}