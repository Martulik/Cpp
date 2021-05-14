#include "shape.hpp"
#include <algorithm>
#include <sstream>
#include <iostream>

namespace dan = doroshin;

bool dan::isSquare(const Shape& s)
{
  if(s.points_.size() != 4) {
    return false;
  }

  auto distSq = [](const Point& a, const Point& b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
  };

  std::vector< int > distances;
  distances.reserve(6);
  for(int i = 0; i < 4; ++i) {
    for(int j = i + 1; j < 4; ++j) {
      distances.push_back(distSq(s.points_[i], s.points_[j]));
    }
  }
  std::sort(distances.begin(), distances.end());
  return distances[0] == distances[3];
}

std::istream& dan::operator>>(std::istream& in, Shape& s)
{
  const auto fail = [&]() {
    in.setstate(in.rdstate() | std::ios::failbit);
  };

  s.points_.clear();
  std::string line_;
  if(std::getline(in, line_)) {
    std::istringstream line(line_);

    int n = 0;
    line >> n;
    if(!line || line.peek() != ' ') {
      fail();
      return in;
    }

    s.points_.reserve(n);
    for(int i = 0; i < n; ++i) {
      Point p;
      line >> p;
      s.points_.push_back(p);

      if(!line) {
        fail();
        return in;
      }
    }

    line >> std::ws;
    if(!line.eof()) {
      fail();
      return in;
    }
  }
  return in;
}

std::ostream& dan::operator<<(std::ostream& out, const Shape& s)
{
  out << s.points_.size() << ' ';
  for(auto&& point: s.points_) {
    out << point << ' ';
  }
  return out;
}
