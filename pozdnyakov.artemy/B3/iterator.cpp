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

size_t& poz::FactorialIterator::operator*()
{
  assert(n_ <= poz::FactorialIterator::MAX_NUM);
  return value_;
}

size_t* poz::FactorialIterator::operator->()
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

poz::FactorialIterator::FactorialIterator(size_t n, size_t value):
  n_(n),
  value_(value)
{}

size_t poz::getFactorial(size_t n)
{
  size_t fac = 1;
  for (size_t i = 1; i <= n; i++)
  {
    fac *= i;
  }
  return fac;
}
