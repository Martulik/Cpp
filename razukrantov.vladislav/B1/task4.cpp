#include "tasks.hpp"

#include <iostream>

#include "sorting.hpp"
#include"functions.hpp"
#include "strategy.hpp"

void razukrantov::task4(const char* order, int size)
{
  std::function< bool(double, double) > compare = razukrantov::getSortOrder< double>(order);
  std::vector< double > vector(size);
  razukrantov::fillRandom(vector.data(), size);
  razukrantov::print(vector, std::cout);
  razukrantov::sort< razukrantov::atAccess< double >, double >(vector, compare);
  razukrantov::print(vector, std::cout);
}
