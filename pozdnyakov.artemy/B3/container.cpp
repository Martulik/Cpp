#include "container.hpp"

namespace poz = pozdnyakov;

poz::FactorialContainer::const_iterator poz::FactorialContainer::begin() const noexcept
{
  return poz::FactorialIterator(1, poz::getFactorial(1));
}

poz::FactorialContainer::const_iterator poz::FactorialContainer::end() const noexcept
{
  unsigned k = 1;
  using fIterator = poz::FactorialIterator;
  return fIterator(fIterator::MAX_NUM + k, poz::getFactorial(fIterator::MAX_NUM + 1));
}
