#include "shape.hpp"
#include "stdexcept"

namespace lab = savchuk;

void lab::Shape::scale(double scaleFactor)
{
  if (scaleFactor <= 0)
  {
    throw std::invalid_argument("The scale factor must be positive");
  }
  doScale(scaleFactor);
}
