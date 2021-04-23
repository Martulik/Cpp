#ifndef TEST_FUNCTION_HPP
#define TEST_FUNCTION_HPP

#include "composite-shape.hpp"
#include <boost/test/unit_test.hpp>

const double delta = 0.5;
void testScale(pozdnyakov::UniqueShape shape);
void testMove(pozdnyakov::UniqueShape shape);
pozdnyakov::UniqueShape makeRect();
pozdnyakov::UniqueShape makeCircle();
pozdnyakov::UniqueShape makeCompositeShape();

#endif
