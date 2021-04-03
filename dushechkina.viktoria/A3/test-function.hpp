#ifndef TEST_FUNCTION_HPP
#define TEST_FUNCTION_HPP

#include <boost/test/unit_test.hpp>
#include "shape.hpp"

namespace dushechkina
{
 void checkBeforeScale(Shape* shape);
 void checkBeforeCenterMoving(Shape* shape);
 void checkBeforeDMoving(Shape* shape);
}

#endif
