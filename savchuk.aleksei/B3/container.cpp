#include "container.hpp"

#include <cassert>
#include <memory>

#include "tools.hpp"

namespace lab = savchuk;

constexpr unsigned int CONTAINER_SIZE = 10;

constexpr unsigned int MAX_IDX = CONTAINER_SIZE + 1;
constexpr unsigned long long MAX_VALUE = lab::calcucateFactorial(MAX_IDX);

lab::Container::Iterator::Iterator():
  idx_(1),
  value_(1)
{
}

lab::Container::Iterator& lab::Container::Iterator::operator++()
{
  assert(idx_ != MAX_IDX);
  ++idx_;
  value_ *= idx_;
  return *this;
}

lab::Container::Iterator lab::Container::Iterator::operator++(int)
{
  Iterator temp = *this;
  operator++();
  return temp;
}

lab::Container::Iterator& lab::Container::Iterator::operator--()
{
  assert(idx_ != 1);
  value_ /= idx_;
  --idx_;
  return *this;
}

lab::Container::Iterator lab::Container::Iterator::operator--(int)
{
  Iterator temp = *this;
  operator--();
  return temp;
}

bool lab::Container::Iterator::operator==(const Iterator& other) const
{
  return idx_ == other.idx_;
}

bool lab::Container::Iterator::operator!=(const Iterator& other) const
{
  return idx_ != other.idx_;
}

const lab::Container::valueType& lab::Container::Iterator::operator*()
{
  return value_;
}

const lab::Container::valueType* lab::Container::Iterator::operator->()
{
  return std::addressof(value_);
}

lab::Container::Iterator::Iterator(unsigned int idx, unsigned long long value):
  idx_(idx),
  value_(value)
{
}

lab::Container::Iterator lab::Container::begin()
{
  return Iterator();
}

lab::Container::Iterator lab::Container::end()
{
  return Iterator(MAX_IDX, MAX_VALUE);
}
