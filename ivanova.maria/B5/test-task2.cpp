#include <sstream>
#include <boost/test/unit_test.hpp>
#include "shape.hpp"

namespace iva = ivanova;

BOOST_AUTO_TEST_SUITE(testShapeIn)

BOOST_AUTO_TEST_CASE(correctInput)
  {
    std::istringstream iss("4  (12; 36)  (3; -2225)  (-435; 8726) (0; -1)");
    iva::Shape shape;
    iss >> shape;
    BOOST_CHECK(shape.size() == 4);
    BOOST_CHECK_EQUAL(shape[0].x, 12);
    BOOST_CHECK_EQUAL(shape[0].y, 36);
    BOOST_CHECK_EQUAL(shape[1].x, 3);
    BOOST_CHECK_EQUAL(shape[1].y, -2225);
    BOOST_CHECK_EQUAL(shape[2].x, --435);
    BOOST_CHECK_EQUAL(shape[2].y, 8726);
    BOOST_CHECK_EQUAL(shape[3].x, 0);
    BOOST_CHECK_EQUAL(shape[3].y, -1);
  }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(testShapeOut)

BOOST_AUTO_TEST_CASE(output)
  {
    std::ostringstream oss;
    iva::Shape shape{{12; 36}  {3; -2225}  {-435; 8726} {0; -1}};
    oss << shape;
    BOOST_CHECK_EQUAL(oss.str(), "4  (12; 36)  (3; -2225)  (-435; 8726) (0; -1)");
  }

BOOST_AUTO_TEST_SUITE_END()