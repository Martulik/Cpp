#include "Container.hpp"
#include <cassert>

namespace lab = ezerinia;

constexpr lab::Container::value_type lab::getFactorial(size_t index)
{
  return index <= 1 ? 1 : getFactorial(index - 1) * index;
}

constexpr size_t minIndex = 1;
constexpr lab::Container::value_type minFactorial = lab::getFactorial(minIndex);
constexpr size_t maxIndex = 11;
constexpr lab::Container::value_type maxFactorial = lab::getFactorial(maxIndex);

lab::Container::Iterator::Iterator():
  index_(0),
  value_(0)
{
}

lab::Container::Iterator::Iterator(size_t index, value_type value):
  index_(index),
  value_(value)
{
}

lab::Container::Iterator lab::Container::begin() const noexcept
{
  return {minIndex, minFactorial};
}

lab::Container::Iterator lab::Container::end() const noexcept
{
  return {maxIndex, maxFactorial};
}

bool lab::Container::Iterator::operator==(const Container::Iterator &src) const
{
  return index_ == src.index_;
}

bool lab::Container::Iterator::operator!=(const Container::Iterator &src) const
{
  return !(*this == src);
}

const lab::Container::value_type &lab::Container::Iterator::operator*() const
{
  assert(value_ != 0);
  return value_;
}

const lab::Container::value_type *lab::Container::Iterator::operator->() const
{
  assert(value_ != 0);
  return std::addressof(value_);
}

lab::Container::Iterator &lab::Container::Iterator::operator++()
{
  assert(index_ <= maxIndex);
  value_ *= ++index_;
  return *this;
}

lab::Container::Iterator &lab::Container::Iterator::operator--()
{
  assert(index_ >= minIndex);
  value_ /= index_--;
  return *this;
}

lab::Container::Iterator lab::Container::Iterator::operator++(int)
{
  Iterator temp = *this;
  ++(*this);
  return temp;
}

lab::Container::Iterator lab::Container::Iterator::operator--(int)
{
  Iterator temp = *this;
  --(*this);
  return temp;
}
