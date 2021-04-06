#include <iostream>

#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"

namespace vika = dushechkina;

using ShapePtr = std::shared_ptr < vika::Shape >;
void printInfoFrameRect(const std::shared_ptr< vika::Shape > f, std::ostream& out)
{
  out << "\nheight = " << vika::getHeight(*f) << ", width = " << vika::getWidth(*f)
      << ", center: { " << vika::getX(*f) << ", " << vika::getY(*f) << " }";
}

void testShape(const std::shared_ptr< vika::Shape > f, std::ostream& out, const vika::point_t& p)
{
  printInfoFrameRect(f, out);
  f->move(p);
  printInfoFrameRect(f, out);
  out << "\n";
}

int main()
{
  try
  {
  const double width = 0.08;
  const double height = 20.48;
  const vika::point_t p1 = { 12.8, 25.6 };
  const vika::point_t p2 = { -8.0, 3.2 };

  ShapePtr rec = std::make_shared< vika::Rectangle >(width, height, p1);
  std::cout << "Rectangle: ";
  testShape(rec, std::cout, p2);

  ShapePtr circle = std::make_shared< vika::Circle >(p1, width);
  std::cout << "\nCircle: ";
  testShape(circle, std::cout, p2);
  circle->move(p1);

  vika::CompositeShape compositeShape(rec);
  compositeShape.pushBack(circle);
  compositeShape.pushBack(std::make_shared< vika::Circle >(p2, height));
  std::cout << "\nComposite Shape: ";
  for (size_t i = 0; i < compositeShape.size(); i++)
  {
    testShape(compositeShape.at(i), std::cout, p2);
  }
  }
  catch (const std::invalid_argument& e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
  catch (const std::out_of_range& e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
  catch (const std::logic_error& e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
}

