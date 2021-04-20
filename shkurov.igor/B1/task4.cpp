#include "tasks.hpp"

#include "functions.hpp"

namespace lab = shkurov;

void lab::taskFour(const char* cmp, int size)
{
  double *arr = new double[size];
  fillRandom(arr, size);

  std::vector< double > vec;
  for (int i = size - 1; i >= 0; i--)
  {
    vec.push_back(arr[i]);
  }

  printContainer(vec, ' ');
  selectionSort< strategyAt< double >, double >(vec, comparsionMethod< double >(cmp));
  printContainer(vec, ' ');
}
