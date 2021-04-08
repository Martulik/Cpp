#include "factorials.hpp"

namespace dan = doroshin;

dan::Factorials::iterator::iterator(value_type arg):
  arg_(arg),
  value_(1)
{
  for(value_type i = 2; i <= arg_; ++i) {
    value_ *= i;
  }
}

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
  return (lhs.arg_ == rhs.arg_);
}

bool dan::operator!=(const dan::Factorials::iterator& lhs, const dan::Factorials::iterator& rhs)
{
  return !(lhs == rhs);
}

dan::Factorials::Factorials(value_t begin, value_t end):
  begin_(begin),
  end_(end)
{}

dan::Factorials::iterator dan::Factorials::begin()
{
  return iterator(begin_);
}

dan::Factorials::iterator dan::Factorials::end()
{
  return iterator(end_);
}
