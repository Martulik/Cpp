#ifndef TEST_FUNCTION_HPP
#define TEST_FUNCTION_HPP

#include "composite-shape.hpp"
#include <boost/test/unit_test.hpp>

const double delta = 0.5;
void testScale(pozdnyakov::UniqueShape shape);
void testMove(pozdnyakov::UniqueShape shape);
pozdnyakov::UniqueShape makeRect(double width, double height, pozdnyakov::point_t pos);
pozdnyakov::UniqueShape makeCircle(double rad, pozdnyakov::point_t pos);
pozdnyakov::UniqueShape makeCompositeShape();

#endif
