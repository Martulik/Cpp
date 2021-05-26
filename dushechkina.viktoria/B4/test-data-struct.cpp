#include <sstream>
#include <boost/test/unit_test.hpp>
#include "data-struct.hpp"

BOOST_AUTO_TEST_SUITE(checkAll)

BOOST_AUTO_TEST_CASE(checkCorrectWorkInput)
{
  dushechkina::DataStruct line;
  std::stringstream input("1,2,programm");
  input >> line;
  BOOST_CHECK_EQUAL(1, line.key1);
  BOOST_CHECK_EQUAL(2, line.key2);
  BOOST_CHECK_EQUAL("programm", line.str);
}

BOOST_AUTO_TEST_CASE(checkWrongWorkInput)
{
  dushechkina::DataStruct line;
  std::stringstream input("100,-100,programm");
  input >> line;
  BOOST_CHECK(input.fail());
}

BOOST_AUTO_TEST_SUITE_END()
