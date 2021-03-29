#include "shape.hpp"

#include <stdexcept>

void pochernin::Shape::scale(double factor)
{
  if (factor < 0)
  {
    throw(std::invalid_argument("Negative factor"));
  }
  doScale(factor);
}
