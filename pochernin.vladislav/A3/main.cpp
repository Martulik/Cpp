#include <iostream>

#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

void print(const pochernin::Shape& shape, std::ostream& out);

int main()
{
  pochernin::Shape* testRectangle = new pochernin::Rectangle(50.123, 100.0, {13.10123, 12.20});
  std::cout << "\nRectangle:\n";
  print(*testRectangle, std::cout);
  pochernin::point_t posPoint = {111.0, 222.0};
  testRectangle->move(posPoint);
  print(*testRectangle, std::cout);
  testRectangle->move(9.0, 8.0);
  print(*testRectangle, std::cout);
  testRectangle->scale(3.5);
  print(*testRectangle, std::cout);

  pochernin::Shape* testCircle = new pochernin::Circle(13.1235, {0.0, 0.0});
  std::cout << "\nCircle:\n";
  print(*testCircle, std::cout);
  posPoint = {111.0, 222.0};
  testCircle->move(posPoint);
  print(*testCircle, std::cout);
  testCircle->move(19.0, 38.0);
  print(*testCircle, std::cout);
  testCircle->scale(2.2);
  print(*testCircle, std::cout);

  delete testRectangle;
  delete testCircle;

  return 0;
}

void print(const pochernin::Shape& shape, std::ostream& out)
{
  out << "-------------------------------------------\n";
  out << "width: " << shape.getFrameRect().width << "\n";
  out << "height: " << shape.getFrameRect().height << "\n";
  out << "pos: " << "(" << shape.getFrameRect().pos.x
      << "; " << shape.getFrameRect().pos.y << ")\n";
  out << "area: " << shape.getArea() << "\n";
  out << "-------------------------------------------\n";
}
