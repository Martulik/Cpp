#define BOOST_TEST_MODULE testmain
#include <boost/test/included/unit_test.hpp>
#include "test-functions.hpp"
#include "container.hpp"

BOOST_AUTO_TEST_SUITE(testInterface)

BOOST_AUTO_TEST_CASE(emptyInterface)
{
  std::unique_ptr< lebedeva::Interface > i1 = lebedeva::makeEmptyInterface();
}

BOOST_AUTO_TEST_SUITE_END()

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
