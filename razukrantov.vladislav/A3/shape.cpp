#include "shape.hpp"
#include <stdexcept>

void razukrantov::Shape::scale(double k)
{
  if (k < 0)
  {
	throw std::invalid_argument("The coefficient cannot be nehative");
  }
  doScale(k);
}
