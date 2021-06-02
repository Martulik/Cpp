#include "geo-vector.hpp"
#include "functions.hpp"
#include <cmath>

namespace poz = pozdnyakov;

poz::GeoVector poz::makeGeoVector(const poz::Point& p1, const poz::Point& p2)
{
  return poz::GeoVector{p1.x - p2.x, p1.y - p2.y};
}

poz::VectorPairs poz::getCollinear(const Shape& shape)
{
  using namespace std::placeholders;
  poz::Vectors vectors;
  auto boundInserter = std::bind(poz::vectorInserter, _1, _2, vectors);
  poz::for_comb< poz::Point, poz::Shape::const_iterator >(shape.cbegin(), shape.cend(), boundInserter);
  poz::VectorPairs collVectors;
  auto collInserter = std::bind(poz::collPred, _1, _2, collVectors);
  poz::for_comb< poz::GeoVector, poz::Vectors::const_iterator >(vectors.cbegin(), vectors.cend(), collInserter);
  return collVectors;
}

void poz::vectorInserter(const poz::Point& p1, const poz::Point& p2, poz::Vectors& vectors)
{
  vectors.push_back(poz::makeGeoVector(p1, p2));
}

void poz::collPred(const poz::GeoVector& vector1, const poz::GeoVector& vector2, poz::VectorPairs& vectors)
{
  if (poz::isCollinear(vector1, vector2))
  {
    vectors.push_back({vector1, vector2});
  }
}

int poz::getModule(const poz::GeoVector& vector)
{
  return sqrt(pow(vector.i, 2) + pow(vector.j, 2));
}

bool poz::isPerp(const poz::GeoVector& vector1, const poz::GeoVector& vector2)
{
  return (vector1.i * vector2.i + vector2.j * vector2.j) == 0;
}

bool poz::isCollinear(const poz::GeoVector& vector1, const poz::GeoVector& vector2)
{
  //extern const int PRECISION;
  return (vector1.i * vector2.i + vector2.j * vector2.j) < (1 / poz::PRECISION);
}
