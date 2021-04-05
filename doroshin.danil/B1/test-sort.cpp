#include <limits>
#include <typeinfo>
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
  using Strategies = mpl::list<
      dan::VectorIndexStrat< T >,
      dan::VectorAtStrat< T >,
      dan::ListIterStrat< T >
  >;
  using Orderings = mpl::list<
      std::less< T >,
      std::greater< T >
  >;
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
            for(size_t i = 1; i < 100; ++i) {
              std::ostringstream name;
              name << typeid(T).name() << ' '
                  << typeid(Strategy).name() << ' '
                  << typeid(Order).name() << ' '
                  << min << ' ' << max
                  << ' ' << i;
              suite->add(
                  test::make_test_case(
                    *std::make_shared<
                      dan::TestRandomSort< T, RandomStrat, Strategy, Order >
                    >(min, max, i, _order),
                    name.str(), __FILE__, __LINE__
                    ));
            }
          }
        }
      );
    }
  );

  return suite;
}

BOOST_AUTO_TEST_SUITE(sort);
static dan::test_suite_registrar register_int(
    make_suite< int, dan::UniformIntStrat< int > >(),
    boost::unit_test::decorator::collector::instance());
static dan::test_suite_registrar register_double(
    make_suite< double, dan::UniformRealStrat< double > >(),
    boost::unit_test::decorator::collector::instance());
BOOST_AUTO_TEST_SUITE_END();
