#include "FactorialContainer.hpp"

#include <memory>
#include <cassert>

namespace lab = shkurov;

constexpr unsigned long factorial(unsigned long number)
{
  if (number == 1)
  {
    return 1;
  }
  else
  {
    return factorial(number - 1) * number;
  }
}

const unsigned long* lab::FactorialContainer::Iterator::operator->() const
{
  return std::addressof(value_);
}

const unsigned long& lab::FactorialContainer::Iterator::operator*() const
{
  return value_;
}

lab::FactorialContainer::Iterator& lab::FactorialContainer::Iterator::operator++()
{
  assert(index_ < 11);

  value_ *= ++index_;
  return *this;
}

lab::FactorialContainer::Iterator lab::FactorialContainer::Iterator::operator++(int)
{
  assert(index_ < 11);

  Iterator temp = *this;
  ++(*this);
  return temp;
}

lab::FactorialContainer::Iterator& lab::FactorialContainer::Iterator::operator--()
{
  assert(index_ > 0);

  value_ /= index_--;
  return *this;
}

lab::FactorialContainer::Iterator lab::FactorialContainer::Iterator::operator--(int)
{
  assert(index_ > 0);

  Iterator temp = *this;
  --(*this);
  return temp;
}

bool lab::FactorialContainer::Iterator::operator==(const Iterator& rhs) const
{
  return value_ == rhs.value_;
}

bool lab::FactorialContainer::Iterator::operator!=(const Iterator& rhs) const
{
  return !(*this == rhs);
}

lab::FactorialContainer::Iterator lab::FactorialContainer::begin() const noexcept
{
  return Iterator(factorial(1), 1);
}

lab::FactorialContainer::Iterator lab::FactorialContainer::end() const noexcept
{
  return Iterator(factorial(11), 11);
}

lab::FactorialContainer::Iterator::Iterator(unsigned long value, size_t index):
  value_(value),
  index_(index)
{
}
