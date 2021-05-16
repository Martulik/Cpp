#include "container.hpp"
#include <cassert>

namespace fer = ferapontov;

fer::Container::Iterator::Iterator():
  index_(0),
  value_(1)
{
}