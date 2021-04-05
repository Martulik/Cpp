#ifndef TEST_REGISTRAR_HPP
#define TEST_REGISTRAR_HPP

#include <boost/test/tree/decorator.hpp>
#include <boost/test/tree/test_unit.hpp>

namespace doroshin
{
  struct test_suite_registrar {
    test_suite_registrar(
        boost::unit_test::test_suite* suite,
        boost::unit_test::decorator::collector_t& collector);
  };

  #define CUSTOM_REGISTER_SUITE(name, suite) \
    static doroshin::test_suite_registrar name \
      (suite, boost::unit_test::decorator::collector_t::instance());
}

#endif //TEST_REGISTRAR_HPP
