#include <iostream>

#include "base-types.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

void printFrameRect(Shape* s);
void testArea(Shape* s);
void testMove(Shape* s, const point_t& p);
void testMove(Shape* s, double dx, double dy);

int main()
{
  Rectangle* rect = new Rectangle({ { 2, 3 }, 7, 5});
  testArea(rect);
  testMove(rect, { 6, -7 });
  testMove(rect, 3.1, 8.6);
  delete rect;

  Circle* circ = new Circle({ { 4, 1 }, 6});
  testArea(circ);
  testMove(circ, { -4, 2 });
  testMove(circ, 5.6, 1.7);
  delete circ;
}

void printFrameRect(Shape* s)
{
  rectangle_t r = s->getFrameRect();
  std::cout << "p = (" << r.pos.x << ", " << r.pos.y << "), ";
  std::cout << "w = " << r.width << ", ";
  std::cout << "h = " << r.height << '\n';
}

void testArea(Shape* s)
{
  std::cout << "area = " << s->getArea() << '\n';
}

void testMove(Shape* s, const point_t& p)
{
  std::cout << "FrameRect before move: ";
  printFrameRect(s);
  s->move(p);
  std::cout << "FrameRect after move: ";
  printFrameRect(s);
}

void testMove(Shape* s, double dx, double dy)
{
  std::cout << "FrameRect before move: ";
  printFrameRect(s);
  s->move(dx, dy);
  std::cout << "FrameRect after move: ";
  printFrameRect(s);
}
