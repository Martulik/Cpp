#define BOOST_TEST_MODULE A3

#include <boost/test/unit_test.hpp>
#include <cstdlib>
#include <ctime>
#include "circle.hpp"
#include "rectangle.hpp"
#include "composite_shape.hpp"

BOOST_AUTO_TEST_CASE(sizeImmutabiltyTest)
{
  srand(time(0));
  const TESTS_RANGE = 10000;
  const TESTS_STEP = 2.01;

  for (int i = -TESTS_RANGE; i < 2 * TESTS_RANGE + 1; i+= TESTS_STEP)
  {
    BOOST_REQUIRE();
  }

}
