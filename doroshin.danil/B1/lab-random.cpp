#include "lab-random.hpp"

std::random_device doroshin::random::device;

const unsigned int doroshin::random::seed = doroshin::random::device();

const std::default_random_engine doroshin::random::engine(doroshin::random::seed);
