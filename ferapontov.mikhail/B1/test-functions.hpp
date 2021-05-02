#ifndef TEST_FUNCTIONS_HPP
#define TEST_FUNCTIONS_HPP

#include <boost/test/unit_test.hpp>

#include <algorithm>
#include <random>
#include <functional>
#include "functions.hpp"
#include "sort.hpp"
#include "strategy.hpp"
namespace ferapontov
{
  template <typename iter>
  void fillVector(iter begin, iter end)
  {
    std::random_device rd;
    std::uniform_int_distribution< int > dist(-100, 100);
    while(begin != end)
    {
      *begin = dist(rd);
      ++begin;
    }
  }

  void testSort(const char* mode, size_t size)
  {

    std::vector< int > v(size);
    fillVector(v.begin(), v.end());

    std::function< bool(int, int) > cmp = std::greater< >();
    std::function< bool(int, int) > sort_cmp = std::less< >();

    if (strcmp(mode, "descending"))
    {
      std::function< bool(int, int) > cmp = std::less< >();
      std::function< bool(int, int) > sort_cmp = std::greater< >();
    }

    std::vector< int > v2(v);
    std::forward_list< int > fl(v.begin(), v.end());
    sort< int, index_access< int > >(v, cmp);
    sort< int, at_access< int > >(v2, cmp);
    sort< int, iterator_access< int > >(fl, cmp);
    BOOST_CHECK(std::is_sorted(v.begin(), v.end(), sort_cmp));
    BOOST_CHECK(std::is_sorted(v2.begin(), v2.end(), sort_cmp));
    BOOST_CHECK(std::is_sorted(fl.begin(), fl.end(), sort_cmp));
  }
}

#endif
