#include "tasks.hpp"

#include "functions.hpp"
#include "sort.hpp"
#include "strategy.hpp"
#include <random>

void ferapontov::task4(const std::string& mode, int size)
{
  std::function< bool(double, double) > cmp = getSortMode< double >(mode);
  std::vector< double > vec;
  for(int i = 0; i < size + 1; i++)
  {
    std::random_device rd;
    std::uniform_real_distribution< double > dist(-1.0, 1.0);
    vec.push_back(dist(rd));
  }
  ferapontov::sort< double, ferapontov::at_access< double > >(vec, cmp);
  print(vec);
}
