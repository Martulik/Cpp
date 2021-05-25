#include "shape.hpp"

#include <iostream>
#include <stdexcept>
#include <iterator>
#include <algorithm>

#include "functions.hpp"

std::ostream& pochernin::operator<<(std::ostream& out, const Point& point)
{
  out << "(" << point.x << "; " << point.y << ")";
  return out;
}

std::istream& pochernin::operator>>(std::istream& in, Point& point)
{
  std::string buffer;
  std::getline(in, buffer, '(');
  if (!std::all_of(buffer.begin(), buffer.end(), [](char ch){return ch != '\n';}))
  {
    throw(std::invalid_argument("Incorrect point reading"));
  }

  std::getline(in, buffer, ';');
  if (!std::all_of(buffer.begin(), buffer.end(), [](char ch){return ch != '\n';}))
  {
    throw(std::invalid_argument("Incorrect point reading"));
  }
  int x = 0;
  deleteExtraSpaces(buffer);
  if (isNumber(buffer))
  {
    x = std::stoi(buffer);
  }
  else
  {
    throw(std::invalid_argument("Incorrect point reading"));
  }

  std::getline(in, buffer, ')');
  if (!std::all_of(buffer.begin(), buffer.end(), [](char ch){return ch != '\n';}))
  {
    throw(std::invalid_argument("Incorrect point reading"));
  }
  int y = 0;
  deleteExtraSpaces(buffer);
  if (isNumber(buffer))
  {
    y = std::stoi(buffer);
  }
  else
  {
    throw(std::invalid_argument("Incorrect point reading"));
  }

  point.x = x;
  point.y = y;

  return in;
}

std::ostream& pochernin::operator<<(std::ostream& out, const Shape& shape)
{
  out << shape.size() << " ";
  std::copy(shape.begin(), shape.end(), std::ostream_iterator< Point >(out, " "));
  return out;
}

std::istream& pochernin::operator>>(std::istream& in, Shape& shape)
{
  size_t count = 0;
  in >> count;
  if ((!in.eof() && in.fail()) || in.bad())
  {
    throw(std::invalid_argument("Incorrect shape reading"));
  }
  if (count == 0)
  {
    return in;
  }

  Shape temp;
  std::copy_n(std::istream_iterator< Point >(in), count, std::back_inserter(temp));

  std::string remaining;
  std::getline(in, remaining);
  if (!std::all_of(remaining.begin(), remaining.end(), ::isspace))
  {
    throw(std::invalid_argument("Incorrect shape reading"));
  }

  shape.swap(temp);

  return in;
}

bool pochernin::operator<(const Shape& lhs, const Shape& rhs)
{
  if ((lhs.size() > 4) && (rhs.size() > 4))
  {
    return false;
  }
  if ((lhs.size() == 4) && (rhs.size() == 4))
  {
    return isSquare(lhs);
  }
  return lhs.size() < rhs.size();
}
