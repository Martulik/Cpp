#ifndef TEST_FUNCTIONS_HPP
#define TEST_FUNCTIONS_HPP

#include "shape.hpp"
#include <memory>

#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"

void makeBadCircle();
void makeBadRectangle();

std::unique_ptr< shkurov::Shape > makeCircle();
std::unique_ptr< shkurov::Shape > makeRectangle();
std::unique_ptr< shkurov::Shape > makeCompositeShape();

void testMoveToPoint(shkurov::Shape* shape);
void testScale(shkurov::Shape* shape);
void invalidScale(shkurov::Shape* shape);

#endif
