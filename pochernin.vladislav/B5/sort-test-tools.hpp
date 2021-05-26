#ifndef SORT_TEST_TOOLS_HPP
#define SORT_TEST_TOOLS_HPP

#include <cstddef>

namespace pochernin
{
  enum shape_type_t
  {
    triangle,
    square,
    rectangle,
    other
  };

  struct ShapePool
  {
    size_t triangles = 0;
    size_t squares = 0;
    size_t rectangles = 0;
    size_t other = 0;
  };

  int getRandomNumber(int min, int max);
  ShapePool getShapePool(double raio);
}

#endif
