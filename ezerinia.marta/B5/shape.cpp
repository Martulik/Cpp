#include "shape.hpp"
#include <iterator>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <sstream>

namespace lab = ezerinia;

double lab::getSideLength(const Point &p1, const Point &p2)
{
  //return sqrt(abs((p1.x - p2.x) * (p1.x - p2.x) - (p1.y - p2.y) * (p1.y - p2.y)));
  return (p1.x - p2.x) * (p1.x - p2.x) - (p1.y - p2.y) * (p1.y - p2.y);
}

bool lab::isSideEqual(const Shape &shape)
{
  double side1 = getSideLength(shape[0], shape[1]);
  double side2 = getSideLength(shape[1], shape[2]);

//  for (unsigned int i = 0; i < shape.size() - 1; i++) {
//    if (getSideLength(shape[i], shape[i + 1]) != side) {
//      return false;
//    }
//  }
  return side1 == side2;
}

bool lab::operator<(const Shape &lhs, const Shape &rhs)
{
  if (lhs.size() < rhs.size()) {
    return true;
  } else {
    if ((lhs.size() == rhs.size()) && (rhs.size() == 4)) {
      if (isSideEqual(lhs)) {
        return true;
      }
    }
  }
  return false;
}

std::istream &lab::operator>>(std::istream &in, Point &point)
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

std::istream &lab::operator>>(std::istream &in, Shape &shape)
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
  shape.swap(shape_temp);
  shape.pop_back();
  if (nVertices != shape.size() || shape.size() < 3) {
    throw std::runtime_error("Wrong number of vertices");
  }
  return in;
}

std::ostream &lab::operator<<(std::ostream &out, const Point &point)
{
  out << " (" << point.x << "; " << point.y << ")";
  return out;
}

std::ostream &lab::operator<<(std::ostream &out, const Shape &shape)
{
  out << shape.size() << " ";
  std::copy(shape.begin(), shape.end(), std::ostream_iterator< Point >(out, " "));
  return out;
}
