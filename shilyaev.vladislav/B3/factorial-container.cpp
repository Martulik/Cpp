#include "factorial-container.hpp"

namespace shilyaev {
  constexpr unsigned int factorial(unsigned int n)
  {
    return (n <= 1) ? 1 : (n * factorial(n - 1));
  }
  constexpr unsigned int endLastMultiplier = 11;
  constexpr unsigned int endValue = factorial(endLastMultiplier);
  constexpr unsigned int startLastMultiplier = 1;
  constexpr unsigned int startValue = factorial(startLastMultiplier);

  FactorialContainer::Iterator::Iterator(unsigned int value, unsigned int lastMultiplier):
    value_(value),
    lastMultiplier_(lastMultiplier)
  {
  }

  const unsigned int &FactorialContainer::Iterator::operator*() const
  {
    return value_;
  }

  FactorialContainer::Iterator &FactorialContainer::Iterator::operator++()
  {
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
    return a.value_ == b.value_;
  }

  bool operator!=(const FactorialContainer::Iterator &a, const FactorialContainer::Iterator &b)
  {
    return !(a == b);
  }

  FactorialContainer::Iterator FactorialContainer::begin() const
  {
    return {startValue, startLastMultiplier};
  }

  FactorialContainer::Iterator FactorialContainer::end() const
  {
    return {endValue, endLastMultiplier};
  }

}
