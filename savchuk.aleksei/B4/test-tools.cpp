#include <sstream>
#include <vector>

#include <boost/test/unit_test.hpp>

#include "tools.hpp"

namespace lab = savchuk;

std::vector< std::string > v = { "1,", "3," };

BOOST_AUTO_TEST_SUITE(input)

BOOST_AUTO_TEST_CASE(read_key)
{
  std::istringstream ss("6,");
  BOOST_CHECK_THROW(lab::readKey(ss, ','), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END();
