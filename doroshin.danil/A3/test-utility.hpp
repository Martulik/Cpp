#include <boost/test/unit_test.hpp>
#include "base-types.hpp"
#include "shape.hpp"

namespace doroshin
{
  void equal_size(const rectangle_t&, const rectangle_t&);

  void test_move_rel(Shape&, point_t);

  void test_move_abs(Shape&, point_t);

  void test_scale(Shape&, udouble_t coeff);
}
