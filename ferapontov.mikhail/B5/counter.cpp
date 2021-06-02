#include "counter.hpp"
#include <ostream>

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

std::ostream& ferapontov::operator<<(std::ostream& out, Counter& counter)
{
  std::ostream::sentry sentry(out);
  if (sentry)
  {
    out << "Vertices: " << counter.vertices << '\n';
    out << "Triangles: " << counter.triangels << '\n';
    out << "Squares: " << counter.squares << '\n';
    out << "Rectangles: " << counter.rectangles << '\n';
  }
  return out;
}
