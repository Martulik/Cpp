#include <boost/test/unit_test.hpp>

#include <functional>
#include <vector>
#include <cstddef>

#include "test-utility.hpp"

namespace lab = savchuk;

BOOST_AUTO_TEST_SUITE(sort)

BOOST_AUTO_TEST_CASE(empty)
{
  lab::testSort(0, std::less< int >());
  lab::testSort(0, std::greater< int >());
}

BOOST_AUTO_TEST_CASE(not_empty)
{
  std::vector< size_t > sizes = { 1, 2, 3, 5, 10, 100, 1000 };
  for (size_t& size: sizes)
  {
    lab::testSort(size, std::less< int >());
    lab::testSort(size, std::greater< int >());
  }
}

BOOST_AUTO_TEST_SUITE_END();
