#include <sstream>
#include <boost/test/unit_test.hpp>
#include "shape.hpp"


BOOST_AUTO_TEST_SUITE(test_point)

BOOST_AUTO_TEST_CASE(success_input_point)
{
  std::istringstream istringstream("(3;-3)");
  diurdeva::Point point{};
  istringstream >> point;
  BOOST_CHECK_EQUAL(point.x, 3);
  BOOST_CHECK_EQUAL(point.y, -3);
  BOOST_CHECK(istringstream);
}

BOOST_AUTO_TEST_CASE(wrong_input_point)
{
  std::istringstream in("(-3,-3)");
  diurdeva::Point point{};
  BOOST_CHECK_THROW(in >> point, std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(test_shape)

BOOST_AUTO_TEST_CASE(success_input_shape)
{
  std::istringstream in("3  (13;13)  (13; 45)  (36; 13) ");
  diurdeva::Shape shape;
  in >> shape;
  BOOST_CHECK(shape.size() == 3);
  BOOST_CHECK_EQUAL(shape[0].x, 13);
  BOOST_CHECK_EQUAL(shape[0].y, 13);
  BOOST_CHECK_EQUAL(shape[1].x, 13);
  BOOST_CHECK_EQUAL(shape[1].y, 45);
  BOOST_CHECK_EQUAL(shape[2].x, 36);
  BOOST_CHECK_EQUAL(shape[2].y, 13);
}

BOOST_AUTO_TEST_CASE(wrong_input_shape)
{
  std::istringstream in("3 (13; 13) (13; 45) ");
  diurdeva::Shape shape;
  BOOST_CHECK_THROW(in >> shape, std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(output_shape)
{
  diurdeva::Shape shape = {{13, 13}, {13, 45}, {36, 13}};
  std::string str = "3 (13; 13) (13; 45) (36; 13) ";
  std::ostringstream ostringstream;
  ostringstream << shape;
  BOOST_CHECK_EQUAL(str, ostringstream.str());
}

BOOST_AUTO_TEST_CASE(IsShape)
{
  BOOST_CHECK(isRectangle(diurdeva::Shape{ {0, 2}, {0, 4}, {3, 4}, {3, 2} }));
  BOOST_CHECK(!isRectangle(diurdeva::Shape{ {0, 0}, {0, 4}, {5, 3}, {5, 0} }));
  BOOST_CHECK(isSquare(diurdeva::Shape{ {0, 0}, {0, 2}, {2, 2}, {2, 0} }));
  BOOST_CHECK(!isSquare(diurdeva::Shape{ {0, 0}, {0, 2}, {3, 2}, {3, 0} }));
}

BOOST_AUTO_TEST_SUITE_END()
