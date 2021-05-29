#include "geo-vector.hpp"
#include <cmath>
#include <algorithm>

namespace poz = pozdnyakov;

poz::GeoVector poz::makeGeoVector(const poz::Point& p1, const poz::Point& p2)
{
  return poz::GeoVector{p1.x - p2.x, p1.y - p2.y};
}

void poz::makeVectorCombinations(const poz::Shape& shape, poz::Shape::const_iterator& it, const poz::Vectors& out);
{
  auto boundMaker = std::bind(poz::makeGeoVector, *it, std::placeholders::_2);
  std::transform(std::next(it), shape.end(), std::back_inserter(out), boundMaker);
  return vectors;
}

poz::VectorPairs poz::getCollinear(const Shape& shape)
{
  std::vector< GetVector > vectors;
  auto boundInserter = std::bind(poz::vectorInserter, std::placeholders::_1, std::placeholders::_2, vectors);
  poz::for_comb(shape.cbegin(), shape.cend(), boundInserter);
  poz::VectorPairs collVectors;
  auto collInserter = std::bind(poz::collPred, std::placeholders::_1, std::placeholders::_2, collVectors);
  poz::for_comb(vectors.begin(), vectors.end(), collInserter);
  return collVectors;
}

void poz::vectorInserter(const poz::Point& p1, const poz::Point& p2, poz::Vectors& vectors)
{
  vectors.push_back(poz::makeGeoVector(p1, p2));
}

void poz::collPred(const GeoVector& vector1, const GeoVector& vector2, poz::VectorPairs& vectors)
{
  if (poz::isCollinear(vector1, vector2))
  {
    vectors.push_back({vector1, vector2});
  }
}

int getModule(GeoVector& vector)
{
  return sqrt(pow(vector.i, 2) + pow(vector.j, 2));
}

bool poz::isPerp(const poz::GeoVector& vector1, const poz::GeoVector& vector2)
{
  return (vector1.i * vector2.i + vector2.j * vector2.j) == 0;
}

bool poz::isCollinear(const poz::GeoVector& vector1, const poz::GeoVector& vector2)
{
  return (vector1.i * vector2.i + vector2.j * vector2.j) < (1 / poz::PRECISON);
}
