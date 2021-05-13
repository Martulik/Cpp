#include <boost/test/unit_test.hpp>
#include <sstream>
#include "dataStruct.hpp"

BOOST_AUTO_TEST_SUITE(dataStruct)

BOOST_AUTO_TEST_CASE(checkInput)
{
  diurdeva::DataStruct data;
  std::stringstream input("2,3,apple");
  input >> data;
  BOOST_CHECK_EQUAL(2, data.key1);
  BOOST_CHECK_EQUAL(3, data.key2);
  BOOST_CHECK_EQUAL("apple", data.str);
}

BOOST_AUTO_TEST_CASE(wrongInput)
{
  diurdeva::DataStruct data;
  std::stringstream input("2,-4,apple");
  BOOST_CHECK_THROW(input >> data, std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(noSeparator)
{
  diurdeva::DataStruct data;
  std::stringstream input("2 2,apple");
  BOOST_CHECK_THROW(input >> data, std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(checkOutput)
{
  diurdeva::DataStruct data{ 3, 2, "apple" };
  std::stringstream input;
  input << data;
  BOOST_CHECK_EQUAL(input.str(), "1,2,apple\n");
}

BOOST_AUTO_TEST_SUITE_END()
