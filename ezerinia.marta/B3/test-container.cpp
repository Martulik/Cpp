#include <boost/test/unit_test.hpp>
#include "Container.hpp"

BOOST_AUTO_TEST_SUITE(container)

  BOOST_AUTO_TEST_CASE(factorials)
  {
    ezerinia::Container container;
    unsigned int factorial = 1;
    int i = 1;
    for (auto iter = container.begin(); iter != container.end(); iter++, i++) {
      factorial *= i;
      BOOST_CHECK(*iter == factorial);
    }
  }

BOOST_AUTO_TEST_SUITE_END()
