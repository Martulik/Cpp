#include "shape.hpp"
#include <iterator>
#include <iostream>
#include <algorithm>
#include <string>
#include <functional>

namespace lab = ezerinia;

int lab::getSideSquared(const Point &p1, const Point &p2)
{
  return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

bool lab::isSideEqual(const Shape &sh)
{
  double side = getSideSquared(sh.front(), sh.back());
  std::vector< int > sides;
  sides.reserve(sh.size());
  std::transform(std::next(sh.begin()), sh.end(), sh.begin(), std::back_inserter(sides), getSideSquared);
  return std::all_of(sides.begin(), sides.end(), std::bind(std::equal_to<>(), std::placeholders::_1, side));
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
  std::getline(in, line, '(');
  if (line.find('\n') != std::string::npos) {
    throw std::invalid_argument("Read point fail");
  }
  std::getline(in, line, ')');
  if (line.find(';') == std::string::npos) {
    throw std::invalid_argument("Not found ';'");
  }
  std::string str_point_x = line.substr(0, line.find(';'));
  std::string str_point_y = line.substr(line.find(';') + 1);
  point.x = std::stoi(str_point_x);
  point.y = std::stoi(str_point_y);
  return in;
}

std::istream &lab::operator>>(std::istream &in, Shape &shape)
{
  if (!in) {
    throw std::invalid_argument("Read fail");
  }
  unsigned int vertices_int;
  std::string vertices_str;
  in >> vertices_str;
  if (vertices_str.empty()) {
    return in;
  }
  vertices_int = std::stoi(vertices_str);
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
