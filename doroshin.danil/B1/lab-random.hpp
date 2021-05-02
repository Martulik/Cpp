#ifndef LAB_RANDOM_HPP
#define LAB_RANDOM_HPP

#include <random>

namespace doroshin
{
  namespace random
  {
    extern const unsigned int seed;
    extern std::random_device device;
    extern const std::default_random_engine engine;
  }
}

#endif //LAB_RANDOM_HPP
