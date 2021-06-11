#include "functions.hpp"
#include <iterator>
#include <iostream>
#include <numeric>
#include <algorithm>

std::set< std::string > lebedeva::doInputWords(std::istream& in)
{
  std::istream_iterator< std::string > inIterFirst(in);
  std::istream_iterator< std::string > inIterLast;
  std::set< std::string > words(inIterFirst, inIterLast);
  return words;
}

void lebedeva::doOutputWords(std::ostream& out, std::set< std::string >& words)
{
  std::ostream_iterator< std::string > outIter(out, "\n");
  std::copy(words.begin(), words.end(), outIter);
}

lebedeva::ShapesSpecifics lebedeva::countShapes(const std::vector< Shape >& shapes)
{
  ShapesSpecifics temp;
  temp.vertices = std::accumulate(shapes.begin(), shapes.end(), 0, countVertices);
  temp.triangles = std::count_if(shapes.begin(), shapes.end(), isTriangle);
  temp.squares = std::count_if(shapes.begin(), shapes.end(), isSquare);
  temp.rectangles = std::count_if(shapes.begin(), shapes.end(), isRectangle);
  return temp;
}

size_t lebedeva::countVertices(size_t sum, const Shape& shape)
{
  return (sum + shape.size());
}

lebedeva::Point lebedeva::getFrontPoint(const Shape& shape)
{
  return (shape.front());
}

lebedeva::Shape lebedeva::getFrontPoints(const std::vector< Shape >& shapes)
{
  Shape temp;
  temp.reserve(shapes.size());
  std::transform(shapes.begin(), shapes.end(), std::back_inserter(temp), getFrontPoint);
  return temp;
}

bool lebedeva::hasLessVertices(const Shape& shape1, const Shape& shape2)
{
  if (shape1.size() == shape2.size())
  {
    return (isSquare(shape1) && !isSquare(shape2));
  }
  else
  {
    return (shape1.size() < shape2.size());
  }
}

void lebedeva::printInfo(std::ostream& out, const ShapesSpecifics& info)
{
  out << "Vertices: " << info.vertices << "\n";
  out << "Triangles: " << info.triangles << "\n";
  out << "Squares: " << info.squares << "\n";
  out << "Rectangles: " << info.rectangles;
}

void lebedeva::printPoints(std::ostream& out, const Shape& points)
{
  out << "Points: ";
  std::ostream_iterator< Point > outIter(std::cout, " ");
  std::copy(points.begin(), points.end(), outIter);
}

void lebedeva::printShapes(std::ostream& out, const std::vector< Shape >& shapes)
{
  out << "Shapes:\n";
  std::ostream_iterator< Shape > outIter(std::cout, "\n");
  std::copy(shapes.begin(), shapes.end(), outIter);
}
