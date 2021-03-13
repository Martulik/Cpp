#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE A3
#include <boost/test/included/unit_test.hpp>
#include "composite-shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

BOOST_AUTO_TEST_SUITE(CompositeShape)
double tolerance = 0.0001;
BOOST_AUTO_TEST_CASE(move_is_correct)
{
  double width = 1,
         height = 2;
  murzakanov::point_t rectPos{1, 2};
  murzakanov::Rectangle rectangle(width, height, rectPos);
  double firstArea = rectangle.getArea();
  rectangle.move(1.5, 2.5);
  BOOST_CHECK_EQUAL(firstArea, rectangle.getArea());
  BOOST_CHECK_EQUAL(width, rectangle.getFrameRect().width);
  BOOST_CHECK_EQUAL(height, rectangle.getFrameRect().height);
}

BOOST_AUTO_TEST_CASE(scale_is_correct)
{
  double width = 1,
         height = 2;
  murzakanov::point_t rectPos{15.2, 13.3};
  murzakanov::Rectangle rectangle(width, height, rectPos);
  double firstArea = rectangle.getArea();
  rectangle.scale(5);
  BOOST_CHECK_CLOSE(firstArea * 5 * 5, rectangle.getArea(), tolerance);
}

BOOST_AUTO_TEST_CASE(incorrect_values)
{
  double radius = -1;
  murzakanov::point_t circlePos{15.2, 13.2};
  BOOST_CHECK_THROW(murzakanov::Circle circle(radius, circlePos), std::invalid_argument);
  double width = -5,
         height = -4;
  murzakanov::point_t rectPos{123.5, -54.3};
  BOOST_CHECK_THROW(murzakanov::Rectangle rectangle(width, height, rectPos), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(push_back)
{
  double width = 2.0,
         height = 3.0;
  murzakanov::point_t pos{1.5, 2.3};
  murzakanov::CompositeShape cmpShp;
  std::shared_ptr< murzakanov::Rectangle > rect;
  rect = std::make_shared< murzakanov::Rectangle >(width, height, pos);
  BOOST_CHECK_NO_THROW(cmpShp.addShape(rect));
}

BOOST_AUTO_TEST_SUITE_END()
