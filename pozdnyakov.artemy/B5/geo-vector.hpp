#ifndef GEO_VECTOR_HPP
#define GEO_VECTOR_HPP

#include <iterator>
#include "point.hpp"

namespace pozdnyakov
{
  const int PRECISION = 10000;
  struct GeoVector
  {
    int i, j;
  };
  using Vectors = std::vector< GeoVector >;
  using VectorPairs = std::vector< std::pair< GeoVector, GeoVector > >;
  GeoVector makeGeoVector(const Point& p1, const Point& p2);
  VectorPairs getCollinear(const Shape& shape);
  void vectorInserter(const Point& p1, const Point& p2, Vectors& vectors);
  void collPred(const GeoVector& vector1, const GeoVector& vector2, VectorPairs& vectors);
  int getModule(const GeoVector& vector);
  bool isPerp(const GeoVector& vector1, const GeoVector& vector2);
  bool isCollinear(const GeoVector& vector1, const GeoVector& vector2);
}

#endif
