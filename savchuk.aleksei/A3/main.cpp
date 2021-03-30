#include <iostream>
#include <memory>

#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"
#include "shape-utility.hpp"

namespace lab = savchuk;

const lab::point_t& POS_1 = { 2.3, -7.1 };
const double WIDTH = 6.1;
const double HEIGHT = 9.4;
const lab::point_t& POS_2 = { 42.8, -11.7 };
const double RADIUS = 3.5;

void printFrameRect(const lab::Shape& s);
void testArea(const lab::Shape& s);
void testMove(lab::Shape& s, const lab::point_t& p);
void testMove(lab::Shape& s, double dx, double dy);
void testScale(lab::Shape& s, double k);

int main()
{
  std::unique_ptr< lab::Shape > r(new lab::Rectangle(POS_1, WIDTH, HEIGHT));
  testArea(*r);
  testMove(*r, { 6.8, -7.2 });
  testMove(*r, 3.1, 8.6);
  testScale(*r, 7.1);

  std::unique_ptr< lab::Shape > c(new lab::Circle(POS_2, RADIUS));
  testArea(*c);
  testMove(*c, { -42.3, -26.5 });
  testMove(*c, 5.6, 1.7);
  testScale(*c, 3.2);

  lab::Rectangle rect(POS_1, WIDTH, HEIGHT);
  lab::Circle circ(POS_2, RADIUS);
  std::unique_ptr< lab::Shape > comp(new lab::CompositeShape({ &rect, &circ }));
  testArea(*comp);
  testMove(*comp, { -4.1, 2.3 });
  testMove(*comp, 3.6, 7.6);
  testScale(*comp, 2.7);
}

void printFrameRect(const lab::Shape& s)
{
  std::cout << "p = (" << lab::getPosX(s) << ", " << lab::getPosY(s) << "), ";
  std::cout << "w = " << lab::getWidth(s) << ", ";
  std::cout << "h = " << lab::getHeight(s) << '\n';
}

void testArea(const lab::Shape& s)
{
  std::cout << "area = " << s.getArea() << '\n';
}

void testMove(lab::Shape& s, const lab::point_t& p)
{
  std::cout << "FrameRect before move: ";
  printFrameRect(s);
  s.move(p);
  std::cout << "FrameRect after move: ";
  printFrameRect(s);
}

void testMove(lab::Shape& s, double dx, double dy)
{
  std::cout << "FrameRect before move: ";
  printFrameRect(s);
  s.move(dx, dy);
  std::cout << "FrameRect after move: ";
  printFrameRect(s);
}

void testScale(lab::Shape& s, double k)
{
  std::cout << "FrameRect before scale: ";
  printFrameRect(s);
  s.scale(k);
  std::cout << "FrameRect after scale: ";
  printFrameRect(s);
}
