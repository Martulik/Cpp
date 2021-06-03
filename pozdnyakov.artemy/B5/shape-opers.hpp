#ifndef SHAPE_OPERS_HPP
#define SHAPE_OPERS_HPP

#include <iosfwd>
#include "point.hpp"

namespace pozdnyakov
{
  const int PRECISION = 1000;
  bool isSquare(const Shape& shape);
  bool isRect(const Shape& shape);
  bool isTriangle(const Shape& shape);
  size_t sizeAccum(size_t prev, const Shape& shape);
  template < int x, class Container >
  bool compSize(Container cont)
  {
    return x == cont.size();
  }
  const Point& getFirst(const Shape& shape);
  int getSquareDistance(const Point& point1, const Point& point2);
  bool comparator(const Shape& shape1, const Shape& shape2);
  template < int x, class Container >
  bool valComparator(Container cont1, Container cont2)
  {
    return cont1.size() < cont2.size();
  }
  std::istream& operator>>(std::istream& in, Point& point);
  std::ostream& operator<<(std::ostream& out, const Point& point);
  std::istream& operator>>(std::istream& in, Shape& shape);
  std::ostream& operator<<(std::ostream& out, const Shape& shape);
  bool operator==(const Point& point1, const Point& point2);
}

#endif
