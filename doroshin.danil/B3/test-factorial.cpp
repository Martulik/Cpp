#include <boost/test/unit_test.hpp>
#include "factorials.hpp"

namespace dan = doroshin;
namespace test = boost::unit_test;

class FactorialFixture
{
public:
  const int begin_ = 1;
  const int end_ = 10;
  const dan::Factorials fact_;

  constexpr FactorialFixture():
    fact_(begin_, end_)
  {}
};

BOOST_FIXTURE_TEST_SUITE(Factorial, FactorialFixture)

BOOST_AUTO_TEST_CASE(equality_ascending)
{
  int n = begin_;
  for(auto fact: fact_) {
    BOOST_CHECK_EQUAL(fact, dan::factorial(n++));
  }
}

BOOST_AUTO_TEST_CASE(equality_descending)
{
  int n = end_;
  auto begin = std::make_reverse_iterator(fact_.end());
  auto end = std::make_reverse_iterator(fact_.begin());
  for(auto i = begin; i != end; ++i) {
    BOOST_CHECK_EQUAL(*i, dan::factorial(n--));
  }
}

BOOST_AUTO_TEST_SUITE_END()
