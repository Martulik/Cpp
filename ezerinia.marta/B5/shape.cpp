#include "shape.hpp"
#include <iostream>
#include <iterator>
#include <algorithm>
#include <cmath>
#include <iosfwd>

#include <stdexcept>
#include <sstream>

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
  std::string str;
  char trash = '\0';
  std::getline(in, str, ')');
  if (str.empty() || in.eof()) {
    return in;
  }
  std::istringstream iss(str);
  iss >> trash;
  if (trash != '(') {
    throw std::runtime_error("Read point.x fail");
  }
  iss >> point.x >> trash >> point.y;
  if (trash != ';') {
    throw std::runtime_error("Read point.y fail");
  }
  return in;
}

std::istream &operator>>(std::istream &in, Shape &shape)
{
  unsigned int nVertices = 0;
  char trash = '\0';
  in >> nVertices >> std::noskipws >> trash;
  if (trash == '\n') {
    throw std::runtime_error("Read shape fail");
  }
  std::string str;
  in >> std::skipws;
  std::getline(in, str);
  if (str.empty()) {
    return in;
  }
  std::istringstream iss(str);
  Shape shape_temp((std::istream_iterator< Point >(iss)), std::istream_iterator< Point >());
  shape_temp.pop_back();
  if (nVertices != shape_temp.size()) {
    throw std::runtime_error("Wrong number of vertices");
  }
  shape.swap(shape_temp);
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
