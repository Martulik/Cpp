#include <boost/test/unit_test.hpp>
#include <iostream>
#include "factorials.hpp"

namespace dan = doroshin;
namespace test = boost::unit_test;

class FactorialFixture
{
public:
  int begin_ = 1;
  int end_ = 10;
  dan::Factorials fact_;

  FactorialFixture():
    fact_(begin_, end_)
  {}
};

unsigned long long factorial(int n)
{
  unsigned long long res = 1;
  for(int i = 2; i <= n; ++i) {
    res *= i;
  }
  return res;
}

BOOST_FIXTURE_TEST_SUITE(Factorial, FactorialFixture)

BOOST_AUTO_TEST_CASE(equality_ascending)
{
  int n = begin_;
  for(auto fact: fact_) {
    BOOST_CHECK_EQUAL(fact, factorial(n++));
  }
}

BOOST_AUTO_TEST_CASE(equality_descending)
{
  int n = end_;
  auto begin = std::make_reverse_iterator(fact_.end());
  auto end = std::make_reverse_iterator(fact_.begin());
  for(auto i = begin; i != end; ++i) {
    BOOST_CHECK_EQUAL(*i, factorial(n--));
  }
}

BOOST_AUTO_TEST_SUITE_END()
