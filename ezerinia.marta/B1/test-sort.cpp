#include <boost/test/unit_test.hpp>
#include "tools.hpp"

namespace lab = ezerinia;

const int max_size_collection = 3;

template< typename I >
void fillCont(I begin, const I &end)
{
  srand(time(NULL));
  while (begin != end) {
    *begin = rand();
    begin++;
  }
}

template< typename S, typename C >
void testSort(const C cmp, const int size)
{
  typename S::container_t cont(size);
  fillCont(cont.begin(), cont.end());
  lab::sortAndPrint< S >(cont, cmp, std::cout);
  BOOST_CHECK(std::is_sorted(cont.begin(), cont.end(), cmp));
}

template< typename T, typename S >
void doTestSort()
{
  for (int i = 0; i < max_size_collection; i++) {
    testSort< S >(std::greater< T >(), i);
    testSort< S >(std::less< T >(), i);
  }
}

BOOST_AUTO_TEST_SUITE(sort)

  BOOST_AUTO_TEST_CASE(sort_vector_by_index)
  {
    doTestSort< int, lab::indexVec< int > >();
  }

  BOOST_AUTO_TEST_CASE(sort_vector_by_at)
  {
    doTestSort< int, lab::atVec< int > >();
  }

  BOOST_AUTO_TEST_CASE(sort_iter)
  {
    doTestSort< int, lab::iteratorList< int > >();
  }

BOOST_AUTO_TEST_SUITE_END()
