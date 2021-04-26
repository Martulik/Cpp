#include <boost/test/unit_test.hpp>

#include "test-functions.hpp"

BOOST_AUTO_TEST_SUITE(testSort)

BOOST_AUTO_TEST_CASE(sort)
{
  std::string amode = "ascending";
  std::string dmode = "descending";
  ferapontov::testSort(amode, 5);
  ferapontov::testSort(amode, 10);
  ferapontov::testSort(amode, 50);
  ferapontov::testSort(dmode, 5);
  ferapontov::testSort(dmode, 10);
  ferapontov::testSort(dmode, 50);
}

BOOST_AUTO_TEST_SUITE_END()
