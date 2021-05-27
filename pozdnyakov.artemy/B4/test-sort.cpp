#include <boost/test/unit_test.hpp>
#include "test-functions.hpp"

namespace poz = pozdnyakov;

BOOST_AUTO_TEST_SUITE(test_sort)

BOOST_AUTO_TEST_CASE(different_key1)
{
  auto getter = [](const poz::DataStruct& obj)
  {
    return obj.key1;
  };
  std::vector< poz::DataStruct > vector
  {
    {5, -3, "rogki"},
    {4, 1, "eopf"},
    {-2, -3, "pewjofi"}
  };
  BOOST_REQUIRE(poz::testSort< int >(vector, getter, std::less< int >()));
}

BOOST_AUTO_TEST_CASE(different_key2)
{
  auto getter = [](const poz::DataStruct& obj)
  {
    return obj.key2;
  };
  std::vector< poz::DataStruct > vector
  {
    {3, 4, "asdfwdqmgh"},
    {3, -2, "kjhtre"},
    {3, 1, "uyhgfcxs"}
  };
  BOOST_REQUIRE(poz::testSort< int >(vector, getter, std::less< int >()));
}

BOOST_AUTO_TEST_CASE(different_str)
{
  auto getter = [](const poz::DataStruct& obj)
  {
    return obj.str;
  };
  auto strComp = [](std::string str1, std::string str2)
  {
    return str1.length() < str2.length();
  };
  std::vector< poz::DataStruct > vector
  {
    {2, -1, "pwqinf"},
    {2, -1, "ioenfwo"},
    {2, -1, "fineqofiqqq"}
  };
  BOOST_REQUIRE(poz::testSort< std::string >(vector, getter, strComp));
}

BOOST_AUTO_TEST_SUITE_END()
