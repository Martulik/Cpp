#include "iterator.hpp"
#include <cassert>

namespace poz = pozdnyakov;

poz::FactorialIterator::FactorialIterator():
  n_(0),
  value_(0)
{}

poz::FactorialIterator& poz::FactorialIterator::operator++()
{
  assert(n_ != MAX_NUM + 1);
  n_++;
  value_ *= n_;
  return (*this);
}

poz::FactorialIterator poz::FactorialIterator::operator++(int)
{
  assert(n_ != MAX_NUM + 1);
  poz::FactorialIterator temp = (*this);
  ++(*this);
  return temp;
}

poz::FactorialIterator& poz::FactorialIterator::operator--()
{
  assert(n_ != 1);
  value_ /= n_;
  n_--;
  return (*this);
}

poz::FactorialIterator poz::FactorialIterator::operator--(int)
{
  assert(n_ != 1);
  poz::FactorialIterator temp = (*this);
  --(*this);
  return temp;
}

unsigned long& poz::FactorialIterator::operator*()
{
  assert(n_ != 0);
  return value_;
}

unsigned long* poz::FactorialIterator::operator->()
{
  return std::addressof(value_);
}

bool poz::FactorialIterator::operator==(const poz::FactorialIterator& it) const
{
  return value_ == it.value_;
}

bool poz::FactorialIterator::operator!=(const poz::FactorialIterator& it) const
{
  return !((*this) == it);
}

poz::FactorialIterator::FactorialIterator(unsigned n, unsigned long value):
  n_(n),
  value_(value)
{}
