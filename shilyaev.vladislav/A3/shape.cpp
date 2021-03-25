#include "shape.hpp"
#include <stdexcept>

void shilyaev::Shape::scale(double factor)
{
  if (factor < 0.0) {
    throw std::invalid_argument("Scale factor can't be negative");
  }
  scaleInternal(factor);
}
