#include <iostream>

#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"

void print(const pochernin::Shape& shape, std::ostream& out);
void print(const pochernin::CompositeShape& compositeShape, std::ostream& out);

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

  pochernin::CompositeShape compositeShape;
  compositeShape.push_back(std::shared_ptr<pochernin::Shape>(testRectangle));
  compositeShape.push_back(std::shared_ptr<pochernin::Shape>(testCircle));
  std::cout << "\nComposite Shape\n";
  print(compositeShape, std::cout);
  posPoint = {100, 1000};
  compositeShape.move(posPoint);
  print(compositeShape, std::cout);
  compositeShape.move(50.0, 500.0);
  print(compositeShape, std::cout);
  compositeShape.scale(2);
  print(compositeShape, std::cout);

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

void print(const pochernin::CompositeShape& compositeShape, std::ostream& out)
{
  out << "---------------------------------------------------------------\n";
  out << "In Composite Shape:\n";
  for (size_t i = 0; i < compositeShape.getSize(); i++)
  {
    print(*compositeShape[i], std::cout);
  }
  out << "The Composite Shape itself\n";
  out << "width: " << compositeShape.getFrameRect().width << "\n";
  out << "height: " << compositeShape.getFrameRect().height << "\n";
  out << "pos: " << "(" << compositeShape.getFrameRect().pos.x
      << "; " << compositeShape.getFrameRect().pos.y << ")\n";
  out << "area: " << compositeShape.getArea() << "\n";
  out << "---------------------------------------------------------------\n";
}
