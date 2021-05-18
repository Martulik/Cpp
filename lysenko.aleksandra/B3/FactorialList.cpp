#include "FactorialList.h"

#include <cassert>

namespace lysenko
{
  constexpr unsigned int getFactorial(unsigned int index)
  {
    unsigned int res = 1;
    for (unsigned int i = 1; i <= index; i++)
    {
      res *= i;
    }
    return res;
  }
}

lysenko::FactorialList::Iterator::Iterator():
  content_(0),
  index_(0)
{}

lysenko::FactorialList::Iterator::Iterator(unsigned int content, unsigned int index):
  content_(content),
  index_(index)
{}

const unsigned int* lysenko::FactorialList::Iterator::operator->()
{
  assert(index_ > 1);
  return std::addressof(content_);
}

const unsigned int& lysenko::FactorialList::Iterator::operator*()
{
  assert(index_ > 1);
  return content_;
}

lysenko::FactorialList::Iterator& lysenko::FactorialList::Iterator::operator++()
{
  assert((index_ != 11) && (index_ > 1));
  index_++;
  content_ *= index_;

  return *this;
}

lysenko::FactorialList::Iterator& lysenko::FactorialList::Iterator::operator--()
{
  assert(index_ > 1);
  content_ /= index_;
  index_--;

  return *this;
}

lysenko::FactorialList::Iterator lysenko::FactorialList::Iterator::operator++(int)
{
  const Iterator tmp = *this;
  this->operator++();
  return tmp;
}

lysenko::FactorialList::Iterator lysenko::FactorialList::Iterator::operator--(int)
{
  const Iterator tmp = *this;
  this->operator--();
  return tmp;
}

bool lysenko::FactorialList::Iterator::operator==(const lysenko::FactorialList::Iterator& other) const
{
  return content_ == other.content_;
}

bool lysenko::FactorialList::Iterator::operator !=(const lysenko::FactorialList::Iterator& other) const
{
  return !(content_ == other.content_);
}

lysenko::FactorialList::Iterator lysenko::FactorialList::begin() const noexcept
{
  return Iterator(MINIMUM_INDEX,MINIMUM_INDEX);
}

lysenko::FactorialList::Iterator lysenko::FactorialList::end() const noexcept
{
  return Iterator(lysenko::getFactorial(MAXIMUM_INDEX),MAXIMUM_INDEX);
}

lysenko::FactorialList::reverseIterator lysenko::FactorialList::rbegin() const noexcept
{
  return std::make_reverse_iterator(end());
}

lysenko::FactorialList::reverseIterator lysenko::FactorialList::rend() const noexcept
{
  return std::make_reverse_iterator(begin());
}
