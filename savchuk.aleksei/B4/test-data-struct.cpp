#include <sstream>

#include <boost/test/unit_test.hpp>

#include "data-struct.hpp"
#include "tools.hpp"
#include "test-values.hpp"

namespace lab = savchuk;

BOOST_AUTO_TEST_SUITE(input)

BOOST_AUTO_TEST_CASE(correct_input)
{
  for (auto&& str: lab::correctValues)
  {
    std::istringstream ss(str);
    lab::DataStruct ds;
    BOOST_CHECK(ss >> ds);
  }
}

BOOST_AUTO_TEST_CASE(incorrect_input)
{
  for (auto&& str: lab::incorrectValues)
  {
    std::istringstream ss(str);
    lab::DataStruct ds;
    BOOST_CHECK(!(ss >> ds));
  }
}

BOOST_AUTO_TEST_CASE(invalid_keys)
{
  for (auto&& str: lab::invalidKeys)
  {
    std::istringstream ss(str);
    lab::DataStruct ds;
    BOOST_CHECK_THROW(ss >> ds, std::invalid_argument);
  }
}

BOOST_AUTO_TEST_SUITE_END();
