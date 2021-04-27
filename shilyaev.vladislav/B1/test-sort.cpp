#include <boost/test/unit_test.hpp>
#include <algorithm>
#include <ctime>
#include "access-strategies.hpp"
#include "sort.hpp"

namespace shi = shilyaev;

namespace shilyaev {
  template < typename AccessStrategy >
  bool testSort(const typename std::function< bool(int, int) > &compare, size_t itemCount)
  {
    typename AccessStrategy::Collection collection(itemCount);
    std::generate(collection.begin(), collection.end(), std::rand);
    bubbleSort< AccessStrategy >(collection, compare);
    return std::is_sorted(collection.cbegin(), collection.cend(), compare);
  }
}

BOOST_AUTO_TEST_CASE(Sort)
{
  std::srand(std::time(nullptr));
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
