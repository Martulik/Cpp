#include "factorials.hpp"

namespace dan = doroshin;

dan::Factorials::value_t dan::Factorials::iterator::operator*() const noexcept
{
  return value_;
}

dan::Factorials::iterator& dan::Factorials::iterator::operator++() noexcept
{
  value_ *= ++arg_;
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
  value_ /= arg_--;
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

dan::Factorials::iterator dan::Factorials::cbegin() const noexcept
{
  return iterator(begin_);
}

dan::Factorials::iterator dan::Factorials::cend() const noexcept
{
  return iterator(end_ + 1);
}
