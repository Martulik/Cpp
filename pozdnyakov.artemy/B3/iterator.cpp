#include "iterator.hpp"
#include <cassert>

namespace poz = pozdnyakov;

poz::FactorialIterator& poz::FactorialIterator::operator++()
{
  n_++;
  value_ *= n_;
  return (*this);
}

poz::FactorialIterator poz::FactorialIterator::operator++(int)
{
  poz::FactorialIterator temp = (*this);
  ++(*this);
  return temp;
}

poz::FactorialIterator& poz::FactorialIterator::operator--()
{
  value_ /= n_;
  n_--;
  return (*this);
}

poz::FactorialIterator poz::FactorialIterator::operator--(int)
{
  poz::FactorialIterator temp = (*this);
  --(*this);
  return temp;
}

unsigned long& poz::FactorialIterator::operator*()
{
  assert(n_ <= poz::FactorialIterator::MAX_NUM);
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

unsigned long poz::getFactorial(unsigned n)
{
  unsigned long fac = 1;
  for (unsigned i = 1; i <= n; i++)
  {
    fac *= i;
  }
  return fac;
}
