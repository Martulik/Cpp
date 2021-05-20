#include "container.hpp"

#include <cassert>

#include "functions.hpp"

constexpr unsigned Max = 11;
constexpr unsigned Res = razukrantov::getFactorial(Max);

razukrantov::Container::Iterator::Iterator(const valueType index, unsigned long long value):
  index_(index),
  value_(value)
{
}

razukrantov::Container::Iterator& razukrantov::Container::Iterator::operator++()
{
  assert(index_ < Res);
  ++index_;
  value_ *= index_;
  return *this;
}

razukrantov::Container::Iterator razukrantov::Container::Iterator::operator++(int)
{
  Iterator temp = *this;
  ++(*this);
  return temp;
}

razukrantov::Container::Iterator& razukrantov::Container::Iterator::operator--()
{
  assert(index_ != 1);
  value_ /= index_;
  --index_;
  return *this;
}

razukrantov::Container::Iterator razukrantov::Container::Iterator::operator--(int)
{
  Iterator temp = *this;
  --(*this);
  return temp;
}

const razukrantov::Container::valueType& razukrantov::Container::Iterator::operator*() const
{
  return value_;
}

const razukrantov::Container::valueType* razukrantov::Container::Iterator::operator->() const
{
  return std::addressof(value_);
}
bool razukrantov::Container::Iterator::operator==(const Iterator& other) const
{
  return (value_ == other.value_ && other.index_ == index_);
}

bool razukrantov::Container::Iterator::operator!=(const Iterator& other) const
{
  return !(this->operator==(other));
}

razukrantov::Container::Iterator razukrantov::Container::begin() const noexcept
{
  return Iterator(1, 1);
}

razukrantov::Container::Iterator razukrantov::Container::end() const noexcept
{
  return Iterator(Max, Res);
}
