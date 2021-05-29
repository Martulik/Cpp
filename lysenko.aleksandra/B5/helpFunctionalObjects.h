#ifndef HELP_FUNCTIONAL_OBJECTS_H
#define HELP_FUNCTIONAL_OBJECTS_H

#include "Shape.h"

namespace lysenko
{
  struct getNumberOfVerticals
  {
    size_t operator()(const lysenko::Shape& obj) const
    {
      return obj.size();
    }
  };
}
#endif