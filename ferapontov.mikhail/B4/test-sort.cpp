#include <boost/test/unit_test.hpp>

#include <vector>
#include <algorithm>
#include "DataStruct.hpp"

BOOST_AUTO_TEST_SUITE(TestSort)

BOOST_AUTO_TEST_CASE(sort)
{
  std::vector< ferapontov::DataStruct > unsortedVec;
  unsortedVec = {{5, 5, "data"}, {-1, -1, "sort"}, {-4, 2, "sorted moment"}};
  std::vector< ferapontov::DataStruct > sortedVec;
  sortedVec = {{-4, 2, "sorted moment"}, {-1, -1, "sort"}, {5, 5, "data"}};
  std::sort(unsortedVec.begin(), unsortedVec.end());
  BOOST_CHECK(unsortedVec == sortedVec);
}

BOOST_AUTO_TEST_SUITE_END()
