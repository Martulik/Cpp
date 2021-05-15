#include <sstream>
#include <boost/test/unit_test.hpp>
#include "datastruct.hpp"

namespace dan = doroshin;
namespace test = boost::unit_test;

BOOST_AUTO_TEST_SUITE(Datastruct)

BOOST_AUTO_TEST_CASE(empty)
{
  std::istringstream in ("");
  dan::DataStruct data;
  in >> data;
  BOOST_CHECK(in.fail());
}

BOOST_AUTO_TEST_CASE(no_commas)
{
  std::istringstream in ("1 1 a");
  dan::DataStruct data;
  in >> data;
  BOOST_CHECK(in.fail());
}

BOOST_AUTO_TEST_CASE(invalid_type)
{
  std::istringstream in ("a,b,c");
  dan::DataStruct data;
  in >> data;
  BOOST_CHECK(in.fail());
}

BOOST_AUTO_TEST_CASE(one_comma)
{
  std::istringstream in ("1,2 abc");
  dan::DataStruct data;
  in >> data;
  BOOST_CHECK(in.fail());
}

BOOST_AUTO_TEST_CASE(correct)
{
  std::istringstream in ("1,2,abc");
  dan::DataStruct data;
  in >> data;
  BOOST_CHECK(!in.fail());
  BOOST_CHECK_EQUAL(data.key1, 1);
  BOOST_CHECK_EQUAL(data.key2, 2);
  BOOST_CHECK_EQUAL(data.str, "abc");
}

BOOST_AUTO_TEST_CASE(invalid_first1)
{
  std::istringstream in ("-6,2 abc");
  dan::DataStruct data;
  in >> data;
  BOOST_CHECK(in.fail());
}

BOOST_AUTO_TEST_CASE(invalid_first2)
{
  std::istringstream in ("6,2 abc");
  dan::DataStruct data;
  in >> data;
  BOOST_CHECK(in.fail());
}

BOOST_AUTO_TEST_CASE(invalid_second1)
{
  std::istringstream in ("1,-7 abc");
  dan::DataStruct data;
  in >> data;
  BOOST_CHECK(in.fail());
}

BOOST_AUTO_TEST_CASE(invalid_second2)
{
  std::istringstream in ("1,7 abc");
  dan::DataStruct data;
  in >> data;
  BOOST_CHECK(in.fail());
}

BOOST_AUTO_TEST_SUITE_END()
