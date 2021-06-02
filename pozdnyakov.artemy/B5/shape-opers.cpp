#include "shape-opers.hpp"
#include <string>
#include <stdexcept>
#include <iterator>
#include <iostream>
#include <functional>
#include "shape-opers.hpp"
#include "geo-vector.hpp"
#include "functions.hpp"

namespace poz = pozdnyakov;

bool poz::isSquare(const poz::Shape& shape)
{
  if (shape.size() != 4)
  {
    return false;
  }
  poz::VectorPairs collVectors = poz::getCollinear(shape);
  if (collVectors.size() != 2)
  {
    return false;
  }
  const poz::GeoVector& vector1 = std::get< 0 >(collVectors[0]);
  const poz::GeoVector& vector2 = std::get< 1 >(collVectors[0]);
  return isPerp(vector1, vector2) && (poz::getModule(vector1) == poz::getModule(vector2));
}

bool poz::isRect(const poz::Shape& shape)
{
  if (shape.size() != 4)
  {
    return false;
  }
  poz::VectorPairs collVectors = poz::getCollinear(shape);
  if (collVectors.size() != 2)
  {
    return false;
  }
  const poz::GeoVector& vector1 = std::get< 0 >(collVectors[0]);
  const poz::GeoVector& vector2 = std::get< 1 >(collVectors[0]);
  return poz::isPerp(vector1, vector2);
}

bool poz::isTriangle(const poz::Shape& shape)
{
  return shape.size() == 3;
}

size_t poz::sizeAccum(size_t prev, const Shape& shape)
{
  return prev + shape.size();
}

const poz::Point& poz::getFirst(const poz::Shape& shape)
{
  return shape[0];
}

bool poz::comparator(const poz::Shape& shape1, const poz::Shape& shape2)
{
  if (shape1.size() < 3 || shape1.size() > 4 || shape2.size() < 3 || shape2.size() > 4)
  {
    return shape1.size() < shape2.size();
  }
  return (poz::isTriangle(shape1) || (!poz::isTriangle(shape2) && (poz::isSquare(shape1)
    || (!poz::isSquare(shape2) && (shape1.size() < shape2.size())))));
}

void poz::removeZero(std::vector< poz::Shape >& shapes)
{
  using iterator = std::vector< poz::Shape >::iterator;
  std::sort(shapes.begin(), shapes.end(), poz::valComparator< 0, poz::Shape >);
  poz::Shape zeroShape;
  iterator it2 = std::find_if_not(shapes.begin(), shapes.end(), poz::compSize< 0, poz::Shape >);
  shapes.erase(shapes.begin(), it2);
}

std::istream& poz::operator>>(std::istream& in, poz::Point& point)
{
  std::string buf;
  std::getline(in, buf, ')');
  if (in.fail() && !in.eof())
  {
    throw std::runtime_error("Incorrect input");
  }
  poz::checkLineEnding(buf);
  poz::removeWS(buf);
  if (!(buf[0] == '('))
  {
    throw std::invalid_argument("Incorrect point format");
  }
  buf.erase(0, 1);
  std::string x;
  std::string y;
  unsigned int pos = buf.find(';');
  if (pos == std::string::npos)
  {
    throw std::invalid_argument("Incorrect point format");
  }
  x = buf.substr(0, pos);
  y = buf.substr(pos + 1, buf.size() - pos);
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
  if (in.fail() && !in.eof())
  {
    throw std::invalid_argument("Invalid vertices count");
  }
  if (in.eof())
  {
    return in;
  }
  poz::Shape tempShape;
  std::copy_n(std::istream_iterator< poz::Point >(in), n, std::back_inserter(tempShape));
  if (in.eof())
  {
    return in;
  }
  shape = tempShape;
  return in;
}

std::ostream& poz::operator<<(std::ostream& out, const poz::Shape& shape)
{
  out << shape.size() << "  ";
  std::copy(shape.begin(), shape.end(), std::ostream_iterator< poz::Point >(out, " "));
  return out;
}
