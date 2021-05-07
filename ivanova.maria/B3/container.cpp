#include "container.hpp"

namespace iva = ivanova;

iva::Container::Iterator iva::Container::begin() const
{
  return {1};
}

iva::Container::Iterator iva::Container::end() const
{
  return {11};
}

iva::Container::Iterator::Iterator(size_t index):
  index_(index),
  value_(factorial(index))
{}

iva::Container::Iterator &iva::Container::Iterator::operator ++()
{
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
  value_ /= index_--;
  return *this;
}

iva::Container::Iterator iva::Container::Iterator::operator --(int)
{
  Iterator iter = *this;
  --(*this);
  return iter;
}

const size_t &iva::Container::Iterator::operator *() const
{
  return value_;
}

bool iva::Container::Iterator::operator ==(const Iterator &other) const
{
  return index_ == other.index_;
}

bool iva::Container::Iterator::operator !=(const Iterator &other) const
{
  return !(*this == other);
}

constexpr int iva::Container::Iterator::factorial(const size_t number)
{
  if (number == 1)
  {
    return 1;
  }
  return number * factorial(number - 1);
}
