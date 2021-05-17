#include <boost/test/unit_test.hpp>

#include "container.hpp"
#include "tools.hpp"

namespace lab = savchuk;

BOOST_AUTO_TEST_SUITE(container)

BOOST_AUTO_TEST_CASE(factorial)
{
  lab::Container cnt;
  unsigned n = 1;
  for (auto&& val: cnt)
  {
    BOOST_CHECK_EQUAL(val, lab::calcucateFactorial(n));
    ++n;
  }
}

BOOST_AUTO_TEST_SUITE_END();
