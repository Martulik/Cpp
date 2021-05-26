#include <boost/test/unit_test.hpp>
#include "container.hpp"

namespace poz = pozdnyakov;

BOOST_AUTO_TEST_CASE(test_factorial)
{
  poz::FactorialContainer cont;
  poz::FactorialContainer::iterator begin = cont.begin();
  unsigned long factor = 1;
  for (unsigned i = 1; i < 11; i++)
  {
    factor *= i;
    BOOST_REQUIRE_EQUAL(factor, *begin);
    begin++;
  }
}
