#ifndef GEO_VECTOR_HPP
#define GEO_VECTOR_HPP

#include <iterator>
#include "point.hpp"

namespace pozdnyakov
{
  extern const int PRECISON = 10000;
  using Vectors = std::vector< GeoVector >;
  using VectorPairs = std::vector< std::pair< GeoVector, GeoVector > >;
  struct GeoVector
  {
    int i, j;
  };
  GeoVector makeGeoVector(Point& p1, Point& p2);
  void makeVectorCombinations(Shape& shape, Shape::const_iterator& it, Vectors& out);
  VectorPairs getCollinear(Shape& shape);
  void vectorInserter(Point& p1, Point& p2, Vectors& vectors);
  void collPred(GeoVector& vector1, GeoVector& vector2, VectorPairs& vectors);
  int getModule(GeoVector& vector);
  bool isPerp(GeoVector& vector1, GeoVector& vector2);
  bool isCollinear(GeoVector& vector1, GeoVector& vector2);
}

#endif
