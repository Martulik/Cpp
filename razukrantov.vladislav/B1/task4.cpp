#include "tasks.hpp"

#include <iostream>

#include "sorting.hpp"
#include "functions.hpp"
#include "strategy.hpp"

void razukrantov::task4(const char* order, int size)
{
  std::function< bool(double, double) > compare = razukrantov::getSortOrder< double>(order);
  std::vector< double > vector(size);
  razukrantov::fillRandom(vector.data(), size);
  razukrantov::print< razukrantov::bracketsAccess< double >, double >(vector, std::cout, " ");
  std::cout << "\n";
  razukrantov::sort< razukrantov::atAccess< double > >(vector, compare);
  razukrantov::print< razukrantov::bracketsAccess< double >, double >(vector, std::cout, " ");
  std::cout << "\n";
}
