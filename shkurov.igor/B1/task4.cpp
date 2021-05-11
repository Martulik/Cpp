#include "tasks.hpp"

#include "functions.hpp"

namespace lab = shkurov;

void lab::taskFour(const char* cmp, int size)
{
  std::unique_ptr< double[] > arr(std::make_unique< double[] >(size));
  fillRandom(arr.get(), size);

  std::vector< double > vec(arr.get(), arr.get() + size);

  printContainer(vec, " ");
  std::cout << '\n';
  selectionSort< strategyAt< double >, double >(vec, comparsionMethod< double >(cmp));
  printContainer(vec, " ");
}
