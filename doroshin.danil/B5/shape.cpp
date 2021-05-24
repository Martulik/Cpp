#include "shape.hpp"
#include <algorithm>
#include <iterator>
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

namespace doroshin {
  template< class InputIt, class Size, class OutputIt>
  OutputIt copy_n(InputIt first, Size count, OutputIt result)
  {
      while(count > 0) {
          *result++ = *first;
          if(count > 1) {
            first++;
          }
          count--;
      }
      return result;
  }
}

std::istream& dan::operator>>(std::istream& in, Shape& s)
{
  const auto fail = [&]() {
    in.setstate(in.rdstate() | std::ios::failbit);
  };

  s.points_.clear();
  size_t n = 0;
  in >> n;
  if(!in || in.peek() != ' ') {
    fail();
    return in;
  }

  s.points_.reserve(n);
  std::istream_iterator< Point > iPoint(in);
  dan::copy_n(iPoint, n, std::back_inserter(s.points_));
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
