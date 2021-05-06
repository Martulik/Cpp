#include "Container.hpp"

namespace lab = ezerinia;

lab::Container::Iterator::Iterator():
  index_(1),
  value_(1)
{
}

lab::Container::Iterator lab::Container::begin()
{
  return Iterator();
}

lab::Container::Iterator lab::Container::end()
{
  Iterator temp{};
  std::advance(temp, 10);
  return temp;
}

bool lab::Container::Iterator::operator==(const Container::Iterator &src) const
{
  return index_ == src.index_;
}

bool lab::Container::Iterator::operator!=(const Container::Iterator &src) const
{
  return !(*this == src);
}

lab::Container::value_type &lab::Container::Iterator::operator*()
{
  return value_;
}

lab::Container::value_type *lab::Container::Iterator::operator->()
{
  return &value_;
}

lab::Container::Iterator &lab::Container::Iterator::operator++()
{
  value_ *= ++index_;
  return *this;
}

lab::Container::Iterator &lab::Container::Iterator::operator--()
{
  value_ /= index_--;
  return *this;
}

lab::Container::Iterator lab::Container::Iterator::operator++(int)
{
  Iterator temp = *this;
  value_ *= ++index_;
  return temp;
}

lab::Container::Iterator lab::Container::Iterator::operator--(int)
{
  Iterator temp = *this;
  value_ /= index_--;
  return temp;
}
