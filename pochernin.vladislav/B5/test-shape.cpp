#include <boost/test/unit_test.hpp>

#include "shape.hpp"

BOOST_AUTO_TEST_SUITE(testShape)

  BOOST_AUTO_TEST_CASE(correctInput)
  {
    pochernin::Shape shape;
    std::stringstream stream("3 (123; 456) (111; 222) (333; 444)");
    stream >> shape;
    BOOST_CHECK_EQUAL(shape.size(), 3);
    BOOST_CHECK_EQUAL(shape[0].x, 123);
    BOOST_CHECK_EQUAL(shape[0].y, 456);
    BOOST_CHECK_EQUAL(shape[1].x, 111);
    BOOST_CHECK_EQUAL(shape[1].y, 222);
    BOOST_CHECK_EQUAL(shape[2].x, 333);
    BOOST_CHECK_EQUAL(shape[2].y, 444);
  }

  BOOST_AUTO_TEST_CASE(incorrectInput)
  {
    pochernin::Shape shape;
    std::stringstream stream("3 (123sd;as 0)a ;asd 2 sa");
    BOOST_CHECK_THROW(stream >> shape, std::invalid_argument);
  }

BOOST_AUTO_TEST_SUITE_END()
