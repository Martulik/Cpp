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
    std::generate(begin, end, rand);
  }

  void testSort(const char* mode, size_t size)
  {
    srand(time(0));
    std::vector< int > v(size);
    fillVector(v.begin(), v.end());

    std::function< bool(int, int) > cmp = std::greater< >();

    if (strcmp(mode, "descending"))
    {
      std::function< bool(int, int) > cmp = std::less< >();
    }

    std::vector< int > v2(v);
    std::forward_list< int > fl(v.begin(), v.end());
    sort< int, index_access< int > >(v, cmp);
    sort< int, at_access< int > >(v2, cmp);
    sort< int, iterator_access< int > >(fl, cmp);
    BOOST_CHECK(std::is_sorted(v.begin(), v.end(), cmp));
    BOOST_CHECK(std::is_sorted(v2.begin(), v2.end(), cmp));
    BOOST_CHECK(std::is_sorted(fl.begin(), fl.end(), cmp));
  }
}

#endif
