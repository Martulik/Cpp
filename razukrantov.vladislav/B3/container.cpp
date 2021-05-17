#include "container.hpp"

#include <cassert>

#include "functions.hpp"

constexpr size_t MAX_SIZE = 11;

razukrantov::Container::Iterator::Iterator(const size_t index):
  index_(index),
  value_(razukrantov::getFactorial(index))
{
}

razukrantov::Container::Iterator& razukrantov::Container::Iterator::operator++()
{
  assert(index_ < MAX_SIZE);
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

size_t& razukrantov::Container::Iterator::operator*()
{
  return value_;
}

size_t* razukrantov::Container::Iterator::operator->()
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
  return Iterator(1);
}

razukrantov::Container::Iterator razukrantov::Container::end() const noexcept
{
  return Iterator(MAX_SIZE);
}
