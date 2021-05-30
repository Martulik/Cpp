#ifndef HELP_FUNCTIONAL_OBJECTS_H
#define HELP_FUNCTIONAL_OBJECTS_H

#include <vector>
#include <functional>

#include "Shape.h"

namespace lysenko
{
  bool isTriangle(const Shape& obj);
  bool isRectangle(const Shape& obj);
  bool isSquare(const Shape& obj);

  struct getNumberOfVerticals
  {
    size_t operator()(const lysenko::Shape& obj) const
    {
      return obj.size();
    }
  };

  void checkIfAppropriateShape(std::vector< int >& numb, const lysenko::Shape& obj);

  void deletePentagons(std::vector< Shape >& vect, const Shape& obj);

  struct addPoint
  {
    std::vector< Point > operator()(std::vector< Point >& points, const Shape& obj)
    {
      points.insert(points.end(), obj[0]);
      return points;
    }
  };

  void doSort(std::vector< Shape >& myShp, const Shape& obj, bool (*sortType)(const Shape&));
}
#endif
