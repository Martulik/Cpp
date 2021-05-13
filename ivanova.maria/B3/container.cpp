#include "container.hpp"
#include <cassert>

namespace iva = ivanova;

constexpr iva::Container::value_type iva::factorial(const size_t number)
{
  if (number <= 1)
  {
    return 1;
  }
  return number * factorial(number - 1);
}

constexpr size_t minNum = 1;
constexpr iva::Container::value_type minFact = iva::factorial(minNum);

constexpr size_t maxNum = 11;
constexpr iva::Container::value_type maxFact = iva::factorial(maxNum);


iva::Container::Iterator iva::Container::begin() const
{
  return {minNum, minFact};
}

iva::Container::Iterator iva::Container::end() const
{
  return {maxNum, maxFact};
}

iva::Container::Iterator::Iterator():
  index_(0),
  value_(0)
{
}

iva::Container::Iterator &iva::Container::Iterator::operator ++()
{
  assert(index_ <= maxNum);
  value_ *= ++index_;
  return *this;
}

iva::Container::Iterator iva::Container::Iterator::operator ++(int)
{
  Iterator iter = *this;
  ++(*this);
  return iter;
}

iva::Container::Iterator &iva::Container::Iterator::operator --()
{
  assert(index_ >= minNum);
  value_ /= index_--;
  return *this;
}

iva::Container::Iterator iva::Container::Iterator::operator --(int)
{
  assert(index_ != minNum);
  Iterator iter = *this;
  --(*this);
  return iter;
}

const size_t &iva::Container::Iterator::operator *() const
{
  assert(value_ != 0);
  return value_;
}

const size_t *iva::Container::Iterator::operator ->() const
{
  assert(value_ != 0);
  return std::addressof(value_);
}

bool iva::Container::Iterator::operator ==(const Iterator &other) const
{
  return index_ == other.index_;
}

bool iva::Container::Iterator::operator !=(const Iterator &other) const
{
  return !(*this == other);
}

ivanova::Container::Iterator::Iterator(size_t index, value_type value):
  index_(index),
  value_(value)
{
}

