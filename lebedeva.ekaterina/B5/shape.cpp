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
  std::vector< double > distances = getPointsDistances(shape);
  return ((shape.size() == 4) && (!distances.empty()) && (distances[0] == distances[2]));
}

bool lebedeva::isRectangle(const Shape& shape)
{
  std::vector< double > distances = getPointsDistances(shape);
  //std::vector< double > distances = getPointsDistances(shape);
  return ((shape.size() == 4) && (!distances.empty()) && (distances[4] == getHypotenuse(distances[0], distances[2])));
}

bool lebedeva::isPentagon(const Shape& shape)
{
  return (shape.size() == 5);
}

std::vector< double > lebedeva::getPointsDistances(const Shape& shape)
{
  std::vector< double > res;
  res.push_back(getDistance(shape[0], shape[1]));
  res.push_back(getDistance(shape[0], shape[2]));
  res.push_back(getDistance(shape[0], shape[3]));
  res.push_back(getDistance(shape[1], shape[2]));
  res.push_back(getDistance(shape[1], shape[3]));
  res.push_back(getDistance(shape[2], shape[3]));
  std::sort(res.begin(), res.end());
  return res;
}

double lebedeva::getDistance(const Point& p1, const Point& p2)
{
  int temp1 = p2.x - p1.x;
  int temp2 = p2.y - p1.y;
  return std::sqrt(std::pow(temp1, 2) + std::pow(temp2, 2));
}

double lebedeva::getHypotenuse(const double a, const double b)
{
  double temp1 = std::pow(a, 2);
  double temp2 = std::pow(b, 2);
  return std::sqrt(temp1 + temp2);
}
