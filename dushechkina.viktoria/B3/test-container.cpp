#include <boost/test/unit_test.hpp>
#include "factorial.hpp"

struct Fixture
{
  dushechkina::Container fact;
};

BOOST_FIXTURE_TEST_SUITE(Container, Fixture)

BOOST_AUTO_TEST_CASE(correctWork)
{
  unsigned int n = 1;
  unsigned int k = 1;
  for (auto i = fact.begin(); i != fact.end(); i++, n++, k *= n)
  {
    BOOST_CHECK_EQUAL(*i, k);
  }
}

BOOST_AUTO_TEST_SUITE_END()
