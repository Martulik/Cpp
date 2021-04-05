#ifndef TEST_FUNCTIONS_HPP
#define TEST_FUNCTIONS_HPP

#include <boost/test/unit_test.hpp>
#include <memory>
#include "shape.hpp"

namespace borisova
{
  const double width = 11.5;
  const double height = 0.01;
  const double param1 = 4.12;
  const double param2 = 91.004;
  const double negParam = -12.91;

  const point_t point1{ 0.4, 2.56 };
  const point_t point2{ 65.03, 0.99 };
  const double coeff = 3.2;
  const point_t dpos{ 5.09, 11.47 };

  void paramAfterMoving(std::unique_ptr< Shape > obj);
  void areaAfterMoving(std::unique_ptr< Shape > obj);
  void areaAfterScale(std::unique_ptr< Shape > obj);
}

#endif
