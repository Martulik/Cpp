#ifndef EXTRA_TASK_HPP
#define EXTRA_TASK_HPP

#include "point.hpp"

#include <random>

namespace dushechkina
{
  Shape generateFigure(std::mt19937& rand);
  bool isShapeNotSelfInter(const Shape& shape);
  Shape changeShapeSelfInter(Shape& shape);
}

#endif
