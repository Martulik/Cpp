#include <boost/test/unit_test.hpp>
#include "container.hpp"

namespace iva = ivanova;

BOOST_AUTO_TEST_SUITE(testOfContainerFactorial)

  BOOST_AUTO_TEST_CASE(testWorkWithContainers)
  {
    ivanova::Container cont;
    int i = 1;
    int factorial = 1;
    for (auto it = cont.begin(); it != cont.end(); it++)
    {
      factorial *= i;
      i++;
      BOOST_CHECK_EQUAL(*it, factorial);
    }
  }

BOOST_AUTO_TEST_SUITE_END()
