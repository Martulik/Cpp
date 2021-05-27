#ifndef COUNTER_HPP
#define COUNTER_HPP

#include "Shape.hpp"

namespace ferapontov
{
  struct Counter
  {
    unsigned long long vertices;
    unsigned long long triangels;
    unsigned long long squares;
    unsigned long long rectangles;

    void operator()(const Shape& shp);

    void print(std::ostream& out);
  };
}

#endif
