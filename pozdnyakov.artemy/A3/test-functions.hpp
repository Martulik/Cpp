#ifndef TEST_FUNCTION_HPP
#define TEST_FUNCTION_HPP

#include "composite-shape.hpp"
#include <boost/test/unit_test.hpp>

const double delta = 0.5;
void testScale(UniqueShape shape);
void testMove(UniqueShape shape);
UniqueShape makeRect();
UniqueShape makeCircle();
UniqueShape makeCompositeShape();

#endif
