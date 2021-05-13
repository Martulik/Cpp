#include "container.hpp"
#include <cassert>

namespace lab = borisova;
using unInt = lab::Container::unInt;

constexpr unInt minimum = 1;
constexpr unInt maximum = 11;

constexpr unInt factorial(unInt index)
{
  unInt temp = 1;
  for (unInt i = 1; i <= index; i++)
  {
    temp *= i;
  }
  return temp;
}

constexpr unInt minValue = factorial(minimum);
constexpr unInt maxValue = factorial(maximum);

lab::Container::Iterator::Iterator():
  index_(0),
  value_(1)
{
}

lab::Container::Iterator::Iterator(unInt value, unInt index):
  index_(index),
  value_(value)
{
}

lab::Container::Iterator lab::Container::begin() const noexcept
{
  return { minValue, minimum };
}

lab::Container::Iterator lab::Container::end() const noexcept
{
  return { maxValue, maximum };
}

lab::Container::Iterator& lab::Container::Iterator::operator++()
{
  assert(index_ < maximum);
  index_++;
  value_ *= index_;
  return *this;
}

lab::Container::Iterator lab::Container::Iterator::operator++(int)
{
  Iterator temp = *this;
  ++(*this);
  return temp;
}

lab::Container::Iterator& lab::Container::Iterator::operator--()
{
  assert(index_ > minimum);
  value_ /= index_--;
  return *this;
}

lab::Container::Iterator lab::Container::Iterator::operator--(int)
{
  Iterator temp = *this;
  --(*this);
  return temp;
}

bool lab::Container::Iterator::operator==(const Iterator& src) const
{
  return (src.value_ == value_ && src.index_ == index_);
}

bool lab::Container::Iterator::operator!=(const Iterator& src) const
{
  return !(*this == src);
}

const unInt& lab::Container::Iterator::operator*()
{
  return value_;
}

const unInt* lab::Container::Iterator::operator->()
{
  return std::addressof(value_);
}
