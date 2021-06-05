#include "shape.hpp"
#include "tools.hpp"

#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>

namespace lab = shkurov;

std::istream& lab::operator>>(std::istream& in, lab::Point& point)
{
  in >> std::ws;

  if (in.get() != '(')
  {
    in.setstate(std::ios::failbit);
    return in;
  }

  in >> std::ws;
  if (in.peek() == '\n')
  {
    in.setstate(std::ios::failbit);
    return in;
  }

  int x = 0;
  in >> x;

  in >> std::ws;
  if (in.get() != ';')
  {
    in.setstate(std::ios::failbit);
    return in;
  }

  in >> std::ws;
  if (in.peek() == '\n')
  {
    in.setstate(std::ios::failbit);
    return in;
  }

  int y = 0;
  in >> y;

  in >> std::ws;
  if (in.get() != ')')
  {
    in.setstate(std::ios::failbit);
    return in;
  }

  point.x = x;
  point.y = y;

  return in;
}

std::istream& lab::operator>>(std::istream& in, lab::Shape& shape)
{
  unsigned int vertices = 0;
  in >> vertices;

  if (in.eof())
  {
    return in;
  }

  if (in.get() != ' ')
  {
    in.setstate(std::ios::failbit);
    return in;
  }
  Shape temp(vertices);
  std::copy_n(std::istream_iterator< Point >(in), vertices, temp.begin());
  std::swap(temp, shape);

  return in;
}

std::ostream& lab::operator<<(std::ostream& out, const lab::Point& point)
{
  out << " (" << point.x << ';' << point.y << ") ";

  return out;
}

std::ostream& lab::operator<<(std::ostream& out, const lab::Shape& shape)
{
  out << shape.size() << "  ";
  std::copy(shape.begin(), shape.end(), std::ostream_iterator< lab::Point >(out, " "));

  return out;
}

bool lab::operator<(const lab::Shape& lhs, const lab::Shape& rhs)
{
  if (lhs.size() == 4 && rhs.size() == 4)
  {
    return isRectangle(lhs) && isSquare(rhs);
  }
  else
  {
    return lhs.size() < rhs.size();
  }
}
