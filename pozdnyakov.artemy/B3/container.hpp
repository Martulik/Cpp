#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include "iterator.hpp"

namespace pozdnyakov
{
  class FactorialContainer
  {
  public:
    using iterator = FactorialIterator;
    FactorialContainer() = default;
    FactorialIterator begin() const;
    FactorialIterator end() const;
  };
}

#endif
