#include "tasks.hpp"

#include "functions.hpp"
#include "strategies.hpp"

namespace lab = shkurov;

void lab::taskOne(const char* cmp)
{
  std::vector< int > vecOne;

  int x;
  while (std::cin >> x)
  {
    vecOne.push_back(x);
  }

  if (std::cin.fail() && !std::cin.eof())
  {
    throw std::invalid_argument("Incorrect input.");
  }

  std::vector< int > vecTwo(vecOne);
  std::forward_list< int > list(vecOne.begin(), vecOne.end());

  selectionSort< strategyIndex< int > >(vecOne, comparsionMethod< int >(cmp));
  selectionSort< strategyAt< int > >(vecTwo, comparsionMethod< int >(cmp));
  selectionSort< strategyIterator< int > >(list, comparsionMethod< int >(cmp));

  printContainer(vecOne, ' ');
  printContainer(vecTwo, ' ');
  printContainer(list, ' ');
}
