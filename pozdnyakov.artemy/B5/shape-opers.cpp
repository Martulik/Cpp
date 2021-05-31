#include "shape-opers.hpp"
#include <string>
#include <stdexcept>
#include <iterator>
#include <iostream>
#include <algorithm>
#include "shape-opers.hpp"
#include "geo-vector.hpp"

namespace poz = pozdnyakov;

bool poz::isSquare(const poz::Shape& shape)
{
  if (shape.size() != 4)
  {
    return false;
  }
  poz::VectorPairs collVectors = poz::getCollinear(shape);
  const poz::GeoVector& vector1 = std::get< 0 >(collVectors[0]);
  const poz::GeoVector& vector2 = std::get< 1 >(collVectors[0]);
  return (collVectors.size() == 2) && isPerp(vector1, vector2) && (poz::getModule(vector1) == poz::getModule(vector2));
}

bool poz::isRect(const poz::Shape& shape)
{
  if (shape.size() != 4)
  {
    return false;
  }
  poz::VectorPairs collVectors = poz::getCollinear(shape);
  const poz::GeoVector& vector1 = std::get< 0 >(collVectors[0]);
  const poz::GeoVector& vector2 = std::get< 1 >(collVectors[0]);
  return (collVectors.size() == 2) && poz::isPerp(vector1, vector2);
}

bool poz::isTriangle(const poz::Shape& shape)
{
  return shape.size() == 3;
}

size_t poz::sizeAccum(size_t prev, const Shape& shape)
{
  return prev + shape.size();
}

std::istream& poz::operator>>(std::istream& in, poz::Point& point)
{
  std::string x;
  std::string y;
  in >> x >> y;
  if (in.fail() || in.bad())
  {
    throw std::runtime_error("Incorrect input");
  }
  if (!(x[0] == '(') && (x[x.length() - 1] == ';') && (y[y.length() - 1] == ')'))
  {
    throw std::invalid_argument("Incorrect shape format");
  }
  x.erase(0, 1);
  x.erase(x.length() - 1, 1);
  y.erase(y.length() - 1, 1);
  point.x = std::stoi(x);
  point.y = std::stoi(y);
  return in;
}

std::ostream& poz::operator<<(std::ostream& out, const poz::Point& point)
{
  out << '(' << point.x << "; " << point.y << ')';
  return out;
}

std::istream& poz::operator>>(std::istream& in, poz::Shape& shape)
{
  int n;
  in >> n;
  if (in.fail())
  {
    throw std::invalid_argument("Invalid vertices count");
  }
  std::copy_n(std::istream_iterator< poz::Point >(in), n, std::back_inserter(shape));
  return in;
}

std::ostream& poz::operator<<(std::ostream& out, const poz::Shape& shape)
{
  out << shape.size() << ' ';
  std::copy(shape.begin(), shape.end(), std::ostream_iterator< poz::Point >(out, " "));
  return out;
}
