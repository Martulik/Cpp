#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include "iterator.hpp"

namespace pozdnyakov
{
  class FactorialContainer
  {
  public:
    using iterator = FactorialIterator;
    using const_iterator = const FactorialIterator;
    FactorialContainer() = default;
    const_iterator cbegin() const noexcept;
    const_iterator cend() const noexcept;
  };
}

#endif
