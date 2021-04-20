#ifndef MAIN_UTILITY_HPP
#define MAIN_UTILITY_HPP

#include "shape.hpp"

namespace savchuk
{
  void printFrameRect(const Shape& s);
  void testArea(const Shape& s);
  void testMove(Shape& s, const point_t& p);
  void testMove(Shape& s, double dx, double dy);
  void testScale(Shape& s, double k);
}

#endif
