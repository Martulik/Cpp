#include "shape.hpp"
#include <algorithm>
#include <iterator>
#include <iostream>
#include <functional>
#include "istream-fail.hpp"

namespace dan = doroshin;

int distSq(const dan::Point& a, const dan::Point& b)
{
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool dan::isSquare(const Shape& s)
{
  using namespace std::placeholders;
  if(s.points_.size() != 4) {
    return false;
  }

  std::vector< int > sides;
  std::transform(++s.points_.begin(), s.points_.end(), s.points_.begin(), std::back_inserter(sides), distSq);
  return std::all_of(sides.begin(), sides.end(), std::bind(std::equal_to<>(), sides.front(), _1));
}

bool dan::isTriangle(const Shape& s)
{
  return s.points_.size() == 3;
}

bool dan::isRectangle(const Shape& s)
{
  return s.points_.size() == 4;
}

bool dan::isPentagon(const Shape& s)
{
  return s.points_.size() == 5;
}

std::istream& dan::operator>>(std::istream& in, Shape& s)
{
  s.points_.clear();
  size_t n = 0;
  in >> n;
  if(!in || in.peek() != ' ') {
    return dan::fail(in);
  }

  s.points_.reserve(n);
  std::istream_iterator< Point > iPoint(in);
  std::copy_n(iPoint, n, std::back_inserter(s.points_));
  return in;
}

std::ostream& dan::operator<<(std::ostream& out, const Shape& s)
{
  out << s.points_.size() << ' ';
  std::ostream_iterator< Point > iOut(out, " ");
  std::copy(s.points_.begin(), s.points_.end(), iOut);
  return out;
}
