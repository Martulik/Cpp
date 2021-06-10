#include "shape.hpp"
#include <iostream>
#include <iterator>
#include <string>
#include <algorithm>

std::istream& lebedeva::operator>>(std::istream& in, Shape& shape)
{
  std::string sVertices;
  std::getline(in >> std::ws, sVertices, ' ');
  if ((sVertices.back() == '\n') || (sVertices.empty()))
  {
    throw std::invalid_argument("Invalid input");
  }
  size_t vertices = std::stoi(sVertices);
  if (vertices < 1)
  {
    throw std::invalid_argument("Invalid number of vertices");
  }

  Shape tempShape;
  tempShape.reserve(vertices);
  std::istream_iterator< Point > inIter(in);
  std::copy_n(inIter, vertices, std::back_inserter(tempShape));
  if (!in || vertices != tempShape.size())
  {
    throw std::invalid_argument("Invalid number of vertices");
  }
  shape = std::move(tempShape);
  return in;
}

std::ostream& lebedeva::operator<<(std::ostream& out, const Shape& shape)
{
  std::ostream_iterator< Point > outIter(out, " ");
  out << shape.size() << ' ';
  std::copy(shape.begin(), shape.end(), outIter);
  return out;
}
