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
  if (!(in >> peaks))
  {
    return in;
  }
  if (peaks <= 2)
  {
    throw std::invalid_argument("Invalid figure\n");
  }
  Shape temp;
  temp.reserve(peaks);
  std::copy_n(std::istream_iterator< Point >(in), peaks, std::back_inserter(temp));
  if ((in.fail() && !in.eof()) || temp.size() != peaks)
  {
    throw std::invalid_argument("Invalid number of peaks");
  }
  std::swap(shape, temp);
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

bool lab::isSquare(const Shape& src)
{
  return isRectangle(src) && equalAdjacentDistance(src);
}

bool lab::isRectangle(const Shape& src)
{
  return (src.size() == 4) && isPerpendicularity(src[0], src[1], src[2]) && equalOpposite(src);
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

bool lab::equalAdjacentDistance(const Shape& src)
{
  int first = getSquareDistance(src[0], src[1]);
  int second = getSquareDistance(src[1], src[2]);
  return first == second;
}

bool lab::equalOpposite(const Shape& src)
{
  int first = getSquareDistance(src[0], src[1]);
  int second = getSquareDistance(src[2], src[3]);
  int third = getSquareDistance(src[1], src[2]);
  int fourth = getSquareDistance(src[3], src[0]);
  return (first == second) && (third == fourth);
}
