#include <boost/test/unit_test.hpp>
#include <algorithm>
#include <limits>
#include <random>

#include "access-strategies.hpp"
#include "sort.hpp"

namespace shi = shilyaev;

namespace shilyaev {
  template < typename Iterator >
  void fill(Iterator begin, const Iterator& end)
  {
    int min = std::numeric_limits< int >::lowest();
    int max = std::numeric_limits< int >::max();
    std::uniform_int_distribution< int > distribution(min, max);
    std::random_device randomDevice;
    for (; begin != end; begin++) {
      *begin = distribution(randomDevice);
    }
  }

  template < typename AccessStrategy >
  bool testSort(const typename std::function< bool(int, int) > &compare, size_t itemCount)
  {
    typename AccessStrategy::Collection collection(itemCount);
    fill(collection.begin(), collection.end());
    bubbleSort< AccessStrategy >(collection, compare);
    return std::is_sorted(collection.cbegin(), collection.cend(), compare);
  }
}

BOOST_AUTO_TEST_CASE(Sort)
{
  const size_t sizes[] = {0, 1, 2, 1000};
  for (size_t size: sizes) {
    BOOST_CHECK((shi::testSort< shi::VectorAtStrategy< int > >(std::less<>(), size)));
    BOOST_CHECK((shi::testSort< shi::VectorBracketsStrategy< int > >(std::less<>(), size)));
    BOOST_CHECK((shi::testSort< shi::ForwardListIteratorStrategy< int > >(std::less<>(), size)));
    BOOST_CHECK((shi::testSort< shi::VectorAtStrategy< int > >(std::greater<>(), size)));
    BOOST_CHECK((shi::testSort< shi::VectorBracketsStrategy< int > >(std::greater<>(), size)));
    BOOST_CHECK((shi::testSort< shi::ForwardListIteratorStrategy< int > >(std::greater<>(), size)));
  }
}
