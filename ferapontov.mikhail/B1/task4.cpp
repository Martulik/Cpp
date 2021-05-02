#include "tasks.hpp"

#include <random>
#include <iomanip>
#include <memory>
#include "functions.hpp"
#include "sort.hpp"
#include "strategy.hpp"

void ferapontov::task4(const char* mode, int size)
{
  std::function< bool(double, double) > cmp = getSortMode< double >(mode);
  std::vector< double > vec(size);
  ferapontov::fillRandom(std::addressof(vec[0]), size);
  print(vec);
  ferapontov::sort< double, ferapontov::at_access< double > >(vec, cmp);
  print(vec);
}
