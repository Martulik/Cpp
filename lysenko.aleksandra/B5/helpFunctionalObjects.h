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

  struct checkIfAppropriateShape
  {
    void operator()(std::vector< int >& numb, const lysenko::Shape& obj)
    {
      if (lysenko::isTriangle(obj))
      {
        numb[0]++;
        return;
      }

      if (lysenko::isSquare(obj))
      {
        numb[1]++;
        numb[2]++;
        return;
      }

      if (lysenko::isRectangle(obj))
      {
        numb[2]++;
      }
    }
  };

  void deletePentagons(std::vector< Shape >& vect, const Shape& obj);

  struct addPoint
  {
    std::vector< Point > operator()(std::vector< Point >& points, const Shape& obj)
    {
      points.insert(points.end(),obj[0]);
      return points;
    }
  };

  void doSort(std::vector< Shape >& myShp, const Shape& obj, bool (*sortType)(const Shape&));
}
#endif
