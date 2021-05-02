#include "tasks.hpp"

#include <vector>

#include "comparator.hpp"
#include "strategies.hpp"
#include "sort.hpp"
#include "print.hpp"

int lysenko::task4(const char* order, const char* numberOfArguments)
{
  std::function < bool(const double&, const double&) > comparator  = getComparator< double >(order);

  if (comparator == nullptr)
  {
    std::cerr << "Invalid type of sort";
    return 1;
  }

  int size = 0;

  try
  {
    size = std::atoi(numberOfArguments);
  }

  catch (const std::out_of_range& ex)
  {
    std::cerr << "Task number is too much";
    return 1;
  }

  if (size <= 0)
  {
    std::cerr << "Invalid size of array";
    return 1;
  }

  std::vector< double > myVect(size);

  fillRandom(myVect.data(), size);
  lysenko::print< lysenko::strategyForIndex, std::vector< double > >(myVect, 1);

  lysenko::sortBubble< lysenko::strategyForAt, std::vector< double > >(myVect, comparator);
  lysenko::print< lysenko::strategyForIndex, std::vector< double > >(myVect, 1);

  return 0;
}

void lysenko::fillRandom(double* myVectPointer, int size)
{
  for (int i = 0; i < size; ++i)
  {
    double randomOne = -1.0 + 0.01 * (rand() % 201);
    myVectPointer[i] = randomOne;
  }
}
