#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <iosfwd>
#include <set>
#include <string>
#include <vector>
#include <memory>
#include <random>
#include "shape.hpp"

namespace lebedeva
{
  std::set< std::string > doInputWords(std::istream& in);
  void doOutputWords(std::ostream& out, std::set< std::string >& words);

  ShapesSpecifics countShapes(const std::vector< Shape >& shapes);
  size_t countVertices(size_t sum, const Shape& shapes);
  Point getFrontPoint(const Shape& shape);
  Shape getFrontPoints(const std::vector< Shape >& shapes);
  bool hasLessVertices(const Shape& shape1, const Shape& shape2);
  void printInfo(std::ostream& out, const ShapesSpecifics& info);
  void printPoints(std::ostream& out, const Shape& points);
  void printShapes(std::ostream& out, const std::vector< Shape >& shapes);

  Shape makeQuadrangle(std::random_device& gen);
  Point makePoint(std::random_device& gen, const bool isShift);
  void rotateShape(Shape& shape, std::random_device& gen);
}
#endif
