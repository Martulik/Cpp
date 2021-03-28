#include "shape.hpp"
#include <stdexcept>

void murzakanov::Shape::check(double arg, const char* mes)
{
  if (arg < 0)
  {
    throw std::invalid_argument(mes);
  }
}
