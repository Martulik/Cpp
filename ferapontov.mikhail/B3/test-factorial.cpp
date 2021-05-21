#include <boost/test/unit_test.hpp>

#include "container.hpp"

BOOST_AUTO_TEST_SUITE(testFactorial)

BOOST_AUTO_TEST_CASE(fact)
{
  ferapontov::Container container;
  unsigned int factorial = 1;
  ferapontov::Container::Iterator myFactorial = container.begin();
  for(unsigned int i = 1; i < 11; i++)
  {
    factorial *= i;
    BOOST_CHECK_EQUAL(factorial, *myFactorial);
    myFactorial++;
  }
}

BOOST_AUTO_TEST_SUITE_END()
