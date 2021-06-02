#include "tools.hpp"

namespace lab = savchuk;

void lab::ShapeCounter::operator()(const Shape& shape)
{
  vertices += shape.size();
  if (isTriangle(shape))
  {
    ++triangles;
  }
  if (isRectangle(shape))
  {
    ++rectangles;
  }
  if (isSquare(shape))
  {
    ++squares;
  }
}
