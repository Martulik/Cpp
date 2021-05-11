#include "random-engine.hpp"

std::default_random_engine& getRandomEngine()
{
  static std::default_random_engine engine(std::random_device{}());
  return engine;
}
