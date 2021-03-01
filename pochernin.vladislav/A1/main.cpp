#include <iostream>
#include <cassert>

#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

void print(const Shape& shape, std::ostream& out);
bool isPosEqual(const Shape& shape, const point_t& pos);

int main()
{
  const double figureWidth = 100.0;
  const double figureHeight = 1000.0;
  const point_t startPos = {10.0, 20.0};
  const point_t deltaPos = {-110.0, 30.0};
  const point_t finishPos = {-100.0, 50.0};

  Shape* testRectangle = new Rectangle (figureWidth, figureHeight, startPos);
  std::cout << "\nRectangle:\n";
  print(*testRectangle, std::cout);
  testRectangle->move(deltaPos.x, deltaPos.y);
  assert(isPosEqual(*testRectangle, finishPos));
  print(*testRectangle, std::cout);

  Shape* testCircle = new Circle (figureWidth, startPos);
  std::cout << "\nCircle:\n";
  print(*testCircle, std::cout);
  testCircle->move(finishPos);
  assert(isPosEqual(*testCircle, finishPos));
  print(*testCircle, std::cout);

  delete testRectangle;
  delete testCircle;
}

void print(const Shape& shape, std::ostream& out)
{
  out << "-------------------------------------------\n";
  out << "width: " << shape.getFrameRect().width << "\n";
  out << "height: " << shape.getFrameRect().height << "\n";
  out << "pos: " << "(" << shape.getFrameRect().pos.x
      << "; " << shape.getFrameRect().pos.y << ")\n";
  out << "area: " << shape.getArea() << "\n";
  out << "-------------------------------------------\n";
}

bool isPosEqual(const Shape& shape, const point_t& pos)
{
  return ((shape.getFrameRect().pos.x == pos.x) && (shape.getFrameRect().pos.y == pos.y));
}
