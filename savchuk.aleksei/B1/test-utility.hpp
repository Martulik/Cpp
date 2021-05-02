#ifndef TEST_UTILITY_HPP
#define TEST_UTILITY_HPP

#include <algorithm>
#include <functional>
#include <forward_list>
#include <vector>

#include <boost/test/unit_test.hpp>
#include <boost/test/tools/floating_point_comparison.hpp>

#include "access-policies.hpp"
#include "sort.hpp"
#include "tools.hpp"
#include "random-engine.hpp"

namespace savchuk
{
  template< typename Iterator >
  void fillContainer(Iterator first, Iterator last)
  {
    std::generate(first, last, getRandomEngine());
  }
  template< typename Container >
  Container getTestContainer(size_t size)
  {
    Container cnt(size);
    fillContainer(cnt.begin(), cnt.end());
    return cnt;
  }
  template< typename Compare >
  void testSort(size_t size, Compare cmp)
  {
    std::vector< int > v1 = getTestContainer< std::vector< int > >(size);
    std::vector< int > v2 = getTestContainer< std::vector< int > >(size);
    std::forward_list< int > fwl = getTestContainer< std::forward_list< int > >(size);
    selectionSort< int, IndexVectorPolicy >(v1, cmp);
    selectionSort< int, AtVectorPolicy >(v2, cmp);
    selectionSort< int, IteratorFwListPolicy >(fwl, cmp);
    BOOST_CHECK(std::is_sorted(v1.cbegin(), v1.cend(), cmp));
    BOOST_CHECK(std::is_sorted(v2.cbegin(), v2.cend(), cmp));
    BOOST_CHECK(std::is_sorted(fwl.cbegin(), fwl.cend(), cmp));
  }
}

#endif
