#ifndef TEST_FUNCTIONS_HPP
#define TEST_FUNCTIONS_HPP

#include <boost/test/unit_test.hpp>
#include <memory>
#include "shape.hpp"

namespace borisova
{
  const double coeff = 3.2;
  const point_t dpos{ 5.09, 11.47 };

  void paramAfterMoving(std::unique_ptr< Shape > obj);
  void areaAfterMoving(std::unique_ptr< Shape > obj);
  void areaAfterScale(std::unique_ptr< Shape > obj);
  std::unique_ptr< Shape > makeComposite();
}

#endif
