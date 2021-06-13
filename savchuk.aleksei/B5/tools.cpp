#include "tools.hpp"

#include <random>

namespace lab = savchuk;

void lab::ShapeCounter::operator()(const Shape& shape)
{
  vertices += shape.size();
  if (isTriangle(shape))
  {
    ++triangles;
  }
  if (isRectangle(shape))
  {
    ++rectangles;
  }
  if (isSquare(shape))
  {
    ++squares;
  }
}

std::function< int() > lab::getGenerator(int leftBound, int rightBound)
{
  static std::default_random_engine eng(std::random_device{}());
  std::uniform_int_distribution<> dist(leftBound, rightBound);
  return std::bind(dist, eng);
}
