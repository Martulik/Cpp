#include "counter.hpp"
#include "ostream"

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

void ferapontov::Counter::print(std::ostream& out)
{
  out << "Vertices: " << this->vertices << '\n';
  out << "Triangles: " << this->triangels << '\n';
  out << "Squares: " << this->squares << '\n';
  out << "Rectangles: " << this->rectangles << '\n';
}
