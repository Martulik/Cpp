#include "container.hpp"

#include <cassert>

#include "tools.hpp"

namespace lab = savchuk;

constexpr unsigned int CONTAINER_SIZE = 10;

lab::Container::Iterator::Iterator():
  idx_(1),
  value_(1)
{
}

lab::Container::Iterator& lab::Container::Iterator::operator++()
{
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
  assert(idx_ > 1);
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

lab::Container::valueType& lab::Container::Iterator::operator*()
{
  return value_;
}

lab::Container::valueType* lab::Container::Iterator::operator->()
{
  return &value_;
}

lab::Container::Iterator::Iterator(unsigned int idx):
  idx_(idx),
  value_(lab::calcucateFactorial(idx))
{
}

lab::Container::Iterator lab::Container::begin()
{
  return Iterator();
}

lab::Container::Iterator lab::Container::end()
{
  return Iterator(CONTAINER_SIZE + 1);
}
