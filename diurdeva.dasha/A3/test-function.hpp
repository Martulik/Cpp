#ifndef TEST_FUNCTION_HPP
#define TEST_FUNCTION_HPP

#include "shape.hpp"

const diurdeva::point_t pointCenter = { 3.5, 4.0 };
const double width = 8.0;
const double height = 5.0;
const double radius = 3.0;
const double negativeOptions = -8.0;
const size_t testIndex = 200;
const size_t reserveValue = 10;
const diurdeva::point_t newCenter = { 3.0, 2.0 };
const double accuracy = 0.001;
const double factor = 2.0;

void checkAreaBeforeScale(diurdeva::Shape &shape);
void checkConstOptionsBeforeMoving(diurdeva::Shape &shape);

#endif
