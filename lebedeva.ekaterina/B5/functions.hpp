#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <iosfwd>
#include <set>
#include <string>
#include <vector>
#include "shape.hpp"

namespace lebedeva
{
  std::set< std::string > doInputWords(std::istream& in);
  void doOutputWords(std::ostream& out, std::set< std::string >& words);

  ShapesSpecifics countShapes(std::vector< Shape >& shapes);
  size_t countVertices(size_t sum, const Shape& shapes);
  void removePentagons(std::vector< Shape >& shapes);
  Point getFrontPoint(const Shape& shape);
  Shape getFrontPoints(std::vector< Shape >& shapes);
  void sortShapes(std::vector< Shape >& shapes);
  bool hasMoreVertices(const Shape& shape1, const Shape& shape2);
  void printInfo(std::ostream& out, const ShapesSpecifics& info);
  void printPoints(std::ostream& out, const Shape& points);
  void printShapes(std::ostream& out, const std::vector< Shape >& shapes);
}
#endif
