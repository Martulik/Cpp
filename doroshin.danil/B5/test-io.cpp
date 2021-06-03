#include <sstream>
#include <boost/test/unit_test.hpp>
#include "shape.hpp"

namespace dan = doroshin;
namespace test = boost::unit_test;

BOOST_AUTO_TEST_SUITE(Point)

BOOST_AUTO_TEST_CASE(empty)
{
  std::istringstream in("");
  dan::Point p;
  in >> p;
  BOOST_CHECK(in.fail());
}

BOOST_AUTO_TEST_CASE(invalid_x)
{
  std::istringstream in("(abc;1)");
  dan::Point p;
  in >> p;
  BOOST_CHECK(in.fail());
}

BOOST_AUTO_TEST_CASE(invalid_y)
{
  std::istringstream in("(1;abc)");
  dan::Point p;
  in >> p;
  BOOST_CHECK(in.fail());
}

BOOST_AUTO_TEST_CASE(correct)
{
  std::istringstream in("(1;2)");
  dan::Point p;
  in >> p;
  BOOST_CHECK(!in.fail());
  BOOST_CHECK_EQUAL(p, (dan::Point{1,2}));
}

BOOST_AUTO_TEST_CASE(spaces)
{
  std::istringstream in("  ( 1  ; 2 )");
  dan::Point p;
  in >> p;
  BOOST_CHECK(!in.fail());
  BOOST_CHECK_EQUAL(p, (dan::Point{1,2}));
}

BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE(Shape)

BOOST_AUTO_TEST_CASE(not_enough_points)
{
  std::istringstream in("3 (1;1)");
  dan::Shape s;
  in >> s;
  BOOST_CHECK(in.fail());
}

BOOST_AUTO_TEST_CASE(too_many_points)
{
  std::istringstream in("3 (1;1) (2;2) (3;3) (4;4)");
  dan::Shape s;
  in >> s;
  BOOST_CHECK(!in.fail());
  BOOST_CHECK_EQUAL(s.points_.size(), 3);
  BOOST_CHECK_EQUAL(s.points_[0], (dan::Point{1,1}));
  BOOST_CHECK_EQUAL(s.points_[1], (dan::Point{2,2}));
  BOOST_CHECK_EQUAL(s.points_[2], (dan::Point{3,3}));
  in >> s;
  BOOST_CHECK(in.fail());
}

BOOST_AUTO_TEST_CASE(correct)
{
  std::istringstream in("3 (1;1) (2;2) (3;3) a\n");
  dan::Shape s;
  in >> s;
  BOOST_CHECK(!in.fail());
  BOOST_CHECK_EQUAL(s.points_.size(), 3);
  BOOST_CHECK_EQUAL(s.points_[0], (dan::Point{1,1}));
  BOOST_CHECK_EQUAL(s.points_[1], (dan::Point{2,2}));
  BOOST_CHECK_EQUAL(s.points_[2], (dan::Point{3,3}));
}

BOOST_AUTO_TEST_SUITE_END()
