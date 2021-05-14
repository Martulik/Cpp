#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <iosfwd>
#include <vector>
#include "point.hpp"

namespace doroshin
{
  using Shape = std::vector< Point >;

  std::istream& getShape(std::istream&, Shape&);
  std::ostream& putShape(std::ostream&, const Shape&);
}

#endif //SHAPE_HPP
