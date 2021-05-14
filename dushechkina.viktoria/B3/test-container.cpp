#include <iostream>
#include <boost/test/unit_test.hpp>
#include "factorial.hpp"

struct Fixture
{
	dushechkina::Container fact;
	std::ostringstream output;
};

BOOST_FIXTURE_TEST_SUITE(FACTORIAL, Fixture)

  BOOST_AUTO_TEST_CASE(correct_dereferencing)
  {
	  unsigned k = 1;
	  unsigned n = 1;
	  for (auto i = fact.begin(); i != fact.end(); ++i)
	  {
		  BOOST_CHECK_EQUAL(*i, k);
		  k *= ++n;
	  }
  }

BOOST_AUTO_TEST_SUITE_END()
