#ifndef B5_TASK2_HPP
#define B5_TASK2_HPP
#include <iosfwd>
#include "point.hpp"

namespace ivanova
{
  int task2(std::istream &in, std::ostream &out);

  std::istream &operator >>(std::istream &in, Shape &shp);
  std::ostream &operator <<(std::ostream &out, const Shape &elem);
  bool compare(Shape &elem1, Shape &elem2);
}

#endif
