#include "shape.hpp"
#include <iostream>
#include <iterator>
#include <algorithm>
#include <cmath>

double getSideLength(const Point &p1, const Point &p2)
{
  return sqrt((p1.x - p2.x) * (p1.x - p2.x) - (p1.y - p2.y) * (p1.y - p2.y));
}

bool isSidesEqual(const Shape &shape)
{
  double side = getSideLength(shape[0], shape[shape.size()]);
  for (unsigned int i = 0; i < shape.size() - 1; i++) {
    if (getSideLength(shape[i], shape[i + 1]) != side) {
      return false;
    }
  }
  return true;
}

std::istream &operator>>(std::istream &in, Point &point)
{
  in.ignore(256, '(');
  in >> point.x;
  in.ignore(256, ';');
  in >> point.y;
  in.ignore(256, ')');
  return in;
}

std::istream &operator>>(std::istream &in, Shape &shape)
{
  std::string str;
  int nVertices = 0;
  in >> nVertices;
  for (int i = 0; i < nVertices; i++) {
    Point point{};
    in >> point;
    shape.push_back(point);
  }
  return in;
}

std::ostream &operator<<(std::ostream &out, const Point &point)
{
  out << " (" << point.x << ";" << point.y << ")";
  return out;
}

std::ostream &operator<<(std::ostream &out, const Shape &shape)
{
  out << shape.size() << " ";
  std::copy(shape.begin(), shape.end(), std::ostream_iterator< Point >(out, " "));
  return out;
}
