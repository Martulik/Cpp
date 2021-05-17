#include "point.hpp"
#include <iostream>
#include <algorithm>
#include <iterator>
#include <cmath>

namespace iva = ivanova;

namespace ivanova
{
  bool checkDiagonalsAndSides(const Shape &shp);
  bool checkNum(std::string &num);
}
bool iva::isRect(const iva::Shape &shp)
{
  return (shp.size() == 4 && iva::checkDiagonalsAndSides(shp));
}

bool iva::isTriangle(const iva::Shape &shp)
{
  return (shp.size() == 3);
}

bool iva::isSquare(const iva::Shape &shp)
{
  return (isRect(shp) && iva::checkDiagonalsAndSides(shp));
}

bool iva::isPentagon(const iva::Shape &shp)
{
  return (shp.size() == 5);
}

std::istream &ivanova::operator >>(std::istream &in, ivanova::Point &point)
{
  std::string str;
  std::getline(in, str, '(');
  std::getline(in, str, ';');
  if (!checkNum(str))
  {
    std::cerr << "invalid input";
    exit(1);
  }
  point.x = std::stoi(str);
  std::getline(in, str, ')');
  if (!checkNum(str))
  {
    std::cerr << "invalid input";
    exit(1);
  }
  point.y = std::stoi(str);
  return in;
}

std::ostream &ivanova::operator <<(std::ostream &out, const ivanova::Point &point)
{
  out << '(' << point.x << ';' << point.y << ')' << ' ';
  return out;
}

bool iva::checkDiagonalsAndSides(const iva::Shape &shp)
{
  int ab = std::pow(shp[0].x - shp[1].x, 2);
  int bc = std::pow(shp[1].x - shp[2].x, 2);
  int cd = std::pow(shp[2].x - shp[3].x, 2);
  int da = std::pow(shp[3].x - shp[0].x, 2);
  int ac = std::pow(shp[0].x - shp[2].x, 2);
  int bd = std::pow(shp[1].x - shp[3].x, 2);
  if (ab == bc && bc == cd && cd == da && ac == bd && ac == ab + bc)
  {
    return true;
  }
  else if (ab == cd && bc == da && ac == bd && ac == ab + bc)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool iva::checkNum(std::string &num)
{
  auto b = (std::any_of(num.begin(), num.end(), [](const char &elem) { return (std::isdigit(elem)); }));
  return b;
}