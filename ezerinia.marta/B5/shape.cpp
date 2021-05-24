#include "shape.hpp"
#include <iterator>
#include <iostream>
#include <algorithm>
#include <string>

namespace lab = ezerinia;

int lab::getSideLengthSquared(const Point &p1, const Point &p2)
{
  return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

bool lab::isSideEqual(const Shape &shape)
{
  double side = getSideLengthSquared(shape[0], shape[shape.size() - 1]);
  for (unsigned int i = 0; i < shape.size() - 1; i++) {
    if (getSideLengthSquared(shape[i], shape[i + 1]) != side) {
      return false;
    }
  }
  return true;
}

bool lab::operator<(const Shape &lhs, const Shape &rhs)
{
  if (lhs.size() > 5 && rhs.size() > 5) {
    return false;
  }
  if (rhs.size() == 4 && lhs.size() == 4) {
    return isSideEqual(lhs) && !isSideEqual(rhs);
  }
  return lhs.size() < rhs.size();
}

std::istream &lab::operator>>(std::istream &in, Point &point)
{
  std::string line;
  try {
    std::getline(in, line, '(');
    std::getline(in, line, ';');
    if (line.empty() || line == "\n") {
      return in;
    }
    point.x = std::stoi(line);
    std::getline(in, line, ')');
    if (line.empty() || line == "\n") {
      return in;
    }
    point.y = std::stoi(line);
  }
  catch (const std::invalid_argument &ex) {
    throw std::invalid_argument("Read point fail");
  }
  return in;
}

std::istream &lab::operator>>(std::istream &in, Shape &shape)
{
  std::string vertices_str;
  if (in.fail() || in.bad()) {
    throw std::invalid_argument("Read fail");
  }
  unsigned int vertices_int;
  try {
    in >> vertices_str;
    if (vertices_str.empty()) {
      return in;
    }
    vertices_int = std::stoi(vertices_str);
  }
  catch (const std::invalid_argument &ex) {
    throw std::invalid_argument("Read vertices fail");
  }
  Shape shape_temp;
  shape_temp.reserve(vertices_int);
  Point point;
  while (in && in.peek() != '\n') {
    in >> point;
    shape_temp.push_back(point);
  }
  if ((!in && !in.eof()) || vertices_int != shape_temp.size() || shape_temp.size() < 3) {
    throw std::invalid_argument("Read shape fail");
  }
  shape.swap(shape_temp);
  return in;
}

std::ostream &lab::operator<<(std::ostream &out, const Point &point)
{
  out << '(' << point.x << "; " << point.y << ')';
  return out;
}

std::ostream &lab::operator<<(std::ostream &out, const Shape &shape)
{
  out << shape.size() << ' ';
  std::copy(shape.begin(), shape.end(), std::ostream_iterator< Point >(out, " "));
  return out;
}
