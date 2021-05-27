#ifndef COUNTER_HPP
#define COUNTER_HPP

#include "Shape.hpp"

namespace ferapontov
{
  struct Counter
  {
    unsigned long vertices;
    unsigned long triangels;
    unsigned long squares;
    unsigned long rectangles;

    void operator()(const Shape& shp);
  };
}

#endif
