#include "counter.hpp"

void ferapontov::Counter::operator()(const Shape& shp)
{
  vertices += shp.size();
  if (isTriangle(shp))
  {
    triangels += 1;
  }
  else if (isRectangle(shp))
  {
    rectangles += 1;
    if (isSquare(shp))
    {
      squares += 1;
    }
  }
}