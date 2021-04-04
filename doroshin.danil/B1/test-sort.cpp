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
                suite->add(BOOST_TEST_CASE_NAME(std::bind(*std::make_shared< dan::TestRandomInts< Strategy, Order > >(i, _order)), name.str()));
              }
            }
        }
      );
    }
  );

  return suite;
}

static dan::test_suite_registrar registrar(make_suite(), &test::framework::master_test_suite(), test::decorator::collector_t::instance());
