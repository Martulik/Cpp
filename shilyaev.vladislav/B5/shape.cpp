#include "shape.hpp"
#include <iostream>
#include <iterator>
#include <functional>
#include <algorithm>
#include <sstream>
#include <cctype>

namespace shilyaev {
  using QuadrilateralPredicate = std::function< bool(int ab, int bc, int cd, int da, int bd, int ac) >;

  std::ostream &operator<<(std::ostream &ostream, const Point &point)
  {
    ostream << '(' << point.x << "; " << point.y << ')';
    return ostream;
  }

  std::istream &operator>>(std::istream &istream, Point &point)
  {
    try {
      std::string str;
      std::getline(istream, str, '(');
      std::getline(istream, str, ';');
      point.x = std::stoi(str);
      std::getline(istream, str, ')');
      point.y = std::stoi(str);
    } catch (const std::invalid_argument &) {
      istream.setstate(std::ios::failbit);
    }
    return istream;
  }

  std::ostream &operator<<(std::ostream &ostream, const Shape &shape)
  {
    ostream << shape.size() << ' ';
    std::copy(shape.begin(), shape.end(), std::ostream_iterator< Point >(ostream, " "));
    return ostream;
  }

  std::istream &operator>>(std::istream &istream, Shape &shape)
  {
    std::string line;
    while (std::all_of(line.begin(), line.end(), static_cast< int (&)(int) >(std::isspace))) {
      if (!std::getline(istream, line)) {
        return istream;
      }
    }
    std::istringstream istringstream(line);
    size_t verticesCount = 0;
    istringstream >> verticesCount;
    if (verticesCount < 1) {
      istream.setstate(std::ios::failbit);
      return istream;
    }
    Shape newShape;
    newShape.reserve(verticesCount);
    std::istream_iterator< Point > istreamIterator(istringstream);
    std::istream_iterator< Point > istreamIteratorEnd;
    std::copy(istreamIterator, istreamIteratorEnd, std::back_inserter(newShape));
    if ((!istringstream && !istringstream.eof()) || newShape.size() != verticesCount) {
      istream.setstate(std::ios::failbit);
      return istream;
    }
    shape.swap(newShape);
    return istream;
  }

  bool isTriangle(const Shape &shape)
  {
    return shape.size() == 3;
  }

  int calculateDistanceSquared(const Point &a, const Point &b)
  {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
  }

  bool isRectangleByDistances(int ab, int bc, int cd, int da, int bd, int ac)
  {
    return ab == cd && bc == da && bd == ac && bd == ab + bc;
  }

  bool isSquareByDistances(int ab, int bc, int cd, int da, int bd, int ac)
  {
    return ab == bc && isRectangleByDistances(ab, bc, cd, da, bd, ac);
  }

  bool doesQuadrilateralMatch(const Shape &shape, const QuadrilateralPredicate &predicate)
  {
    if (shape.size() != 4) {
      return false;
    }
    int ab = calculateDistanceSquared(shape[0], shape[1]);
    int bc = calculateDistanceSquared(shape[1], shape[2]);
    int cd = calculateDistanceSquared(shape[2], shape[3]);
    int da = calculateDistanceSquared(shape[3], shape[0]);
    int bd = calculateDistanceSquared(shape[1], shape[3]);
    int ac = calculateDistanceSquared(shape[0], shape[2]);
    return predicate(ab, bc, cd, da, bd, ac);
  }

  bool isRectangle(const Shape &shape)
  {
    return doesQuadrilateralMatch(shape, isRectangleByDistances);
  }

  bool isSquare(const Shape &shape)
  {
    return doesQuadrilateralMatch(shape, isSquareByDistances);
  }

  bool isPentagon(const Shape &shape)
  {
    return shape.size() == 5;
  }
}
