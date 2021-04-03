#define BOOST_TEST_MODULE A3

#include <limits>
#include <stdexcept>
#include <boost/test/included/unit_test.hpp>

#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"

void make_bad_circle();
void make_bad_rectangle();
shkurov::Shape* make_circle();
shkurov::Shape* make_rectangle();
shkurov::Shape* make_composite();
void test_move_to_point(shkurov::Shape* shape);
void test_scale(shkurov::Shape* shape);
void invalid_scale(shkurov::Shape* shape);
const double EPSILON = std::numeric_limits< double >::epsilon();

BOOST_AUTO_TEST_SUITE(rectangle_test)

std::unique_ptr< shkurov::Shape > rect_ptr(make_rectangle());

BOOST_AUTO_TEST_CASE(constructor_throw_exception)
{
  BOOST_CHECK_THROW(make_bad_rectangle(), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(move)
{
  test_move_to_point(rect_ptr.get());
}

BOOST_AUTO_TEST_CASE(scale)
{
  test_scale(rect_ptr.get());
}

BOOST_AUTO_TEST_CASE(scale_throw_exception)
{
  BOOST_CHECK_THROW(invalid_scale(rect_ptr.get()), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END();


BOOST_AUTO_TEST_SUITE(circle_test)

std::unique_ptr< shkurov::Shape > circle_ptr(make_circle());

BOOST_AUTO_TEST_CASE(constructor_throw_exception)
{
  BOOST_CHECK_THROW(make_bad_circle(), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(move)
{
  test_move_to_point(circle_ptr.get());
}

BOOST_AUTO_TEST_CASE(scale_correct_modification)
{
  test_scale(circle_ptr.get());
}

BOOST_AUTO_TEST_CASE(scale_throw_exception)
{
  BOOST_CHECK_THROW(invalid_scale(circle_ptr.get()), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END();


BOOST_AUTO_TEST_SUITE(composite_shape_test)

std::unique_ptr< shkurov::Shape > composite_ptr(new shkurov::CompositeShape({make_circle(), make_rectangle()}));

BOOST_AUTO_TEST_CASE(move_semantics)
{
  shkurov::CompositeShape composite({make_circle(), make_rectangle()});
  double origin_area = composite.getArea();
  shkurov::CompositeShape moved_shape(std::move(composite));
  BOOST_CHECK_CLOSE(origin_area, moved_shape.getArea(), EPSILON);

  composite = std::move(moved_shape);
  BOOST_CHECK_CLOSE(origin_area, composite.getArea(), EPSILON);
}

BOOST_AUTO_TEST_CASE(move_correct_center_translocation)
{
  test_move_to_point(composite_ptr.get());
}

BOOST_AUTO_TEST_CASE(scale_correct_modification)
{
  test_scale(composite_ptr.get());
}

BOOST_AUTO_TEST_CASE(scale_throw_exception)
{
  BOOST_CHECK_THROW(invalid_scale(composite_ptr.get()), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END();
