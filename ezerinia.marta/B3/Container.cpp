#include "Container.hpp"

Container::Iterator::Iterator(size_t index):
  index_(index),
  value_(getFactorial(index))
{}

Container::Iterator Container::begin()
{
  return Iterator(1);
}

Container::Iterator Container::end()
{
  return Iterator(11);
}

bool Container::Iterator::operator==(const Container::Iterator &src) const
{
  return (value_ == src.value_) && (index_ == src.index_);
}

bool Container::Iterator::operator!=(const Container::Iterator &src) const
{
  return !(*this == src);
}

unsigned int &Container::Iterator::operator*()
{
  return value_;
}

unsigned int *Container::Iterator::operator->()
{
  return &value_;
}

Container::Iterator &Container::Iterator::operator++()
{
  ++index_;
  value_ *= index_;
  return *this;
}

Container::Iterator &Container::Iterator::operator--()
{
  if (index_ > 1) {
    value_ /= index_;
    --index_;
  }
  return *this;
}

Container::Iterator Container::Iterator::operator++(int)
{
  Iterator temp = *this;
  ++(*this);
  return temp;
}

Container::Iterator Container::Iterator::operator--(int)
{
  Iterator temp = *this;
  --(*this);
  return temp;
}

unsigned int Container::Iterator::getFactorial(size_t index) const
{
  if (index <= 1) {
    return 1;
  } else {
    return index * getFactorial(index - 1);
  }
}
