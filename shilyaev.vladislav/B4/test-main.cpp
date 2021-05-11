#define BOOST_TEST_MODULE B3
#include <boost/test/included/unit_test.hpp>
#include <sstream>
#include "data-struct.hpp"

BOOST_AUTO_TEST_CASE(CompareDataStruct)
{
  BOOST_CHECK(!shilyaev::compare({1, 2, "str"}, {1, 2, "str"}));
  BOOST_CHECK(shilyaev::compare({1, 2, "str"}, {2, 2, "str"}));
  BOOST_CHECK(shilyaev::compare({1, 2, "str"}, {1, 3, "str"}));
  BOOST_CHECK(shilyaev::compare({1, 2, "str"}, {1, 2, "string"}));
}

BOOST_AUTO_TEST_CASE(OutputDataStruct)
{
  const shilyaev::DataStruct dataStruct{1, -2, "str"};
  const std::string expected = "1, -2, str";
  std::ostringstream ostringstream;
  ostringstream << dataStruct;
  BOOST_CHECK_EQUAL(ostringstream.str(), expected);
}

BOOST_AUTO_TEST_CASE(InputDataStruct)
{
  std::istringstream istringstream("1,-2,str");
  const shilyaev::DataStruct expected{1, -2, "str"};
  shilyaev::DataStruct dataStruct;
  istringstream >> dataStruct;
  BOOST_CHECK_EQUAL(dataStruct, expected);
  BOOST_CHECK(istringstream);
}

BOOST_AUTO_TEST_CASE(InputDataStructInvalidKey)
{
  std::istringstream istringstream("1, 8, str");
  shilyaev::DataStruct dataStruct;
  istringstream >> dataStruct;
  BOOST_CHECK(istringstream.fail());
}

BOOST_AUTO_TEST_CASE(InputDataStructMalformed)
{
  std::istringstream istringstream("1 -1 str");
  shilyaev::DataStruct dataStruct;
  istringstream >> dataStruct;
  BOOST_CHECK(istringstream.fail());
}
