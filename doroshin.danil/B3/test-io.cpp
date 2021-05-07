#include <sstream>
#include <boost/test/unit_test.hpp>
#include "name.hpp"
#include "entry.hpp"

namespace dan = doroshin;
namespace test = boost::unit_test;

BOOST_AUTO_TEST_SUITE(Name)

BOOST_AUTO_TEST_CASE(empty_err)
{
  std::istringstream in ("");
  dan::Name name;
  in >> name;
  BOOST_CHECK(in.fail());
}

BOOST_AUTO_TEST_CASE(empty)
{
  std::istringstream in ("\"\"");
  dan::Name name;
  in >> name;
  BOOST_CHECK(!in.fail());
  BOOST_CHECK_EQUAL(name.name_, "");
}

BOOST_AUTO_TEST_CASE(missing_quote)
{
  std::istringstream in ("\'");
  dan::Name name;
  in >> name;
  BOOST_CHECK(in.fail());
}

BOOST_AUTO_TEST_CASE(correct)
{
  std::istringstream in ("\"Name\"");
  dan::Name name;
  in >> name;
  BOOST_CHECK(!in.fail());
  BOOST_CHECK_EQUAL(name.name_, "Name");
}

BOOST_AUTO_TEST_CASE(inner_quote)
{
  std::istringstream in ("\"Na\\\"me\"");
  dan::Name name;
  in >> name;
  BOOST_CHECK(!in.fail());
  BOOST_CHECK_EQUAL(name.name_, "Na\"me");
}

BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE(Entry)

BOOST_AUTO_TEST_CASE(empty_err)
{
  std::istringstream in ("");
  dan::Entry ent;
  in >> ent;
  BOOST_CHECK(in.fail());
}

BOOST_AUTO_TEST_CASE(missing_name)
{
  std::istringstream in ("123");
  dan::Entry ent;
  in >> ent;
  BOOST_CHECK(in.fail());
}

BOOST_AUTO_TEST_CASE(missing_space)
{
  std::istringstream in ("123\"abc\"");
  dan::Entry ent;
  in >> ent;
  BOOST_CHECK(in.fail());
}

BOOST_AUTO_TEST_CASE(correct)
{
  std::istringstream in ("123 \"abc\"");
  dan::Entry ent;
  in >> ent;
  BOOST_CHECK(!in.fail());
  BOOST_CHECK_EQUAL(ent.name.name_, "abc");
  BOOST_CHECK_EQUAL(ent.number, 123);
}

BOOST_AUTO_TEST_SUITE_END()