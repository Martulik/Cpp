#define BOOST_TEST_MODULE B3
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_suite)

BOOST_AUTO_TEST_CASE(test_case)
{
  BOOST_REQUIRE(1 == 1);
}

BOOST_AUTO_TEST_SUITE_END()