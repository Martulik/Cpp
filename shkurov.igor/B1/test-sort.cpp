#include <boost/test/unit_test.hpp>

#include "functions.hpp"

namespace lab = shkurov;

BOOST_AUTO_TEST_SUITE(functions)

BOOST_AUTO_TEST_CASE(sortWithAtStrategy)
{
  int sorted[]{1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::vector< int > testVec{9, 4, 5, 1, 3, 8, 2, 6, 7};

  std::function< bool(int, int) > cmp = lab::comparsionMethod< int >("ascending");
  lab::selectionSort< lab::strategyAt< int >, int >(testVec, cmp);

  BOOST_CHECK_EQUAL_COLLECTIONS(testVec.begin(), testVec.end(), sorted, sorted + 9);
}

BOOST_AUTO_TEST_CASE(sortWithIndexStrategy)
{
  double sorted[]{1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.0};
  std::vector< double > testVec{1.2, 5.6, 4.5, 8.9, 7.8, 2.3, 9.0, 3.4, 6.7};

  std::function< bool(int, int) > cmp = lab::comparsionMethod< int >("ascending");
  lab::selectionSort< lab::strategyIndex< double >, double >(testVec, cmp);

  BOOST_CHECK_EQUAL_COLLECTIONS(testVec.begin(), testVec.end(), sorted, sorted + 9);
}

BOOST_AUTO_TEST_CASE(sortWithIteratorStrategy)
{
  int sorted[]{9, 8, 7, 6, 5, 4, 3, 2, 1};
  std::vector< int > testVec{6, 9, 3, 1, 2, 7, 8, 4, 5};

  std::function< bool(int, int) > cmp = lab::comparsionMethod< int >("descending");
  lab::selectionSort< lab::strategyIndex< int >, int >(testVec, cmp);

  BOOST_CHECK_EQUAL_COLLECTIONS(testVec.begin(), testVec.end(), sorted, sorted + 9);
}

BOOST_AUTO_TEST_SUITE_END();
