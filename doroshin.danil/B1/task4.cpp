#include "task4.hpp"
#include <random>

void doroshin::fillRandom(double* array, size_t size)
{
  std::random_device rd;
  std::default_random_engine gen(rd());
  std::uniform_real_distribution< double > dist(-1.0, 1.0);

  for(size_t i = 0; i < size; ++i) {
    array[i] = dist(gen);
  }
}
