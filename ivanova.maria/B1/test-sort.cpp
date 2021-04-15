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

template< typename T >
void testSort(const char* method, const int size)
{
  typename T::cont cont(size);
  fillContainer(cont.begin(), cont.end());
  iva::sortAndPrint< T >(cont, method);
  if (!strcmp(method, "ascending"))
  {
    BOOST_CHECK(std::is_sorted(cont.begin(), cont.end(), std::less< int >()));
  }
  if (!strcmp(method, "descending"))
  {
    BOOST_CHECK(std::is_sorted(cont.begin(), cont.end(), std::greater< int >()));
  }
}

template< typename T >
void doTestSort()
{
  for (int i = 0; i < maxSize; i++)
  {
    testSort< T >("ascending", i);
    testSort< T >("descending", i);
  }
}

BOOST_AUTO_TEST_SUITE(sort)

BOOST_AUTO_TEST_CASE(sortVectorByIndex)
{
  doTestSort< iva::strategyBrackets< int > >();
}

BOOST_AUTO_TEST_CASE(sortVectorUsingAt)
{
  doTestSort< iva::strategyAt< int > >();
}

BOOST_AUTO_TEST_CASE(sortIterator)
{
  doTestSort< iva::strategyList< int > >();
}

BOOST_AUTO_TEST_SUITE_END()
