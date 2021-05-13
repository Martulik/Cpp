#include <boost/test/unit_test.hpp>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <list>
#include "strategy.hpp"
#include "functions.hpp"
#include "sort.hpp"
#include "compare.hpp"

namespace vika = dushechkina;

const auto lessComparator = vika::getSortingOrder< int >("ascending");
const auto greaterComparator = vika::getSortingOrder< int >("descending");

struct f
{
  std::vector< int > vector;
  std::list< int > list;
  std::vector< int > sortedAscendingVector;
  std::list< int > sortedAscendingList;
  std::vector< int > sortedDescendingVector;
  std::list< int > sortedDescendingList;
  f():
    vector({ 4, 8, 2, 7, -13 }),
    list({ 4, 8, 2, 7, -13 }),
    sortedAscendingVector(vector),
    sortedAscendingList(list)
  {
    std::sort(sortedAscendingVector.begin(), sortedAscendingVector.end());
    sortedDescendingVector = sortedAscendingVector;
    std::reverse(sortedDescendingVector.begin(), sortedDescendingVector.end());
    sortedAscendingList.sort();
    sortedDescendingList = sortedAscendingList;
    sortedDescendingList.reverse();
  }
};

BOOST_FIXTURE_TEST_SUITE(testSort, f)
  BOOST_AUTO_TEST_CASE(sortBracketsType)
  {
    vika::sort< vika::Brackets >(vector, lessComparator);
    BOOST_CHECK(vector == sortedAscendingVector);
    vika::sort< vika::Brackets >(vector, greaterComparator);
    BOOST_CHECK(vector == sortedDescendingVector);
  }

  BOOST_AUTO_TEST_CASE(sortAtType)
  {
    vika::sort< vika::At >(vector, lessComparator);
    BOOST_CHECK(vector == sortedAscendingVector);
    vika::sort< vika::At >(vector, greaterComparator);
    BOOST_CHECK(vector == sortedDescendingVector);
  }

  BOOST_AUTO_TEST_CASE(sortIteratorType)
  {
    vika::sort< vika::Iterator >(list, lessComparator);
    BOOST_CHECK(list == sortedAscendingList);
    vika::sort< vika::Iterator >(list, greaterComparator);
   BOOST_CHECK(list == sortedDescendingList);
  }
BOOST_AUTO_TEST_SUITE_END()
