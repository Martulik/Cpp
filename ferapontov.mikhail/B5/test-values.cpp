#include <boost/test/unit_test.hpp>

#include <sstream>
#include "shape.hpp"

BOOST_AUTO_TEST_SUITE(TestValues)

BOOST_AUTO_TEST_CASE(Triangle)
{
  std::istringstream line("3 (0;0) (1; 1) (0;1)");
  ferapontov::Shape tr;
  line >> tr;
  BOOST_CHECK(ferapontov::isTriangle(tr));
}

BOOST_AUTO_TEST_CASE(Square)
{
  std::istringstream line("4 (0;0) (1; 1) (0;1) (1 ;0)");
  ferapontov::Shape square;
  line >> square;
  BOOST_CHECK(ferapontov::isSquare(square));
}

BOOST_AUTO_TEST_CASE(Rectangle)
{
  std::istringstream line1("4 (0;0) (1; 1) (0;1) (1 ;0)");
  std::istringstream line2("4 (2340;10) (198; 4561) (-23;1) (-24;43)");
  ferapontov::Shape square;
  ferapontov::Shape rect;
  line1 >> square;
  line2 >> rect;
  BOOST_CHECK(ferapontov::isRectangle(square));
  BOOST_CHECK(ferapontov::isRectangle(rect));
}

BOOST_AUTO_TEST_CASE(Pentagon)
{
  std::istringstream line("5 (860;3) (124; 1345) (023;15) (351 ;0) (12124; 1345)");
  ferapontov::Shape penta;
  line >> penta;
  BOOST_CHECK(ferapontov::isPentagon(penta));
}

BOOST_AUTO_TEST_SUITE_END()
