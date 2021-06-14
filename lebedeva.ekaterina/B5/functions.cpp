#include "functions.hpp"
#include <iterator>
#include <iostream>
#include <numeric>
#include <algorithm>
//#include <cmath>

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

lebedeva::Shape lebedeva::makeQuadrilateral(std::random_device& gen)
{
  Shape quadrilateral;
  std::uniform_int_distribution< int > probability(0, 1);

  if (probability(gen))
  {
    makeRotated(quadrilateral, gen);
  }
  else
  {
    makeDefault(quadrilateral, gen);
  }

  if (probability(gen))
  {
    makeCrossed(quadrilateral, gen);
  }

  return quadrilateral;
}

lebedeva::Point lebedeva::makePoint(std::random_device& gen, const bool isShift)
{
  std::uniform_int_distribution< int > coordinate(-10, 10);
  int x = coordinate(gen);
  int y = coordinate(gen);
  if (isShift)
  {
    std::uniform_int_distribution< int > coordSh(1, 20);
    std::uniform_int_distribution< int > isSquare(0, 1);
    if (isSquare(gen))
    {
      x = coordSh(gen);
      y = x;
    }
    else
    {
      x = coordSh(gen);
      y = coordSh(gen);
      if (y == x)
      {
        y = coordSh(gen);
      }
    }
  }
  return { x, y };
}

void lebedeva::makeDefault(Shape& shape, std::random_device& gen)
{
  Point p0 = makePoint(gen, 0);
  Point shift = makePoint(gen, 1);
  Point p1 = { p0.x, (p0.y + shift.y) };
  Point p2 = { (p0.x + shift.x), (p0.y + shift.y) };
  Point p3 = { (p0.x + shift.x), p0.y };
  shape = { p0, p1, p2, p3 };
}

void lebedeva::makeRotated(Shape& shape, std::random_device& gen)
{
  std::uniform_real_distribution< double > coord(1.0, 20.0);
  std::uniform_int_distribution< int > degree(0, 360);
  Point wh = makePoint(gen, 1);
  Point shift = makePoint(gen, 0);
  double x1 = -1 * (wh.x / 2);
  double y1 = wh.y / 2;
  double x2 = wh.x / 2;
  double y2 = -1 * (wh.y / 2);
  int deg = degree(gen);
  shape.push_back(rotate(x1, y2, deg) + shift);
  shape.push_back(rotate(x1, y1, deg) + shift);
  shape.push_back(rotate(x2, y1, deg) + shift);
  shape.push_back(rotate(x2, y2, deg) + shift);
}

lebedeva::Point lebedeva::rotate(double x, double y, int degree)
{
  const double MY_PI = 3.14;
  double rad = degree * MY_PI / 180;
  double tempX = x;
  double tempY = y;
  x = tempX * std::cos(rad) - tempY * std::sin(rad);
  y = tempX * std::sin(rad) + tempY * std::cos(rad);
  return { static_cast< int >(x), static_cast< int >(y) };
}

void lebedeva::makeCrossed(Shape& shape, std::random_device& gen)
{
  std::uniform_int_distribution< int > probability(0, 1);
  if (probability(gen))
  {
    std::swap(shape[1], shape[2]);
  }
  else
  {
    std::swap(shape[2], shape[3]);
  }
}
