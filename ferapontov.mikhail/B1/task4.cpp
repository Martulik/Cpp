#include "tasks.hpp"

#include <random>
#include <iomanip>
#include "functions.hpp"
#include "sort.hpp"
#include "strategy.hpp"

void ferapontov::task4(const std::string& mode, int size)
{
  std::function< bool(double, double) > cmp = getSortMode< double >(mode);
  std::random_device rd;
  std::uniform_int_distribution< > dist(-10, 10);
  std::vector< double > vec(size);
  for (int i = 0; i < size; i++)
  {
    vec[i] = dist(rd) / 10.0;
  }

  print(vec);
  ferapontov::sort< double, ferapontov::at_access< double > >(vec, cmp);
  print(vec);
}
