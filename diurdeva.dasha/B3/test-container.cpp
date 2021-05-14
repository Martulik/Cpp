#include <boost/test/unit_test.hpp>
#include "container.hpp"

BOOST_AUTO_TEST_SUITE(container)

BOOST_AUTO_TEST_CASE(factorial)
{
  diurdeva::Container cont;
  unsigned int factorial = 1;
  int i = 1;
  for (auto iter = cont.begin(); iter != cont.end(); iter++, i++) {
    factorial *= i;
    BOOST_CHECK(*iter == factorial);
  }
}

BOOST_AUTO_TEST_SUITE_END()
