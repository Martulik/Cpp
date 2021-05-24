#include "container.hpp"
#include <cassert>

namespace lebedeva
{
  const Container::valueType MAX = 11;
  const Container::valueType MIN = 1;

  constexpr Container::valueType factorial(const Container::valueType i)
  {
    if (i == MIN)
    {
      return 1;
    }
    return i * factorial(i - 1);
  }
}

lebedeva::Container::Iterator::Iterator():
  index_(0),
  value_(1)
{}

lebedeva::Container::Iterator::Iterator(valueType i, valueType value):
  index_(i),
  value_(value)
{}

const lebedeva::Container::valueType* lebedeva::Container::Iterator::operator->()
{
  return std::addressof(value_);
}

const lebedeva::Container::valueType& lebedeva::Container::Iterator::operator*()
{
  return value_;
}

lebedeva::Container::Iterator& lebedeva::Container::Iterator::operator++()
{
  assert(index_ < MAX);
  index_++;
  value_ *= index_;
  return *this;
}

lebedeva::Container::Iterator lebedeva::Container::Iterator::operator++(int)
{
  Iterator iter = *this;
  ++(*this);
  return iter;
}

lebedeva::Container::Iterator& lebedeva::Container::Iterator::operator--()
{
  assert(index_ > MIN);
  value_ /= index_;
  index_--;
  return *this;
}

lebedeva::Container::Iterator lebedeva::Container::Iterator::operator--(int)
{
  Iterator iter = *this;
  --(*this);
  return iter;
}

bool lebedeva::Container::Iterator::operator==(const Iterator& rhs) const
{
  return (index_ == rhs.index_);
}

bool lebedeva::Container::Iterator::operator!=(const Iterator& rhs) const
{
  return (index_ != rhs.index_);
}

lebedeva::Container::Iterator lebedeva::Container::begin() const noexcept
{
  return { MIN, factorial(MIN) };
}

lebedeva::Container::Iterator lebedeva::Container::end() const noexcept
{
  return { MAX, factorial(MAX) };
}
