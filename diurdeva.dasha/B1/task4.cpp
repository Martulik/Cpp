#include "tasks.hpp"
#include <vector>
#include "tools.hpp"

int diurdeva::task4(const std::function< bool(double, double) > compare, const int size)
{
  std::vector< double > vec(size);
  fillRandom(vec.data(), size);
  print(vec);
  printAndSort< atAccess< double > >(vec, compare);
  return 0;
}
