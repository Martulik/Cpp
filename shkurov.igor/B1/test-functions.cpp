#include <boost/test/unit_test.hpp>

#include "functions.hpp"

namespace lab = shkurov;

BOOST_AUTO_TEST_SUITE(functions)

BOOST_AUTO_TEST_CASE(containsSpaces)
{
  std::string strTrue("Hello world!");
  std::string strFalse("This_string_techincally_has_no_spaces");

  BOOST_CHECK_EQUAL(lab::containsSpaces(strTrue.c_str()), true);
  BOOST_CHECK_EQUAL(lab::containsSpaces(strFalse.c_str()), false);
}

BOOST_AUTO_TEST_CASE(isNumber)
{
  std::string strNumber("12393102");
  std::string strSentence("2020 Polytech");

  BOOST_CHECK_EQUAL(lab::isNumber(strNumber.c_str()), true);
  BOOST_CHECK_EQUAL(lab::isNumber(strSentence.c_str()), false);
}

BOOST_AUTO_TEST_SUITE_END();
