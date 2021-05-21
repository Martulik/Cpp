#include "factorial-container.hpp"
#include <cassert>

namespace shilyaev {
  using ValueType = FactorialContainer::ValueType;

  constexpr ValueType factorial(ValueType n)
  {
    return (n <= 1) ? 1 : (n * factorial(n - 1));
  }

  constexpr ValueType beginLastMultiplier = 1;
  constexpr ValueType beginValue = factorial(beginLastMultiplier);
  constexpr ValueType endLastMultiplier = 11;
  constexpr ValueType endValue = factorial(endLastMultiplier);

  FactorialContainer::Iterator::Iterator():
    value_(0),
    lastMultiplier_(0)
  {
  }

  FactorialContainer::Iterator::Iterator(ValueType value, ValueType lastMultiplier):
    value_(value),
    lastMultiplier_(lastMultiplier)
  {
  }

  const ValueType &FactorialContainer::Iterator::operator*() const
  {
    assert(value_ != 0);
    return value_;
  }

  const ValueType *FactorialContainer::Iterator::operator->() const
  {
    assert(value_ != 0);
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

  FactorialContainer::Iterator FactorialContainer::begin() const noexcept
  {
    return {beginValue, beginLastMultiplier};
  }

  FactorialContainer::Iterator FactorialContainer::end() const noexcept
  {
    return {endValue, endLastMultiplier};
  }
}
