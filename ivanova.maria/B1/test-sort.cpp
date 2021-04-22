#include <boost/test/unit_test.hpp>
#include <ctime>
#include <algorithm>
#include "functions.hpp"

namespace iva = ivanova;

const int maxSize = 3;
template< typename T > void fillContainer(T it, const T &end)
{
  srand(time(NULL));
  while (it != end) {
    *it = rand();
    it++;
  }
}

template< typename T, typename S >
void testSort(S sort, const int size)
{
  typename T::cont cont(size);
  fillContainer(cont.begin(), cont.end());
  iva::sortAndPrint< T >(cont, sort);
  BOOST_CHECK(std::is_sorted(cont.begin(), cont.end(), sort));
}

template< typename T, typename S>
void doTestSort()
{
  for (int i = 0; i < maxSize; i++)
  {
    testSort< S >(std::less< T >(), i);
    testSort< S >(std::greater< T >(), i);
  }
}

BOOST_AUTO_TEST_SUITE(sort)

BOOST_AUTO_TEST_CASE(sortVectorByIndex)
{
  doTestSort< int, iva::strategyBrackets< int > >();
}

BOOST_AUTO_TEST_CASE(sortVectorUsingAt)
{
  doTestSort< int, iva::strategyAt< int > >();
}

BOOST_AUTO_TEST_CASE(sortIterator)
{
  doTestSort< int, iva::strategyList< int > >();
}

BOOST_AUTO_TEST_SUITE_END()
