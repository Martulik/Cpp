#define BOOST_TEST_MODULE mytests
#include <sstream>
#include <boost/test/included/unit_test.hpp>
#include "data-struct.hpp"

BOOST_AUTO_TEST_SUITE(TestDataStruct)

BOOST_AUTO_TEST_CASE(CorrectInput)
{
  lebedeva::DataStruct data;
  std::stringstream input("1, 2, abc");
  input >> data;
  BOOST_CHECK_EQUAL(1, data.key1);
  BOOST_CHECK_EQUAL(2, data.key2);
  BOOST_CHECK_EQUAL("abc", data.str);
}

BOOST_AUTO_TEST_CASE(NoCommaDelimiter)
{
  lebedeva::DataStruct data;
  std::stringstream input("1:2:abc");
  input >> data;
  BOOST_CHECK(input.fail());
}

BOOST_AUTO_TEST_CASE(EmptyFirstKey)
{
  lebedeva::DataStruct data;
  std::stringstream input(", 2,abc");
  input >> data;
  BOOST_CHECK(input.fail());
}

BOOST_AUTO_TEST_CASE(FirstKeyNotNumber)
{
  lebedeva::DataStruct data;
  std::stringstream input("qwe,2,abc");
  input >> data;
  BOOST_CHECK(input.fail());
}

BOOST_AUTO_TEST_CASE(FirstKeyTooBig)
{
  lebedeva::DataStruct data;
  std::stringstream input("10,2,abc");
  input >> data;
  BOOST_CHECK(input.fail());
}

BOOST_AUTO_TEST_CASE(FirstKeyTooSmall)
{
  lebedeva::DataStruct data;
  std::stringstream input("-10,2,abc");
  input >> data;
  BOOST_CHECK(input.fail());
}

BOOST_AUTO_TEST_CASE(NoSecondDelimiter)
{
  lebedeva::DataStruct data;
  std::stringstream input("1, 2:abc");
  input >> data;
  BOOST_CHECK(input.fail());
}

BOOST_AUTO_TEST_CASE(EmptySecondKey)
{
  lebedeva::DataStruct data;
  std::stringstream input("1, ,abc");
  input >> data;
  BOOST_CHECK(input.fail());
}

BOOST_AUTO_TEST_CASE(SecondKeyNotNumber)
{
  lebedeva::DataStruct data;
  std::stringstream input("1, qwe,abc");
  input >> data;
  BOOST_CHECK(input.fail());
}

BOOST_AUTO_TEST_CASE(SecondKeyTooBig)
{
  lebedeva::DataStruct data;
  std::stringstream input("1,20,abc");
  input >> data;
  BOOST_CHECK(input.fail());
}

BOOST_AUTO_TEST_CASE(SecondKeyTooSmall)
{
  lebedeva::DataStruct data;
  std::stringstream input("1,-20,abc");
  input >> data;
  BOOST_CHECK(input.fail());
}

BOOST_AUTO_TEST_CASE(EmptyString)
{
  lebedeva::DataStruct data;
  std::stringstream input("1, 2, ");
  input >> data;
  BOOST_CHECK(input.fail());
}

BOOST_AUTO_TEST_CASE(CompareTest1)
{
  lebedeva::DataStruct data1 = { -2, 1, "abc" };
  lebedeva::DataStruct data2 = { 1, -2, "ab" };
  BOOST_CHECK(data1 < data2);
}

BOOST_AUTO_TEST_CASE(CompareTest2)
{
  lebedeva::DataStruct data1 = { 1, -2, "ab" };
  lebedeva::DataStruct data2 = { 1, 1, "abc" };
  BOOST_CHECK(data1 < data2);
}

BOOST_AUTO_TEST_CASE(CompareTest3)
{
  lebedeva::DataStruct data1 = { 1, -2, "ab" };
  lebedeva::DataStruct data2 = { 1, -2, "abc" };
  BOOST_CHECK(data1 < data2);
}

BOOST_AUTO_TEST_SUITE_END()
