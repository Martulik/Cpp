#include "tasks.hpp"

#include <vector>

#include "functions.hpp"
#include "accesses.hpp"

void pochernin::task4(const char* sortingDirection, size_t size)
{
  bool isAscending = pochernin::isAscending(sortingDirection);
  std::vector< double > vec(size);
  pochernin::fillRandom(vec.data(), size);

  pochernin::print(vec, " ");
  pochernin::sort< atAccess< double > >(vec, isAscending);
  pochernin::print(vec, " ");
}
