#include "shape.hpp"
#include <iostream>
#include <iterator>
#include <functional>
#include <algorithm>

namespace shilyaev {
  std::ostream &operator<<(std::ostream &ostream, const Shape &shape)
  {
    ostream << shape.size() << ' ';
    std::copy(shape.cbegin(), shape.cend(), std::ostream_iterator< Point >(ostream, " "));
    return ostream;
  }

  std::istream &operator>>(std::istream &istream, Shape &shape)
  {
    size_t verticesCount = 0;
    istream >> verticesCount;
    if (!istream || verticesCount < 1) {
      istream.setstate(std::ios::failbit);
      return istream;
    }
    Shape newShape;
    newShape.reserve(verticesCount);
    std::istream_iterator< Point > istreamIterator(istream);
    std::copy_n(istreamIterator, verticesCount, std::back_inserter(newShape));
    if (!istream || verticesCount != newShape.size()) {
      istream.setstate(std::ios::failbit);
      return istream;
    }
    shape = std::move(newShape);
    return istream;
  }

  bool isTriangle(const Shape &shape)
  {
    return shape.size() == 3;
  }

  bool isParallelogram(const Shape &shape)
  {
    return shape.size() == 4 && shape[0] + shape[2] == shape[1] + shape[3];
  }

  int dotProduct(Point a, Point b)
  {
    return a.x * b.x + a.y * b.y;
  }

  bool isRectangle(const Shape &shape)
  {
    return isParallelogram(shape) && dotProduct(shape[1] - shape[0], shape[3] - shape[0]) == 0;
  }

  bool isSquare(const Shape &shape)
  {
    return isRectangle(shape) && dotProduct(shape[2] - shape[0], shape[3] - shape[1]) == 0;
  }

  bool isPentagon(const Shape &shape)
  {
    return shape.size() == 5;
  }
}
