#ifndef TEST_RANDOM_HPP
#define TEST_RANDOM_HPP

#include <functional>
#include <algorithm>
#include <random>
#include <limits>
#include <typeinfo>
#include "insert-sort.hpp"

namespace doroshin
{
  template< typename Strat, typename Cmp >
  class TestRandomInts
  {
  public:
    TestRandomInts(size_t N, Cmp cmp);

    void sort();
    void test() const;

    void operator()();
  private:
    Cmp compare;
    typename Strat::container_t values;
  };

  template< typename Strat, typename Cmp >
  TestRandomInts< Strat, Cmp >::TestRandomInts(size_t N, Cmp cmp):
    compare(cmp)
  {
    const int min = std::numeric_limits<int>::min();
    const int max = std::numeric_limits<int>::max();
    std::random_device rd;
    std::default_random_engine gen(rd());
    std::uniform_int_distribution< int > dist(min, max);
    auto random = std::bind(dist, gen);

    std::generate_n(typename Strat::output_iterator_t(values), N, random);
  }

  template< typename Strat, typename Cmp >
  void TestRandomInts< Strat, Cmp >::sort()
  {
    insert_sort< int, Strat >(values, Strat::begin(values), Strat::end(values), compare);
  }

  template< typename Strat, typename Cmp >
  void TestRandomInts< Strat, Cmp >::test() const
  {
    BOOST_CHECK(std::is_sorted(std::begin(values), std::end(values), compare));
  }

  template< typename Strat, typename Cmp >
  void TestRandomInts< Strat, Cmp >::operator()()
  {
    sort();
    test();
  }
}

#endif //TEST_RANDOM_HPP
