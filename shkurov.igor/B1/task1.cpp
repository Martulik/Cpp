#include "tasks.hpp"
#include "functions.hpp"
#include "strategies.hpp"

namespace lab = shkurov;

void lab::taskOne(const char* cmp)
{
  std::vector< int > vecOne {9, 4, 5, 12, 1, 3};
  std::vector< int > vecTwo(vecOne);
  std::forward_list< int > list(vecOne.begin(), vecOne.end());

  selectionSort< strategyIndex< int > >(vecOne, comparsionMethod< int >(cmp));
  selectionSort< strategyAt< int > >(vecTwo, comparsionMethod< int >(cmp));
  selectionSort< strategyIterator< int > >(list, comparsionMethod< int >(cmp));

  printContainer(vecOne, ' ');
  printContainer(vecTwo, ' ');
  printContainer(list, ' ');
}
