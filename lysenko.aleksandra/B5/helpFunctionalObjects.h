#ifndef HELP_FUNCTIONAL_OBJECTS_H
#define HELP_FUNCTIONAL_OBJECTS_H

#include <vector>
#include <functional>
#include <algorithm>
#include <iterator>

#include "Shape.h"
#include "helpFunctionalObjects.h"

namespace lysenko
{
  bool isTriangle(const Shape& obj);
  bool isRectangle(const Shape& obj);
  bool isSquare(const Shape& obj);
  bool isPentagon(const Shape& obj);

  struct getNumberOfVertices
  {
    size_t operator()(const lysenko::Shape& obj) const
    {
      return obj.size();
    }
  };

  struct addPoint
  {
    std::vector< Point > operator()(std::vector< Point >& firstPoitsofShapes, const Shape& obj)
    {
      firstPoitsofShapes.push_back(obj[0]);
      return firstPoitsofShapes;
    }
  };

  struct addShape
  {
    std::vector< Shape > operator()(std::vector< Shape >& shapes, const Shape& obj)
    {
      shapes.push_back(obj);
      return shapes;
    }
  };

  struct fillTheVect
  {
    std::vector< double > operator()(std::vector< double >& distances, const double& dist)
    {
      distances.push_back(dist);
      return distances;
    }
  };

  void shapeSort(std::vector< Shape >& vect);
}

#endif
