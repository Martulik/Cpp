#ifndef TEST_FUNCTIONS_HPP
#define TEST_FUNCTIONS_HPP

#include <boost/test/unit_test.hpp>
#include "shape.hpp"

namespace borisova
{
  double width = 11.5;
  double height = 0.01;
  double param1 = 4.12;
  double param2 = 91.004;
  double negParam = -12.91;
  double coeff = 3.2;

  point_t dpos{ 5.09, 11.47 };
  point_t point1{ 0.4, 2.56 };
  point_t point2{ 65.03, 0.99 };
  point_t point3{ param1, param2 };

  void paramAfterMoving(Shape* obj);
  void areaAfterMoving(Shape* obj);
  void areaAfterScale(Shape* obj);
}

#endif
