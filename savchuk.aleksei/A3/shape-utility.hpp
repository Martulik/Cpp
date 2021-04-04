#ifndef SHAPE_UTILITY_HPP
#define SHAPE_UTILITY_HPP

#include "shape.hpp"
#include "composite-shape.hpp"

namespace savchuk
{
  double getWidth(const Shape&);
  double getHeight(const Shape&);
  double getPosX(const Shape&);
  double getPosY(const Shape&);
  void swap(CompositeShape&, CompositeShape&);
}

#endif
