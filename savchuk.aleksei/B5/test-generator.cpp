#include <array>
#include <cstddef>
#include <algorithm>

#include <boost/test/unit_test.hpp>

#include "shape-generator.hpp"
#include "test-tools.hpp"

namespace lab = savchuk;

BOOST_AUTO_TEST_SUITE(shape_generator)

BOOST_AUTO_TEST_CASE(correct_square)
{
  const size_t SIZE = 1000;
  std::array< lab::Shape, SIZE > arr;
  std::generate(arr.begin(), arr.end(), lab::ShapeGenerator());
  std::for_each(arr.cbegin(), arr.cend(), lab::checkRandomShape);
}

BOOST_AUTO_TEST_SUITE_END();
