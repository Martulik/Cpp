#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE A3
#include <boost/test/included/unit_test.hpp>
#include "composite-shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

double width = 2.0,
       height = 3.0,
       radius = 1.766;
murzakanov::point_t pos{1, 2};
double tolerance = 0.001;

BOOST_AUTO_TEST_SUITE(CompositeShape)
BOOST_AUTO_TEST_CASE(move_is_correct)
{

  murzakanov::Rectangle rectangle(width, height, pos);
  double firstArea = rectangle.getArea();
  rectangle.move(1.5, 2.5);
  BOOST_CHECK_EQUAL(firstArea, rectangle.getArea());
  BOOST_CHECK_EQUAL(width, rectangle.getFrameRect().width);
  BOOST_CHECK_EQUAL(height, rectangle.getFrameRect().height);
}

BOOST_AUTO_TEST_CASE(scale_is_correct)
{
  murzakanov::Rectangle rectangle(width, height, pos);
  double firstArea = rectangle.getArea();
  rectangle.scale(5);
  BOOST_CHECK_CLOSE(firstArea * 5 * 5, rectangle.getArea(), tolerance);
}

BOOST_AUTO_TEST_CASE(incorrect_values)
{
  double radius = -1;
  BOOST_CHECK_THROW(murzakanov::Circle circle(radius, pos), std::invalid_argument);
  double width = -5,
         height = -4;
  murzakanov::point_t rectPos{123.5, -54.3};
  BOOST_CHECK_THROW(murzakanov::Rectangle rectangle(width, height, rectPos), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(addShape)
{
  std::shared_ptr< murzakanov::Circle > circle;
  circle = std::make_shared< murzakanov::Circle >(radius, pos);
  std::shared_ptr< murzakanov::Rectangle > rect;
  rect = std::make_shared< murzakanov::Rectangle >(width, height, pos);
  murzakanov::CompositeShape cmpShp(rect);
  BOOST_CHECK_NO_THROW(cmpShp.addShape(circle));
}

BOOST_AUTO_TEST_CASE(popShape)
{
  std::shared_ptr< murzakanov::Rectangle > rect;
  rect = std::make_shared< murzakanov::Rectangle >(width, height, pos);
  murzakanov::CompositeShape cmpShp(rect);

  BOOST_CHECK_NO_THROW(cmpShp.popShape());
  BOOST_CHECK_THROW(cmpShp.at(0), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
