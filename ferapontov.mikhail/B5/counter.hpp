#ifndef COUNTER_HPP
#define COUNTER_HPP

#include "shape.hpp"
#include <iosfwd>

namespace ferapontov
{
  struct Counter
  {
    unsigned long long vertices;
    unsigned long long triangels;
    unsigned long long squares;
    unsigned long long rectangles;

    void operator()(const Shape& shp);
  };

  std::ostream& operator<<(std::ostream& out, Counter& counter);
}

#endif
