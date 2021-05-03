#include <boost/test/unit_test.hpp>
#include <algorithm>
#include "factorial-container.hpp"

namespace shilyaev {
  std::vector< unsigned int > generateFactorialVector(unsigned int n)
  {
    std::vector< unsigned int > vector;
    vector.reserve(n);
    unsigned int value = 1;
    for (unsigned int i = 1; i <= n; i++) {
      value *= i;
      vector.push_back(value);
    }
    return vector;
  }
}

BOOST_AUTO_TEST_CASE(IncrementIterator)
{
  std::vector< unsigned int > vector = shilyaev::generateFactorialVector(10);
  shilyaev::FactorialContainer factorialContainer;
  auto vectorIterator = vector.begin();
  auto factorialIterator = factorialContainer.begin();
  while (vectorIterator != vector.end()) {
    BOOST_CHECK_EQUAL(*vectorIterator++, *factorialIterator++);
  }
  BOOST_CHECK(factorialIterator == factorialContainer.end());
}

BOOST_AUTO_TEST_CASE(DecrementIterator)
{
  std::vector< unsigned int > vector = shilyaev::generateFactorialVector(10);
  shilyaev::FactorialContainer factorialContainer;
  auto vectorIterator = vector.end();
  auto factorialIterator = factorialContainer.end();
  while (vectorIterator != vector.begin()) {
    BOOST_CHECK_EQUAL(*--vectorIterator, *--factorialIterator);
  }
  BOOST_CHECK(factorialIterator == factorialContainer.begin());
}
