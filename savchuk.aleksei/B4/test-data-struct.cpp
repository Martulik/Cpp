#include <algorithm>
#include <functional>

#include <boost/test/unit_test.hpp>

#include "test-values.hpp"
#include "test-tools.hpp"

namespace lab = savchuk;

BOOST_AUTO_TEST_SUITE(input)

BOOST_AUTO_TEST_CASE(correct_input)
{
  std::istringstream ss;
  auto first = lab::correctValues.cbegin();
  auto last = lab::correctValues.cend();
  std::for_each(first, last, std::bind(lab::checkCorrectInput, std::move(ss), std::placeholders::_1));
}

BOOST_AUTO_TEST_CASE(incorrect_input)
{
  std::istringstream ss;
  auto first = lab::incorrectValues.cbegin();
  auto last = lab::incorrectValues.cend();
  std::for_each(first, last, std::bind(lab::checkIncorrectInput, std::move(ss), std::placeholders::_1));
}

BOOST_AUTO_TEST_CASE(invalid_keys)
{
  std::istringstream ss;
  auto first = lab::invalidKeys.cbegin();
  auto last = lab::invalidKeys.cend();
  std::for_each(first, last, std::bind(lab::checkInvalidKey, std::move(ss), std::placeholders::_1));
}

BOOST_AUTO_TEST_SUITE_END();
