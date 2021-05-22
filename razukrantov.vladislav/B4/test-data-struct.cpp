#include <sstream>

#include <boost/test/unit_test.hpp>

#include "data-struct.hpp"

BOOST_AUTO_TEST_SUITE(testDataStruct)

BOOST_AUTO_TEST_CASE(correctInput)
{
  std::stringstream stream("1,-1,str");
  razukrantov::DataStruct ds;
  stream >> ds;
  BOOST_CHECK_EQUAL(ds.key1, 1);
  BOOST_CHECK_EQUAL(ds.key2, -1);
  BOOST_CHECK_EQUAL(ds.str, "str");
}

BOOST_AUTO_TEST_CASE(incorrectInput)
{
  std::stringstream stream("10, 6, fgh");
  razukrantov::DataStruct ds;
  stream >> ds;
  BOOST_CHECK(stream.fail());
}

BOOST_AUTO_TEST_SUITE_END()
