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
  
  struct checkIsRectangle
  {
    int operator()(const lysenko::Shape& obj) const
    {
      if (isRectangle(obj))
      {
        return 1;
      }
      else
      {
        return 0;
      }
    }
  };

  struct checkIsTriangle
  {
    int operator()(const lysenko::Shape& obj) const
    {
      if (isTriangle(obj))
      {
        return 1;
      }
      else
      {
        return 0;
      }
    }
  };

  struct checkIsSquare
  {
    int operator()(const lysenko::Shape& obj) const
    {
      if (isSquare(obj))
      {
        return 1;
      }
      else
      {
        return 0;
      }
    }
  };

  /*struct checkIfAppropriateShape
  {
    void operator()(std::vector< int > numb, const lysenko::Shape& obj)
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
  };*/
}
#endif