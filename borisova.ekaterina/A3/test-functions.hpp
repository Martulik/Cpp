#ifndef TEST_FUNCTIONS_HPP
#define TEST_FUNCTIONS_HPP

#include <boost/test/unit_test.hpp>
#include "shape.hpp"

namespace borisova
{
  const double coeff = 3.2;
  const point_t dpos{ 5.09, 11.47 };

  void paramAfterMoving(Shape* obj);
  void areaAfterMoving(Shape* obj);
  void areaAfterScale(Shape* obj);
}

#endif
