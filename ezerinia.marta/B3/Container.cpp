#include "Container.hpp"

const size_t minIndex = 1;
const size_t maxValue = 11;

namespace lab = ezerinia;

lab::Container::Iterator::Iterator(size_t index):
  index_(index),
  value_(getFactorial(index))
{
}

lab::Container::Iterator lab::Container::begin()
{
  return Iterator(minIndex);
}

lab::Container::Iterator lab::Container::end()
{
  return Iterator(maxValue);
}

bool lab::Container::Iterator::operator==(const Container::Iterator &src) const
{
  return value_ == src.value_ && index_ == src.index_;
}

bool lab::Container::Iterator::operator!=(const Container::Iterator &src) const
{
  return !(*this == src);
}

unsigned int &lab::Container::Iterator::operator*()
{
  return value_;
}

unsigned int *lab::Container::Iterator::operator->()
{
  return &value_;
}

lab::Container::Iterator &lab::Container::Iterator::operator++()
{
  ++index_;
  value_ *= index_;
  return *this;
}

lab::Container::Iterator &lab::Container::Iterator::operator--()
{
  if (index_ > 1) {
    value_ /= index_;
    --index_;
  }
  return *this;
}

lab::Container::Iterator lab::Container::Iterator::operator++(int)
{
  Iterator temp = *this;
  ++(*this);
  return temp;
}

lab::Container::Iterator lab::Container::Iterator::operator--(int)
{
  Iterator temp = *this;
  --(*this);
  return temp;
}

unsigned int lab::Container::Iterator::getFactorial(size_t index) const
{
  if (index <= 1) {
    return 1;
  } else {
    return index * getFactorial(index - 1);
  }
}
