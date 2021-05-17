#include "shape.hpp"
#include <algorithm>
#include <sstream>
#include <iostream>

namespace dan = doroshin;

int distSq(const dan::Point& a, const dan::Point& b)
{
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool dan::isSquare(const Shape& s)
{
  if(s.points_.size() != 4) {
    return false;
  }

  int d1 = distSq(s.points_[0], s.points_[1]);
  int d2 = distSq(s.points_[1], s.points_[2]);
  return d1 == d2;
}

std::istream& dan::operator>>(std::istream& in, Shape& s)
{
  const auto fail = [&]() {
    in.setstate(in.rdstate() | std::ios::failbit);
  };

  s.points_.clear();
  std::string line_;
  in >> std::ws;
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
