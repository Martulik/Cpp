#include <boost/test/unit_test.hpp>
#include <algorithm>
#include "factorial-container.hpp"

BOOST_AUTO_TEST_CASE(IncrementIterator)
{
  shilyaev::FactorialContainer factorialContainer;
  auto factorialIterator = factorialContainer.begin();
  unsigned int expectedFactorial = 1;
  for (unsigned int i = 1; i <= 10; i++) {
    expectedFactorial *= i;
    BOOST_CHECK_EQUAL(expectedFactorial, *factorialIterator++);
  }
  BOOST_CHECK(factorialIterator == factorialContainer.end());
}

BOOST_AUTO_TEST_CASE(DecrementIterator)
{
  shilyaev::FactorialContainer factorialContainer;
  auto factorialIterator = factorialContainer.end();
  unsigned int expectedFactorial = 1;
  for (unsigned int i = 2; i <= 10; i++) {
    expectedFactorial *= i;
  }
  for (unsigned int i = 10; i >= 1; i--) {
    BOOST_CHECK_EQUAL(expectedFactorial, *--factorialIterator);
    expectedFactorial /= i;
  }
  BOOST_CHECK(factorialIterator == factorialContainer.begin());
}
