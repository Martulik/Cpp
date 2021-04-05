#include "shape.hpp"
#include "stdexcept"

void shkurov::Shape::scale(const double k)
{
  if (k < 0)
  {
    throw std::invalid_argument("Exception: scale coefficient must be positive");
  }
  scaleFigure(k);
}