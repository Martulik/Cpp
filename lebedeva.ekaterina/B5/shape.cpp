#include "shape.hpp"
#include <iostream>
#include <iterator>
#include <string>
#include <algorithm>
#include <cmath>

std::istream& lebedeva::operator>>(std::istream& in, Shape& shape)
{
  std::string sVertices;
  std::getline(in >> std::ws, sVertices, ' ');
  if (sVertices.empty())
  {
    return in;
  }
  if (sVertices.back() == '\n')
  {
    throw std::invalid_argument("Invalid input");
  }
  int vertices = std::stoi(sVertices);
  if (vertices < 1)
  {
    throw std::invalid_argument("Invalid number of vertices");
  }

  Shape tempShape;
  tempShape.reserve(vertices);
  std::istream_iterator< Point > inIter(in);
  std::copy_n(inIter, vertices, std::back_inserter(tempShape));
  int size = tempShape.size();
  if (!in || vertices != size)
  {
    throw std::invalid_argument("Invalid number of vertices");
  }
  shape = std::move(tempShape);
  return in;
}

std::ostream& lebedeva::operator<<(std::ostream& out, const Shape& shape)
{
  std::ostream_iterator< Point > outIter(out, " ");
  out << shape.size() << ' ';
  std::copy(shape.begin(), shape.end(), outIter);
  return out;
}

bool lebedeva::isTriangle(const Shape& shape)
{
  return (shape.size() == 3);
}

bool lebedeva::isSquare(const Shape& shape)
{
  return (isRectangle(shape) && compareDistances(shape));
}

bool lebedeva::isRectangle(const Shape& shape)
{
  return (shape.size() == 4);
}

bool lebedeva::isPentagon(const Shape& shape)
{
  return (shape.size() == 5);
}

int lebedeva::getDistance(const Point& p1, const Point& p2)
{
  int temp1 = p2.x - p1.x;
  int temp2 = p2.y - p1.y;
  return (temp1 * temp1 + temp2 * temp2);
}

bool lebedeva::compareDistances(const Shape& shape)
{
  int temp1 = getDistance(shape[0], shape[1]);
  int temp2 = getDistance(shape[0], shape[3]);
  return (temp2 == temp1);
}

bool lebedeva::isCrossedSquare(const Shape& shape)
{
  return (isRectangle(shape) && checkEquivalence(shape));
}

bool lebedeva::isCrossedRectangle(const Shape& shape)
{
  return (isRectangle(shape) && !checkRectangleDistances(shape) && checkDistances(shape));
}

bool lebedeva::isSquareAdvanced(const Shape& shape)
{
  return (isRectangle(shape) && (checkSimpleEquivalence(shape) || checkEquivalence(shape)));
}

bool lebedeva::isRectangleAdvanced(const Shape& shape)
{
  return (isRectangle(shape) && checkDistances(shape));
}

bool lebedeva::checkDistances(const Shape& shape)
{
  constexpr auto eps = std::numeric_limits< double >::epsilon() * 2e+2;
  double a = getDistance(shape[0], shape[1]);
  double b = getDistance(shape[0], shape[2]);
  double c = getDistance(shape[1], shape[2]);
  return (std::abs(a + b - c) < eps || std::abs(a + c - b) < eps || std::abs(b + c - a) < eps);
}

bool lebedeva::checkEquivalence(const Shape& shape)
{
  constexpr auto eps = std::numeric_limits< double >::epsilon() * 1e+1;
  double a = std::sqrt(getDistance(shape[0], shape[1]));
  double b = std::sqrt(getDistance(shape[0], shape[2]));
  double c = std::sqrt(getDistance(shape[1], shape[2]));
  return (std::abs(a - b) < eps || std::abs(b - c) < eps);
}

bool lebedeva::checkSimpleEquivalence(const Shape& shape)
{
  constexpr auto eps = std::numeric_limits< double >::epsilon() * 1e+1;
  double a = std::sqrt(getDistance(shape[0], shape[1]));
  double c = std::sqrt(getDistance(shape[1], shape[2]));
  return (std::abs(a - c) < eps);
}

bool lebedeva::checkRectangleDistances(const Shape& shape)
{
  constexpr auto eps = std::numeric_limits< double >::epsilon() * 1e+2;
  double sum = getDistance(shape[0], shape[1]) + getDistance(shape[0], shape[3]);
  double hyp = getDistance(shape[1], shape[3]);
  return (std::abs(sum - hyp) < eps);
}
