#include <boost/test/unit_test.hpp>
#include "sort.hpp"
#include "strategies.hpp"
#include "test-functions.hpp"

namespace poz = pozdnyakov;

BOOST_AUTO_TEST_CASE(test_sort)
{
  std::vector< double > vector{-3.1, 5.4, 12.8, -14.3, 89.15, 13.69, 0.2, 0, 0, 12.99, -99.1};
  std::list< double > list{69.4, 3.75, -70.2, 7.85, 6.70, -6.1, -6.1, 25.1, -38.0, 2.58, 36.2, -6.15, 1.33};
  BOOST_REQUIRE(poz::testSort(vector, list, std::greater< double >()) == true);
  BOOST_REQUIRE(poz::testSort(vector, list, std::less< double >()) == true);
}
