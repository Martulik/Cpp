#include "point.hpp"
#include <iostream>
#include <sstream>
#include <iterator>

namespace iva = ivanova;

bool iva::isRect(const iva::Shape &shp)
{
  return (shp.size() == 4 && iva::checkSidesForRectangle(shp));
}

bool iva::isTriangle(const iva::Shape &shp)
{
  return (shp.size() == 3);
}

bool iva::isSquare(const iva::Shape &shp)
{
  return (isRect(shp) && iva::checkSidesForSquare(shp));
}

bool iva::isPentagon(const iva::Shape &shp)
{
  return (shp.size() == 5);
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
  iss >> point.x;
  iss >> separator;
  if (separator == ';')
  {
    iss >> point.y;
    return in;
  }
  else
  {
    std::cerr << "invalid separator";
    exit(1);
  }
}

std::ostream &ivanova::operator <<(std::ostream &out, const ivanova::Point &point)
{
  out << " (" << point.x << "; " << point.y << ")";
  return out;
}

//int iva::getSide(const Point &a, const Point &b)
//{
//  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
//}
bool iva::checkSidesForRectangle(const Shape &shp)
{
//          getSide(shp[0], shp[1]);
//  int bc = getSide(shp[1], shp[2]);
//  int cd = getSide(shp[2], shp[3]);
//  int da = getSide(shp[3], shp[0]);
//  int ac = getSide(shp[0], shp[2]);
//  int bd = getSide(shp[1], shp[3]);
  int ab = (shp[0].x - shp[1].x) * (shp[0].x - shp[1].x) + (shp[0].y - shp[1].y) * (shp[0].y - shp[1].y);
  int bc = (shp[1].x - shp[2].x) * (shp[1].x - shp[2].x) + (shp[1].y - shp[2].y) * (shp[1].y - shp[2].y);
  int cd = (shp[2].x - shp[3].x) * (shp[2].x - shp[3].x) + (shp[2].y - shp[3].y) * (shp[2].y - shp[3].y);
  int da = (shp[3].x - shp[0].x) * (shp[3].x - shp[0].x) + (shp[3].y - shp[0].y) * (shp[3].y - shp[0].y);
  int ac = (shp[0].x - shp[2].x) * (shp[0].x - shp[2].x) + (shp[0].y - shp[2].y) * (shp[0].y - shp[2].y);
  int bd = (shp[3].x - shp[1].x) * (shp[3].x - shp[1].x) + (shp[3].y - shp[1].y) * (shp[1].y - shp[3].y);
  if (ab == cd && bc == da && ac == bd && bd == ab + bc)
  {
    return true;
  }
  return false;
}
bool iva::checkSidesForSquare(const Shape &shp)
{
//  int ab = getSide(shp[0], shp[1]);
//  int bc = getSide(shp[1], shp[2]);
//  int cd = getSide(shp[2], shp[3]);
//  int da = getSide(shp[3], shp[0]);
//  int ac = getSide(shp[0], shp[2]);
//  int bd = getSide(shp[1], shp[3]);
  int ab = (shp[0].x - shp[1].x) * (shp[0].x - shp[1].x) + (shp[0].y - shp[1].y) * (shp[0].y - shp[1].y);
  int bc = (shp[1].x - shp[2].x) * (shp[1].x - shp[2].x) + (shp[1].y - shp[2].y) * (shp[1].y - shp[2].y);
  int cd = (shp[2].x - shp[3].x) * (shp[2].x - shp[3].x) + (shp[2].y - shp[3].y) * (shp[2].y - shp[3].y);
  int da = (shp[3].x - shp[0].x) * (shp[3].x - shp[0].x) + (shp[3].y - shp[0].y) * (shp[3].y - shp[0].y);
  int ac = (shp[0].x - shp[2].x) * (shp[0].x - shp[2].x) + (shp[0].y - shp[2].y) * (shp[0].y - shp[2].y);
  int bd = (shp[3].x - shp[1].x) * (shp[3].x - shp[1].x) + (shp[3].y - shp[1].y) * (shp[1].y - shp[3].y);
  if (ab == bc && bc == cd && cd == da && ac == bd && bd == ab + bc)
  {
    return true;
  }
  else return false;
}
