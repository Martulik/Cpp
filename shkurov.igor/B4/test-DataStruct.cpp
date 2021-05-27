#include "sstream"

#include <boost/test/unit_test.hpp>

#include "DataStruct.hpp"

namespace lab = shkurov;

BOOST_AUTO_TEST_SUITE(DataStruct)

BOOST_AUTO_TEST_CASE(inputOutOfRange)
{
  lab::DataStruct data;
  std::stringstream in("1, 10, str");
  BOOST_CHECK_THROW(in >> data, std::logic_error);
}

BOOST_AUTO_TEST_CASE(incorrectDelimeter)
{
  lab::DataStruct data;
  std::stringstream in("1. 10, str");
  BOOST_CHECK_THROW(in >> data, std::logic_error);
}

BOOST_AUTO_TEST_CASE(empty)
{
  lab::DataStruct data;
  std::stringstream in("");
  BOOST_CHECK_NO_THROW(in >> data);
}

BOOST_AUTO_TEST_CASE(compare)
{
  BOOST_REQUIRE(lab::compare({1, 3, "str"}, {2, 3, "str"}));
  BOOST_REQUIRE(lab::compare({2, 3, "str"}, {2, 5, "str"}));
  BOOST_REQUIRE(lab::compare({2, 3, "str"}, {2, 3, "strstr"}));
}

BOOST_AUTO_TEST_CASE(correctInput)
{
  lab::DataStruct data;
  std::stringstream in("1, 2, test");
  BOOST_CHECK_NO_THROW(in >> data);
}

BOOST_AUTO_TEST_SUITE_END()
