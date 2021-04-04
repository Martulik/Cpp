#include "shape.hpp"

namespace ferapontov
{
  double getX(const Shape& src)
  {
    return src.getFrameRect().pos.x;
  }

  double getY(const Shape& src)
  {
    return src.getFrameRect().pos.y;
  }

  double getHeight(const Shape& src)
  {
    return src.getFrameRect().height;
  }

  double getWidth(const Shape& src)
  {
    return src.getFrameRect().width;
  }
}

