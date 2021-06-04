#include <sstream>
#include <boost/test/unit_test.hpp>
#include "point.hpp"

BOOST_AUTO_TEST_SUITE(TestShape)

BOOST_AUTO_TEST_CASE(testingCorrectWorkDeterminantTriangle)
{
  std::istringstream in("3 (1;1) (-5;27) (0;17)");
  dushechkina::Shape shape;
  in >> shape;
  BOOST_CHECK(dushechkina::isTriangle(shape));
}

BOOST_AUTO_TEST_CASE(testingCorrectWorkDeterminantSquare)
{
  std::istringstream in("4 (1;1) (1;6) (6;1) (6;6)");
  dushechkina::Shape shape;
  in >> shape;
  BOOST_CHECK(dushechkina::isSquare(shape));
  BOOST_CHECK(dushechkina::isRectangle(shape));
}

BOOST_AUTO_TEST_CASE(testingCorrectWorkDeterminantRectangle)
{
  std::istringstream in("4 (1;1) (1;5) (10;1) (10;5)");
  dushechkina::Shape shape;
  in >> shape;
  BOOST_CHECK(dushechkina::isRectangle(shape));
}

BOOST_AUTO_TEST_CASE(Pentagon)
{
  std::istringstream in("5 (1;1) (7; 9) (10;1) (4 ;5) (13; 7)");
  dushechkina::Shape shape;
  in >> shape;
  BOOST_CHECK(dushechkina::isPentagon(shape));
}

BOOST_AUTO_TEST_CASE(testingCorrectWorkInput)
{
  std::string line = "4 (0;1) (2;3) (4;5) (6;7)";
  std::istringstream in(line);
  dushechkina::Shape shape;
  in >> shape;
  BOOST_CHECK_EQUAL(shape[0].x, 0);
  BOOST_CHECK_EQUAL(shape[0].y, 1);
  BOOST_CHECK_EQUAL(shape[1].x, 2);
  BOOST_CHECK_EQUAL(shape[1].y, 3);
  BOOST_CHECK_EQUAL(shape[2].x, 4);
  BOOST_CHECK_EQUAL(shape[2].y, 5);
  BOOST_CHECK_EQUAL(shape[3].x, 6);
  BOOST_CHECK_EQUAL(shape[3].y, 7);
}

BOOST_AUTO_TEST_SUITE_END()
