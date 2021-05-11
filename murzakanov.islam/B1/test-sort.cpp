#include <boost/test/unit_test.hpp>

#include "tools.hpp"

#include <functional>
#include <vector>
#include <random>
#include <algorithm>
#include <forward_list>
#include <list>

#include "sorting.hpp"
#include "strategy.hpp"

namespace mur = murzakanov;

void doTestSortOneElement()
{
  srand(time(0));
  const char order[] = "ascending";
  std::function< bool(int, int) > cmp = mur::getSortMode< int >(order);
  for (int containerSize = 0; containerSize < 4; containerSize++)
  {
    std::vector< int > vecBrackets(containerSize);
    std::vector< int > vecInd(containerSize);
    std::forward_list< int > listIt(containerSize);

    std::generate(vecBrackets.begin(), vecBrackets.end(), rand);
    std::generate(vecInd.begin(), vecInd.end(), rand);
    std::generate(listIt.begin(), listIt.end(), rand);

    mur::sort< mur::StrategyBrackets< int >, int >(vecBrackets, cmp);
    mur::sort< mur::StrategyAt< int >, int >(vecInd, cmp);
    mur::sort< mur::StrategyIter< int >, int >(listIt, cmp);

    BOOST_CHECK(std::is_sorted(vecBrackets.begin(), vecBrackets.end()));
    BOOST_CHECK(std::is_sorted(vecInd.begin(), vecInd.end()));
    BOOST_CHECK(std::is_sorted(listIt.begin(), listIt.end()));
  }
}

BOOST_AUTO_TEST_SUITE(test_sort)

  BOOST_AUTO_TEST_CASE(sort_by_strategies)
  {
    doTestSortOneElement();
  }

BOOST_AUTO_TEST_SUITE_END()
