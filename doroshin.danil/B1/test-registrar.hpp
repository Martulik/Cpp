#ifndef TEST_REGISTRAR_HPP
#define TEST_REGISTRAR_HPP

#include <boost/test/impl/decorator.ipp>
#include <boost/test/framework.hpp>
#include <boost/test/tree/auto_registration.hpp>
#include <boost/test/tree/test_case_template.hpp>
#include <boost/test/tree/global_fixture.hpp>

namespace doroshin
{
  struct test_suite_registrar {
    test_suite_registrar(
        boost::unit_test::test_suite* suite,
        boost::unit_test::decorator::collector& collector);
  };
}

#endif //TEST_REGISTRAR_HPP
