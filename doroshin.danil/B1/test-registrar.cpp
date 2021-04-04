#include "test-registrar.hpp"

namespace test = boost::unit_test;
namespace dan = doroshin;

dan::test_suite_registrar::test_suite_registrar(
        test::test_suite* suite,
        test::test_suite* to,
        test::decorator::collector_t& collector)
{
  to->add(suite);
  collector.store_in(*to);
  collector.reset();
}
