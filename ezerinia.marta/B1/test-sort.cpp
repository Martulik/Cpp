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

template< typename S >
void testSort(const std::function< bool(int, int) > cmp, const int size)
{
  typename S::container_t cont(size);
  fillCont(cont.begin(), cont.end());
  lab::sortAndPrint< S >(cont, cmp);
  BOOST_CHECK(std::is_sorted(cont.begin(), cont.end(), cmp));
}

template< typename S >
void doTestSort()
{
  for (int i = 0; i < max_size_collection; i++) {
    testSort< S >(std::greater< >(), i);
    testSort< S >(std::less< >(), i);
  }
}

BOOST_AUTO_TEST_SUITE(sort)

  BOOST_AUTO_TEST_CASE(sort_vector_by_index)
  {
    doTestSort< lab::indexVec< int > >();
  }

  BOOST_AUTO_TEST_CASE(sort_vector_by_at)
  {
    doTestSort< lab::atVec< int > >();
  }

  BOOST_AUTO_TEST_CASE(sort_iter)
  {
    doTestSort< lab::iteratorList< int > >();
  }

BOOST_AUTO_TEST_SUITE_END()
