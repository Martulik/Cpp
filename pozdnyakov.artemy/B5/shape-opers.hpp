#ifndef SHAPE_OPERS_HPP
#define SHAPE_OPERS_HPP

#include <iosfwd>
#include <algorithm>
#include <initializer_list>
#include "point.hpp"

namespace pozdnyakov
{
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
  bool comparator(const Shape& shape1, const Shape& shape2);
  template < int x, class Container >
  bool valComparator(Container cont1, Container)
  {
    return cont1.size() == x;
  }
  void removeZero(std::vector< Shape >& shapes);
  std::istream& operator>>(std::istream& in, Point& point);
  std::ostream& operator<<(std::ostream& out, const Point& point);
  std::istream& operator>>(std::istream& in, Shape& shape);
  std::ostream& operator<<(std::ostream& out, const Shape& shape);
}

#endif
