#include "sort-test-tools.hpp"

#include <cstdlib>
#include <cassert>

int pochernin::getRandomNumber(int min, int max)
{
  return rand() % (max - min + 1) + min;
}

pochernin::ShapePool pochernin::getShapePool(double ratio)
{
  assert((ratio >= 0) && (ratio <= 1));
  ShapePool shapePool;

  size_t remaining = 100000;

  size_t add = remaining * ratio;
  shapePool.other = add;
  remaining -= add;

  ratio = rand() / static_cast< double >(RAND_MAX);
  add = remaining * ratio;
  shapePool.triangles = add;
  remaining -= add;

  ratio = rand() / static_cast< double >(RAND_MAX);
  add = remaining * ratio;
  shapePool.squares = add;
  remaining -= add;

  shapePool.rectangles = remaining;

  return shapePool;
}
