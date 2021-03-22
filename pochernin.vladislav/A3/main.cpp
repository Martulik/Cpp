#include <iostream>
#include <cassert>

#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"

void print(const pochernin::Shape& shape, std::ostream& out);
void print(const pochernin::CompositeShape& compositeShape, std::ostream& out);
bool isPosEqual(const pochernin::Shape& shape, const pochernin::point_t& pos);
bool isPosEqual(const pochernin::CompositeShape& compositeShape, const pochernin::point_t& pos);
void testShape(pochernin::Shape* shape, std::ostream& out, const pochernin::point_t& finishPos);

int main()
{
  const double figureWidth = 100.0;
  const double figureHeight = 1000.0;
  const pochernin::point_t startPos = {10.0, 20.0};
  const pochernin::point_t finishPos = {-100.0, 50.0};

  pochernin::Shape* testRectangle = new pochernin::Rectangle(figureWidth, figureHeight, startPos);
  std::cout << "\nRectangle:\n";
  testShape(testRectangle, std::cout, finishPos);

  pochernin::Shape* testCircle = new pochernin::Circle(figureWidth, startPos);
  std::cout << "\nCircle:\n";
  testShape(testCircle, std::cout, finishPos);

  pochernin::CompositeShape compositeShape;
  testRectangle->move(startPos);
  compositeShape.push_back(std::shared_ptr< pochernin::Shape >(testRectangle));
  compositeShape.push_back(std::shared_ptr< pochernin::Shape >(testCircle));
  std::cout << "\nComposite Shape:\n";
  print(compositeShape, std::cout);
  compositeShape.move(startPos);
  assert(isPosEqual(compositeShape, startPos));
  print(compositeShape, std::cout);
}

void print(const pochernin::Shape& shape, std::ostream& out)
{
  out << "width: " << shape.getFrameRect().width << "\n";
  out << "height: " << shape.getFrameRect().height << "\n";
  out << "pos: " << "(" << shape.getFrameRect().pos.x
      << "; " << shape.getFrameRect().pos.y << ")\n";
  out << "area: " << shape.getArea() << "\n\n";
}

void print(const pochernin::CompositeShape& compositeShape, std::ostream& out)
{
  out << "In Composite Shape:\n";
  for (size_t i = 0; i < compositeShape.size(); i++)
  {
    print(*compositeShape.at(i), std::cout);
  }
  out << "The Composite Shape itself\n";
  out << "width: " << compositeShape.getFrameRect().width << "\n";
  out << "height: " << compositeShape.getFrameRect().height << "\n";
  out << "pos: " << "(" << compositeShape.getFrameRect().pos.x
      << "; " << compositeShape.getFrameRect().pos.y << ")\n";
  out << "area: " << compositeShape.getArea() << "\n";
}

bool isPosEqual(const pochernin::Shape& shape, const pochernin::point_t& pos)
{
  return ((shape.getFrameRect().pos.x == pos.x) && (shape.getFrameRect().pos.y == pos.y));
}

bool isPosEqual(const pochernin::CompositeShape& compositeShape, const pochernin::point_t& pos)
{
  return ((compositeShape.getFrameRect().pos.x == pos.x) && (compositeShape.getFrameRect().pos.y == pos.y));
}

void testShape(pochernin::Shape* shape, std::ostream& out, const pochernin::point_t& finishPos)
{
  print(*shape, out);
  shape->move(finishPos);
  assert(isPosEqual(*shape, finishPos));
  print(*shape, out);
}
