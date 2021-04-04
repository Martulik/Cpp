#include <limits>
#include <boost/test/unit_test.hpp>
#include <boost/test/parameterized_test.hpp>
#include <boost/mpl/list.hpp>
#include <boost/mpl/for_each.hpp>
#include "test-registrar.hpp"
#include "test-random.hpp"
#include "sort-strategies.hpp"

namespace mpl = boost::mpl;
namespace test = boost::unit_test;
namespace dan = doroshin;

test::test_suite* make_suite()
{
  using Strategies = mpl::list< dan::VectorIndexStrat< int >, dan::VectorAtStrat< int >, dan::ListIterStrat< int > >;
  using Orderings = mpl::list< std::less< int >, std::greater< int > >;
  const std::vector< std::pair< int, int > > limits = {
      { 0, 1 },
      { -10, 10 },
      { -1000, 1000 },
      { std::numeric_limits< int >::min(), std::numeric_limits< int >::max() }
    };

  test::test_suite* suite = BOOST_TEST_SUITE("Random int");

  mpl::for_each< Strategies >(
    [&](auto _strat) {
      using Strategy = decltype(_strat);
      mpl::for_each< Orderings >(
        [&](auto _order) {
          using Order = decltype(_order);

          for(const auto& limit: limits) {
            int min = limit.first;
            int max = limit.second;
            for(size_t i = 1; i < 300; ++i) {
              size_t repeat = std::floor(std::log(i));
              for(size_t j = 0; j <= repeat; ++j) {
                std::ostringstream name;
                name << typeid(Strategy).name() << ' ' << typeid(Order).name() << ' ' << min << ' ' << max << ' ' << i << ' ' << j;
                suite->add(BOOST_TEST_CASE_NAME(std::bind(*std::make_shared< dan::TestRandomSort< int, dan::UniformIntStrat< int >, Strategy, Order > >(min, max, i, _order)), name.str()));
              }
            }
          }
        }
      );
    }
  );

  return suite;
}

static dan::test_suite_registrar registrar(make_suite(), &test::framework::master_test_suite(), test::decorator::collector_t::instance());
