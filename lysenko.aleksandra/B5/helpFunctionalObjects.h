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
      if (isTriangle(obj))
      {
        numb[0] += 1;
        return;
      }

      if (isSquare(obj))
      {
        numb[1] += 1;
        numb[2] += 1;
        return;
      }

      if (isRectangle(obj))
      {
        numb[2] += 1;
      }
    }
  };

  struct deletePentagons
  {
    void operator()(std::vector< Shape >& vect, const Shape& obj)
    {
      if (obj.size() == 5)
      {
        vect.erase(std::find(vect.begin(), vect.end(), obj));
      }
    }
  };

  struct addPoint
  {
    std::vector< Point > operator()(std::vector< Point >& points, const Shape& obj)
    {
      points.insert(points.end(), obj[0]);
      return points;
    }
  };

  struct doSort
  {
    void operator()(std::vector< Shape >& myShp, const Shape& obj, bool (*sortType)(const Shape&))
    {
      if (sortType(obj))
      {
        myShp.insert(myShp.end(), obj);
      }
    }
  };
}

#endif
