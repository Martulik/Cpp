#ifndef TEST_REGISTRAR_HPP
#define TEST_REGISTRAR_HPP

#include <boost/test/tree/decorator.hpp>
#include <boost/test/tree/test_unit.hpp>

namespace doroshin
{
  struct test_suite_registrar {
    test_suite_registrar(
        boost::unit_test::test_suite* suite,
        boost::unit_test::test_suite* to,
        boost::unit_test::decorator::collector_t& collector);
  };
}

#endif //TEST_REGISTRAR_HPP
