#include "container.hpp"
#include <cassert>
#include "functions.hpp"

namespace fer = ferapontov;

constexpr unsigned int SIZE = 10;
constexpr size_t MAX_INDEX = 11;

fer::Container::Iterator::Iterator():
  index_(0),
  value_(1)
{
}

fer::Container::Iterator::Iterator(size_t index, valueType value):
  index_(index),
  value_(value)
{
}
fer::Container::Iterator& fer::Container::Iterator::operator++()
{
  assert(index_ < MAX_INDEX && "<OUT OF RANGE>\n");
  index_ += 1;
  value_ *= index_;
  return *this;
}

fer::Container::Iterator& fer::Container::Iterator::operator--()
{
  assert(index_ != 1 && "<OUT OF RANGE>\n");
  value_ /= index_;
  index_ -= 1;
  return *this;
}

fer::Container::Iterator fer::Container::Iterator::operator++(int)
{
  Iterator temp = *this;
  ++(*this);
  return temp;
}

fer::Container::Iterator fer::Container::Iterator::operator--(int)
{
  Iterator temp = *this;
  --(*this);
  return temp;
}

const fer::Container::valueType& fer::Container::Iterator::operator*() const
{
  return value_;
}

const fer::Container::valueType* fer::Container::Iterator::operator->() const
{
  return std::addressof(value_);
}

bool fer::Container::Iterator::operator==(const Iterator& it) const
{
  return index_ == it.index_;
}

bool fer::Container::Iterator::operator!=(const Iterator& it) const
{
  return index_ != it.index_;
}

fer::Container::Iterator fer::Container::begin() const noexcept
{
  return Iterator(1, 1);
}

fer::Container::Iterator fer::Container::end() const noexcept
{
  return Iterator(11, fer::getFarctorial(MAX_INDEX));
}
