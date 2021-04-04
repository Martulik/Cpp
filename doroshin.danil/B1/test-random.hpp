#ifndef TEST_RANDOM_HPP
#define TEST_RANDOM_HPP

#include <functional>
#include <algorithm>
#include <random>
#include <typeinfo>
#include "insert-sort.hpp"

namespace doroshin
{
  template< typename T, typename RandomStrat, typename SortStrat, typename Cmp >
  class TestRandomSort
  {
  public:
    TestRandomSort(T min, T max, size_t N, Cmp cmp);

    void operator()();
  private:
    T min, max;
    Cmp compare;
    typename SortStrat::container_t values;
  };

  template< typename T, typename RandomStrat, typename SortStrat, typename Cmp >
  TestRandomSort< T, RandomStrat, SortStrat, Cmp >::TestRandomSort(T min, T max, size_t N, Cmp cmp):
    min(min),
    max(max),
    compare(cmp)
  {
    std::random_device rd;
    std::default_random_engine gen(rd());
    typename RandomStrat::distribution dist(min, max);
    auto random = std::bind(dist, gen);

    std::generate_n(typename SortStrat::output_iterator_t(values), N, random);
  }

  template< typename T, typename RandomStrat, typename SortStrat, typename Cmp >
  void TestRandomSort< T, RandomStrat, SortStrat, Cmp >::operator()()
  {
    insert_sort< T, SortStrat >(values, compare);
    BOOST_CHECK(std::is_sorted(std::begin(values), std::end(values), compare));
  }

  template< typename T >
  struct UniformIntStrat
  {
    using distribution = std::uniform_int_distribution< T >;
  };

  template< typename T >
  struct UniformRealStrat
  {
    using distribution = std::uniform_real_distribution< T >;
  };
}

#endif //TEST_RANDOM_HPP
