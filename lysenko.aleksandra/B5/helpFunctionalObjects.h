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

  struct getNumberOfVertices
  {
    size_t operator()(const lysenko::Shape& obj) const
    {
      return obj.size();
    }
  };

  struct checkIfIsTriangle
  {
    bool operator()(const Shape& obj)
    {
      return isTriangle(obj);
    }
  };

  struct checkIfIsSquare
  {
    bool operator()(const Shape& obj)
    {
      return isSquare(obj);
    }
  };

  struct checkIfIsRectangle
  {
    bool operator()(const Shape& obj)
    {
      return isRectangle(obj);
    }
  };

  struct deletePentagons
  {
    void operator()(std::vector< Shape >& vect, const Shape& obj)
    {
      if (obj.size() != 5)
      {
        vect.insert(vect.end(), obj);
      }
    }
  };

  struct addPoint
  {
    std::vector< Point > operator()(std::vector< Point >& firstPoitsofShapes, const Shape& obj)
    {
      firstPoitsofShapes.insert(firstPoitsofShapes.end(), obj[0]);
      return firstPoitsofShapes;
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
