#include <limits>
#include <boost/test/unit_test.hpp>

#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"

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

void make_bad_circle()
{
  shkurov::Shape* ptr = new shkurov::Circle(CIRCLE_POS, -A);

  ptr++;  // action of no utility to avoid "unused variable" warnings
}

void make_bad_rectangle()
{
  shkurov::Shape* ptr = new shkurov::Rectangle(RECTANGLE_POS, B, -C);

  ptr++;
}

shkurov::Shape* make_circle()
{
  shkurov::Shape* ptr = new shkurov::Circle(CIRCLE_POS, A);\

  return ptr;
}

shkurov::Shape* make_rectangle()
{
  shkurov::Shape* ptr = new shkurov::Rectangle(RECTANGLE_POS, B, C);

  return ptr;
}

shkurov::Shape* make_composite_shape()
{
  shkurov::Shape* circle = new shkurov::Circle(CIRCLE_POS, A);
  shkurov::Shape* rectangle = new shkurov::Rectangle(RECTANGLE_POS, B, C);
  shkurov::Shape* ptr = new shkurov::CompositeShape({circle, rectangle});

  return ptr;
}

void test_move_to_point(shkurov::Shape* shape)
{
  double origin_height = test_utility::getHeight(shape);
  double origin_width = test_utility::getWidth(shape);
  double origin_area = shape->getArea();

  shape->move(FINAL_POS);

  BOOST_CHECK_CLOSE(origin_height, test_utility::getHeight(shape), EPSILON);
  BOOST_CHECK_CLOSE(origin_width, test_utility::getWidth(shape), EPSILON);
  BOOST_CHECK_CLOSE(origin_area, shape->getArea(), EPSILON);
}

void test_scale(shkurov::Shape* shape)
{
  double pred_area = shape->getArea() * K * K;

  shape->scale(K);

  BOOST_CHECK_CLOSE(pred_area, shape->getArea(), EPSILON);
}

void invalid_scale(shkurov::Shape* shape)
{
  shape->scale(-K);
}
