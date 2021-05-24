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
  try {
    std::string line;
    std::getline(in, line, '(');
    if (line.find('\n') != std::string::npos) {
      throw std::invalid_argument("Read point fail");
    }
    std::getline(in, line, ')');
    if (line.find(';') == std::string::npos) {
      throw std::invalid_argument("Not found ';'");
    }
    std::string str_point_x = line.substr(0, line.find(';'));
    point.x = std::stoi(str_point_x);
    std::string str_point_y = line.substr(line.find(';') + 1);
    point.y = std::stoi(str_point_y);
  }
  catch (const std::invalid_argument &ex) {
    throw ex;
  }
  return in;
}

std::istream &lab::operator>>(std::istream &in, Shape &shape)
{
  if (!in) {
    throw std::invalid_argument("Read fail");
  }
  unsigned int vertices_int;
  try {
    std::string vertices_str;
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
  std::copy_n(std::istream_iterator< Point >(in), vertices_int, std::back_inserter(shape_temp));
  std::string str;
  std::getline(in, str);
  if ((!in && !in.eof()) || !std::all_of(str.begin(), str.end(), ::isspace) || vertices_int != shape_temp.size()) {
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
