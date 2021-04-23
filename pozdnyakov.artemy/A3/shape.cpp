#include "shape.hpp"
#include <stdexcept>

namespace poz = pozdnyakov;

void poz::Shape::scale(double coef)
{
  if (coef <= 0)
  {
    throw std::invalid_argument("Invalid shape argument");
  }
  unsafeScale(coef);
}
