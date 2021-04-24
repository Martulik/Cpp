#include <boost/test/unit_test.hpp>

#include "test-functions.hpp"

BOOST_AUTO_TEST_SUITE(testSort)

BOOST_AUTO_TEST_CASE(sort)
{
  ferapontov::testSort(std::greater< int >(), 5);
  ferapontov::testSort(std::greater< int >(), 10);
}

BOOST_AUTO_TEST_SUITE_END()
