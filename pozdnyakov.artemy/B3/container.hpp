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
  constexpr unsigned long getFactorial(const unsigned n)
  {
    unsigned long fac = 1;
    for (unsigned i = 1; i <= n; i++)
    {
      fac *= i;
    }
    return fac;
  }
}

#endif
