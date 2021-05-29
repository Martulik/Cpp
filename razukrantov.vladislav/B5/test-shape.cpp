#include <sstream>
#include <boost/test/unit_test.hpp>

#include "shape.hpp"

BOOST_AUTO_TEST_SUITE(testShape)

BOOST_AUTO_TEST_CASE(correctInput)
{
  std::stringstream stream("3 (10; 12) (20; 22) (-1; 12)\n");
  razukrantov::Shape shape;
  stream >> shape;
  BOOST_CHECK(shape.size() == 3);
  BOOST_CHECK_EQUAL(shape[0].x, 10);
  BOOST_CHECK_EQUAL(shape[0].y, 12);
  BOOST_CHECK_EQUAL(shape[1].x, 20);
  BOOST_CHECK_EQUAL(shape[1].y, 22);
  BOOST_CHECK_EQUAL(shape[2].x, -1);
  BOOST_CHECK_EQUAL(shape[2].y, 12);
}

BOOST_AUTO_TEST_CASE(incorrectInput)
{
  razukrantov::Shape shape;
  std::stringstream stream("3 (10; 12) (20;22)");
  BOOST_CHECK_THROW(stream >> shape, std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(incorrectInput2)
{
  razukrantov::Shape shape;
  std::stringstream stream("3 (10; 12) (20; \n 22) (-1; 12)");
  BOOST_CHECK_THROW(stream >> shape, std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(output)
{
  razukrantov::Shape shape = {{10, 12}, {20, 22}, {-1, 12}};
  std::string str = "3 (10; 12) (20; 22) (-1; 12) ";
  std::ostringstream out;
  out << shape;
  BOOST_CHECK_EQUAL(str, out.str());
}

BOOST_AUTO_TEST_SUITE_END()
