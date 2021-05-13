#define BOOST_TEST_MODULE B3
#include <boost/test/included/unit_test.hpp>
#include "container.hpp"

namespace poz = pozdnyakov;

BOOST_AUTO_TEST_CASE(test_factorial)
{
  poz::FactorialContainer cont;
  poz::FactorialContainer::iterator begin = cont.begin();
  size_t factor = 1;
  for (size_t i = 1; i < 11; i++)
  {
    factor *= i;
    BOOST_REQUIRE_EQUAL(factor, *begin);
    begin++;
  }
}
