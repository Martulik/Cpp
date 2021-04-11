#include "main-utility.hpp"

#include <iostream>

#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"
#include "shape-utility.hpp"

namespace lab = savchuk;

void lab::printFrameRect(const lab::Shape& s)
{
  std::cout << "p = (" << getPosX(s) << ", " << getPosY(s) << "), ";
  std::cout << "w = " << getWidth(s) << ", ";
  std::cout << "h = " << getHeight(s) << '\n';
}

void lab::testArea(const lab::Shape& s)
{
  std::cout << "area = " << s.getArea() << '\n';
}

void lab::testMove(lab::Shape& s, const lab::point_t& p)
{
  std::cout << "FrameRect before move: ";
  printFrameRect(s);
  s.move(p);
  std::cout << "FrameRect after move: ";
  printFrameRect(s);
}

void lab::testMove(lab::Shape& s, double dx, double dy)
{
  std::cout << "FrameRect before move: ";
  printFrameRect(s);
  s.move(dx, dy);
  std::cout << "FrameRect after move: ";
  printFrameRect(s);
}

void lab::testScale(lab::Shape& s, double k)
{
  std::cout << "FrameRect before scale: ";
  printFrameRect(s);
  s.scale(k);
  std::cout << "FrameRect after scale: ";
  printFrameRect(s);
}
