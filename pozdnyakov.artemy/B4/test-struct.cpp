#include <boost/test/unit_test.hpp>
#include "test-functions.hpp"

namespace poz = pozdnyakov;

BOOST_AUTO_TEST_CASE(test_struct_out)
{
  BOOST_REQUIRE(poz::testOut());
}
