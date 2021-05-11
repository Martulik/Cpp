#include "factorials.hpp"
#include <cassert>

namespace dan = doroshin;

dan::Factorials::value_t dan::Factorials::iterator::operator*() const noexcept
{
  return value_;
}

dan::Factorials::iterator::value_type* dan::Factorials::iterator::operator->() noexcept
{
  return &value_;
}

dan::Factorials::iterator& dan::Factorials::iterator::operator++() noexcept
{
  value_t old_val = value_;
  value_ *= ++arg_;
  assert(old_val <= value_);
  return *this;
}

dan::Factorials::iterator dan::Factorials::iterator::operator++(int) noexcept
{
  iterator old_iter = *this;
  operator++();
  return old_iter;
}

dan::Factorials::iterator& dan::Factorials::iterator::operator--() noexcept
{
  value_t old_val = value_;
  value_ /= arg_--;
  assert(old_val >= value_);
  return *this;
}

dan::Factorials::iterator dan::Factorials::iterator::operator--(int) noexcept
{
  iterator old_iter = *this;
  operator--();
  return old_iter;
}

bool dan::operator==(const dan::Factorials::iterator& lhs, const dan::Factorials::iterator& rhs) noexcept
{
  return (*lhs == *rhs);
}

bool dan::operator!=(const dan::Factorials::iterator& lhs, const dan::Factorials::iterator& rhs) noexcept
{
  return !(lhs == rhs);
}

dan::Factorials::iterator dan::Factorials::begin() const noexcept
{
  return iterator(begin_);
}

dan::Factorials::iterator dan::Factorials::end() const noexcept
{
  return iterator(end_ + 1);
}
