#include "tools.hpp"
#include <cmath>
#include <limits>
#include "shape.hpp"

bool murzakanov::checkIsRectangle(const Shape& shp)
{

}

bool murzakanov::checkIsSquare(const Shape& shp)
{

}

bool murzakanov::isEqual(double op1, double op2)
{
  return std::fabs(op1 - op2) < std::numeric_limits< double >::epsilon;
}

double murzakanov::getDistance(const Point& p1, const Point& p2)
{
  return (sqrt(pow(p1.x - p2.x), 2) + pow(p1.y - p2.y, 2));
}
