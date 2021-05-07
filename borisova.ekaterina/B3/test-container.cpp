#include <boost/test/unit_test.hpp>
#include "container.hpp"

BOOST_AUTO_TEST_SUITE(container)

BOOST_AUTO_TEST_CASE(factorial)
{
  using itr = borisova::Container::Iterator;
  borisova::Container container;
  size_t factorial = 1;
  size_t i = 1;
  for (itr iter = container.begin(); iter != container.end(); iter++, i++)
  {
    factorial *= i;
    BOOST_CHECK_EQUAL(*iter, factorial);
  }
}
BOOST_AUTO_TEST_SUITE_END()
