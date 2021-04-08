#ifndef TEST_FUNCTIONS_HPP
#define TEST_FUNCTIONS_HPP

#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"

namespace ferapontov
{
  Rectangle makeRectangle();
  Circle makeCircle();
  CompositeShape makeComposite();

  void test_move(Shape& shp, const point_t& pos);
  void test_move(Shape& shp, double dx, double dy);
  void test_scale(Shape& shp, double k);
  void test_invalid_argument(Shape& shp, double k);
}

#endif