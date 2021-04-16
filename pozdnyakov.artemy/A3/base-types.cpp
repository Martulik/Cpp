#include "base-types.hpp"

double pozdnyakov::rectangle_t::getMinX()
{
  return pos.x - width / 2;
}

double pozdnyakov::rectangle_t::getMaxX()
{
  return pos.x + width / 2;
}

double pozdnyakov::rectangle_t::getMinY()
{
  return pos.y - height / 2;
}

double pozdnyakov::rectangle_t::getMaxY()
{
  return pos.y + height / 2;
}
