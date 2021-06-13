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

lebedeva::Shape lebedeva::makeQuadrangle(std::random_device& gen)
{
  Point p0 = makePoint(gen, 0);
  Point shift = makePoint(gen, 1);
  Point p1 = { p0.x, p0.y + shift.y };
  Point p2 = { p0.x + shift.x, p0.y + shift.y };
  Point p3 = { p0.x + shift.x, p0.y };
  Shape quadrangle = { p0, p1, p2, p3 };

  std::uniform_int_distribution< int > probability(0, 1);

  if (probability(gen))
  {
    rotateShape(quadrangle, gen);
  }

  if (probability(gen))
  {
    if (probability(gen))
    {
      std::swap(quadrangle[1], quadrangle[2]);
    }
    else
    {
      std::swap(quadrangle[2], quadrangle[3]);
    }
  }

  return quadrangle;
}

lebedeva::Point lebedeva::makePoint(std::random_device& gen, const bool isShift)
{
  std::uniform_int_distribution< int > coordinate(-10000, 10000);
  int x = coordinate(gen);
  int y = coordinate(gen);
  if (isShift)
  {
    std::uniform_int_distribution< int > isSquare(0, 1);
    if (isSquare(gen))
    {
      y = x;
    }
    else
    {
      for (y; (y == x); y = coordinate(gen));
    }
  }
  return { x, y };
}

void lebedeva::rotateShape(Shape& shape, std::random_device& gen)
{
  std::uniform_real_distribution< double > degree(0.0, 180.0);
  const double MY_PI = 3.1415;
  double rotDegree = degree(gen);
  double rad = (rotDegree * MY_PI) / 180;
  double Sin = std::sin(rad);
  double Cos = std::cos(rad);
  Point p0 = shape[0];
  for (size_t i = 1; i < shape.size(); i++)
  {
    Point temp = shape[i];
    shape[i].x = p0.x + (temp.x - p0.x) * Cos - (temp.y - p0.y) * Sin;
    shape[i].y = p0.y + (temp.x - p0.x) * Sin + (temp.y - p0.y) * Cos;
  }
}
