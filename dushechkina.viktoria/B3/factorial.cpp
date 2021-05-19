#include "factorial.hpp"
#include "util.hpp"
#include <cassert>
#include <iostream>

constexpr unsigned int BEGIN_VALUE = 1;
constexpr unsigned int BEGIN_INDEX = 1;
constexpr unsigned int END_INDEX = 11;

dushechkina::Container::Iterator::Iterator():
  index_(BEGIN_INDEX),
  factorial_(BEGIN_VALUE)
{}

dushechkina::Container::Iterator::Iterator(unsigned int index):
  index_(index)
{
  if (index < BEGIN_INDEX || index > END_INDEX)
  {
    incorrectIndex(std::cout);
  }

  unsigned int value = BEGIN_VALUE;
  for (unsigned int i = BEGIN_INDEX; i <= index; ++i)
  {
    value *= i;
  }
  factorial_ = value;
}

const unsigned int* dushechkina::Container::Iterator::operator->()
{
  assert(index_ >= BEGIN_INDEX);
  return std::addressof(factorial_);
}

const unsigned int& dushechkina::Container::Iterator::operator*()
{
  assert(index_ >= BEGIN_INDEX);
  return factorial_;
}

bool dushechkina::Container::Iterator::operator==(const Iterator& rhs) const
{
  return index_ == rhs.index_;
}

bool dushechkina::Container::Iterator::operator!=(const Iterator& rhs) const
{
  return index_ != rhs.index_;
}

dushechkina::Container::Iterator& dushechkina::Container::Iterator::operator++()
{
  assert(index_ <= END_INDEX);
  ++index_;
  factorial_ *= index_;
  return *this;
}

dushechkina::Container::Iterator dushechkina::Container::Iterator::operator++(int)
{
  assert(index_ <= END_INDEX);
  Iterator temp = *this;
  operator++();
  return temp;
}

dushechkina::Container::Iterator& dushechkina::Container::Iterator::operator--()
{
  assert(index_ >= BEGIN_INDEX);
  factorial_ /= index_;
  --index_;
  return *this;
}

dushechkina::Container::Iterator dushechkina::Container::Iterator::operator--(int)
{
  assert(index_ >= BEGIN_INDEX);
  Iterator temp = *this;
  operator--();
  return temp;
}

dushechkina::Container::Iterator dushechkina::Container::begin() const noexcept
{
  return Iterator(BEGIN_INDEX);
}

dushechkina::Container::Iterator dushechkina::Container::end() const noexcept
{
  return Iterator(END_INDEX);
}
