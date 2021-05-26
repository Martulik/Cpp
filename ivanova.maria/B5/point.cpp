#include "point.hpp"
#include <iostream>
#include <sstream>
#include <iterator>
#include <algorithm>

namespace iva = ivanova;

std::istream &ivanova::operator >>(std::istream &in, Shape &shp)
{
  size_t vertices = 0;
  std::string line;
  std::getline(in >> std::ws, line);
  if (line.empty())
  {
    return in;
  }
  std::istringstream iu;
  std::istringstream iss(line);
  iss >> vertices >> std::skipws;
  if (vertices < 3)
  {
    std::cerr << "invalid input";
    exit(1);
  }
  shp.reserve(vertices);
  Shape tmp;
  std::copy(std::istream_iterator< Point >(iss), std::istream_iterator < Point >(), std::back_inserter(tmp));
  if (tmp.size() != vertices)
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

bool ivanova::compare(Shape &elem1, Shape &elem2)
{
  if (elem1.size() != elem2.size())
  {
    return elem1.size() < elem2.size();
  }
  if (isRect(elem1) && isRect(elem2))
  {
    if (isSquare(elem1) && (isSquare(elem2)))
    {
      return false;
    }
    return isSquare(elem1) && isRect(elem2);
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
  std::getline(in >> std::ws, str, ')');
  std::istringstream iss(str);
  if (str.empty())
  {
    return in;
  }
  char separator = ' ';
  iss >> separator;
  if (separator != '(')
  {
    std::cerr << "invalid separator";
    exit(1);
  }
  std::string a;
  std::getline(iss, a, ';');
  point.x = std::stoi(a);
  a.clear();
  std::getline(iss, a, ')');
  point.y = std::stoi(a);
  return in;
}

std::ostream &ivanova::operator <<(std::ostream &out, const ivanova::Point &point)
{
  out << " (" << point.x << "; " << point.y << ")";
  return out;
}

bool iva::checkSidesForSquare(const Shape &shp)
{
  int ab = (shp[0].x - shp[1].x) * (shp[0].x - shp[1].x) + (shp[0].y - shp[1].y) * (shp[0].y - shp[1].y);
  int bc = (shp[1].x - shp[2].x) * (shp[1].x - shp[2].x) + (shp[1].y - shp[2].y) * (shp[1].y - shp[2].y);
  int cd = (shp[2].x - shp[3].x) * (shp[2].x - shp[3].x) + (shp[2].y - shp[3].y) * (shp[2].y - shp[3].y);
  int da = (shp[3].x - shp[0].x) * (shp[3].x - shp[0].x) + (shp[3].y - shp[0].y) * (shp[3].y - shp[0].y);
  int ac = (shp[0].x - shp[2].x) * (shp[0].x - shp[2].x) + (shp[0].y - shp[2].y) * (shp[0].y - shp[2].y);
  int bd = (shp[1].x - shp[3].x) * (shp[1].x - shp[3].x) + (shp[1].y - shp[3].y) * (shp[1].y - shp[3].y);
  if (ab == bc && bc == cd && cd == da && ac == bd && bd == ab + bc)
  {
    return true;
  }
  else return false;
}

bool ivanova::isPentagon(const ivanova::Shape &shp)
{
  return shp.size() == 5;
}
