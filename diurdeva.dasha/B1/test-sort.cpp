#include <boost/test/unit_test.hpp>
#include <algorithm>
#include <ctime>
#include "strategy.hpp"
#include "tools.hpp"

namespace diurdeva {

  int randomNumber()
  {
    return rand() % 100;
  }

  template< typename Iterator >
  void fillCont(Iterator begin, const Iterator& end)
  {
    std::generate(begin, end, randomNumber);
  }

  template< typename Strategy >
  bool testSort(const std::function< bool(int, int) > compare, const int size)
  {
    typename Strategy::container_type container(size);
    fillCont(container.begin(), container.end());
    diurdeva::sort< Strategy >(container, compare);
    return std::is_sorted(container.cbegin(), container.cend(), compare);
  }
}

BOOST_AUTO_TEST_CASE(testSort)
{
  srand(time(NULL));
  const size_t sizeCont[] = {0, 1, 2, 3, 100};
  for (size_t containerSize: sizeCont) {
    BOOST_CHECK((diurdeva::testSort< diurdeva::atAccess< int > >(std::less<>(), containerSize)));
    BOOST_CHECK((diurdeva::testSort< diurdeva::atAccess< int > >(std::greater<>(), containerSize)));
    BOOST_CHECK((diurdeva::testSort< diurdeva::indexAccess< int > >(std::less<>(), containerSize)));
    BOOST_CHECK((diurdeva::testSort< diurdeva::indexAccess< int > >(std::greater<>(), containerSize)));
    BOOST_CHECK((diurdeva::testSort< diurdeva::iteratorAccess< int > >(std::less<>(), containerSize)));
    BOOST_CHECK((diurdeva::testSort< diurdeva::iteratorAccess< int > >(std::greater<>(), containerSize)));
  }
}
