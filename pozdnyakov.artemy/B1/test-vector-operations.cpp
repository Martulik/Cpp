#include <boost/test/unit_test.hpp>
#include <vector>
#include "test-functions.hpp"

namespace poz = pozdnyakov;

BOOST_AUTO_TEST_SUITE(test_vector_operations)

  BOOST_AUTO_TEST_CASE(test_add_ones)
  {
    std::vector< int > vector{12, 3, -14, 15, -92, 6, 88, -8, 322};
    BOOST_REQUIRE(poz::testAddOnes(vector));
  }

  BOOST_AUTO_TEST_CASE(test_erase_even)
  {
    std::vector< int > vector{25, -40, 39, 25, -8, 22, 83, 36, -47, 58, 80, -52, 58};
    BOOST_REQUIRE(poz::testEraseEven(vector));
  }

BOOST_AUTO_TEST_SUITE_END()
