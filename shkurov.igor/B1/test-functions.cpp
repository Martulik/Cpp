#include <boost/test/unit_test.hpp>

#include "functions.hpp"

namespace lab = shkurov;

BOOST_AUTO_TEST_SUITE(functions)

BOOST_AUTO_TEST_CASE(containsSpaces)
{
  std::string strTrue("Hello world!");
  std::string strFalse("This_string_techincally_has_no_spaces");

  BOOST_CHECK_EQUAL(lab::containsSpaces(strTrue), true);
  BOOST_CHECK_EQUAL(lab::containsSpaces(strFalse), false);
}

BOOST_AUTO_TEST_CASE(isNumber)
{
  std::string strNumber("12393102");
  std::string strSentence("2020 Polytech");

  BOOST_CHECK_EQUAL(lab::isNumber(strNumber), true);
  BOOST_CHECK_EQUAL(lab::isNumber(strSentence), false);
}

BOOST_AUTO_TEST_SUITE_END();
