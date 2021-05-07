#include "container.hpp"
#include <cassert>

namespace borisova
{
  constexpr size_t minimum = 1;
  constexpr size_t maximum = 11;
}

namespace lab = borisova;

lab::Container::Iterator::Iterator():
  index_(0),
  value_(1)
{
}

lab::Container::Iterator::Iterator(size_t index):
  index_(index),
  value_(factorial(index))
{
}

lab::Container::Iterator lab::Container::begin() const
{
  Iterator iter;
  return iter.getBegin();
}

lab::Container::Iterator lab::Container::end() const
{
  Iterator iter;
  return iter.getEnd();
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
  value_ /= index_;
  index_--;
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

size_t* lab::Container::Iterator::operator->()
{
  return std::addressof(value_);
}

lab::Container::Iterator lab::Container::Iterator::getBegin() const
{
  return Iterator(minimum);
}
lab::Container::Iterator lab::Container::Iterator::getEnd() const
{
  return Iterator(maximum);
}

constexpr size_t lab::Container::Iterator::factorial(size_t index)
{
  size_t temp = 1;
  for (size_t i = 1; i <= index; i++)
  {
    temp *= i;
  }
  return temp;
}
