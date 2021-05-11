#include "container.hpp"

namespace poz = pozdnyakov;

poz::FactorialIterator poz::FactorialContainer::begin() const
{
  return poz::FactorialIterator(1, poz::getFactorial(1));
}

poz::FactorialIterator poz::FactorialContainer::end() const
{
  size_t k = 1;
  return poz::FactorialIterator(poz::FactorialIterator::MAX_NUM + k, poz::getFactorial(poz::FactorialIterator::MAX_NUM + 1));
}
