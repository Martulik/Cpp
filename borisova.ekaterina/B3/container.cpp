#include "container.hpp"

namespace lab = borisova;

lab::Container::Iterator::Iterator(size_t index):
index_(index),
value_(1)
{
  size_t temp = 1;
  while (temp != index)
  {
    temp++;
    value_ *= temp;
  }
}

lab::Container::Iterator lab::Container::begin()
{
  return Iterator(minimum);
}

lab::Container::Iterator lab::Container::end()
{
  return Iterator(maximum);
}

lab::Container::Iterator& lab::Container::Iterator::operator++()
{
  if (index_ < maximum)
  {
    index_++;
    value_ *= index_;
  }
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
  if (index_ > minimum)
  {
    value_ /= index_;
    index_--;
  }
  return *this;
}

lab::Container::Iterator lab::Container::Iterator::operator--(int)
{
  Iterator temp = *this;
  (*this)--;
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

size_t& lab::Container::Iterator::operator*()
{
  return value_;
}
