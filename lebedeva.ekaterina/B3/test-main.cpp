#define BOOST_TEST_MODULE mytests
#include <boost/test/included/unit_test.hpp>
#include "container.hpp"

BOOST_AUTO_TEST_SUITE(testContainer)
BOOST_AUTO_TEST_CASE(factorialTest)
{
  lebedeva::Container factContainer;
  using Type = lebedeva::Container::valueType;
  using iter = lebedeva::Container::Iterator;
  Type elem = 1;
  Type factorial = 1;
  for (iter i = factContainer.begin(); i != factContainer.end(); i++)
  {
    factorial *= elem++;
    BOOST_CHECK_EQUAL(*i, factorial);
  }
}
BOOST_AUTO_TEST_SUITE_END()
