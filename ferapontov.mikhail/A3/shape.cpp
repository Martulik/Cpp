#include "shape.hpp"
#include <stdexcept>

namespace ferapontov
{
  void Shape::scale(const double k)
  {
    if(k <= 0)
    {
      throw std::invalid_argument("Scale factor must be positive");
    }
    doScale(k);
  }

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
