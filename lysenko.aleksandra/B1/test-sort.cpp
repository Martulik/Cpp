#include <boost/test/unit_test.hpp>

#include <vector>
#include <forward_list>

#include "sort.hpp"
#include "comparator.hpp"

namespace lysenko
{
  int myRand()
  {
    return rand() % 333;
  }
}

namespace lysenko
{
  template< template< typename > typename sortBy, typename container_type >
  void doSort(container_type& container, const char* order)
  {
    std::function < bool(const double&, const double&) > comparator = getComparator< int >(order);

    lysenko::sortBubble <sortBy, container_type>(container, comparator);
    BOOST_CHECK(std::is_sorted(container.begin(), container.end(), lysenko::getComparator< int >(order)));
  }
}

namespace lysenko
{
  template< template< typename > typename sortBy, typename container_type >
  void sortWithStategy(int size)
  {
    container_type myContainer(size);

    std::generate(myContainer.begin(), myContainer.end(), myRand);

    lysenko::doSort< sortBy, container_type >(myContainer, "ascending");

    lysenko::doSort< sortBy, container_type >(myContainer, "descending");
  }
}

BOOST_AUTO_TEST_SUITE(testSortForIndex)

BOOST_AUTO_TEST_CASE(testEmptyVector)
{
  lysenko::sortWithStategy< lysenko::strategyForIndex, std::vector< int > >(0);
}

BOOST_AUTO_TEST_CASE(testVectorOfSizeOne)
{
  lysenko::sortWithStategy< lysenko::strategyForIndex, std::vector< int > >(1);
}

BOOST_AUTO_TEST_CASE(testVectorOfSizeTwo)
{
  lysenko::sortWithStategy< lysenko::strategyForIndex, std::vector< int > >(2);
}

BOOST_AUTO_TEST_CASE(testVectorOfSizeThree)
{
  lysenko::sortWithStategy< lysenko::strategyForIndex, std::vector< int > >(3);
}
BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(testSortForAt)

BOOST_AUTO_TEST_CASE(testEmptyVector)
{
  lysenko::sortWithStategy< lysenko::strategyForAt, std::vector< int > >(0);
}

BOOST_AUTO_TEST_CASE(testVectorOfSizeOne)
{
  lysenko::sortWithStategy< lysenko::strategyForAt, std::vector< int > >(1);
}

BOOST_AUTO_TEST_CASE(testVectorOfSizeTwo)
{
  lysenko::sortWithStategy< lysenko::strategyForAt, std::vector< int > >(2);
}

BOOST_AUTO_TEST_CASE(testVectorOfSizeThree)
{
  lysenko::sortWithStategy< lysenko::strategyForAt, std::vector< int > >(3);
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(testSortForIterator)

BOOST_AUTO_TEST_CASE(testEmptyList)
{
  lysenko::sortWithStategy< lysenko::strategyForIterator, std::forward_list< int > >(0);
}

BOOST_AUTO_TEST_CASE(testListOfSizeOne)
{
  lysenko::sortWithStategy< lysenko::strategyForIterator, std::forward_list< int >  >(1);
}

BOOST_AUTO_TEST_CASE(testListOfSizeTwo)
{
  lysenko::sortWithStategy< lysenko::strategyForIterator, std::forward_list< int >  >(2);
}

BOOST_AUTO_TEST_CASE(testListOfSizeThree)
{
  lysenko::sortWithStategy<lysenko::strategyForIterator, std::forward_list< int >  >(3);
}
BOOST_AUTO_TEST_SUITE_END()
