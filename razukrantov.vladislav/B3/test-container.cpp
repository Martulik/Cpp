#include <boost/test/unit_test.hpp>

#include "container.hpp"

BOOST_AUTO_TEST_SUITE(testContainer)

BOOST_AUTO_TEST_CASE(checkFactorial)
{
  razukrantov::Container container;
  razukrantov::Container::Iterator iterator = container.begin();
  size_t factorial = 1;
  for (int i = 1; i < 10; i++)
  {
    factorial *= i;
    BOOST_CHECK(*iterator == factorial);
    iterator++;
  }
}

BOOST_AUTO_TEST_SUITE_END()
