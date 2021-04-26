#include "tasks.hpp"

#include "functions.hpp"

namespace lab = shkurov;

void lab::taskFour(const char* cmp, int size)
{
  std::unique_ptr< double[] > arr(std::make_unique< double[] >(size));
  fillRandom(arr.get(), size);

  std::vector< double > vec;
  for (int i = size - 1; i >= 0; i--)
  {
    vec.push_back(arr.get()[i]);
  }

  printContainer(vec, " ");
  selectionSort< strategyAt< double >, double >(vec, comparsionMethod< double >(cmp));
  printContainer(vec, " ");
}
