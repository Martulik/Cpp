#include "shape.hpp"
#include <sstream>
#include <iostream>

namespace dan = doroshin;

std::istream& dan::getShape(std::istream& in, Shape& s)
{
  const auto fail = [&]() {
    in.setstate(in.rdstate() | std::ios::failbit);
  };

  s.clear();
  std::string line_;
  if(std::getline(in, line_)) {
    std::istringstream line(line_);

    int n = 0;
    line >> n;
    if(!line || line.peek() != ' ') {
      fail();
      return in;
    }

    s.reserve(n);
    for(int i = 0; i < n; ++i) {
      Point p;
      line >> p;
      s.push_back(p);

      if(!line || line.peek() != ' ') {
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

std::ostream& dan::putShape(std::ostream& out, const Shape& s)
{
  out << s.size() << ' ';
  for(auto&& point: s) {
    out << point << ' ';
  }
  return out;
}
