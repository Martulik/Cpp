#include "test-functions.hpp"

#include <limits>
#include <boost/test/unit_test.hpp>

struct point_t;

const shkurov::point_t CIRCLE_POS = {3, -5};
const shkurov::point_t RECTANGLE_POS = {-8, 1};
const shkurov::point_t FINAL_POS = {0, 4};
const double A = 7.0;
const double B = 10.0;
const double C = 4.0;
const double K = 3.0;
const double EPSILON = std::numeric_limits< double >::epsilon();

namespace test_utility
{
  double getX(const shkurov::Shape* shape)
  {
    return shape->getFrameRect().pos.x;
  }

  double getY(const shkurov::Shape* shape)
  {
    return shape->getFrameRect().pos.y;
  }

  double getHeight(const shkurov::Shape* shape)
  {
    return shape->getFrameRect().height;
  }

  double getWidth(const shkurov::Shape* shape)
  {
    return shape->getFrameRect().width;
  }
}

void makeBadCircle()
{
  shkurov::Circle circle(CIRCLE_POS, -A);
}

void makeBadRectangle()
{
  shkurov::Rectangle rect(RECTANGLE_POS, B, -C);
}

std::unique_ptr< shkurov::Shape > makeCircle()
{
  return std::unique_ptr< shkurov::Shape >(new shkurov::Circle(CIRCLE_POS, A));
}

std::unique_ptr< shkurov::Shape > makeRectangle()
{
  return std::unique_ptr< shkurov::Shape >(new shkurov::Rectangle(RECTANGLE_POS, B, C));
}

std::unique_ptr< shkurov::Shape > makeCompositeShape()
{
  std::unique_ptr< shkurov::Shape > circle(new shkurov::Circle(CIRCLE_POS, A));
  std::unique_ptr< shkurov::Shape > rectangle(new shkurov::Rectangle(RECTANGLE_POS, B, C));

  return std::unique_ptr< shkurov::Shape >(new shkurov::CompositeShape(std::move(circle), std::move(rectangle)));
}

void testMoveToPoint(shkurov::Shape* shape)
{
  double origin_height = test_utility::getHeight(shape);
  double origin_width = test_utility::getWidth(shape);
  double origin_area = shape->getArea();

  shape->move(FINAL_POS);

  BOOST_CHECK_CLOSE(origin_height, test_utility::getHeight(shape), EPSILON);
  BOOST_CHECK_CLOSE(origin_width, test_utility::getWidth(shape), EPSILON);
  BOOST_CHECK_CLOSE(origin_area, shape->getArea(), EPSILON);
}

void testScale(shkurov::Shape* shape)
{
  double pred_area = shape->getArea() * K * K;

  shape->scale(K);

  BOOST_CHECK_CLOSE(pred_area, shape->getArea(), EPSILON);
}

void invalidScale(shkurov::Shape* shape)
{
  shape->scale(-K);
}
