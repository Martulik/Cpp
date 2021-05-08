#include "factorial-container.hpp"
#include <cassert>

namespace shilyaev {
  constexpr unsigned int factorial(unsigned int n)
  {
    return (n <= 1) ? 1 : (n * factorial(n - 1));
  }

  constexpr unsigned int beginLastMultiplier = 1;
  constexpr unsigned int beginValue = factorial(beginLastMultiplier);
  constexpr unsigned int endLastMultiplier = 11;
  constexpr unsigned int endValue = factorial(endLastMultiplier);

  FactorialContainer::Iterator::Iterator(unsigned int value, unsigned int lastMultiplier):
    value_(value),
    lastMultiplier_(lastMultiplier)
  {
  }

  const unsigned int &FactorialContainer::Iterator::operator*() const
  {
    return value_;
  }

  const unsigned int *FactorialContainer::Iterator::operator->() const
  {
    return std::addressof(value_);
  }

  FactorialContainer::Iterator &FactorialContainer::Iterator::operator++()
  {
    assert(lastMultiplier_ < endLastMultiplier);
    value_ *= ++lastMultiplier_;
    return *this;
  }

  FactorialContainer::Iterator FactorialContainer::Iterator::operator++(int)
  {
    Iterator temp = *this;
    ++(*this);
    return temp;
  }

  FactorialContainer::Iterator &FactorialContainer::Iterator::operator--()
  {
    assert(lastMultiplier_ > beginLastMultiplier);
    value_ /= lastMultiplier_--;
    return *this;
  }

  FactorialContainer::Iterator FactorialContainer::Iterator::operator--(int)
  {
    Iterator temp = *this;
    --(*this);
    return temp;
  }

  bool operator==(const FactorialContainer::Iterator &a, const FactorialContainer::Iterator &b)
  {
    return *a == *b;
  }

  bool operator!=(const FactorialContainer::Iterator &a, const FactorialContainer::Iterator &b)
  {
    return !(a == b);
  }

  FactorialContainer::Iterator FactorialContainer::begin() const
  {
    return {beginValue, beginLastMultiplier};
  }

  FactorialContainer::Iterator FactorialContainer::end() const
  {
    return {endValue, endLastMultiplier};
  }
}
