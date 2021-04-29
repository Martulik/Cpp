#include "base-types.hpp"

namespace poz = pozdnyakov;

double poz::getMinX(poz::rectangle_t rect)
{
  return rect.pos.x - rect.width / 2;
}

double poz::getMaxX(poz::rectangle_t rect)
{
  return rect.pos.x + rect.width / 2;
}

double poz::getMinY(poz::rectangle_t rect)
{
  return rect.pos.y - rect.height / 2;
}

double poz::getMaxY(poz::rectangle_t rect)
{
  return rect.pos.y + rect.height / 2;
}
