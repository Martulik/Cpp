#include <iostream>
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

void print(const Shape& shp, std::ostream& out)
{
  out << "width is: " << shp.getFrameRect().width << "\n";
  out << "height is: " << shp.getFrameRect().height << "\n";
  out << "area is: " << shp.getArea() << "\n";
  out << "center is: " << shp.getFrameRect().pos.x << "; "
      << shp.getFrameRect().pos.y << "\n";
}

void test(Shape* shp, std::ostream& out)
{
  out << "test 1:" << "\n";
  shp->move({ 10.5, 11.5 });
  print(*shp, out);
  out << "test 2:" << "\n";
  shp->move(4.5, 7.5);
  print(*shp, out);
}

int main()
{
  point_t point{ 8.5, 7.5 };
  Shape* ownRectangle = new Rectangle(5, 7, point);
  std::cout << "Rectangle characters:" << "\n";
  test(ownRectangle, std::cout);

  point_t point2{ 2.5, 3.5 };
  Shape* ownCircle = new Circle(8, point2);
  std::cout << "Circle characters:" << "\n";
  test(ownCircle, std::cout);

  delete ownRectangle;
  delete ownCircle;
}
