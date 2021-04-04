#include <functional>
#include <iomanip>
#include <algorithm>
#include <random>
#include <limits>
#include <typeinfo>
#include <boost/test/unit_test.hpp>
#include <boost/test/parameterized_test.hpp>
#include <boost/mpl/list.hpp>
#include <boost/mpl/for_each.hpp>
#include "test-registrar.hpp"
#include "insert-sort.hpp"
#include "sort-strategies.hpp"

namespace mpl = boost::mpl;
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

test::test_suite* make_suite()
{
  using Strategies = mpl::list< dan::VectorIndexStrat< int >, dan::VectorAtStrat< int > >; //, dan::ListIterStrat< int > >;
  using Orderings = mpl::list< std::less< int >, std::greater< int > >;

  test::test_suite* suite = BOOST_TEST_SUITE("Random int");

  mpl::for_each< Strategies >(
    [&suite](auto _strat) {
      using Strategy = decltype(_strat);
      mpl::for_each< Orderings >(
        [&suite](auto _order) {
          using Order = decltype(_order);

          for(size_t i = 0; i < 300; ++i) {
              for(size_t j = 0; j <= std::floor(std::log(i)); ++j) {
                std::ostringstream name;
                name << typeid(Strategy).name() << ' ' << typeid(Order).name() << ' ' << i << ' ' << j;
                suite->add(BOOST_TEST_CASE_NAME(std::bind(*std::make_shared< TestRandomInts< Strategy, Order > >(i, _order)), name.str()));
              }
            }
        }
      );
    }
  );

  return suite;
}

static dan::test_suite_registrar registrar(make_suite(), &test::framework::master_test_suite(), test::decorator::collector_t::instance());
