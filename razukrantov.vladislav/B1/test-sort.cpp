#include <boost/test/unit_test.hpp>

#include "functions.hpp"
#include "sorting.hpp"
#include "strategy.hpp"

#include <functional>
#include <vector>
#include <ctime>
#include <algorithm>

void testSort(const char* order, size_t size)
{
  srand(time(0));
  std::function< bool(int, int) > compare = std::greater< >();
  if (strcmp(order, "descending"))
  {
      std::function< bool(int, int) > cmp = std::less< >();
  }
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
  const char* order = "ascending";
  const char* order2 = "descending";
  testSort(order, 1);
  testSort(order, 2);
  testSort(order, 3);
  testSort(order2, 1);
  testSort(order2, 2);
  testSort(order2, 3);
}

BOOST_AUTO_TEST_SUITE_END()
