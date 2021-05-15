#include "factorial-container.hpp"

#include <cstddef>
#include <cassert>

#include "tools.hpp"

namespace mur = murzakanov;
constexpr size_t MAX_INDEX = 11;

mur::FactorialContainer::Iterator::Iterator():
  num_(0),
  value_(1)
{
}

mur::FactorialContainer::Iterator::Iterator(const value_type num, const value_type value):
  num_(num),
  value_(value)
{
}

mur::FactorialContainer::Iterator& mur::FactorialContainer::Iterator::operator++()
{
  assert(num_ < MAX_INDEX && "Out of range\n");
  num_++;
  value_ *= num_;
  return *this;
}

murzakanov::FactorialContainer::Iterator mur::FactorialContainer::Iterator::operator++(int)
{
  Iterator tempIt = *this;
  ++(*this);
  return tempIt;
}

mur::FactorialContainer::Iterator& mur::FactorialContainer::Iterator::operator--()
{
  assert (num_ != 1 && "Out of range\n");
  value_ /= num_;
  num_--;
  return *this;
}

mur::FactorialContainer::Iterator mur::FactorialContainer::Iterator::operator--(int)
{
  Iterator tempIt = *this;
  --(*this);
  return tempIt;
}

const mur::FactorialContainer::value_type& murzakanov::FactorialContainer::Iterator::operator*()
{
  return value_;
}

const mur::FactorialContainer::value_type* murzakanov::FactorialContainer::Iterator::operator->()
{
  return std::addressof(value_);
}

bool murzakanov::FactorialContainer::Iterator::operator==(const Iterator& rhs) const
{
  return (value_ == rhs.value_);
}

bool murzakanov::FactorialContainer::Iterator::operator!=(const Iterator& rhs) const
{
  return !(value_ == rhs.value_);
}

mur::FactorialContainer::Iterator mur::FactorialContainer::begin() const noexcept
{
  return {1, getFactorial(1)};
}

mur::FactorialContainer::Iterator mur::FactorialContainer::end() const noexcept
{
  return {11, getFactorial(MAX_INDEX)};
}
