#ifndef HELP_FUNCTIONAL_OBJECTS_H
#define HELP_FUNCTIONAL_OBJECTS_H

#include <vector>
#include <functional>

#include "Shape.h"

namespace lysenko
{
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

  void shapeSort(std::vector< Shape >& vect);

}

#endif
