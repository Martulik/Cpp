#ifndef TEST_UTILITY_HPP
#define TEST_UTILITY_HPP

#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"

namespace savchuk
{
  Rectangle makeRect();
  Circle makeCirc();
  CompositeShape makeComposite();
  void checkMoveInvariant(Shape& s, const point_t& p);
  void checkMoveInvariant(Shape& s, double dx, double dy);
  void checkScaleFrameRect(Shape& s, double k);
  void checkScaleArea(Shape& s, double k);
  void checkScaleInvalidArgument(Shape& s, double k);
  void checkCorrectFrameRect(const Shape& s, const rectangle_t& r);
}

#endif
