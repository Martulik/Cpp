#include <algorithm>

#include <boost/test/unit_test.hpp>

#include "test-tools.hpp"
#include "test-values.hpp"

namespace lab = savchuk;

BOOST_AUTO_TEST_SUITE(input_shapes)

BOOST_AUTO_TEST_CASE(correct_input_shapes)
{
  std::for_each(lab::correctInput.begin(), lab::correctInput.end(), lab::checkCorrectInput);
}

BOOST_AUTO_TEST_CASE(incorrect_input_shapes)
{
  std::for_each(lab::incorrectInput.begin(), lab::incorrectInput.end(), lab::checkIncorrectInput);
}

BOOST_AUTO_TEST_SUITE_END();
