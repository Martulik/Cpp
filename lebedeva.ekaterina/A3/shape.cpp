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

double leb::getBorderCoordinate(const rectangle_t frameRect, Direction direction)
{
  double result = 0;
  if (direction == Direction::Right)
  {
    result = frameRect.pos.x + (frameRect.width / 2);
  }
  if (direction == Direction::Left)
  {
    result = frameRect.pos.x - (frameRect.width / 2);
  }
  if (direction == Direction::Top)
  {
    result = frameRect.pos.y + (frameRect.height / 2);
  }
  if (direction == Direction::Bottom)
  {
    result = frameRect.pos.y - (frameRect.height / 2);
  }
  return result;
}
