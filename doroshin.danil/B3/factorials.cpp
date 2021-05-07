#include "factorials.hpp"

namespace dan = doroshin;

dan::Factorials::value_t dan::Factorials::iterator::operator*() const
{
  return value_;
}

dan::Factorials::iterator& dan::Factorials::iterator::operator++()
{
  value_ *= ++arg_;
  return *this;
}

dan::Factorials::iterator dan::Factorials::iterator::operator++(int)
{
  iterator old_iter = *this;
  operator++();
  return old_iter;
}

dan::Factorials::iterator& dan::Factorials::iterator::operator--()
{
  value_ /= arg_--;
  return *this;
}

dan::Factorials::iterator dan::Factorials::iterator::operator--(int)
{
  iterator old_iter = *this;
  operator--();
  return old_iter;
}

bool dan::operator==(const dan::Factorials::iterator& lhs, const dan::Factorials::iterator& rhs)
{
  return (*lhs == *rhs);
}

bool dan::operator!=(const dan::Factorials::iterator& lhs, const dan::Factorials::iterator& rhs)
{
  return !(lhs == rhs);
}

dan::Factorials::iterator dan::Factorials::begin() const
{
  return iterator(begin_);
}

dan::Factorials::iterator dan::Factorials::end() const
{
  return iterator(end_ + 1);
}
