#include "Container.hpp"
#include <cassert>

namespace lab = ezerinia;

constexpr size_t maxIndex = 11;

lab::Container::Iterator::Iterator():
  index_(1),
  value_(1)
{
}

lab::Container::Iterator::Iterator(size_t index):
  index_(index),
  value_(getFactorial(index))
{
}

lab::Container::Iterator lab::Container::begin()
{
  return Iterator();
}

lab::Container::Iterator lab::Container::end()
{
  return {11};
}

bool lab::Container::Iterator::operator==(const Container::Iterator &src) const
{
  return index_ == src.index_;
}

bool lab::Container::Iterator::operator!=(const Container::Iterator &src) const
{
  return !(*this == src);
}

lab::Container::value_type &lab::Container::Iterator::operator*()
{
  return value_;
}

lab::Container::value_type *lab::Container::Iterator::operator->()
{
  return &value_;
}

lab::Container::Iterator &lab::Container::Iterator::operator++()
{
  assert(index_ != maxIndex);
  value_ *= ++index_;
  return *this;
}

lab::Container::Iterator &lab::Container::Iterator::operator--()
{
  assert(index_ != 1);
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

constexpr lab::Container::value_type lab::Container::Iterator::getFactorial(size_t index)
{
  return index == 1 ? 1 : getFactorial(index - 1) * index;
}
