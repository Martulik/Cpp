#include "shape-generator.hpp"

#include <cmath>

#include "point.hpp"
#include "tools.hpp"

namespace savchuk
{
  constexpr const int MIN_COORDINATE = -10'000;
  constexpr const int MAX_COORDINATE = 10'000;
}

namespace lab = savchuk;

std::function< int() > lab::ShapeGenerator::boolean_gen_ = lab::getGenerator(0, 1);
std::function< int() > lab::ShapeGenerator::int_gen_ = lab::getGenerator(MIN_COORDINATE, MAX_COORDINATE);

lab::Shape lab::ShapeGenerator::operator()() const
{
  Point p1 = { int_gen_(), int_gen_() };
  Point p2 = { int_gen_(), int_gen_() };

  if (boolean_gen_())
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
  double dx1 = p2.x - p1.x;
  double dy1 = p2.y - p1.y;

  const double SIN_45 = std::sqrt(2) / 2;
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
