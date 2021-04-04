#include <limits>
#include <boost/test/unit_test.hpp>
#include <boost/test/parameterized_test.hpp>
#include <boost/mpl/list.hpp>
#include <boost/mpl/for_each.hpp>
#include "test-registrar.hpp"
#include "test-random.hpp"
#include "sort-strategies.hpp"

using namespace std::literals::string_literals;
namespace mpl = boost::mpl;
namespace test = boost::unit_test;
namespace dan = doroshin;

template< typename T, typename RandomStrat >
test::test_suite* make_suite()
{
  using Strategies = mpl::list< dan::VectorIndexStrat< T >, dan::VectorAtStrat< T >, dan::ListIterStrat< T > >;
  using Orderings = mpl::list< std::less< T >, std::greater< T > >;
  const std::vector< std::pair< T, T > > limits = {
    { 0, 1 },
    { -10, 10 },
    { -1000, 1000 },
    { std::numeric_limits< T >::lowest(), std::numeric_limits< T >::max() }
  };

  test::test_suite* suite = BOOST_TEST_SUITE("Random "s + typeid(T).name());

  mpl::for_each< Strategies >(
    [&](auto _strat) {
      using Strategy = decltype(_strat);
      mpl::for_each< Orderings >(
        [&](auto _order) {
          using Order = decltype(_order);

          for(const auto& limit: limits) {
            T min = limit.first;
            T max = limit.second;
            for(size_t i = 1; i < 300; ++i) {
              size_t repeat = std::floor(std::log(i));
              for(size_t j = 0; j <= repeat; ++j) {
                std::ostringstream name;
                name << typeid(T).name() << ' ' << typeid(Strategy).name() << ' ' << typeid(Order).name() << ' ' << min << ' ' << max << ' ' << i << ' ' << j;
                suite->add(BOOST_TEST_CASE_NAME(std::bind(*std::make_shared< dan::TestRandomSort< T, RandomStrat, Strategy, Order > >(min, max, i, _order)), name.str()));
              }
            }
          }
        }
      );
    }
  );

  return suite;
}

static dan::test_suite_registrar register_int(make_suite< int, dan::UniformIntStrat< int > >(), &test::framework::master_test_suite(), test::decorator::collector_t::instance());
static dan::test_suite_registrar register_double(make_suite< double, dan::UniformRealStrat< double > >(), &test::framework::master_test_suite(), test::decorator::collector_t::instance());
