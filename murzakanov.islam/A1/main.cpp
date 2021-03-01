#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

void print(std::ostream & out, const Shape& shp)
{
  out << "Shape:\n" <<"::Position: " << "(" << shp.getFrameRect().pos.x
      << ", " << shp.getFrameRect().pos.y << ")";
  out << "\nSpecific: " << shp.getName() << "\n\n";
}


int main(){
  Shape* polyRectangle = new Rectangle(1, 2, { 3, 5 });
  Shape* polyCircle = new Circle(5.25, { 13, -12 });
  print(std::cout, *polyRectangle);
  print(std::cout, *polyCircle);

  point_t newPoint({ 15, 23 });
  polyRectangle->move(newPoint);
  std::cout << "Rectangle's info after move()\n";
  print(std::cout, *polyRectangle);

  double dx = -3.5;
  double dy = -1.8;
  polyCircle->move(dx, dy);
  std::cout<< "Circle's info after move()\n";
  print(std::cout, *polyCircle);

  delete polyRectangle;
  delete polyCircle;
  return 0;
}
