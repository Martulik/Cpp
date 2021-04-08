#include <boost/test/unit_test.hpp>
#include <algorithm>
#include <limits>
#include <random>

#include "order-strategies.hpp"
#include "access-strategies.hpp"
#include "sort.hpp"

namespace shi = shilyaev;

namespace shilyaev {
  const size_t ITEM_COUNT = 1000;

  template < typename Iterator >
  void fill(Iterator begin, const Iterator& end)
  {
    std::uniform_int_distribution< int > distribution(std::numeric_limits< int >::lowest(), std::numeric_limits< int >::max());
    std::random_device randomDevice;
    for (; begin != end; begin++) {
      *begin = distribution(randomDevice);
    }
  }

  template < typename AccessStrategy, typename Order, typename Compare >
  bool testSort(Compare compare)
  {
    typename AccessStrategy::Collection collection(ITEM_COUNT);
    fill(collection.begin(), collection.end());
    bubbleSort< AccessStrategy, Order >(collection);
    return std::is_sorted(collection.cbegin(), collection.cend(), compare);
  }
}

BOOST_AUTO_TEST_CASE(Sort)
{
  BOOST_CHECK((shi::testSort< shi::VectorAtStrategy< int >, shi::AscendingOrder >(std::less<>())));
  BOOST_CHECK((shi::testSort< shi::VectorBracketsStrategy< int >, shi::AscendingOrder >(std::less<>())));
  BOOST_CHECK((shi::testSort< shi::ForwardListIteratorStrategy< int >, shi::AscendingOrder >(std::less<>())));

  BOOST_CHECK((shi::testSort< shi::VectorAtStrategy< int >, shi::DescendingOrder >(std::greater<>())));
  BOOST_CHECK((shi::testSort< shi::VectorBracketsStrategy< int >, shi::DescendingOrder >(std::greater<>())));
  BOOST_CHECK((shi::testSort< shi::ForwardListIteratorStrategy< int >, shi::DescendingOrder >(std::greater<>())));
}
