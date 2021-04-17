#include <boost/test/unit_test.hpp>

#include "tools.hpp"

#include <functional>
#include <vector>
#include <random>
#include <string>
#include <algorithm>
#include <forward_list>

#include "sorting.hpp"
#include "strategy.hpp"

int containerSize = 3;
namespace mur = murzakanov;
template < typename T >
void fillContainer (typename T::iterator it, const typename T::iterator& end)
{
  while (it != end)
  {
    *it = rand();
    it++;
  }
}

void doTestSort()
{
  std::string order = "ascending";
  std::function< bool(int, int) > cmp = mur::getSortMode< int >(order);
  std::vector< int > vecBrackets(containerSize);
  std::vector< int > vecInd(containerSize);
  std::forward_list< int > listIt(containerSize);

  fillContainer< std::vector< int > >(vecBrackets.begin(), vecBrackets.end());
  fillContainer< std::vector< int > >(vecInd.begin(), vecInd.end());
  fillContainer< std::forward_list< int > >(listIt.begin(), listIt.end());

  mur::sort< mur::StrategyBrackets< int >, int >(vecBrackets, cmp);
  mur::sort< mur::StrategyAt< int >, int >(vecInd, cmp);
  mur::sort< mur::StrategyIter< int >, int >(listIt, cmp);

  BOOST_CHECK(std::is_sorted(vecBrackets.begin(), vecBrackets.end()));
  BOOST_CHECK(std::is_sorted(vecInd.begin(), vecInd.end()));
  BOOST_CHECK(std::is_sorted(listIt.begin(), listIt.end()));
}

BOOST_AUTO_TEST_SUITE(test_sort)

  BOOST_AUTO_TEST_CASE(sort_vector_by_strategies)
  {
    doTestSort();
  }

BOOST_AUTO_TEST_SUITE_END()
