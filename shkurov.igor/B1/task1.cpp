#include "tasks.hpp"
#include "functions.hpp"
#include "strategies.hpp"

namespace lab = shkurov;

void taskOne(const char* cmp)
{
  std::vector< int > vecOne {9, 4, 5, 12, 1, 3};
  std::vector< int > vecTwo;
  std::forward_list< int > list;

  selectionSort< lab::strategyIndex< int > >(vecOne, comparsionMethod< int >(cmp));
}