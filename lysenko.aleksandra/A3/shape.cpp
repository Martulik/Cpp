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

double lysenko::getX(std::shared_ptr< const Shape > src)
{
  return src->getFrameRect().pos.x;
}

double lysenko::getY(std::shared_ptr< const Shape > src)
{
  return src->getFrameRect().pos.y;
}

double lysenko::getWidth(std::shared_ptr< const Shape > src)
{
  return src->getFrameRect().width;
}

double lysenko::getHeight(std::shared_ptr< const Shape > src)
{
  return src->getFrameRect().height;
}
