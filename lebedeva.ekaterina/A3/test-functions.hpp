#ifndef TEST_FUNCTIONS_HPP
#define TEST_FUNCTIONS_HPP
#include <boost/test/unit_test.hpp>
#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"
#include "test-variables.hpp"

namespace lebedeva
{
  void checkName(std::string expectedName, std::string name);
  void checkFrameRect(const rectangle_t& oldFrameRect, const rectangle_t& newFrameRect);
  void checkScale(Shape& shape, const double k);
  void checkMoveToPoint(Shape& shape, const point_t& newPos);
  void checkMoveAbs(Shape& figure, const point_t& newPos);

  std::unique_ptr< Rectangle > makeRectangle();
  std::unique_ptr< Circle > makeCircle();
  std::unique_ptr< CompositeShape > makeCompositeShape();
}

#endif
