#include "test-registrar.hpp"

namespace test = boost::unit_test;
namespace dan = doroshin;

dan::test_suite_registrar::test_suite_registrar(
        test::test_suite* suite,
        test::decorator::collector_t& collector)
{
  test::test_suite& parent = test::framework::current_auto_test_suite();
  parent.add(suite);
  collector.store_in(parent);
  collector.reset();
}
