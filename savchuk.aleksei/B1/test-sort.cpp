#include <boost/test/unit_test.hpp>

#include <vector>
#include <algorithm>

#include "access-policies.hpp"
#include "sort.hpp"
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
  lab::testSort(1, std::less< int >());
  lab::testSort(1, std::greater< int >());
  lab::testSort(5, std::less< int >());
  lab::testSort(5, std::greater< int >());
  lab::testSort(10, std::less< int >());
  lab::testSort(10, std::greater< int >());
  lab::testSort(100, std::less< int >());
  lab::testSort(100, std::greater< int >());
  lab::testSort(1000, std::less< int >());
  lab::testSort(1000, std::greater< int >());
}

BOOST_AUTO_TEST_SUITE_END();
