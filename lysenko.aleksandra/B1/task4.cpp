#include "tasks.hpp"

namespace lysenko
{
  void fillRandom(std::vector < double > myVect, int size);
}
int lysenko::task4(const char* order, const char* numberOfArguments)
{
  int size = std::atoi(numberOfArguments);
  std::vector < double > myVect;

  if (size <= 0)
  {
    std::cerr << "Invalid size of array";
    return 1;
  }

  fillRandom(myVect, size);

  bool (*comparator)(const double&, const double&) = getComparator< double >(order);
  if (comparator == nullptr)
  {
    std::cerr << "Invalid type of sort";
    return 1;
  }
  lysenko::sortBubble< lysenko::strategyForAt, std::vector< double > >(myVect, comparator);
  return 0;
}

void lysenko::fillRandom(std::vector < double > myVect, int size)
{
  for (int i = 0; i < size; ++i)
  {
    double randomOne = -1.0 + 0.01 * (rand() % 201);
    myVect.push_back(randomOne);
  }
}
