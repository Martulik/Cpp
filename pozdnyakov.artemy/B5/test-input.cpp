#include <string>
#include <sstream>
#include <stdexcept>
#include <boost/test/unit_test.hpp>
#include "shape-opers.hpp"

namespace poz = pozdnyakov;

BOOST_AUTO_TEST_SUITE(test_input)

BOOST_AUTO_TEST_CASE(test_point)
{
  std::string str = "(  231  ;   21039 )  ";
  std::stringstream stream;
  stream << str;
  poz::Point point;
  stream >> point;
  poz::Point toComp{231, 21039};
  BOOST_REQUIRE_EQUAL(point.x, toComp.x);
  BOOST_REQUIRE_EQUAL(point.y, toComp.y);
}

BOOST_AUTO_TEST_CASE(test_incorrect_point)
{
  std::string str = "(dw pq;o kd)";
  std::stringstream stream;
  stream << str;
  poz::Point point;
  BOOST_CHECK_THROW(stream >> point, std::exception);
}

BOOST_AUTO_TEST_CASE(test_shape)
{
  std::string str = "3   (1377; -99) (888; 96)  (  322;911)";
  std::stringstream stream;
  stream << str;
  poz::Shape shape;
  stream >> shape;
  poz::Shape toComp{{1377, -99}, {888, 96}, {322, 911}};
  BOOST_REQUIRE_EQUAL(shape, toComp);
}

BOOST_AUTO_TEST_CASE(test_incorrect_shape)
{
  std::string str = "8 (qs;sq) (131;1313) (13;)544";
  std::stringstream stream;
  stream << str;
  poz::Shape shape;
  BOOST_CHECK_THROW(stream >> shape, std::exception);
}

BOOST_AUTO_TEST_SUITE_END()
