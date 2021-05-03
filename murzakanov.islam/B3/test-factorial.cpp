#include <boost/test/unit_test.hpp>

#include "factorial-container.hpp"

#include <algorithm>

size_t getFactorial(int n)
{
  if (n == 0)
  {
    return 1;
  }
  return getFactorial(n - 1) * n;
}

void doTestFactorials()
{
  murzakanov::FactorialContainer container;
  auto it = container.begin();
  for (int i = 1; i < 10; i++)
  {
    BOOST_REQUIRE_EQUAL(getFactorial(i), *it);
    it++;
  }
}

BOOST_AUTO_TEST_SUITE(test_factorial)

  BOOST_AUTO_TEST_CASE(factorials_is_same)
  {
    doTestFactorials();
  }

BOOST_AUTO_TEST_SUITE_END()
