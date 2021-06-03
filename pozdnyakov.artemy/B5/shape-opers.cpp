#include "shape-opers.hpp"
#include <string>
#include <stdexcept>
#include <iterator>
#include <iostream>
#include <functional>
#include <cmath>
#include "shape-opers.hpp"
#include "functions.hpp"

namespace poz = pozdnyakov;

bool poz::isSquare(const poz::Shape& shape)
{
  using namespace std::placeholders;
  using FuncType = std::function< void(const poz::Point&) >;
  if (shape.size() != 4)
  {
    return false;
  }
  poz::sides_accum acc;
  FuncType boundMem = std::bind(&sides_accum::operator(), &acc, shape[0], _1);
  std::for_each(shape.begin() + 1, shape.end(), boundMem);
  return std::get< 1 >(acc.len1) >= 2 || std::get< 1 >(acc.len2) >= 2;
}

bool poz::isRect(const poz::Shape& shape)
{
  return shape.size() == 4;
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

int poz::getSquareDistance(const poz::Point& point1, const poz::Point& point2)
{
  return pow(point1.x - point2.x, 2) + pow(point1.y - point2.y, 2);
}

bool poz::comparator(const poz::Shape& shape1, const poz::Shape& shape2)
{
  if (shape1.size() != 4 || shape2.size() != 4)
  {
    return shape1.size() < shape2.size();
  }
  return poz::isSquare(shape1) && !poz::isSquare(shape2);
}

poz::sides_accum::sides_accum():
  len1({-1, -1}),
  len2({-1, -1})
{}

void poz::sides_accum::operator()(const poz::Point& point1, const poz::Point& point2)
{
  int dist = poz::getSquareDistance(point1, point2);
  if (std::get< 1 >(len1) == -1)
  {
    std::get< 0 >(len1) = dist;
    std::get< 1 >(len1) = 1;
  }
  else if (std::get< 0 >(len1) == dist)
  {
    std::get< 1 >(len1)++;
  }
  else if (std::get< 1 >(len2) == -1)
  {
    std::get< 0 >(len2) = dist;
    std::get< 1 >(len2) = 1;
  }
  else if (std::get< 0 >(len2) == dist)
  {
    std::get< 1 >(len2)++;
  }
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
  size_t pos = buf.find(';');
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
