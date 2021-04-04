#include "shape.hpp"
#include <stdexcept>

namespace curr = lysenko;

void curr::Shape::scale(double k)
{
  if (k < 0)
  {
    throw std::invalid_argument("Negative scale for figure is illegal");
  }
  doScale(k);
}
