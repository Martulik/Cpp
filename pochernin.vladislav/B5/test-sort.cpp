#include <boost/test/unit_test.hpp>

#include <ctime>

#include "sort-test-tools.hpp"

BOOST_AUTO_TEST_SUITE(testSort)

  BOOST_AUTO_TEST_CASE(testTest)
  {
    srand(time(0));

    pochernin::ShapePool shapePool = pochernin::getShapePool(0.3);

    shapePool.other = shapePool.other;
    BOOST_CHECK(true);
  }

BOOST_AUTO_TEST_SUITE_END()
