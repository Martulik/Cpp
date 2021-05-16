#include <boost/test/unit_test.hpp>

#include "FactorialContainer.hpp"

BOOST_AUTO_TEST_SUITE(test_factorial)

BOOST_AUTO_TEST_CASE(correct_values)
{
  shkurov::FactorialContainer cont;
  std::vector< unsigned long > factorials({1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800});
  BOOST_CHECK_EQUAL_COLLECTIONS(factorials.begin(), factorials.end(), cont.begin(), cont.end());
}

BOOST_AUTO_TEST_SUITE_END()

