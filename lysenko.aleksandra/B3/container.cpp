#include "container.h"

#include <cassert>

lysenko::Container::Iterator::Iterator() :
  content_(1),
  index_(1)
{};

lysenko::Container::Iterator::Iterator(unsigned int index) :
  content_(1),
  index_(index)
{
  for (unsigned int i = 1; i <= index; ++i)
  {
    content_ *= i;
  }
  assert((index >= MINIMUM_INDEX) && (index <= MAXIMUM_INDEX));
}

unsigned int& lysenko::Container::Iterator::operator*()
{
  return content_;
}

lysenko::Container::Iterator& lysenko::Container::Iterator::operator++()
{
  index_++;
  content_ *= index_;

  return *this;
}

lysenko::Container::Iterator& lysenko::Container::Iterator::operator--()
{
  content_ /= index_;
  index_--;

  return *this;
}

lysenko::Container::Iterator lysenko::Container::Iterator::operator++(int)
{
  assert(index_ != 11);
  const Iterator tmp = *this;
  this->operator++();
  return tmp;
}

lysenko::Container::Iterator lysenko::Container::Iterator::operator--(int)
{
  assert(index_ > 1);
  const Iterator tmp = *this;
  this->operator--();
  return tmp;
}

bool lysenko::Container::Iterator::operator==(const lysenko::Container::Iterator& other) const
{
  return content_ == other.content_;
}

bool lysenko::Container::Iterator::operator !=(const lysenko::Container::Iterator& other) const
{
  return !(content_ == other.content_);
}

lysenko::Container::Iterator lysenko::Container::begin() const
{
  return Iterator(MINIMUM_INDEX);
}

lysenko::Container::Iterator lysenko::Container::end() const
{
  return Iterator(MAXIMUM_INDEX);
}

lysenko::Container::reverse_iterator lysenko::Container::rbegin() const
{
  return std::make_reverse_iterator(end());
}

lysenko::Container::reverse_iterator lysenko::Container::rend() const
{
  return std::make_reverse_iterator(begin());
}
