#include "task4.hpp"
#include <algorithm>
#include <functional>
#include <random>
#include "lab-random.hpp"

void doroshin::fillRandom(double* array, size_t size)
{
  std::uniform_real_distribution< double > dist(-1.0, 1.0);
  auto random = std::bind(dist, random::engine);

  std::generate_n(array, size, random);
}
