#include <stdexcept>
#include "shape.hpp"

namespace leb = lebedeva;

void leb::Shape::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Invalid parameter. Could not scale.");
  }
  doScale(k);
}

double leb::getBorderCoordinate(const rectangle_t frameRect,
  const std::string direction)
{
  if (direction == "right")
  {
    return (frameRect.pos.x + (frameRect.width / 2));
  }
  if (direction == "left")
  {
    return (frameRect.pos.x - (frameRect.width / 2));
  }
  if (direction == "top")
  {
    return (frameRect.pos.y + (frameRect.height / 2));
  }
  if (direction == "bottom")
  {
    return (frameRect.pos.y - (frameRect.height / 2));
  }
  throw std::invalid_argument("Unknown direction.");
}
