#include <iostream>
#include <memory>
#include "composite-shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"



namespace borisova
{
  using sh_ptr = std::shared_ptr< borisova::Shape >;
  void testAll();
  void test(sh_ptr obj, borisova::point_t& dpos, std::ostream& out, double k);
  void print(const sh_ptr obj, std::ostream& out);
  void printPos(const sh_ptr obj, std::ostream& out);
  void moving(const sh_ptr obj, std::ostream& out);
}

int main()
{
  borisova::testAll();
}

void borisova::testAll()
{
  double x = 0.4;
  double y = 2.56;
  double width = 11.5;
  double height = 0.01;
  double dx = 65.03;
  double dy = 0.99;
  double coeff = 4.12;

  borisova::point_t point1{ x, y };
  borisova::point_t point2{ dx, dy };

  borisova::CompositeShape compositeShape
  {
    std::make_shared< borisova::Rectangle >(point1, width, height),
    std::make_shared< borisova::Circle >(point1, width),
    std::make_shared< borisova::Rectangle >(point2, width, height),
    std::make_shared< borisova::Circle >(point2, height)
  };

  for (size_t i = 0; i < compositeShape.getSize(); i++)
  {
    borisova::test(compositeShape.at(i), point1, std::cout, coeff);
  }
}

void borisova::test(sh_ptr obj, borisova::point_t& dpos, std::ostream& out, const double k)
{
  print(obj, out);
  obj->move(dpos);
  moving(obj, out);
  obj->move(dpos.x, dpos.y);
  moving(obj, out);
  out << "Area is: " << obj->getArea() << '\n';
  obj->scale(k);
  out << "Area after scale on " << k << " is: " << obj->getArea() << '\n';
}

void borisova::print(const sh_ptr obj, std::ostream& out)
{
  out << "\nShape:\n" << "::Position: ";
  printPos(obj, out);
  out << "\nSpecific: " << obj->getName() << '\n';
}

void borisova::printPos(const sh_ptr obj, std::ostream& out)
{
  out << getX(*obj) << ", " << getY(*obj) << '\n';
}

void borisova::moving(const sh_ptr obj, std::ostream& out)
{
  out << "Figure moved on: ";
  printPos(obj, out);
}
