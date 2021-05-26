#include "shape.hpp"
#include <iostream>
#include <iterator>
#include <algorithm>

namespace lab = borisova;

bool lab::operator<(const Shape& firstShape, const Shape& secondShape)
{
  if (firstShape.size() > 4 && secondShape.size() > 4)
  {
    return false;
  }
  if ((firstShape.size() == secondShape.size()) && (firstShape.size() == 4))
  {
    return isSquare(firstShape);
  }
  return firstShape.size() < secondShape.size();
}

std::istream& lab::operator>>(std::istream& in, Shape& shape)
{
  size_t peaks;
  std::string line;
 // in >> peaks;
  if (!(in >> peaks))
  {
    return in;
  }
  if (peaks <= 2)
  {
    throw std::invalid_argument("Invalid figure\n");
  }

  Shape temp;
  std::copy_n(std::istream_iterator< Point >(in), peaks, std::back_inserter(temp));
  if ((in.fail() && !in.eof()) || temp.size() != peaks)
  {
    throw std::invalid_argument("Invalid number of peaks");
  }
  shape = temp;
  return in;
}

std::ostream& lab::operator<<(std::ostream& out, const Shape& shape)
{
  out << shape.size() << ' ';
  std::copy(shape.begin(), shape.end(), std::ostream_iterator< Point >(out, " "));
  return out;
}

bool lab::isTriangle(const Shape& shape)
{
  return (shape.size() == 3);
}

bool lab::isSquare(const Shape& shape)
{
  return (isRectangle(shape) &&
      getDistance(shape.at(0), shape.at(1)) == getDistance(shape.at(1), shape.at(2)));
}

bool lab::isRectangle(const Shape& shape)
{
  if (shape.size() == 4)
  {
    if (isPerpendicularity(shape.at(0), shape.at(1), shape.at(2)) &&
        isPerpendicularity(shape.at(1), shape.at(2), shape.at(3)) &&
          isPerpendicularity(shape.at(2), shape.at(3), shape.at(0)))
    {
      return true;
    }
  }
  return false;
}

bool lab::isPentagon(const Shape& shape)
{
  return (shape.size() == 5);
}

int lab::countPeaks(int peaks, const Shape& src)
{
  return peaks + src.size();
}

lab::Point lab::returnBack(const Shape& src)
{
  return src.back();
}
