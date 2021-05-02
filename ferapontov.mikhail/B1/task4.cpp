#include "tasks.hpp"

#include <random>
#include <iomanip>
#include "functions.hpp"
#include "sort.hpp"
#include "strategy.hpp"

void ferapontov::task4(const char* mode, int size, std::random_device& rd)
{
  std::function< bool(double, double) > cmp = getSortMode< double >(mode);
  std::vector< double > vec(size);
  ferapontov::fillRandom(vec, rd);
  print(vec);
  ferapontov::sort< double, ferapontov::at_access< double > >(vec, cmp);
  print(vec);
}
