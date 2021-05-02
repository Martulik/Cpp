#include "random-tools.hpp"
#include <random>

namespace shilyaev {
  std::default_random_engine &getRandomEngine()
  {
    static std::default_random_engine randomEngine(std::random_device{}());
    return randomEngine;
  }

  void fillRandom(double *array, int size)
  {
    std::uniform_real_distribution< double > distribution(-1.0, 1.0);
    for (int i = 0; i < size; i++) {
      array[i] = distribution(getRandomEngine());
    }
  }
}
