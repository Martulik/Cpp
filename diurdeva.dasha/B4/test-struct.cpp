#include <sstream>
#include <boost/test/unit_test.hpp>
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
  std::stringstream input("-10,4,apple");
  input >> data;
  BOOST_CHECK(input.fail());

}

BOOST_AUTO_TEST_CASE(noSeparator)
{
  diurdeva::DataStruct data;
  std::stringstream input("2 2,apple");
  input >> data;
  BOOST_CHECK(input.fail());
}

BOOST_AUTO_TEST_CASE(checkOutput)
{
  diurdeva::DataStruct data{ 3, 2, "apple" };
  std::stringstream input;
  input << data;
  BOOST_CHECK_EQUAL(input.str(), "3,2,apple");
}

BOOST_AUTO_TEST_SUITE_END()
