#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

void print(std::ostream& out, const Shape* shp)
{
  out << "Shape:\n" <<"::Position: " << "(" << shp->getFrameRect().pos.x
      << ", " << shp->getFrameRect().pos.y << ")";
  out << "\nSpecific: " << shp->getName() << "\n\n";
}

void printAfterMove(Shape* shp, const point_t& point, bool isRelative)
{
  if (isRelative)
  {
    shp->move(point.x, point.y);
  }
  else
  {
    shp->move(point);
  }
  std::cout << "Figure's info after move()\n";
  print(std::cout, shp);
}

int main()
{
  Shape* polyRectangle = new Rectangle(1, 2, { 3, 5 });
  Shape* polyCircle = new Circle(5.25, { 13, -12 });
  print(std::cout, polyRectangle);
  print(std::cout, polyCircle);

  point_t point({ 15, 23 });
  printAfterMove(polyRectangle, point, false);
  printAfterMove(polyCircle, point, true);
  delete polyRectangle;
  delete polyCircle;
  return 0;
}
