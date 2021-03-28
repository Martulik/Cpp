#include "shape.hpp"

namespace dan = doroshin;

void dan::Shape::scale(double k)
{
  dan::udouble_t u_k = dan::make_abs(k);
  scaleImpl(u_k);
}

double dan::getX(const dan::Shape& sh)
{
  return sh.getFrameRect().pos.x;
}

double dan::getY(const dan::Shape& sh)
{
  return sh.getFrameRect().pos.y;
}

double dan::getWidth(const dan::Shape& sh)
{
  return sh.getFrameRect().width;
}

double dan::getHeight(const dan::Shape& sh)
{
  return sh.getFrameRect().height;
}
