#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <vector>

namespace lysenko
{
  struct point_t
  {
    int x;
    int y;
  };

  std::istream& operator>>(std::istream& in, point_t& point);
  std::ostream& operator<<(std::ostream& out, const point_t& point);

  class Shape
  {
  public:
    friend std::istream& operator>>(std::istream& in, Shape& Shape);
  private:
    std::vector< point_t > verticles_;
  };
}

#endif