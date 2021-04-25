#include <boost/test/unit_test.hpp>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <list>
#include "strategy.hpp"
#include "functions.hpp"
#include "sort.hpp"
#include "compare.hpp"

BOOST_AUTO_TEST_SUITE(testSort)

namespace vika = dushechkina;
const auto lessComparator = vika::getSortingOrder< int >("ascending");
const auto greaterComparator = vika::getSortingOrder< int >("descending");

BOOST_FIXTURE_TEST_CASE(sortBracketsType, fixture)
{
	vika::sort< vika::Brackets >(vector, lessComparator);
	BOOST_CHECK(vector == sortedAscendingVector);
	vika::sort< vika::Brackets >(vector, greaterComparator);
	BOOST_CHECK(vector == sortedDescendingVector);
}

BOOST_FIXTURE_TEST_CASE(sortAtType, fixture)
{
	vika::sort< vika::At >(vector, lessComparator);
	BOOST_CHECK(vector == sortedAscendingVector);
	vika::sort< vika::At >(vector, greaterComparator);
	BOOST_CHECK(vector == sortedDescendingVector);
}

BOOST_FIXTURE_TEST_CASE(sortIteratorType, fixture)
{
	vika::sort< vika::Iterator >(list, lessComparator);
  BOOST_CHECK(list == sortedAscendingList);
	vika::sort< vika::Iterator >(list, greaterComparator);
  BOOST_CHECK(list == sortedDescendingList);
}

BOOST_AUTO_TEST_SUITE_END()
