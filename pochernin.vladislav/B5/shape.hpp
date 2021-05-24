#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <vector>

namespace pochernin
{
  struct Point
  {
    int x, y;
  };

  using Shape = std::vector< Point >;
}

#endif
