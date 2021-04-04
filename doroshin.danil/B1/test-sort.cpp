#include <boost/test/unit_test.hpp>
#include <boost/test/parameterized_test.hpp>
#include <functional>
#include <iomanip>
#include <algorithm>
#include <random>
#include <limits>
#include "insert-sort.hpp"
#include "sort-strategies.hpp"

namespace test = boost::unit_test;
namespace dan = doroshin;

template< typename Strat, typename Cmp >
class TestRandomInts
{
public:
  TestRandomInts(size_t N, Cmp cmp);

  void sort();
  void test() const;

  void operator()();
private:
  static size_t count;
  Cmp compare;
  typename Strat::container_t values;
};

template< typename Strat, typename Cmp >
size_t TestRandomInts< Strat, Cmp >::count = 0;

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

  std::cout << "Random int: " << std::setw(3) << (++count) << '\r';

  values.reserve(N);
  std::generate_n(std::back_inserter(values), N, random);
}

template< typename Strat, typename Cmp >
void TestRandomInts< Strat, Cmp >::sort()
{
  dan::insert_sort< int, Strat >(values, Strat::begin(values), Strat::end(values), compare);
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

BOOST_AUTO_TEST_SUITE(sort_int)

BOOST_AUTO_TEST_CASE(sort)
{
  test::test_suite& suite = test::framework::current_auto_test_suite();
  for(size_t i = 0; i < 300; ++i) {
    for(size_t j = 0; j <= std::floor(std::log(i)); ++j) {
      suite.add(BOOST_TEST_CASE(std::bind(*std::make_shared< TestRandomInts< dan::VectorIndexStrat< int >, std::less<int> > >(i, std::less< int >()))));
    }
  }
}

BOOST_AUTO_TEST_SUITE_END()
