#include <boost/test/included/unit_test.hpp>
#include <ctime>
#include <algorithm>
#include "strategy.hpp"
#include "tools.hpp"

namespace diurdeva {
  template< typename Iterator >
  void fillCont(Iterator begin, const Iterator &end)
  {
    srand(time(NULL));
    while (begin != end) {
      *begin = rand();
      begin++;
    }
  }

  template< typename Strategy >
  bool testSort(const std::function< bool(int, int) > compare, const int size)
  {
    typename Strategy::container_type container(size);
    fillCont(container.begin(), container.end());
    diurdeva::sorting< Strategy >(container, compare);
    return std::is_sorted(container.cbegin(), container.cend(), compare);
  }
}

BOOST_AUTO_TEST_CASE(testSort)
{
  const size_t containerSize[] = {3, 6, 20, 40};
  for (size_t size : containerSize) {
    BOOST_CHECK((diurdeva::testSort< diurdeva::atAccess< int > >(std::less<>(), size)));
    BOOST_CHECK((diurdeva::testSort< diurdeva::indexAccess< int > >(std::less<>(), size)));
    BOOST_CHECK((diurdeva::testSort< diurdeva::iteratorAccess< int > >(std::less<>(), size)));
    BOOST_CHECK((diurdeva::testSort< diurdeva::atAccess< int > >(std::greater<>(), size)));
    BOOST_CHECK((diurdeva::testSort< diurdeva::indexAccess< int > >(std::greater<>(), size)));
    BOOST_CHECK((diurdeva::testSort< diurdeva::iteratorAccess< int > >(std::greater<>(), size)));
  }
}
