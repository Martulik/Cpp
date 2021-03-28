#include "shape.hpp"

namespace dan = doroshin;

void dan::Shape::scale(double k)
{
  dan::udouble_t u_k = dan::make_abs(k);
  scaleImpl(u_k);
}
