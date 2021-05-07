#include "tasks.hpp"

#include <iostream>

#include "sorting.hpp"
#include"functions.hpp"
#include "strategy.hpp"

void razukrantov::task4(const char* order, int size)
{
  std::function< bool(double, double) > compare = getSortOrder< double>(order);
  std::vector< double > vec;
}