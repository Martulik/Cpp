#include "task4.hpp"
#include <algorithm>
#include <functional>
#include <random>

void doroshin::fillRandom(double* array, size_t size)
{
  std::random_device rd;
  std::default_random_engine gen(rd());
  std::uniform_real_distribution< double > dist(-1.0, 1.0);
  auto random = std::bind(dist, gen);

  std::generate_n(array, size, random);
}
