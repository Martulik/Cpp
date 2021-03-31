#include <iostream>
#include "composite-shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

void testAll();
void test(borisova::Shape& obj, borisova::point_t& dpos, std::ostream& out, double k);
void print(const borisova::Shape& obj, std::ostream& out);
void printPos(const borisova::Shape& obj, std::ostream& out);
void moving(const borisova::Shape& obj, std::ostream& out);

int main()
{
  testAll();
}

void testAll()
{
  double x = 0.4;
  double y = 2.56;
  double width = 11.5;
  double height = 0.01;
  double dx = 65.03;
  double dy = 0.99;
  double radius = 43.11;
  double coeff = 4.12;
  double extraX = 4.12;
  double extraY = 91.004;

  borisova::point_t point1{ x, y };
  borisova::point_t point2{ dx, dy };
  borisova::point_t point3{ extraX, extraY };

  borisova::Shape* rectangle = new borisova::Rectangle(point1, width, height);
  test(*rectangle, point2, std::cout, coeff);
  delete rectangle;

  borisova::Shape* circle = new borisova::Circle(dx, dy, radius);
  test(*circle, point1, std::cout, coeff);
  delete circle;

  borisova::Shape* compositeShape = new borisova::CompositeShape
  {
    std::make_shared< borisova::Rectangle >(point1, width, height),
    std::make_shared< borisova::Circle >(point1, width),
    std::make_shared< borisova::Rectangle >(point2, width, height),
    std::make_shared< borisova::Circle >(point2, height)
  };
  test(*compositeShape, point3, std::cout, coeff);
  delete compositeShape;
}

void test(borisova::Shape& obj, borisova::point_t& dpos, std::ostream& out, double k)
{
  print(obj, out);
  obj.move(dpos);
  moving(obj, out);
  obj.move(dpos.x, dpos.y);
  moving(obj, out);
  out << "Area is: " << obj.getArea() << '\n';
  obj.scale(k);
  out << "Area after scale on " << k << " is: " << obj.getArea() << '\n';
}

void print(const borisova::Shape& obj, std::ostream& out)
{
  out << "\nShape:\n" << "::Position: ";
  printPos(obj, out);
  out << "\nSpecific: " << obj.getName() << '\n';
}

void printPos(const borisova::Shape& obj, std::ostream& out)
{
  out << obj.getFrameRect().pos.x << ", " << obj.getFrameRect().pos.y << '\n';
}

void moving(const borisova::Shape& obj, std::ostream& out)
{
  out << "Figure moved on: ";
  printPos(obj, out);
}
