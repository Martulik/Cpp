#include "shape-opers.hpp"
#include <string>
#include <stdexcept>

namespace poz = pozdnyakov;

bool poz::isSquare(const poz::Shape& shape)
{
  if (shape.size() != 4)
  {
    return false;
  }
  poz::VectorPairs collVectors = getCollinear(shape);
  const poz::GeoVector& vector1 = collVectors[0][0];
  const poz::GeoVector& vector2 = collVectors[0][1];
  return (collVectors.size() == 2) && isPerp(vector1, vector2) && (getModule(vector1) == getModule(vector2)));
}

bool poz::isRect(const poz::Shape& shape)
{
  if (shape.size() != 4)
  {
    return false;
  }
  poz::VectorPairs collVectors = getCollinear(shape);
  const poz::GeoVector& vector1 = collVectors[0][0];
  const poz::GeoVector& vector2 = collVectors[0][1];
  return (collVectors.size() == 2) && isPerp(vector1, vector2);
}

bool poz::isTriangle(const poz::Shape& shape)
{
  return shape.size() == 3;
}

std::istream& poz::operator>>(std::istream& in, poz::Point& point)
{
  std::string buf;
  std::getline(in , buf ')');
  if (buf[buf.length() - 1] != ')')
  {
    throw std::invalid_argument("Incorrect shape format");
  }
  size_t spacePos = buf.find(' ')
  std::string x;
  std::string y;
  in >> x;
  if (x[0] != '(' || x[x.length() - 1] != ';')
  {
    throw std::invalid_argument("Incorrect shape format");
  }
  x.erase(0, 1);
  x.erase(x.length - 1, 1);
  in >> y;

  y.erase(y.length - 1, 1);
  point.x = x;
  point.y = y;
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
  std::copy_n(std::istream_iterator< poz::Point > begin(in), n, std::back_inserter(shape));
}

std::ostream& poz::operator<<(std::ostream& out, const poz::Shape& shape)
{

}
