#include "shape.hpp"
#include "exceptions.hpp"

void pozdnyakov::Shape::scale(double coef)
{
  if (coef <= 0)
  {
    throw pozdnyakov::ScaleException();
  }
  safeScale(coef);
}
