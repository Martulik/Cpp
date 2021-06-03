#include "shape-opers.hpp"
#include <string>
#include <stdexcept>
#include <iterator>
#include <iostream>
#include <functional>
#include "shape-opers.hpp"
#include "functions.hpp"

namespace poz = pozdnyakov;

bool poz::isSquare(const poz::Shape& shape)
{
  using namespace std::placeholders;
  using ArgFunc = std::function< void(const poz::Point&, const poz::Point&) >;
  if (shape.size() != 4)
  {
    return false;
  }
  poz::sides_accum acc;
  ArgFunc boundMem = std::bind(&sides_accum::operator(), &acc, _1, _2);
  poz::for_comb< const poz::Point&, poz::Shape::const_iterator >(shape.cbegin(), shape.cend(), boundMem);
  std::vector< int > lens
  {
    std::get< 0 >(acc.lenX1),
    std::get< 0 >(acc.lenX2),
    std::get< 0 >(acc.lenY1),
    std::get< 0 >(acc.lenY2)
  };
  auto boundEqualTo = std::bind(std::equal_to< int >(), std::placeholders::_1, 0);
  lens.erase(std::remove_if(lens.begin(), lens.end(), boundEqualTo), lens.end());
  if (lens.size() == 2)
  {
    return lens[0] == lens[1];
  }
  return false;
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

bool poz::comparator(const poz::Shape& shape1, const poz::Shape& shape2)
{
  if (shape1.size() != 4 || shape2.size() != 4)
  {
    return shape1.size() < shape2.size();
  }
  return poz::isSquare(shape1) && !poz::isSquare(shape2);
}

poz::sides_accum::sides_accum():
  lenX1({-1, -1}),
  lenX2({-1, -1}),
  lenY1({-1, -1}),
  lenY2({-1, -1})
{}

void poz::sides_accum::operator()(const poz::Point& point1, const poz::Point& point2)
{
  if (std::get< 1 >(lenX1) == -1)
  {
    std::get< 0 >(lenX1) = std::abs(point1.x - point2.x);
    std::get< 1 >(lenX1) = 1;
  }
  else if (std::get< 0 >(lenX1) == std::abs(point1.x - point2.x))
  {
    std::get< 1 >(lenX1)++;
  }
  else if (std::get< 1 >(lenX2) == -1)
  {
    std::get< 0 >(lenX2) = std::abs(point1.x - point2.x);
    std::get< 1 >(lenX2) = 1;
  }
  else if (std::get< 0 >(lenX2) == std::abs(point1.x - point2.x))
  {
    std::get< 1 >(lenX2)++;
  }
  if (std::get< 1 >(lenY1) == -1)
  {
    std::get< 0 >(lenY1) = std::abs(point1.y - point2.y);
    std::get< 1 >(lenY1) = 1;
  }
  else if (std::get< 0 >(lenY1) == std::abs(point1.y - point2.y))
  {
    std::get< 1 >(lenY1)++;
  }
  else if (std::get< 1 >(lenY2) == -1)
  {
    std::get< 0 >(lenY2) = std::abs(point1.y - point2.y);
    std::get< 1 >(lenY2) = 1;
  }
  else if (std::get< 0 >(lenY2) == std::abs(point1.y - point2.y))
  {
    std::get< 1 >(lenY2)++;
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
