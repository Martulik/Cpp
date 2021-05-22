#ifndef TOOLS_HPP
#define TOOLS_HPP

#include "shape.hpp"

namespace savchuk
{
  struct ShapeCounter
  {
    unsigned int vertices = 0u;
    unsigned int triangles = 0u;
    unsigned int rectangles = 0u;
    unsigned int squares = 0u;

    void operator()(const Shape& shape);
  };
}

#endif
