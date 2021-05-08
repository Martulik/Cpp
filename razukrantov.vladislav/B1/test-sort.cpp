#include <boost/test/unit_test.hpp>

#include "functions.hpp"
#include "sorting.hpp"
#include "strategy.hpp"

#include <functional>
#include <vector>
#include <ctime>
#include <algorithm>

void testSort(size_t size)
{
  srand(time(0));
  const char* order = "ascending";
  std::function< bool(int, int) > compare = getSortOrder< int >(order);
  std::vector< int > vector(size);
  std::vector< int > vector2(size);
  std::forward_list< int > list(size);
  std::generate(vector.begin(), vector.end(), rand);
  std::generate(vector2.begin(), vector2.end(), rand);
  std::generate(list.begin(), list.end(), rand);

  razukrantov::sort< razukrantov::bracketsAccess< int >, int >(vector, compare);
  razukrantov::sort< razukrantov::atAccess< int >, int >(vector2, compare);
  razukrantov::sort< razukrantov::iteratorAccess< int >, int >(list, compare);

  BOOST_CHECK(std::is_sorted(vector.begin(), vector.end()));
  BOOST_CHECK(std::is_sorted(vector2.begin(), vector2.end()));
  BOOST_CHECK(std::is_sorted(list.begin(), list.end()));
}

BOOST_AUTO_TEST_SUITE(sortTest)

BOOST_AUTO_TEST_CASE(sort)
{
  testSort(1);
  testSort(2);
  testSort(3);
}

BOOST_AUTO_TEST_SUITE_END()
