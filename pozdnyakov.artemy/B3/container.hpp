#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include "iterator.hpp"

namespace pozdnyakov
{
  class FactorialContainer
  {
  public:
    FactorialContainer() = default;
    FactorialIterator begin() const;
    FactorialIterator end() const;
  };
}

#endif

