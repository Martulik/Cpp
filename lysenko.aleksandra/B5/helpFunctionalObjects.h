#ifndef HELP_FUNCTIONAL_OBJECTS_H
#define HELP_FUNCTIONAL_OBJECTS_H

#include <vector>

#include "Shape.h"

namespace lysenko
{
  bool isTriangle(const Shape& obj) noexcept;
  bool isRectangle(const Shape& obj) noexcept;
  bool isSquare(const Shape& obj) noexcept;

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

  void deletePentagons(std::vector< Shape >& vect, const lysenko::Shape& obj);

  struct addPoint
  {
    std::vector< Point > operator()(std::vector< Point >& points, const lysenko::Shape& obj)
    {
      points.insert(points.end(),obj[0]);
      return points;
    }
  };
}
#endif