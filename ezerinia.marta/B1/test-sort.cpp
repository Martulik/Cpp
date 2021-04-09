#include <boost/test/unit_test.hpp>
#include "tools.hpp"

namespace lab = ezerinia;

const int max_size_collection = 3;

template< typename T >
void testSort(const std::function< bool(int, int) > cmp)
{
  typename T::container_t vec;
  for (int i = 0; i <= max_size_collection; i++) {
    vec.push_back(i);
    lab::sortAndPrint< T >(vec, cmp);
    BOOST_CHECK(std::is_sorted(vec.begin(), vec.end(), cmp));
  }
}

BOOST_AUTO_TEST_SUITE(sort)

  BOOST_AUTO_TEST_CASE(sort_vector_by_index)
  {
    testSort< lab::indexVec< int > >(std::greater<>());
  }

  BOOST_AUTO_TEST_CASE(sort_vector_by_at)
  {
    testSort< lab::atVec< int > >(std::less<>());
  }

BOOST_AUTO_TEST_SUITE_END()
