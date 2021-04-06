#ifndef TEST_FUNCTION_HPP
#define TEST_FUNCTION_HPP

#include <boost/test/unit_test.hpp>
#include "shape.hpp"

namespace dushechkina
{
 const dushechkina::point_t center = { 1.28, 6.4 };
 const dushechkina::point_t newCenter = { 3.2, 1.28 };
 const size_t index1 = 100;
 const double ratio = 6.4;
 const size_t rValue = 2;
 const double neg = -5.0;
 const double width1 = 1.28;
 const double width2 = 1.6;
 const double height1 = 0.16;
 const double height2 = 2.56;
 const double radius1 = 3.2;
 const double radius2 = 6.4;
 const double X = 3.2;
 const double Y = 2.56;
 const double TOLERANCE = 0.00001;

 void checkBeforeScale(dushechkina::Shape& shape);
 void checkBeforeCenterMoving(dushechkina::Shape& shape);
 void checkBeforeDMoving(dushechkina::Shape& shape);
}

#endif
