#include "shape-generator.hpp"

#include <cmath>

#include "point.hpp"

namespace lab = savchuk;

// TO-DO: need to modify random int engine!

static std::uniform_int_distribution<> dist(0, 1);
static std::default_random_engine eng;

lab::Shape lab::ShapeGenerator::operator()() const
{
  Point p1 = { 2, 1 };
  Point p2 = { 1, 2 };

  if (dist(eng))
  {
    return getSquare(p1, p2);
  }
  else
  {
    return getOctagon(p1, p2);
  }
}

lab::Shape lab::ShapeGenerator::getSquare(const Point& p1, const Point& p2) const
{
  int dx = p2.x - p1.x;
  int dy = p2.y - p1.y;

  Point p3 = p2;
  move(p3, dy, -dx);
  Point p4 = p3;
  move(p4, -dx, -dy);

  return { p1, p2, p3, p4 };
}

lab::Shape lab::ShapeGenerator::getOctagon(const Point& p1, const Point& p2) const
{
  const double SQRT_2 = std::sqrt(2);

  double dx1 = p2.x - p1.x;
  double dy1 = p2.y - p1.y;

  const double SIN_45 = SQRT_2 / 2;
  const double COS_45 = SIN_45;

  double dx2 = dx1 * COS_45 + dy1 * SIN_45;
  double dy2 = -dx1 * SIN_45 + dy1 * COS_45;

  Point p3 = p2;
  move(p3, dx2, dy2);
  Point p4 = p3;
  move(p4, dy1, -dx1);
  Point p5 = p4;
  move(p5, dy2, -dx2);
  Point p6 = p5;
  move(p6, -dx1, -dy1);
  Point p7 = p6;
  move(p7, -dx2, -dy2);
  Point p8 = p7;
  move(p8, -dy1, dx1);

  return { p1, p2, p3, p4, p5, p6, p7, p8 };
}
