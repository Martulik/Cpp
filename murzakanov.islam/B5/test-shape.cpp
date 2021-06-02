#include <sstream>
#include <boost/test/unit_test.hpp>
#include "shape.hpp"

BOOST_AUTO_TEST_SUITE(test_shape)

  BOOST_AUTO_TEST_CASE(WrongShapeInput)
  {
    std::string line("3 (das;1) (1;4) (5;2)");
    std::stringstream sin(line);
    murzakanov::Shape shp;
    BOOST_CHECK(!(sin >> shp));
  }

BOOST_AUTO_TEST_SUITE_END()
