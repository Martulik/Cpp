#include <sstream>
#include <boost/test/unit_test.hpp>
#include "shape.hpp"
#include "point.hpp"

BOOST_AUTO_TEST_SUITE(InputShape)

BOOST_AUTO_TEST_CASE(correctInput)
{
  std::string line = "3 (1;2)  (31  ;3) (-3; 10   )";
  std::istringstream in(line);
  borisova::Shape shape;
  in >> shape;
  BOOST_CHECK_EQUAL(shape.at(0).x, 1);
  BOOST_CHECK_EQUAL(shape.at(0).y, 2);
  BOOST_CHECK_EQUAL(shape.at(1).x, 31);
  BOOST_CHECK_EQUAL(shape.at(1).y, 3);
  BOOST_CHECK_EQUAL(shape.at(2).x, -3);
  BOOST_CHECK_EQUAL(shape.at(2).y, 10);
}

BOOST_AUTO_TEST_CASE(uncorrectInput)
{
  std::string line = "3 (1;2) (31;3)";
  std::istringstream in(line);
  borisova::Shape shape;
  BOOST_CHECK_THROW(in >> shape, std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(correctType)
{
  BOOST_CHECK(isSquare(borisova::Shape{ {0, 0}, {0, 1}, {1, 1}, {1, 0} }));
  BOOST_CHECK(isRectangle(borisova::Shape{ {0, 2}, {0, 4}, {3, 4}, {3, 2} }));
  BOOST_CHECK(isTriangle(borisova::Shape{ {0, 0}, {21, 31}, {55, 10} }));
}

BOOST_AUTO_TEST_SUITE_END()
