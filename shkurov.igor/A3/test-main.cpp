#define BOOST_TEST_MODULE A3

#include <boost/test/included/unit_test.hpp>
#include <stdexcept>

#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"

const shkurov::point_t BEGIN_POS = {2.0, -5.5};
const shkurov::point_t END_POS = {-3.5, 8};
const double LENGTH_1 = 9.0;
const double LENGTH_2 = 4.0;
// const double NEGATIVE_LENGTH = -2.0;
const double SCALE = 4;
const double NEGATIVE_SCALE = -2;
const double EPSILON = std::numeric_limits< double >::epsilon();
const double PI = 3.1415;
const double RECT_AREA = LENGTH_1 * LENGTH_2;
const double CIRCLE_AREA = PI * LENGTH_1 * LENGTH_1;

BOOST_AUTO_TEST_SUITE(rectangle_test)

std::unique_ptr< shkurov::Shape > rect_ptr(new shkurov::Rectangle(BEGIN_POS, LENGTH_1, LENGTH_2));

// BOOST_AUTO_TEST_CASE(constructor_throw_exception)
// {
//   BOOST_CHECK_THROW(std::unique_ptr< shkurov::Shape >
//    rect_ptr2(new shkurov::Rectangle(BEGIN_POS, NEGATIVE_LENGTH, LENGTH_2)), std::invalid_argument);
// }

BOOST_AUTO_TEST_CASE(move_correct_center_translocation)
{
  rect_ptr->move(END_POS);
  BOOST_CHECK_CLOSE(RECT_AREA, rect_ptr->getArea(), EPSILON);
  BOOST_CHECK_CLOSE(END_POS.x, rect_ptr->getFrameRect().pos.x, EPSILON);
  BOOST_CHECK_CLOSE(END_POS.y, rect_ptr->getFrameRect().pos.y, EPSILON);
}

BOOST_AUTO_TEST_CASE(scale_correct_modification)
{
  rect_ptr->scale(SCALE);
  BOOST_CHECK_CLOSE(LENGTH_1 * SCALE, rect_ptr->getFrameRect().height, EPSILON);
  BOOST_CHECK_CLOSE(LENGTH_2 * SCALE, rect_ptr->getFrameRect().width, EPSILON);
  BOOST_CHECK_CLOSE(SCALE * SCALE * RECT_AREA, rect_ptr->getArea(), EPSILON);
}

BOOST_AUTO_TEST_CASE(scale_throw_exception)
{
  BOOST_CHECK_THROW(rect_ptr->scale(NEGATIVE_SCALE), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END();


BOOST_AUTO_TEST_SUITE(circle_test)

std::unique_ptr< shkurov::Shape > circle_ptr(new shkurov::Circle(BEGIN_POS, LENGTH_1));

// BOOST_AUTO_TEST_CASE(constructor_throw_exception)
// {
//   BOOST_CHECK_THROW(std::unique_ptr< shkurov::Shape >
//    circle_ptr2(new shkurov::Circle(BEGIN_POS, NEGATIVE_LENGTH)), std::invalid_argument);
// }

BOOST_AUTO_TEST_CASE(move_correct_center_translocation)
{
  circle_ptr->move(END_POS);
  BOOST_CHECK_CLOSE(CIRCLE_AREA, circle_ptr->getArea(), EPSILON);
  BOOST_CHECK_CLOSE(END_POS.x, circle_ptr->getFrameRect().pos.x, EPSILON);
  BOOST_CHECK_CLOSE(END_POS.y, circle_ptr->getFrameRect().pos.y, EPSILON);
}

BOOST_AUTO_TEST_CASE(scale_correct_modification)
{
  circle_ptr->scale(SCALE);
  BOOST_CHECK_CLOSE(LENGTH_1 * SCALE, circle_ptr->getFrameRect().height / 2, EPSILON);
  BOOST_CHECK_CLOSE(SCALE * SCALE * CIRCLE_AREA, circle_ptr->getArea(), EPSILON);
}

BOOST_AUTO_TEST_CASE(scale_throw_exception)
{
  BOOST_CHECK_THROW(circle_ptr->scale(NEGATIVE_SCALE), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END();


BOOST_AUTO_TEST_SUITE(composite_shape_test)

shkurov::Shape* rect = new shkurov::Rectangle(BEGIN_POS, LENGTH_1, LENGTH_2);
shkurov::Shape* circle = new shkurov::Circle(BEGIN_POS, LENGTH_1);
std::unique_ptr< shkurov::Shape > composite_ptr(new shkurov::CompositeShape({rect, circle}));

BOOST_AUTO_TEST_CASE(move_semantics_check)
{
  double origin_area = composite_ptr->getArea();
  std::unique_ptr< shkurov::Shape > composite_ptr2 = std::move(composite_ptr);
  BOOST_CHECK_CLOSE(origin_area, composite_ptr2->getArea(), EPSILON);
  BOOST_CHECK_EQUAL(composite_ptr, nullptr);

  composite_ptr = std::move(composite_ptr2);
  BOOST_CHECK_CLOSE(origin_area, composite_ptr->getArea(), EPSILON);
  BOOST_CHECK_EQUAL(composite_ptr2, nullptr);
}

BOOST_AUTO_TEST_CASE(move_correct_center_translocation)
{
  double origin_area = RECT_AREA + CIRCLE_AREA;
  composite_ptr->move(END_POS);
  BOOST_CHECK_CLOSE(origin_area, composite_ptr->getArea(), EPSILON);
  BOOST_CHECK_CLOSE(END_POS.x, composite_ptr->getFrameRect().pos.x, EPSILON);
  BOOST_CHECK_CLOSE(END_POS.y, composite_ptr->getFrameRect().pos.y, EPSILON);
}

BOOST_AUTO_TEST_CASE(scale_correct_modification)
{
  double origin_area = RECT_AREA + CIRCLE_AREA;
  composite_ptr->scale(SCALE);
  BOOST_CHECK_CLOSE(RECT_AREA * SCALE * SCALE, rect->getArea(), EPSILON);
  BOOST_CHECK_CLOSE(CIRCLE_AREA * SCALE * SCALE, circle->getArea(), EPSILON);
  BOOST_CHECK_CLOSE(origin_area * SCALE * SCALE, composite_ptr->getArea(), EPSILON);
  BOOST_CHECK_CLOSE(LENGTH_1 * SCALE, rect->getFrameRect().height, EPSILON);
}

BOOST_AUTO_TEST_CASE(scale_throw_exception)
{
  BOOST_CHECK_THROW(composite_ptr->scale(NEGATIVE_SCALE), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END();

