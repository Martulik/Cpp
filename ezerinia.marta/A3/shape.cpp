#include "shape.hpp"

void ezerinia::Shape::scale(double k)
{
  if (k < 0.0) {
    throw std::invalid_argument("The coefficient of scale must be non-negative");
  }
  doScale(k);
}
