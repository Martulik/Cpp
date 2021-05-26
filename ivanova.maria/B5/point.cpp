#include "point.hpp"
#include <iostream>
#include <iterator>
#include <algorithm>
#include <cmath>
#include <functional>
namespace iva = ivanova;

std::istream &ivanova::operator >>(std::istream &in, Shape &shp)
{
  unsigned int vCount = 0;
  std::string vert;
  in >> vert;
  if (vert.empty())
  {
    return in;
  }
  vCount = std::stoi(vert);
  if (vCount < 3)
  {
    std::cerr << "invalid input";
    exit(1);
  }
  shp.reserve(vCount);
  Shape tmp;
  std::copy_n(std::istream_iterator< Point >(in), vCount, std::back_inserter(tmp));
  std::getline(in, vert);
  if ((!in.eof() && !in) || tmp.size() != vCount || !std::all_of(vert.begin(), vert.end(), ::isspace))
  {
    std::cerr << "invalid input";
    exit(1);
  }
  shp.swap(tmp);
  return in;
}

std::ostream &ivanova::operator <<(std::ostream &out, const Shape &elem)
{
  out << elem.size();
  std::copy(elem.begin(), elem.end(), std::ostream_iterator< Point >(out));
  return out;
}

bool ivanova::compare(const Shape &elem1, const Shape &elem2)
{
  if (!(elem1.size() > 4 && elem2.size() > 4))
  {
    if (elem1.size() == 4 && elem2.size() == 4)
    {
      return checkSidesForSquare(elem1) && !checkSidesForSquare(elem2);
    }
    return elem1.size() < elem2.size();
  }
  return false;
}

unsigned int ivanova::countVertices(unsigned int sum, const Shape& shp)
{
  sum += shp.size();
  return sum;
}

ivanova::Point ivanova::getFront(const ivanova::Shape &shp)
{
  return shp.front();
}

bool iva::isRect(const Shape &shp)
{
  return shp.size() == 4;
}

bool iva::isTriangle(const Shape &shp)
{
  return shp.size() == 3;
}

bool iva::isSquare(const Shape &shp)
{
  return shp.size() == 4 && iva::checkSidesForSquare(shp);
}

std::istream &ivanova::operator >>(std::istream &in, ivanova::Point &point)
{
  std::string str;
  std::getline(in, str, '(');
  if (!std::all_of(str.begin(), str.end(), ::isspace) || str.find('\n') != std::string::npos)
  {
    std::cerr << "invalid input";
    exit(1);
  }
  std::getline(in, str, ')');
  if (!str.find(';'))
  {
    std::cerr << "invalid separator";
    exit(1);
  }
  std::string x = str.substr(0, str.find(';'));
  point.x = std::stoi(x);
  std::string y = str.substr(str.find(';') + 1);
  point.y = std::stoi(y);
  return in;
}

std::ostream &ivanova::operator <<(std::ostream &out, const ivanova::Point &point)
{
  out << " (" << point.x << "; " << point.y << ")";
  return out;
}

bool iva::checkSidesForSquare(const Shape &shp)
{
  int last = getSide(shp.front(), shp.back());
  std::vector < int > temp;
  temp.reserve(shp.size());
  std::transform(shp.begin() + 1, shp.end(), shp.begin(), std::back_inserter(temp), getSide);
  return (std::all_of(temp.begin(), temp.end(), std::bind(std::equal_to<> (), std::placeholders::_1, last)));
}

bool ivanova::isPentagon(const ivanova::Shape &shp)
{
  return shp.size() == 5;
}

int ivanova::getSide(const ivanova::Point &a, const ivanova::Point &b)
{
  return std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2);
}
